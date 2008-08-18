/*
 * Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of The TenDRA Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific, prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
/*
                Crown Copyright (c) 1997

    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-

        (1) Its Recipients shall ensure that this Notice is
        reproduced upon any copies or amended versions of it;

        (2) Any amended version of it shall be clearly marked to
        show both the nature of and the organisation responsible
        for the relevant amendment or amendments;

        (3) Its onward transfer from a recipient to another
        party shall be deemed to be that party's acceptance of
        these conditions;

        (4) DERA gives no warranty or assurance as to its
        quality or suitability for any purpose and DERA accepts
        no liability whatsoever in relation to any use to which
        it may be put.
*/


/*
 * c-lexer.c - SID C lexical analyser.
 *
 * This file implements the SID C lexical analyser.  Any changes to the syntax
 * of SID identifiers should be made both here and in the file
 * "lexer.c".
 */

/*
 * XXX Possibly the various calls to c_lexer_readchar() should really call
 * c_lexi_getchar() instead.
 */

#include <assert.h>
#include <ctype.h>

#include "../shared/check/check.h"
#include "../shared/error/error.h"
#include "c-lexer.h"
#include "c-lexi_lexer.h"

struct c_lexi_state c_lexer_current_state ;


/*
 * These are global until lexi supports passing opaque pointers, which is
 * planned during its forthcoming API change.
 */
CLexerStreamT *c_lexer_stream;
CLexT *c_lexer_token;
CCodeT *code;

/*
 * Generic identifier-reading support; this takes the type of token
 * to return once the identifier is read.
 *
 * This (and everything using it) will be removed once Lexi supports reading
 * identifiers by itself.
 */
int
c_lexer_support_read_id(int c, int rettok, enum c_lexi_groups bodygroup)
{
	IStreamT *istream;
	DStringT dstring;

	istream = &c_lexer_stream->istream;

	dstring_init(&dstring);
	for (;;) {
		char t;

		dstring_append_char(&dstring, c);

		if (!istream_peek_char(istream, &t)) {
			error_posn(ERROR_SERIOUS, istream_name(istream), (int) istream_line(istream),
				"end of file in identifier");
			return C_TOK_EOF;
		}

		c = t;

		if (!c_lexi_group(bodygroup, c)) {
			break;
		}

		c_lexi_getchar();
	}

	c_lexer_token->t = rettok;
	dstring_to_nstring(&dstring, &c_lexer_token->u.string);
	dstring_destroy(&dstring);

	if (rettok == C_TOK_C_HIDENTIFIER) {
		/*
		 * This is a special case; we differentiate between C and SID
		 * identifiers based on the premise that all SID identifiers
		 * contain at least one hyphen.
		 */
		if (nstring_contains(&c_lexer_token->u.string, '-')) {
			c_lexer_token->t = C_TOK_SID_HIDENTIFIER;
		}
	}

	return c_lexer_token->t;
}


/*
 * Externally visible functions. These form sid's interface to the lexer.
 */

void
c_lexer_init(CLexerStreamT *stream, IStreamT *istream)
{
	istream_assign(&stream->istream, istream);
	c_lexer_stream = stream;
	c_lexer_token = &stream->token;
	c_lexi_init(&c_lexer_current_state);
	c_lexer_next_token(stream);
}

void
c_lexer_close(CLexerStreamT *stream)
{
	istream_close(&stream->istream);
}

const char *
c_lexer_stream_name(CLexerStreamT *stream)
{
	return istream_name(&stream->istream);
}

unsigned
c_lexer_stream_line(CLexerStreamT *stream)
{
	return istream_line(&stream->istream);
}

CTokenT
c_lexer_get_terminal(CLexerStreamT *stream)
{
	return stream->token.t;
}

void
c_lexer_next_token(CLexerStreamT *stream)
{
	stream->token = *c_lexer_token;
	c_lexer_token->t = c_lexi_read_token(&c_lexer_current_state);
}

NStringT *
c_lexer_string_value(CLexerStreamT *stream)
{
	assert(stream->token.t == C_TOK_C_HIDENTIFIER
		|| stream->token.t == C_TOK_SID_HIDENTIFIER
		|| stream->token.t == C_TOK_ACT_HBASIC
		|| stream->token.t == C_TOK_ACT_HLABEL
		|| stream->token.t == C_TOK_ACT_HMODIFIABLE
		|| stream->token.t == C_TOK_ACT_HIDENTIFIER
		|| stream->token.t == C_TOK_ACT_HREFERENCE
		|| stream->token.t == C_TOK_ACT_HCODESTRING);

	return &stream->token.u.string;
}

CCodeT *
c_lexer_code_value(CLexerStreamT *stream)
{
	assert(stream->token.t == C_TOK_CODE);
	return stream->token.u.code;
}

void
c_lexer_save_terminal(CLexerStreamT *stream, CTokenT error_terminal)
{
	assert(stream->token.t != error_terminal);
	stream->saved_terminal = stream->token.t;
	stream->token.t = error_terminal;
}

void
c_lexer_restore_terminal(CLexerStreamT *stream)
{
	stream->token.t = stream->saved_terminal;
}


/*
 * Lexi interface wrappers.
 */

int
c_lexi_getchar(void)
{
	IStreamT *istream;
	char c;

	istream = &c_lexer_stream->istream;
	assert(istream);

	if (!istream_read_char(istream, &c)) {
		return LEXI_EOF;
	}

	return c;
}

int
c_lexer_read_builtin(int c0, int c1)
{
	IStreamT *istream;
	DStringT dstring;
	char *cstring;
	int c;

	UNUSED(c0);

	istream = &c_lexer_stream->istream;

	dstring_init(&dstring);
	c = c1;	/* [builtinstart] */
	do {
		if (!c_lexi_group(c_lexi_group_builtinbody,c)) {
			error_posn(ERROR_SERIOUS, istream_name(&c_lexer_stream->istream), (int) istream_line(&c_lexer_stream->istream),
				"illegal character in identifier': '%C'", (void *) &c);
			return C_TOK_EOF;	/* XXX EOF? */
		}

		dstring_append_char(&dstring, c);

		c = c_lexi_getchar();
		if (c == LEXI_EOF) {
			error_posn(ERROR_SERIOUS, istream_name(istream), (int) istream_line(istream),
				"end of file in identifier");
			return C_TOK_EOF;
		}
	} while (!c_lexi_group(c_lexi_group_builtindlmt, c));

	/* XXX This would be replaced by keywords pending lexi's reworked keyword API */
	cstring = dstring_destroy_to_cstring(&dstring);
	if (cstring_ci_equal(cstring, "prefixes")) {
		c_lexer_token->t = C_TOK_BLT_HPREFIXES;
	} else if (cstring_ci_equal(cstring, "persistents")) {
		c_lexer_token->t = C_TOK_BLT_HPERSISTENTS;
	} else if (cstring_ci_equal(cstring, "maps")) {
		c_lexer_token->t = C_TOK_BLT_HMAPS;
	} else if (cstring_ci_equal(cstring, "assignments")) {
		c_lexer_token->t = C_TOK_BLT_HASSIGNMENTS;
	} else if (cstring_ci_equal(cstring, "assign")) {
		c_lexer_token->t = C_TOK_BLT_HASSIGNMENTS;
	} else if (cstring_ci_equal(cstring, "terminals")) {
		c_lexer_token->t = C_TOK_BLT_HTERMINALS;
	} else if (cstring_ci_equal(cstring, "header")) {
		c_lexer_token->t = C_TOK_BLT_HHEADER;
	} else if (cstring_ci_equal(cstring, "actions")) {
		c_lexer_token->t = C_TOK_BLT_HACTIONS;
	} else if (cstring_ci_equal(cstring, "trailer")) {
		c_lexer_token->t = C_TOK_BLT_HTRAILER;
	} else if (cstring_ci_equal(cstring, "result-assignments")) {
		c_lexer_token->t = C_TOK_BLT_HRESULT_HASSIGN;
	} else if (cstring_ci_equal(cstring, "result-assign")) {
		c_lexer_token->t = C_TOK_BLT_HRESULT_HASSIGN;
	} else if (cstring_ci_equal(cstring, "parameter-assignments")) {
		c_lexer_token->t = C_TOK_BLT_HPARAM_HASSIGN;
	} else if (cstring_ci_equal(cstring, "parameter-assign")) {
		c_lexer_token->t = C_TOK_BLT_HPARAM_HASSIGN;
	} else if (cstring_ci_equal(cstring, "param-assignments")) {
		c_lexer_token->t = C_TOK_BLT_HPARAM_HASSIGN;
	} else if (cstring_ci_equal(cstring, "param-assign")) {
		c_lexer_token->t = C_TOK_BLT_HPARAM_HASSIGN;
	} else {
		error_posn(ERROR_FATAL, istream_name(istream), (int) istream_line(istream),
			"unknown builtin '%%%s%%'", cstring);
		UNREACHED;
	}
	DEALLOCATE(cstring);

	return c_lexer_token->t;
}

/*
 * Read a code string until an @ is found (since all non-codestring tokens begin
 * with an @).
 */
int
c_lexer_act_read_string(int c)
{
	IStreamT *istream;
	DStringT dstring;

	istream = &c_lexer_stream->istream;

	dstring_init(&dstring);
	for (;;) {
		char t;

		dstring_append_char(&dstring, c);

		if (!istream_peek_char(istream, &t)) {
			error_posn(ERROR_SERIOUS, istream_name(istream), (int) istream_line(istream),
				"end of file in C code block");
			return C_TOK_EOF;
		}

		c = t;

		if (c == '@') {
			break;
		}

		c_lexi_getchar();
	}

	c_lexer_token->t = C_TOK_ACT_HCODESTRING;
	dstring_to_nstring(&dstring, &c_lexer_token->u.string);
	dstring_destroy(&dstring);

	return c_lexer_token->t;
}

int
c_lexer_unknown_token(int c)
{
	IStreamT *istream;

	istream = &c_lexer_stream->istream;

	if (c == LEXI_EOF) {
		return C_TOK_EOF;
	}

	error_posn(ERROR_SERIOUS, istream_name(istream), (int) istream_line(istream),
		"illegal character '%C'", (void *) &c);

	/*
	 * We try to continue regardless as convenience to the user so that
	 * any further errors might possibly be identified.
	 */
	return c_lexi_read_token(&c_lexer_current_state);
}
