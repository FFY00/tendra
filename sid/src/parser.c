/*
 * Automatically generated from the files:
 *	parser.sid
 * and
 *	parser.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */


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

#include <limits.h>
#include <assert.h>

#include "parser.h"
#include "adt/action.h"
#include "adt/basic.h"
#include <exds/common.h>
#include <exds/exception.h>
#include <exds/bitvec.h>
#include <exds/dalloc.h>
#include <exds/dstring.h>
#include "gen-errors.h"
#include "grammar.h"
#include "lexer.h"
#include "adt/non-local.h"
#include "adt/rule.h"
#include "adt/scope.h"
#include "adt/table.h"
#include "adt/types.h"

#define CURRENT_TERMINAL lexer_get_terminal (sid_current_stream)
#define ADVANCE_LEXER lexer_next_token (sid_current_stream)
#define SAVE_LEXER(x) (lexer_save_terminal (sid_current_stream, (LexerTokenT) (x)))
#define RESTORE_LEXER (lexer_restore_terminal (sid_current_stream))
#define ALT_LIMIT (UINT_MAX - 1)

/* typedefs for the maps section */
typedef AltT * AltP;
typedef EntryT * EntryP;
typedef ItemT * ItemP;
typedef RuleT *RuleP;
typedef NonLocalEntryT *NonLocalEntryP;

LexerStreamT *		sid_current_stream;

static ScopeStackT	sid_scope_stack;
static ScopeStackT	sid_global_scope;
static ScopeStackT 	*sid_current_scope;
static EntryT *		sid_current_entry;
static RuleT *		sid_enclosing_rule;
static RuleT *		sid_current_rule;
static BoolT		sid_redefining_entry;
static NStringT		sid_maximum_scope;
static BoolT		sid_saved_pred_id;
static BoolT		sid_current_pred_id;
static AltT *		sid_current_alt;
static ItemT *		sid_current_item;
static unsigned		sid_alternative;
static BoolT            sid_internal_rule;
static EntryT *		sid_external_rule;
static unsigned		sid_num_alternatives = 0;
static BoolT		sid_propagating_error = FALSE;
static BoolT		sid_finished_terminals = FALSE;

/* BEGINNING OF FUNCTION DECLARATIONS */

static void ZR256(GrammarP, TypeTupleT *, TypeTupleT *);
static void ZR242(GrammarP);
static void ZR237(GrammarP);
static void ZR142(GrammarP, TypeTupleT *);
static void ZR239(GrammarP);
static void ZR177(GrammarP, TypeTupleT *);
static void ZR246(GrammarP);
static void ZR169(GrammarP, TypeTupleT *);
static void ZR151(GrammarP);
static void ZR152(GrammarP);
static void ZR181(GrammarP, TypeTupleT *);
static void ZR228(GrammarP);
static void ZR154(GrammarP);
static void ZR189(GrammarP, TypeTupleT *);
static void ZR198(GrammarP);
static void ZR171(GrammarP, TypeTupleT *);
static void ZR293(GrammarP, NStringT *);
static void ZR167(GrammarP);
static void ZR295(GrammarP);
extern void sid_parse_grammar(GrammarP);
static void ZR145(GrammarP, TypeTupleT *);
static void ZR296(GrammarP, NStringT *);
static void ZR297(GrammarP, NStringT *);
static void ZR147(GrammarP, TypeTupleT *);
static void ZR183(GrammarP, TypeTupleT *);
static void ZR206(GrammarP, TypeTupleT *);
static void ZR226(GrammarP);
static void ZR158(GrammarP);
static void ZR202(GrammarP, TypeTupleT *);
static void ZR261(GrammarP);
static void ZR133(GrammarP, TypeTupleT *);
static void ZR191(GrammarP);
static void ZR192(GrammarP);
static void ZR267(GrammarP);
static void ZR130(GrammarP, TypeTupleT *, TypeTupleT *);
static void ZR215(GrammarP);
static void ZR160(GrammarP);
static void ZR221(GrammarP);
static void ZR224(GrammarP, TypeTupleT *);
static void ZR225(GrammarP);
static void ZR233(GrammarP);
static void ZR193(GrammarP);
static void ZR235(GrammarP);
static void ZR269(GrammarP);
static void ZR174(GrammarP, TypeTupleT *);
static void ZR241(GrammarP);
static void ZR186(GrammarP, TypeTupleT *);

/* BEGINNING OF STATIC VARIABLES */

static BoolT ZI0;

/* BEGINNING OF FUNCTION DEFINITIONS */

static void
ZR256(GrammarP sid_current_grammar, TypeTupleT *ZI128, TypeTupleT *ZI129)
{
    switch (CURRENT_TERMINAL) {
      case 12: case 21:
	{
	    {

    if (sid_current_entry) {
	KeyT * key = entry_key (sid_current_entry);

	if (rule_is_defined (sid_current_rule)) {
	    E_rule_already_defined (key);
	    sid_current_entry = NULL;
	    types_destroy ((ZI128));
	    types_destroy ((ZI129));
	} else {
	    TypeTupleT * param   = rule_param (sid_current_rule);
	    TypeTupleT * result  = rule_result (sid_current_rule);
	    BoolT      errored = FALSE;

	    rule_defined (sid_current_rule);
	    if (!types_disjoint_names ((ZI128))) {
		E_rule_param_clash (key, (ZI128));
		errored = TRUE;
	    }
	    if (types_check_shadowing ((ZI128), &sid_scope_stack,
				       sid_current_rule)) {
		errored = TRUE;
	    }
	    if (sid_redefining_entry) {
		if (!types_fillin_names (param, (ZI128))) {
		    E_rule_param_mismatch (key, param, (ZI128));
		    errored = TRUE;
		}
		types_destroy ((ZI128));
	    } else {
		types_assign (param, (ZI128));
	    }
	    if (!types_disjoint_names ((ZI129))) {
		E_rule_result_clash (key, (ZI129));
		errored = TRUE;
	    }
	    if (types_check_shadowing ((ZI129), &sid_scope_stack,
				       sid_current_rule)) {
		errored = TRUE;
	    }
	    if (types_contains_references ((ZI129))) {
		E_rule_result_has_refs (key, (ZI129));
		errored = TRUE;
	    }
	    if (sid_redefining_entry) {
		if (!types_fillin_names (result, (ZI129))) {
		    E_rule_result_mismatch (key, result, (ZI129));
		    errored = TRUE;
		}
		types_destroy ((ZI129));
	    } else {
		types_assign (result, (ZI129));
	    }
	    if (errored) {
		sid_current_entry = NULL;
	    } else {
		if (types_intersect (param, result)) {
		    E_rule_formal_clash (key, param, result);
		    sid_current_entry = NULL;
		}
	    }
	}
    } else {
	types_destroy ((ZI128));
	types_destroy ((ZI129));
    }
    sid_alternative   = 0;
    sid_internal_rule = FALSE;
    sid_external_rule = sid_current_entry;
    nstring_init (&sid_maximum_scope);
	    }
	    {

    if (sid_current_entry) {
	KeyT *     key   = entry_key (sid_current_entry);
	NStringT * scope = key_get_string (key);

	scope_stack_push (&sid_scope_stack, scope);
    }
	    }
	    ZR198 (sid_current_grammar);
	    ZR221 (sid_current_grammar);
	    {
		if ((CURRENT_TERMINAL) == 26) {
		    RESTORE_LEXER;
		    goto ZL1;
		}
		{
		    switch (CURRENT_TERMINAL) {
		      case 13:
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_begin_rule ();
    }
		    }
		}
	      ZL2:;
	    }
	    ZR226 (sid_current_grammar);
	    ZR233 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if (sid_current_entry) {
	scope_stack_pop (&sid_scope_stack);
    }
	    }
	    {

    if (sid_current_entry) {
	nstring_assign (rule_maximum_scope (sid_current_rule),
			&sid_maximum_scope);
    } else {
	nstring_destroy (&sid_maximum_scope);
    }
	    }
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 9:
	{
	    {

    if (sid_current_entry) {
	KeyT *       key     = entry_key (sid_current_entry);
	TypeTupleT * param   = rule_param (sid_current_rule);
	TypeTupleT * result  = rule_result (sid_current_rule);
	BoolT      errored = FALSE;

	if (types_contains_names ((ZI128))) {
	    E_rule_param_has_names (key, (ZI128));
	    errored = TRUE;
	}
	if (sid_redefining_entry) {
	    if (!types_equal (param, (ZI128))) {
		E_rule_param_mismatch (key, param, (ZI128));
		errored = TRUE;
	    }
	}
	if (types_contains_names ((ZI129))) {
	    E_rule_result_has_names (key, (ZI129));
	    errored = TRUE;
	}
	if (types_contains_references ((ZI129))) {
	    E_rule_result_has_refs (key, (ZI129));
	    errored = TRUE;
	}
	if (sid_redefining_entry) {
	    if (!types_equal (result, (ZI129))) {
		E_rule_result_mismatch (key, result, (ZI129));
		errored = TRUE;
	    }
	}
	if (errored || sid_redefining_entry) {
	    types_destroy ((ZI128));
	    types_destroy ((ZI129));
	} else {
	    types_assign (param, (ZI128));
	    types_assign (result, (ZI129));
	}
    } else {
	types_destroy ((ZI128));
	types_destroy ((ZI129));
    }
	    }
	    ADVANCE_LEXER;
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR242(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_242:;
    {
	ZR239 (sid_current_grammar);
	{
	    switch (CURRENT_TERMINAL) {
	      case 15:
		{
		    ADVANCE_LEXER;
		    goto ZL2_242;
		}
		/*UNREACHED*/
	      case 26:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		break;
	    }
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR237(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{

    if (sid_current_entry) {
	sid_current_alt = alt_create ();
    }
	}
	ZR235 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    if ((sid_current_entry) && (sid_current_alt)) {
	if (types_check_names (rule_result (sid_current_rule),
			       alt_names (sid_current_alt))) {
	    TypeTupleT used;

	    types_copy (&used, rule_result (sid_current_rule));
	    item_compute_minimal_dataflow (alt_item_head (sid_current_alt),
					   &used);
	    types_destroy (&used);
	    rule_set_handler (sid_current_rule, sid_current_alt);
	} else {
	    (void) alt_deallocate (sid_current_alt);
	    E_handler_result_mismatch (entry_key (sid_external_rule));
	}
    }
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR142(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_142:;
    {
	ZR133 (sid_current_grammar, ZI132);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		{

    (ZI0) = ((CURRENT_TERMINAL == LEXER_TOK_CLOSE_TUPLE) ||
		  (CURRENT_TERMINAL == LEXER_TOK_EOF) ||
		  (sid_propagating_error));
		}
		if (!ZI0)
		    goto ZL5;
		goto ZL3;
	    }
	    /*UNREACHED*/
	  ZL5:;
	    switch (CURRENT_TERMINAL) {
	      case 23:
		{
		    ADVANCE_LEXER;
		    goto ZL2_142;
		}
		/*UNREACHED*/
	      default:
		goto ZL4;
	    }
	    /*UNREACHED*/
	  ZL4:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_separator ();
    }
		}
		goto ZL2_142;
	    }
	    /*UNREACHED*/
	  ZL3:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR239(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 17:
	{
	    {

    if ((++ sid_num_alternatives) == ALT_LIMIT) {
	E_too_many_alternatives ();
	UNREACHED;
    }
    if (!sid_internal_rule) {
	sid_alternative ++;
    }
    if (sid_current_entry) {
	if (rule_has_empty_alt (sid_current_rule)) {
	    E_multiple_empty_alts (entry_key (sid_external_rule));
	} else if (!types_equal_zero_tuple (rule_result (sid_current_rule))) {
	    E_alt_result_mismatch (entry_key (sid_external_rule),
				   sid_alternative);
	} else {
	    rule_add_empty_alt (sid_current_rule);
	}
    }
	    }
	    ADVANCE_LEXER;
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 4: case 6: case 10: case 13: case 18:
      case 19: case 24:
	{
	    {

    if ((++ sid_num_alternatives) == ALT_LIMIT) {
	E_too_many_alternatives ();
	UNREACHED;
    }
    if (!sid_internal_rule) {
	sid_alternative ++;
    }
    if (sid_current_entry) {
	sid_current_alt = alt_create ();
    }
	    }
	    ZR235 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if ((sid_current_entry) && (sid_current_alt)) {
	if (types_check_names (rule_result (sid_current_rule),
			       alt_names (sid_current_alt))) {
	    TypeTupleT used;

	    types_copy (&used, rule_result (sid_current_rule));
	    item_compute_minimal_dataflow (alt_item_head (sid_current_alt),
					   &used);
	    types_destroy (&used);
	    rule_add_alt (sid_current_rule, sid_current_alt);
	} else {
	    (void) alt_deallocate (sid_current_alt);
	    E_alt_result_mismatch (entry_key (sid_external_rule),
				   sid_alternative);
	}
    }
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_alternative ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
	{

    sid_propagating_error = FALSE;
	}
    }
}

static void
ZR177(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4: case 18: case 19: case 24:
	{
	    ZR174 (sid_current_grammar, ZI132);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR246(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	NStringT ZI156;

	switch (CURRENT_TERMINAL) {
	  case 4:
	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	{
	    switch (CURRENT_TERMINAL) {
	      case 5:
		{
		    ADVANCE_LEXER;
		    ZR293 (sid_current_grammar, &ZI156);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL3;
		    }
		}
		break;
	      case 9: case 12: case 21:
		{
		    TypeTupleT ZI128;
		    TypeTupleT ZI129;

		    {

    types_init (&(ZI128));
		    }
		    {

    types_init (&(ZI129));
		    }
		    {

    sid_current_entry = scope_stack_add_rule (sid_current_scope,
					      grammar_table(sid_current_grammar), &(ZI156),
					      sid_enclosing_rule,
					      &sid_redefining_entry);
    if (sid_current_entry) {
	sid_current_rule = entry_get_rule (sid_current_entry);
    } else {
	E_duplicate_rule ((&ZI156));
	nstring_destroy (&(ZI156));
    }
		    }
		    ZR256 (sid_current_grammar, &ZI128, &ZI129);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL3;
		    }
		}
		break;
	      default:
		goto ZL3;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_other_defn ();
    }
		}
		{

    nstring_destroy (&(ZI156));
		}
		{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		}
	    }
	  ZL2:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR169(GrammarP sid_current_grammar, TypeTupleT *ZO132)
{
    TypeTupleT ZI132;

    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{

    sid_current_pred_id = FALSE;
	}
	ZR191 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    types_init (&(ZI132));
	}
	ZR177 (sid_current_grammar, &ZI132);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    sid_propagating_error = FALSE;
	}
	ZR192 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (26);
    return;
  ZL0:;
    {

	if((ZO132->head=ZI132.head)==NULL) 
		ZO132->tail = &(ZO132->head);
	else 
		ZO132->tail= ZI132.tail ;
    }
}

static void
ZR151(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 8:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_arrow ();
    }
	}
    }
}

static void
ZR152(GrammarP sid_current_grammar)
{
  ZL2_152:;
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    ZR154 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    } else {
		goto ZL2_152;
	    }
	}
	/*UNREACHED*/
      case 26:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR181(GrammarP sid_current_grammar, TypeTupleT *ZO132)
{
    TypeTupleT ZI132;

    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{

    sid_current_pred_id = FALSE;
	}
	ZR191 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    types_init (&(ZI132));
	}
	ZR189 (sid_current_grammar, &ZI132);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    sid_propagating_error = FALSE;
	}
	ZR192 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (26);
    return;
  ZL0:;
    {

	if((ZO132->head=ZI132.head)==NULL) 
		ZO132->tail = &(ZO132->head);
	else 
		ZO132->tail= ZI132.tail ;
    }
}

static void
ZR228(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 13:
	{
	    EntryP ZI162;
	    RuleP ZI69;
	    AltP ZI230;
	    BoolT ZI231;
	    ItemP ZI232;

	    ADVANCE_LEXER;
	    {

    (ZI162)      = sid_current_entry;
    (ZI69)       = sid_current_rule;
    (ZI230)        = sid_current_alt;
    (ZI231)   = sid_internal_rule;
    (ZI232)             = NULL;
    sid_internal_rule = TRUE;
    if ((sid_current_entry) && (sid_current_alt)) {
	sid_current_entry = table_add_generated_rule (grammar_table(sid_current_grammar),
						      FALSE);
	sid_current_rule  = entry_get_rule (sid_current_entry);
	(ZI232)             = item_create (sid_current_entry);
	rule_defined (sid_current_rule);
	item_inlinable ((ZI232));
	types_copy (item_param ((ZI232)), rule_param ((ZI69)));
	types_append_copy (item_param ((ZI232)), alt_names ((ZI230)));
	types_copy (rule_param (sid_current_rule), item_param ((ZI232)));
	types_make_references (rule_param (sid_current_rule),
			       item_param ((ZI232)));
	alt_add_item ((ZI230), (ZI232));
    } else {
	sid_current_entry = NULL;
    }
	    }
	    ZR226 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if (((ZI162)) && ((ZI230))) {
	rule_compute_result_intersect (sid_current_rule);
	types_copy (item_result ((ZI232)), rule_result (sid_current_rule));
	types_add_new_names (alt_names ((ZI230)), item_result ((ZI232)),
			     grammar_get_predicate_id(sid_current_grammar));
    }
    sid_internal_rule = (ZI231);
    sid_current_alt   = (ZI230);
    sid_current_rule  = (ZI69);
    sid_current_entry = (ZI162);
	    }
	    ZR233 (sid_current_grammar);
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 4: case 6: case 10: case 18: case 19:
      case 24:
	{
	    ZR215 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_propagating_error = FALSE;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR154(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	NStringT ZI156;

	switch (CURRENT_TERMINAL) {
	  case 4:
	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	{

    if (table_add_type (grammar_table(sid_current_grammar), &(ZI156)) == NULL) {
	E_duplicate_type ((&ZI156));
	nstring_destroy (&(ZI156));
    }
	}
	ZR241 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR189(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4: case 24:
	{
	    ZR186 (sid_current_grammar, ZI132);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR198(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 21:
	{
	    EntryP ZI162;
	    RuleP ZI69;

	    ADVANCE_LEXER;
	    {

    (ZI162)       = sid_current_entry;
    (ZI69)        = sid_enclosing_rule;

    sid_enclosing_rule = sid_current_rule;
	    }
	    ZR167 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_current_entry  = (ZI162);
    sid_current_rule   = sid_enclosing_rule;
    sid_enclosing_rule = (ZI69);
    sid_alternative    = 0;
    sid_internal_rule  = FALSE;
    sid_external_rule  = sid_current_entry;
    nstring_init (&sid_maximum_scope);
	    }
	    {
		{
		    switch (CURRENT_TERMINAL) {
		      case 22:
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_end_scope ();
    }
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 26:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR171(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    NStringT ZI156;

	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type ((ZI132), name_entry, NULL,
				 FALSE);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type ((ZI132), non_local_entry,
				 NULL, FALSE);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	types_add_name ((ZI132), grammar_table(sid_current_grammar), &(ZI156), FALSE);
    }
	    }
	}
	break;
      case 19:
	{
	    ADVANCE_LEXER;
	    {

    EntryT * entry = table_add_generated_name (grammar_table(sid_current_grammar));

    types_add_name_entry ((ZI132), entry);
	    }
	}
	break;
      case 18:
	{
	    ADVANCE_LEXER;
	    {

    if (sid_current_pred_id) {
	E_multi_predicate_return ();
    }
    sid_current_pred_id = TRUE;
    types_add_name_entry ((ZI132), grammar_get_predicate_id(sid_current_grammar));
	    }
	}
	break;
      case 24:
	{
	    ADVANCE_LEXER;
	    {
		{
		    NStringT ZI156;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type_var ((ZI132), name_entry,
				     NULL);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type_var ((ZI132), non_local_entry,
				     NULL);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	E_undefined_assignment ((&ZI156));
	types_add_name ((ZI132), grammar_table(sid_current_grammar), &(ZI156), FALSE);
    }
		    }
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_lhs_name ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR293(GrammarP sid_current_grammar, NStringT *ZI156)
{
    switch (CURRENT_TERMINAL) {
      case 6:
	{
	    TypeTupleT ZI128;
	    TypeTupleT ZI129;

	    ZR147 (sid_current_grammar, &ZI128);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR151 (sid_current_grammar);
	    ZR147 (sid_current_grammar, &ZI129);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_current_entry = scope_stack_add_rule (sid_current_scope,
					      grammar_table(sid_current_grammar), &(*ZI156),
					      sid_enclosing_rule,
					      &sid_redefining_entry);
    if (sid_current_entry) {
	sid_current_rule = entry_get_rule (sid_current_entry);
    } else {
	E_duplicate_rule ((ZI156));
	nstring_destroy (&(*ZI156));
    }
	    }
	    ZR256 (sid_current_grammar, &ZI128, &ZI129);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 4:
	{
	    {
		{
		    NStringT ZI138;
		    NonLocalEntryP ZI250;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI138, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		    {

    (ZI250) = NULL;
    if ((sid_enclosing_rule == NULL) ||
	(sid_current_scope == &sid_global_scope)) {
	E_global_scope_non_local ((ZI156));
	nstring_destroy (&(*ZI156));
    } else {
	EntryT * type = table_get_type (grammar_table(sid_current_grammar), (&ZI138));

	if (type == NULL) {
	    E_unknown_type ((&ZI138));
	    nstring_destroy (&(*ZI156));
	} else {
	    EntryT * name = scope_stack_add_non_local (sid_current_scope,
						     grammar_table(sid_current_grammar),
						     &(*ZI156), type,
						     sid_enclosing_rule);

	    if (name) {
		NonLocalListT * non_locals = rule_non_locals (sid_enclosing_rule);
		(ZI250) = non_local_list_add (non_locals, name, type);
	    } else {
		E_duplicate_non_local ((ZI156));
		nstring_destroy (&(*ZI156));
	    }
	}
    }
    nstring_destroy (&(ZI138));
		    }
		    {
			switch (CURRENT_TERMINAL) {
			  case 12:
			    {
				ADVANCE_LEXER;
				{
				    {
					switch (CURRENT_TERMINAL) {
					  case 10:
					    break;
					  default:
					    goto ZL7;
					}
					ADVANCE_LEXER;
				    }
				    goto ZL6;
				  ZL7:;
				    {
					{

    if (!sid_propagating_error) {
	E_expected_begin_action ();
    }
					}
				    }
				  ZL6:;
				}
				{
				    {
					NStringT ZI51;

					switch (CURRENT_TERMINAL) {
					  case 4:
					    {

    nstring_assign (&ZI51, lexer_string_value (sid_current_stream));
					    }
					    break;
					  default:
					    goto ZL9;
					}
					ADVANCE_LEXER;
					{

    EntryT * actionentry = scope_stack_get_action (&sid_scope_stack, grammar_table(sid_current_grammar),
					   (&ZI51));

    if (actionentry == NULL) {
	E_unknown_action ((&ZI51));
    } else if ((ZI250)) {
	EntryT *     type   = non_local_entry_get_type ((ZI250));
	KeyT *       name   = entry_key (non_local_entry_get_name ((ZI250)));
	ActionT *    action = entry_get_action (actionentry);
	TypeTupleT * param  = action_param (action);
	TypeTupleT * result = action_result (action);
	TypeTupleT tuple;
	TypeTupleT ref_tuple;

	types_init (&tuple);
	types_init (&ref_tuple);
	types_add_type_entry (&tuple, type, FALSE);
	types_add_type_entry (&ref_tuple, type, TRUE);
	if ((!types_equal (param, &tuple)) &&
	    (!types_equal (param, &ref_tuple)) &&
	    (!types_equal_zero_tuple (param))) {
	    E_initialiser_param_mismatch (name, &tuple, &ref_tuple, param);
	}
	if (!types_equal (result, &tuple)) {
	    E_initialiser_result_mismatch (name, &tuple, result);
	}
	types_destroy (&ref_tuple);
	types_destroy (&tuple);
	non_local_entry_set_initialiser ((ZI250), actionentry);
    }
    nstring_destroy (&(ZI51));
					}
					ZR225 (sid_current_grammar);
					ZR241 (sid_current_grammar);
					if ((CURRENT_TERMINAL) == 26) {
					    RESTORE_LEXER;
					    goto ZL9;
					}
				    }
				    goto ZL8;
				  ZL9:;
				    {
					{

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
					}
				    }
				  ZL8:;
				}
			    }
			    break;
			  case 9:
			    {
				ADVANCE_LEXER;
			    }
			    break;
			  default:
			    goto ZL5;
			}
			goto ZL4;
		      ZL5:;
			{
			    {

    if (!sid_propagating_error) {
	E_expected_terminator_or_define ();
    }
			    }
			}
		      ZL4:;
		    }
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    nstring_destroy (&(*ZI156));
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR167(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_167:;
    {
	ZR261 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    sid_propagating_error = FALSE;
	}
	{
	    {
		{

    (ZI0) = ((CURRENT_TERMINAL == LEXER_TOK_EOF) ||
		  (CURRENT_TERMINAL == LEXER_TOK_END_SCOPE) ||
		  (CURRENT_TERMINAL == LEXER_TOK_BLT_ENTRY));
		}
		if (!ZI0)
		    goto ZL4;
		goto ZL3;
	    }
	    /*UNREACHED*/
	  ZL4:;
	    switch (CURRENT_TERMINAL) {
	      case 4: case 10: case 20:
		{
		    goto ZL2_167;
		}
		/*UNREACHED*/
	      default:
		goto ZL1;
	    }
	  ZL3:;
	}
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_production_defn ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
	{

    sid_propagating_error = FALSE;
	}
	{
	    {
		{

    (ZI0) = ((CURRENT_TERMINAL == LEXER_TOK_EOF) ||
		  (CURRENT_TERMINAL == LEXER_TOK_END_SCOPE) ||
		  (CURRENT_TERMINAL == LEXER_TOK_BLT_ENTRY));
		}
		if (!ZI0)
		    goto ZL7;
	    }
	    goto ZL6;
	  ZL7:;
	    {
		goto ZL2_167;
	    }
	    /*UNREACHED*/
	  ZL6:;
	}
    }
}

static void
ZR295(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 19:
	{
	    TypeTupleT ZI201;

	    ADVANCE_LEXER;
	    {

    types_init (&(ZI201));
	    }
	    {

    EntryT * entry = table_add_generated_name (grammar_table(sid_current_grammar));

    types_add_name_entry ((&ZI201), entry);
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR221 (sid_current_grammar);
	    ZR206 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 18:
	{
	    TypeTupleT ZI201;

	    ADVANCE_LEXER;
	    {

    types_init (&(ZI201));
	    }
	    {

    if (sid_current_pred_id) {
	E_multi_predicate_return ();
    }
    sid_current_pred_id = TRUE;
    types_add_name_entry ((&ZI201), grammar_get_predicate_id(sid_current_grammar));
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR221 (sid_current_grammar);
	    ZR206 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 10:
	{
	    TypeTupleT ZI201;

	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    {

    types_init (&(ZI201));
	    }
	    ADVANCE_LEXER;
	    ZR224 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

void
sid_parse_grammar(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{

scope_stack_init (&sid_scope_stack);
scope_stack_init (&sid_global_scope);
	}
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 0:
		    break;
		  default:
		    goto ZL3;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL2;
	  ZL3:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_blt_types ();
    }
		}
	    }
	  ZL2:;
	}
	ZR152 (sid_current_grammar);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		switch (CURRENT_TERMINAL) {
		  case 1:
		    break;
		  default:
		    goto ZL5;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL4;
	  ZL5:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_blt_terminals ();
    }
		}
	    }
	  ZL4:;
	}
	ZR158 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    unsigned max_terminal = grammar_max_terminal (sid_current_grammar);

    bitvec_set_size (max_terminal);
    sid_finished_terminals = TRUE;
	}
	{
	    {
		switch (CURRENT_TERMINAL) {
		  case 2:
		    break;
		  default:
		    goto ZL7;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL6;
	  ZL7:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_blt_productions ();
    }
		}
	    }
	  ZL6:;
	}
	ZR167 (sid_current_grammar);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		switch (CURRENT_TERMINAL) {
		  case 3:
		    break;
		  default:
		    goto ZL9;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL8;
	  ZL9:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_blt_entry ();
    }
		}
	    }
	  ZL8:;
	}
	ZR267 (sid_current_grammar);
	ZR241 (sid_current_grammar);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		switch (CURRENT_TERMINAL) {
		  case 25:
		    break;
		  default:
		    goto ZL11;
		}
		ADVANCE_LEXER;
	    }
	    goto ZL10;
	  ZL11:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_eof ();
    }
		}
	    }
	  ZL10:;
	}
    }
    return;
  ZL1:;
    {
	{

    UNREACHED;
	}
    }
}

static void
ZR145(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4: case 5:
	{
	    ZR142 (sid_current_grammar, ZI132);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	break;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR296(GrammarP sid_current_grammar, NStringT *ZI156)
{
    switch (CURRENT_TERMINAL) {
      case 12:
	{
	    TypeTupleT ZI201;

	    {

    types_init (&(ZI201));
	    }
	    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type ((&ZI201), name_entry, NULL,
				 FALSE);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(*ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type ((&ZI201), non_local_entry,
				 NULL, FALSE);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(*ZI156));
    } else {
	types_add_name ((&ZI201), grammar_table(sid_current_grammar), &(*ZI156), FALSE);
    }
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ADVANCE_LEXER;
	    ZR206 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 6: case 9:
	{
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR297 (sid_current_grammar, ZI156);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR297(GrammarP sid_current_grammar, NStringT *ZI156)
{
    switch (CURRENT_TERMINAL) {
      case 9:
	{
	    TypeTupleT ZI201;
	    TypeTupleT ZI204;

	    {

    sid_current_pred_id = FALSE;
	    }
	    {

    types_init (&(ZI201));
	    }
	    {

    types_init (&(ZI204));
	    }
	    {

    TypeTupleT * param  = NULL;
    TypeTupleT * result = NULL;
    EntryT *     entry  = NULL;
    RuleT *      rule;
    BasicT *     basic;

    if ((sid_current_entry) && (sid_current_alt)) {
	entry = scope_stack_get_rule (&sid_scope_stack, grammar_table(sid_current_grammar),
				      (ZI156));
	if (entry) {
	    sid_current_item = item_create (entry);
	    rule             = entry_get_rule (entry);
	    param            = rule_param (rule);
	    result           = rule_result (rule);
	} else {
	    entry = table_get_basic (grammar_table(sid_current_grammar), (ZI156));
	    if (entry) {
		sid_current_item = item_create (entry);
		basic            = entry_get_basic (entry);
		param            = NULL;
		result           = basic_result (basic);
		if (basic_get_ignored (basic)) {
		    E_ignored_basic_call ((ZI156));
		}
	    } else {
		E_unknown_rule_or_basic ((ZI156));
		sid_current_item = NULL;
	    }
	}
    } else {
	sid_current_item = NULL;
    }
    nstring_destroy (&(*ZI156));
    if (sid_current_item) {
	BoolT errored = FALSE;
	KeyT *  key     = entry_key (entry);

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (param) {
		if (types_equal ((&ZI204), param)) {
		    item_add_param (sid_current_item, (&ZI204));
		} else {
		    E_rule_param_call_mismatch (key, param, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    } else {
		if (!types_equal_zero_tuple ((&ZI204))) {
		    E_basic_param_call_mismatch (key, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    }
	} else {
	    types_destroy ((&ZI204));
	    errored = TRUE;
	}
	if (types_disjoint_names ((&ZI201))) {
	    if (types_check_undefined ((&ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((&ZI201), result)) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (&ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			E_predicate ();
		    }
		    item_add_result (sid_current_item, (&ZI201));
		} else {
		    if (param) {
			E_rule_result_call_mismatch (key, result,
						     (&ZI201));
		    } else {
			E_basic_result_call_mismatch (key, result,
						      (&ZI201));
		    }
		    types_destroy ((&ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((&ZI201));
		errored = TRUE;
	    }
	} else {
	    if (param) {
		E_rule_result_call_clash (key, (&ZI201));
	    } else {
		E_basic_result_call_clash (key, (&ZI201));
	    }
	    types_destroy ((&ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else {
	if (sid_current_alt) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
	types_destroy ((&ZI201));
	types_destroy ((&ZI204));
    }
	    }
	    ADVANCE_LEXER;
	}
	break;
      case 6:
	{
	    TypeTupleT ZI201;
	    TypeTupleT ZI204;

	    {

    types_init (&(ZI201));
	    }
	    ZR181 (sid_current_grammar, &ZI204);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    TypeTupleT * param  = NULL;
    TypeTupleT * result = NULL;
    EntryT *     entry  = NULL;
    RuleT *      rule;
    BasicT *     basic;

    if ((sid_current_entry) && (sid_current_alt)) {
	entry = scope_stack_get_rule (&sid_scope_stack, grammar_table(sid_current_grammar),
				      (ZI156));
	if (entry) {
	    sid_current_item = item_create (entry);
	    rule             = entry_get_rule (entry);
	    param            = rule_param (rule);
	    result           = rule_result (rule);
	} else {
	    entry = table_get_basic (grammar_table(sid_current_grammar), (ZI156));
	    if (entry) {
		sid_current_item = item_create (entry);
		basic            = entry_get_basic (entry);
		param            = NULL;
		result           = basic_result (basic);
		if (basic_get_ignored (basic)) {
		    E_ignored_basic_call ((ZI156));
		}
	    } else {
		E_unknown_rule_or_basic ((ZI156));
		sid_current_item = NULL;
	    }
	}
    } else {
	sid_current_item = NULL;
    }
    nstring_destroy (&(*ZI156));
    if (sid_current_item) {
	BoolT errored = FALSE;
	KeyT *  key     = entry_key (entry);

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (param) {
		if (types_equal ((&ZI204), param)) {
		    item_add_param (sid_current_item, (&ZI204));
		} else {
		    E_rule_param_call_mismatch (key, param, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    } else {
		if (!types_equal_zero_tuple ((&ZI204))) {
		    E_basic_param_call_mismatch (key, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    }
	} else {
	    types_destroy ((&ZI204));
	    errored = TRUE;
	}
	if (types_disjoint_names ((&ZI201))) {
	    if (types_check_undefined ((&ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((&ZI201), result)) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (&ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			E_predicate ();
		    }
		    item_add_result (sid_current_item, (&ZI201));
		} else {
		    if (param) {
			E_rule_result_call_mismatch (key, result,
						     (&ZI201));
		    } else {
			E_basic_result_call_mismatch (key, result,
						      (&ZI201));
		    }
		    types_destroy ((&ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((&ZI201));
		errored = TRUE;
	    }
	} else {
	    if (param) {
		E_rule_result_call_clash (key, (&ZI201));
	    } else {
		E_basic_result_call_clash (key, (&ZI201));
	    }
	    types_destroy ((&ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else {
	if (sid_current_alt) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
	types_destroy ((&ZI201));
	types_destroy ((&ZI204));
    }
	    }
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR147(GrammarP sid_current_grammar, TypeTupleT *ZO132)
{
    TypeTupleT ZI132;

    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{

    types_init (&(ZI132));
	}
	ZR191 (sid_current_grammar);
	ZR145 (sid_current_grammar, &ZI132);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    sid_propagating_error = FALSE;
	}
	ZR192 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (26);
    return;
  ZL0:;
    {

	if((ZO132->head=ZI132.head)==NULL) 
		ZO132->tail = &(ZO132->head);
	else 
		ZO132->tail= ZI132.tail ;
    }
}

static void
ZR183(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    NStringT ZI156;

	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type ((ZI132), name_entry, NULL,
				 FALSE);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type ((ZI132), non_local_entry,
				 NULL, FALSE);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	types_add_name ((ZI132), grammar_table(sid_current_grammar), &(ZI156), FALSE);
    }
	    }
	}
	break;
      case 24:
	{
	    ADVANCE_LEXER;
	    {
		{
		    NStringT ZI156;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type ((ZI132), name_entry, NULL,
				 TRUE);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type ((ZI132), non_local_entry,
				 NULL, TRUE);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	types_add_name ((ZI132), grammar_table(sid_current_grammar), &(ZI156), TRUE);
    }
		    }
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_rhs_name ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR206(GrammarP sid_current_grammar, TypeTupleT *ZI201)
{
    switch (CURRENT_TERMINAL) {
      case 10:
	{
	    ADVANCE_LEXER;
	    ZR224 (sid_current_grammar, ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 4:
	{
	    NStringT ZI156;

	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {
		switch (CURRENT_TERMINAL) {
		  case 6:
		    {
			TypeTupleT ZI204;

			ZR181 (sid_current_grammar, &ZI204);
			if ((CURRENT_TERMINAL) == 26) {
			    RESTORE_LEXER;
			    goto ZL3;
			}
			{

    TypeTupleT * param  = NULL;
    TypeTupleT * result = NULL;
    EntryT *     entry  = NULL;
    RuleT *      rule;
    BasicT *     basic;

    if ((sid_current_entry) && (sid_current_alt)) {
	entry = scope_stack_get_rule (&sid_scope_stack, grammar_table(sid_current_grammar),
				      (&ZI156));
	if (entry) {
	    sid_current_item = item_create (entry);
	    rule             = entry_get_rule (entry);
	    param            = rule_param (rule);
	    result           = rule_result (rule);
	} else {
	    entry = table_get_basic (grammar_table(sid_current_grammar), (&ZI156));
	    if (entry) {
		sid_current_item = item_create (entry);
		basic            = entry_get_basic (entry);
		param            = NULL;
		result           = basic_result (basic);
		if (basic_get_ignored (basic)) {
		    E_ignored_basic_call ((&ZI156));
		}
	    } else {
		E_unknown_rule_or_basic ((&ZI156));
		sid_current_item = NULL;
	    }
	}
    } else {
	sid_current_item = NULL;
    }
    nstring_destroy (&(ZI156));
    if (sid_current_item) {
	BoolT errored = FALSE;
	KeyT *  key     = entry_key (entry);

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (param) {
		if (types_equal ((&ZI204), param)) {
		    item_add_param (sid_current_item, (&ZI204));
		} else {
		    E_rule_param_call_mismatch (key, param, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    } else {
		if (!types_equal_zero_tuple ((&ZI204))) {
		    E_basic_param_call_mismatch (key, (&ZI204));
		    types_destroy ((&ZI204));
		    errored = TRUE;
		}
	    }
	} else {
	    types_destroy ((&ZI204));
	    errored = TRUE;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((ZI201), result)) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			E_predicate ();
		    }
		    item_add_result (sid_current_item, (ZI201));
		} else {
		    if (param) {
			E_rule_result_call_mismatch (key, result,
						     (ZI201));
		    } else {
			E_basic_result_call_mismatch (key, result,
						      (ZI201));
		    }
		    types_destroy ((ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((ZI201));
		errored = TRUE;
	    }
	} else {
	    if (param) {
		E_rule_result_call_clash (key, (ZI201));
	    } else {
		E_basic_result_call_clash (key, (ZI201));
	    }
	    types_destroy ((ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else {
	if (sid_current_alt) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
	types_destroy ((ZI201));
	types_destroy ((&ZI204));
    }
			}
			ZR241 (sid_current_grammar);
			if ((CURRENT_TERMINAL) == 26) {
			    RESTORE_LEXER;
			    goto ZL3;
			}
		    }
		    break;
		  case 9:
		    {
			{

    sid_current_pred_id = FALSE;
			}
			{

    EntryT *     name_entry = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));
    EntryT *     entry      = NULL;
    TypeTupleT * param      = NULL;
    TypeTupleT * result     = NULL;
    RuleT *      rule;
    BasicT *     basic;
    TypeTupleT   rhs ;

    types_init(&rhs);

    if ((sid_current_entry) && (sid_current_alt)) {
	if ((name_entry != NULL) &&
	    (!types_contains (alt_names (sid_current_alt), name_entry)) &&
	    (!types_contains (rule_param (sid_current_rule), name_entry))) {
	    name_entry = NULL;
	}
	entry = scope_stack_get_rule (&sid_scope_stack, grammar_table(sid_current_grammar),
				      (&ZI156));
	if (entry) {
	    sid_current_item = item_create (entry);
	    rule             = entry_get_rule (entry);
	    param            = rule_param (rule);
	    result           = rule_result (rule);
	} else {
	    entry = table_get_basic (grammar_table(sid_current_grammar), (&ZI156));
	    if (entry) {
		sid_current_item = item_create (entry);
		basic            = entry_get_basic (entry);
		param            = NULL;
		result           = basic_result (basic);
		if ((name_entry == NULL) &&
		    basic_get_ignored (basic)) {
		    E_ignored_basic_call ((&ZI156));
		}
	    }
	}
	if ((entry == NULL) && (name_entry == NULL)) {
	    NStringT scope;

	    name_entry = scope_stack_get_non_local (&sid_scope_stack,
						    grammar_table(sid_current_grammar),
						    (&ZI156), &scope);
	    if (name_entry) {
		if (nstring_length (&scope) >
		    nstring_length (&sid_maximum_scope)) {
		    nstring_destroy (&sid_maximum_scope);
		    nstring_assign (&sid_maximum_scope, &scope);
		} else {
		    nstring_destroy (&scope);
		}
	    } else {
		E_unknown_rule_or_basic ((&ZI156));
	    }
	} else if ((entry != NULL) && (name_entry != NULL)) {
	    E_ambiguous_call ((&ZI156));
	    entry      = NULL;
	    name_entry = NULL;
	}
    } else {
	name_entry = NULL;
    }
    nstring_destroy (&(ZI156));
    if (entry) {
	BoolT errored = FALSE;
	KeyT *  key     = entry_key (entry);

	if (types_resolve (&rhs, rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (param) {
		if (types_equal (&rhs, param)) {
		    item_add_param (sid_current_item, &rhs);
		} else {
		    E_rule_param_call_mismatch (key, param, &rhs);
		    types_destroy (&rhs);
		    errored = TRUE;
		}
	    } else {
		if (!types_equal_zero_tuple (&rhs)) {
		    E_basic_param_call_mismatch (key, &rhs);
		    types_destroy (&rhs);
		    errored = TRUE;
		}
	    }
	} else {
	    types_destroy (&rhs);
	    errored = TRUE;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((ZI201), result)) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			E_predicate ();
		    }
		    item_add_result (sid_current_item, (ZI201));
		} else {
		    if (param) {
			E_rule_result_call_mismatch (key, result,
						     (ZI201));
		    } else {
			E_basic_result_call_mismatch (key, result,
						      (ZI201));
		    }
		    types_destroy ((ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((ZI201));
		errored = TRUE;
	    }
	} else {
	    if (param) {
		E_rule_result_call_clash (key, (ZI201));
	    } else {
		E_basic_result_call_clash (key, (ZI201));
	    }
	    types_destroy ((ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else if (name_entry) {
	types_add_name_entry (&rhs, name_entry);
	entry = table_add_rename (grammar_table(sid_current_grammar));
	if (types_resolve (&rhs, rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (types_contains_references (&rhs)) {
		E_identity_param_has_refs (&rhs,
					   entry_key (sid_external_rule),
					   sid_alternative);
		types_destroy (&rhs);
		sid_current_item = NULL;
	    } else {
		sid_current_item = item_create (entry);
		item_add_param (sid_current_item, &rhs);
	    }
	} else {
	    types_destroy (&rhs);
	    sid_current_item = NULL;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (sid_current_item) {
		    if (types_fillin_types ((ZI201),
					    item_param (sid_current_item))) {
			types_add_new_names (alt_names (sid_current_alt),
					     (ZI201),
					     grammar_get_predicate_id(sid_current_grammar));
			if (sid_saved_pred_id) {
			    E_predicate ();
			}
			item_add_result (sid_current_item, (ZI201));
			alt_add_item (sid_current_alt, sid_current_item);
		    } else {
			E_identity_mismatch (item_param (sid_current_item),
					     (ZI201));
			types_destroy ((ZI201));
			(void) item_deallocate (sid_current_item);
			sid_current_item = NULL;
		    }
		}
	    } else {
		types_destroy ((ZI201));
		if (sid_current_item) {
		    (void) item_deallocate (sid_current_item);
		    sid_current_item = NULL;
		}
	    }
	} else {
	    E_identity_result_clash ((ZI201));
	    types_destroy ((ZI201));
	    if (sid_current_item) {
		(void) item_deallocate (sid_current_item);
		sid_current_item = NULL;
	    }
	}
	if (sid_current_item == NULL) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
    } else {
	if (sid_current_alt) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
	types_destroy ((ZI201));
	types_destroy (&rhs);
    }
			}
			ADVANCE_LEXER;
		    }
		    break;
		  default:
		    goto ZL3;
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_tuple_or_term ();
    }
		    }
		    {

    nstring_destroy (&(ZI156));
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 6:
	{
	    TypeTupleT ZI204;

	    ZR181 (sid_current_grammar, &ZI204);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if ((sid_current_entry) && (sid_current_alt)) {
	EntryT * entry = table_add_rename (grammar_table(sid_current_grammar));

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (types_contains_references ((&ZI204))) {
		E_identity_param_has_refs ((&ZI204),
					   entry_key (sid_external_rule),
					   sid_alternative);
		types_destroy ((&ZI204));
		sid_current_item = NULL;
	    } else {
		sid_current_item = item_create (entry);
		item_add_param (sid_current_item, (&ZI204));
	    }
	} else {
	    types_destroy ((&ZI204));
	    sid_current_item = NULL;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (sid_current_item) {
		    if (types_fillin_types ((ZI201),
					    item_param (sid_current_item))) {
			types_add_new_names (alt_names (sid_current_alt),
					     (ZI201),
					     grammar_get_predicate_id(sid_current_grammar));
			if (sid_saved_pred_id) {
			    E_predicate ();
			}
			item_add_result (sid_current_item, (ZI201));
			alt_add_item (sid_current_alt, sid_current_item);
		    } else {
			E_identity_mismatch (item_param (sid_current_item),
					     (ZI201));
			types_destroy ((ZI201));
			(void) item_deallocate (sid_current_item);
			sid_current_item = NULL;
		    }
		}
	    } else {
		types_destroy ((ZI201));
		if (sid_current_item) {
		    (void) item_deallocate (sid_current_item);
		    sid_current_item = NULL;
		}
	    }
	} else {
	    E_identity_result_clash ((ZI201));
	    types_destroy ((ZI201));
	    if (sid_current_item) {
		(void) item_deallocate (sid_current_item);
		sid_current_item = NULL;
	    }
	}
	if (sid_current_item == NULL) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
    } else {
	types_destroy ((ZI201));
	types_destroy ((&ZI204));
    }
	    }
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 24:
	{
	    TypeTupleT ZI204;

	    {

    sid_current_pred_id = FALSE;
	    }
	    ADVANCE_LEXER;
	    {

    types_init (&(ZI204));
	    }
	    {
		{
		    NStringT ZI156;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL5;
		    }
		    ADVANCE_LEXER;
		    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type ((&ZI204), name_entry, NULL,
				 TRUE);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type ((&ZI204), non_local_entry,
				 NULL, TRUE);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	types_add_name ((&ZI204), grammar_table(sid_current_grammar), &(ZI156), TRUE);
    }
		    }
		    {

    if ((sid_current_entry) && (sid_current_alt)) {
	EntryT * entry = table_add_rename (grammar_table(sid_current_grammar));

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (types_contains_references ((&ZI204))) {
		E_identity_param_has_refs ((&ZI204),
					   entry_key (sid_external_rule),
					   sid_alternative);
		types_destroy ((&ZI204));
		sid_current_item = NULL;
	    } else {
		sid_current_item = item_create (entry);
		item_add_param (sid_current_item, (&ZI204));
	    }
	} else {
	    types_destroy ((&ZI204));
	    sid_current_item = NULL;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (sid_current_item) {
		    if (types_fillin_types ((ZI201),
					    item_param (sid_current_item))) {
			types_add_new_names (alt_names (sid_current_alt),
					     (ZI201),
					     grammar_get_predicate_id(sid_current_grammar));
			if (sid_saved_pred_id) {
			    E_predicate ();
			}
			item_add_result (sid_current_item, (ZI201));
			alt_add_item (sid_current_alt, sid_current_item);
		    } else {
			E_identity_mismatch (item_param (sid_current_item),
					     (ZI201));
			types_destroy ((ZI201));
			(void) item_deallocate (sid_current_item);
			sid_current_item = NULL;
		    }
		}
	    } else {
		types_destroy ((ZI201));
		if (sid_current_item) {
		    (void) item_deallocate (sid_current_item);
		    sid_current_item = NULL;
		}
	    }
	} else {
	    E_identity_result_clash ((ZI201));
	    types_destroy ((ZI201));
	    if (sid_current_item) {
		(void) item_deallocate (sid_current_item);
		sid_current_item = NULL;
	    }
	}
	if (sid_current_item == NULL) {
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt = NULL;
	}
    } else {
	types_destroy ((ZI201));
	types_destroy ((&ZI204));
    }
		    }
		    ZR241 (sid_current_grammar);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL5;
		    }
		}
		goto ZL4;
	      ZL5:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL4:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_item_rhs ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR226(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	ZR242 (sid_current_grammar);
	{
	    switch (CURRENT_TERMINAL) {
	      case 16:
		{
		    ADVANCE_LEXER;
		    ZR237 (sid_current_grammar);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		}
		break;
	      case 26:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		break;
	    }
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR158(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_158:;
    {
	ZR160 (sid_current_grammar);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
	{

    sid_propagating_error = FALSE;
	}
	{
	    switch (CURRENT_TERMINAL) {
	      case 4: case 19:
		{
		    goto ZL2_158;
		}
		/*UNREACHED*/
	      default:
		break;
	    }
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR202(GrammarP sid_current_grammar, TypeTupleT *ZI201)
{
    switch (CURRENT_TERMINAL) {
      case 6:
	{
	    TypeTupleT ZI204;

	    ZR181 (sid_current_grammar, &ZI204);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if (sid_current_item) {
	BoolT   errored = FALSE;
	EntryT * entry   = item_entry (sid_current_item);
	ActionT *action  = entry_get_action (entry);

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (types_equal ((&ZI204), action_param (action))) {
		item_add_param (sid_current_item, (&ZI204));
	    } else {
		E_action_param_call_mismatch (entry_key (entry),
					      action_param (action),
					      (&ZI204));
		types_destroy ((&ZI204));
		errored = TRUE;
	    }
	} else {
	    types_destroy ((&ZI204));
	    errored = TRUE;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((ZI201),
					action_result (action))) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			BoolT  reference;
			EntryT * type = types_find_name_type ((ZI201),
							    grammar_get_predicate_id(sid_current_grammar),
							    &reference);

			assert((type != NULL) && (!reference));
			if(grammar_get_predicate_type (sid_current_grammar)) {
			    if (type != grammar_get_predicate_type (sid_current_grammar)) {
				E_predicate_type (grammar_get_predicate_type (sid_current_grammar), type);
			    }
			} else {
			    grammar_set_predicate_type (sid_current_grammar,
							type);
			}
			item_to_predicate (sid_current_item);
		    }
		    item_add_result (sid_current_item, (ZI201));
		} else {
		    E_action_result_call_mismatch (entry_key (entry),
						   action_result (action),
						   (ZI201));
		    types_destroy ((ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((ZI201));
		errored = TRUE;
	    }
	} else {
	    E_action_result_call_clash (entry_key (entry), (ZI201));
	    types_destroy ((ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else {
	types_destroy ((ZI201));
	types_destroy ((&ZI204));
    }
	    }
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 9:
	{
	    TypeTupleT ZI204;

	    {

    sid_current_pred_id = FALSE;
	    }
	    {

    types_init (&(ZI204));
	    }
	    {

    if (sid_current_item) {
	BoolT   errored = FALSE;
	EntryT * entry   = item_entry (sid_current_item);
	ActionT *action  = entry_get_action (entry);

	if (types_resolve ((&ZI204), rule_param (sid_current_rule),
			   alt_names (sid_current_alt), E_undefined_name,
			   entry_key (sid_external_rule), sid_alternative)) {
	    if (types_equal ((&ZI204), action_param (action))) {
		item_add_param (sid_current_item, (&ZI204));
	    } else {
		E_action_param_call_mismatch (entry_key (entry),
					      action_param (action),
					      (&ZI204));
		types_destroy ((&ZI204));
		errored = TRUE;
	    }
	} else {
	    types_destroy ((&ZI204));
	    errored = TRUE;
	}
	if (types_disjoint_names ((ZI201))) {
	    if (types_check_undefined ((ZI201),
				       rule_param (sid_current_rule),
				       alt_names (sid_current_alt),
				       E_redefined_name,
				       entry_key (sid_external_rule),
				       sid_alternative)) {
		if (types_fillin_types ((ZI201),
					action_result (action))) {
		    types_add_new_names (alt_names (sid_current_alt),
					 (ZI201), grammar_get_predicate_id(sid_current_grammar));
		    if (sid_saved_pred_id) {
			BoolT  reference;
			EntryT * type = types_find_name_type ((ZI201),
							    grammar_get_predicate_id(sid_current_grammar),
							    &reference);

			assert((type != NULL) && (!reference));
			if(grammar_get_predicate_type (sid_current_grammar)) {
			    if (type != grammar_get_predicate_type (sid_current_grammar)) {
				E_predicate_type (grammar_get_predicate_type (sid_current_grammar), type);
			    }
			} else {
			    grammar_set_predicate_type (sid_current_grammar,
							type);
			}
			item_to_predicate (sid_current_item);
		    }
		    item_add_result (sid_current_item, (ZI201));
		} else {
		    E_action_result_call_mismatch (entry_key (entry),
						   action_result (action),
						   (ZI201));
		    types_destroy ((ZI201));
		    errored = TRUE;
		}
	    } else {
		types_destroy ((ZI201));
		errored = TRUE;
	    }
	} else {
	    E_action_result_call_clash (entry_key (entry), (ZI201));
	    types_destroy ((ZI201));
	    errored = TRUE;
	}
	if (errored) {
	    (void) item_deallocate (sid_current_item);
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	} else {
	    alt_add_item (sid_current_alt, sid_current_item);
	}
    } else {
	types_destroy ((ZI201));
	types_destroy ((&ZI204));
    }
	    }
	    ADVANCE_LEXER;
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_tuple_or_term ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR261(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	{
	    switch (CURRENT_TERMINAL) {
	      case 20:
		{
		    ADVANCE_LEXER;
		    {

    sid_current_scope = &sid_global_scope;
		    }
		}
		break;
	      default:
		{
		    {

    sid_current_scope = &sid_scope_stack;
		    }
		}
		break;
	    }
	}
	{
	    switch (CURRENT_TERMINAL) {
	      case 10:
		{
		    ZR193 (sid_current_grammar);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		}
		break;
	      case 4:
		{
		    ZR246 (sid_current_grammar);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL1;
		    }
		}
		break;
	      default:
		goto ZL1;
	    }
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR133(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    NStringT ZI135;

	    {

    nstring_assign (&ZI135, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {
		{
		    switch (CURRENT_TERMINAL) {
		      case 5:
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_typemark ();
    }
		    }
		}
	      ZL2:;
	    }
	    {
		{
		    NStringT ZI138;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI138, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL5;
		    }
		    ADVANCE_LEXER;
		    {
			switch (CURRENT_TERMINAL) {
			  case 24:
			    {
				ADVANCE_LEXER;
				{

    if (!types_add_typed_name ((ZI132), grammar_table(sid_current_grammar), &(ZI135),
			       (&ZI138), TRUE)) {
	E_unknown_type ((&ZI138));
    }
    nstring_destroy (&(ZI138));
				}
			    }
			    break;
			  default:
			    {
				{

    if (!types_add_typed_name ((ZI132), grammar_table(sid_current_grammar), &(ZI135),
			       (&ZI138), FALSE)) {
	E_unknown_type ((&ZI138));
    }
    nstring_destroy (&(ZI138));
				}
			    }
			    break;
			}
		    }
		}
		goto ZL4;
	      ZL5:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    nstring_destroy (&(ZI135));
		    }
		    {

    if (sid_finished_terminals) {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_DEFINE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_SCOPE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    } else {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL4:;
	    }
	}
	break;
      case 5:
	{
	    ADVANCE_LEXER;
	    {
		{
		    NStringT ZI138;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI138, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL8;
		    }
		    ADVANCE_LEXER;
		    {
			switch (CURRENT_TERMINAL) {
			  case 24:
			    {
				ADVANCE_LEXER;
				{

    if (!types_add_type ((ZI132), grammar_table(sid_current_grammar), (&ZI138), TRUE)) {
	E_unknown_type ((&ZI138));
    }
    nstring_destroy (&(ZI138));
				}
			    }
			    break;
			  default:
			    {
				{

    if (!types_add_type ((ZI132), grammar_table(sid_current_grammar), (&ZI138),
			 FALSE)) {
	E_unknown_type ((&ZI138));
    }
    nstring_destroy (&(ZI138));
				}
			    }
			    break;
			}
		    }
		}
		goto ZL7;
	      ZL8:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    if (sid_finished_terminals) {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_DEFINE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_SCOPE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    } else {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL7:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_tuple_defn ();
    }
	}
	{

    if (sid_finished_terminals) {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_DEFINE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_SCOPE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    } else {
	while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	       (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_CLOSE_TUPLE) &&
	       (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	       (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
		nstring_destroy (lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	}
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	    ADVANCE_LEXER;
	}
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR191(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 6:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_open_tuple ();
    }
	}
    }
}

static void
ZR192(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 7:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_close_tuple ();
    }
	}
    }
}

static void
ZR267(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_267:;
    {
	ZR269 (sid_current_grammar);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		{

    (ZI0) = (CURRENT_TERMINAL == LEXER_TOK_TERMINATOR);
		}
		if (!ZI0)
		    goto ZL5;
		goto ZL3;
	    }
	    /*UNREACHED*/
	  ZL5:;
	    switch (CURRENT_TERMINAL) {
	      case 23:
		{
		    ADVANCE_LEXER;
		    goto ZL2_267;
		}
		/*UNREACHED*/
	      default:
		goto ZL4;
	    }
	    /*UNREACHED*/
	  ZL4:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_separator ();
    }
		}
		{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		}
		{

    sid_propagating_error = FALSE;
		}
		{
		    {
			{

    (ZI0) = (CURRENT_TERMINAL != LEXER_TOK_SEPARATOR);
			}
			if (!ZI0)
			    goto ZL7;
		    }
		    goto ZL6;
		  ZL7:;
		    {
			goto ZL2_267;
		    }
		    /*UNREACHED*/
		  ZL6:;
		}
	    }
	  ZL3:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR130(GrammarP sid_current_grammar, TypeTupleT *ZO128, TypeTupleT *ZO129)
{
    TypeTupleT ZI128;
    TypeTupleT ZI129;

    switch (CURRENT_TERMINAL) {
      case 5:
	{
	    ADVANCE_LEXER;
	    ZR147 (sid_current_grammar, &ZI128);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR151 (sid_current_grammar);
	    ZR147 (sid_current_grammar, &ZI129);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      default:
	{
	    {

    types_init (&(ZI128));
	    }
	    {

    types_init (&(ZI129));
	    }
	}
	break;
      case 26:
	return;
    }
    goto ZL0;
  ZL1:;
    SAVE_LEXER (26);
    return;
  ZL0:;
    {

	if((ZO128->head=ZI128.head)==NULL) 
		ZO128->tail = &(ZO128->head);
	else 
		ZO128->tail= ZI128.tail ;
    }
    {

	if((ZO129->head=ZI129.head)==NULL) 
		ZO129->tail = &(ZO129->head);
	else 
		ZO129->tail= ZI129.tail ;
    }
}

static void
ZR215(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    NStringT ZI156;

	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {
		{
		    {

    sid_current_pred_id = FALSE;
		    }
		    ZR296 (sid_current_grammar, &ZI156);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL3;
		    }
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_tuple_def_or_term ();
    }
		    }
		    {

    nstring_destroy (&(ZI156));
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 24:
	{
	    ADVANCE_LEXER;
	    {
		{
		    NStringT ZI156;
		    TypeTupleT ZI201;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL5;
		    }
		    ADVANCE_LEXER;
		    {

    sid_current_pred_id = FALSE;
		    }
		    {

    types_init (&(ZI201));
		    }
		    {

    NStringT scope;
    EntryT *   non_local_entry = scope_stack_get_non_local (&sid_scope_stack,
							  grammar_table(sid_current_grammar),
							  (&ZI156), &scope);
    EntryT *   name_entry      = table_get_entry (grammar_table(sid_current_grammar), (&ZI156));

    if (name_entry) {
	if ((sid_current_entry) && (sid_current_alt)) {
	    if ((!types_contains (alt_names (sid_current_alt), name_entry)) &&
		(!types_contains (rule_param (sid_current_rule),
				  name_entry))) {
		name_entry = NULL;
	    }
	} else {
	    name_entry = NULL;
	}
    }
    if (name_entry) {
	types_add_name_and_type_var ((&ZI201), name_entry,
				     NULL);
	if (non_local_entry) {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else if (non_local_entry) {
	types_add_name_and_type_var ((&ZI201), non_local_entry,
				     NULL);
	if (nstring_length (&scope) > nstring_length (&sid_maximum_scope)) {
	    nstring_destroy (&sid_maximum_scope);
	    nstring_assign (&sid_maximum_scope, &scope);
	} else {
	    nstring_destroy (&scope);
	}
	nstring_destroy (&(ZI156));
    } else {
	E_undefined_assignment ((&ZI156));
	types_add_name ((&ZI201), grammar_table(sid_current_grammar), &(ZI156), FALSE);
    }
		    }
		    {

    sid_saved_pred_id = sid_current_pred_id;
		    }
		    ZR221 (sid_current_grammar);
		    ZR206 (sid_current_grammar, &ZI201);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL5;
		    }
		}
		goto ZL4;
	      ZL5:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		}
	      ZL4:;
	    }
	}
	break;
      case 6:
	{
	    TypeTupleT ZI201;

	    ZR169 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    sid_saved_pred_id = sid_current_pred_id;
	    }
	    ZR221 (sid_current_grammar);
	    ZR206 (sid_current_grammar, &ZI201);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 10: case 18: case 19:
	{
	    {

    sid_current_pred_id = FALSE;
	    }
	    ZR295 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR160(GrammarP sid_current_grammar)
{
    switch (CURRENT_TERMINAL) {
      case 4:
	{
	    NStringT ZI156;
	    EntryP ZI162;
	    TypeTupleT ZI128;
	    TypeTupleT ZI129;

	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    ADVANCE_LEXER;
	    {

    (ZI162) = table_add_basic (grammar_table(sid_current_grammar), &(ZI156),
					 sid_current_grammar, FALSE);
    if ((ZI162) == NULL) {
	E_duplicate_basic ((&ZI156));
	nstring_destroy (&(ZI156));
    }
	    }
	    ZR130 (sid_current_grammar, &ZI128, &ZI129);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {

    if ((ZI162)) {
	KeyT * key = entry_key ((ZI162));
	BasicT* basic = entry_get_basic ((ZI162));
	if (types_contains_names ((&ZI128))) {
	    E_basic_param_has_names (key, (&ZI128));
	}
	if (types_contains_names ((&ZI129))) {
	    E_basic_result_has_names (key, (&ZI129));
	}
	if (types_contains_references ((&ZI129))) {
	    E_basic_result_has_refs (key, (&ZI129));
	}
	if (!types_equal_zero_tuple ((&ZI128))) {
	    E_basic_param_mismatch (key, (&ZI128));
	}
	types_assign (basic_result (basic), (&ZI129));
    } else {
	types_destroy ((&ZI129));
    }
    types_destroy ((&ZI128));
	    }
	    ZR241 (sid_current_grammar);
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	}
	break;
      case 19:
	{
	    ADVANCE_LEXER;
	    {
		{
		    NStringT ZI156;
		    EntryP ZI162;
		    TypeTupleT ZI128;
		    TypeTupleT ZI129;

		    switch (CURRENT_TERMINAL) {
		      case 4:
			{

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
			}
			break;
		      default:
			goto ZL3;
		    }
		    ADVANCE_LEXER;
		    {

    (ZI162) = table_add_basic (grammar_table(sid_current_grammar), &(ZI156),
					 sid_current_grammar, TRUE);
    if ((ZI162) == NULL) {
	E_duplicate_basic ((&ZI156));
	nstring_destroy (&(ZI156));
    } 
		    }
		    ZR130 (sid_current_grammar, &ZI128, &ZI129);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL3;
		    }
		    {

    if ((ZI162)) {
	KeyT * key = entry_key ((ZI162));
	BasicT* basic = entry_get_basic ((ZI162));
	if (types_contains_names ((&ZI128))) {
	    E_basic_param_has_names (key, (&ZI128));
	}
	if (types_contains_names ((&ZI129))) {
	    E_basic_result_has_names (key, (&ZI129));
	}
	if (types_contains_references ((&ZI129))) {
	    E_basic_result_has_refs (key, (&ZI129));
	}
	if (!types_equal_zero_tuple ((&ZI128))) {
	    E_basic_param_mismatch (key, (&ZI128));
	}
	types_assign (basic_result (basic), (&ZI129));
    } else {
	types_destroy ((&ZI129));
    }
    types_destroy ((&ZI128));
		    }
		    ZR241 (sid_current_grammar);
		    if ((CURRENT_TERMINAL) == 26) {
			RESTORE_LEXER;
			goto ZL3;
		    }
		}
		goto ZL2;
	      ZL3:;
		{
		    {

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		    }
		    {

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		    }
		}
	      ZL2:;
	    }
	}
	break;
      case 26:
	return;
      default:
	goto ZL1;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_terminal_decn ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR221(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 12:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_define ();
    }
	}
    }
}

static void
ZR224(GrammarP sid_current_grammar, TypeTupleT *ZI201)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	NStringT ZI156;

	switch (CURRENT_TERMINAL) {
	  case 4:
	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	{

    if ((sid_current_entry) && (sid_current_alt)) {
	EntryT * entry = scope_stack_get_action (&sid_scope_stack,
					       grammar_table(sid_current_grammar), (&ZI156));

	if (entry) {
	    sid_current_item = item_create (entry);
	} else {
	    E_unknown_action ((&ZI156));
	    sid_current_item = NULL;
	    (void) alt_deallocate (sid_current_alt);
	    sid_current_alt  = NULL;
	}
    } else {
	sid_current_item = NULL;
    }
    nstring_destroy (&(ZI156));
	}
	ZR225 (sid_current_grammar);
	ZR202 (sid_current_grammar, ZI201);
	if ((CURRENT_TERMINAL) == 26) {
	    RESTORE_LEXER;
	    goto ZL1;
	}
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
    }
}

static void
ZR225(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 11:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_end_action ();
    }
	}
    }
}

static void
ZR233(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 14:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_end_rule ();
    }
	}
    }
}

static void
ZR193(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 10:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	{
	    {
		NStringT ZI156;
		EntryP ZI162;
		TypeTupleT ZI128;
		TypeTupleT ZI129;

		switch (CURRENT_TERMINAL) {
		  case 4:
		    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
		    }
		    break;
		  default:
		    goto ZL3;
		}
		ADVANCE_LEXER;
		{

    (ZI162) = scope_stack_add_action (sid_current_scope,
						grammar_table(sid_current_grammar), &(ZI156),
						sid_enclosing_rule,
						&sid_redefining_entry);
    if (!(ZI162)) {
	E_duplicate_action ((&ZI156));
	nstring_destroy (&(ZI156));
    }
		}
		ZR225 (sid_current_grammar);
		ZR130 (sid_current_grammar, &ZI128, &ZI129);
		if ((CURRENT_TERMINAL) == 26) {
		    RESTORE_LEXER;
		    goto ZL3;
		}
		{

    if ((ZI162)) {
	KeyT *       key     = entry_key (sid_current_entry);
	ActionT*     action  = entry_get_action((ZI162));
	TypeTupleT * param   = action_param (action);
	TypeTupleT * result  = action_result (action);
	BoolT      errored = FALSE;

	if (types_contains_names ((&ZI128))) {
	    E_action_param_has_names (key, (&ZI128));
	    errored = TRUE;
	}
	if (sid_redefining_entry) {
	    if (!types_equal (param, (&ZI128))) {
		E_action_param_mismatch (key, param, (&ZI128));
		errored = TRUE;
	    }
	}
	if (types_contains_names ((&ZI129))) {
	    E_action_result_has_names (key, (&ZI129));
	    errored = TRUE;
	}
	if (types_contains_references ((&ZI129))) {
	    E_action_result_has_refs (key, (&ZI129));
	    errored = TRUE;
	}
	if (sid_redefining_entry) {
	    if (!types_equal (result, (&ZI129))) {
		E_action_result_mismatch (key, result, (&ZI129));
		errored = TRUE;
	    }
	}
	if (errored || sid_redefining_entry) {
	    types_destroy ((&ZI128));
	    types_destroy ((&ZI129));
	} else {
	    types_assign (param, (&ZI128));
	    types_assign (result, (&ZI129));
	}
    } else {
	types_destroy ((&ZI128));
	types_destroy ((&ZI129));
    }
		}
		ZR241 (sid_current_grammar);
		if ((CURRENT_TERMINAL) == 26) {
		    RESTORE_LEXER;
		    goto ZL3;
		}
	    }
	    goto ZL2;
	  ZL3:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
		}
		{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
		}
	    }
	  ZL2:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR235(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_235:;
    {
	ZR228 (sid_current_grammar);
	{
	    switch (CURRENT_TERMINAL) {
	      case 4: case 6: case 10: case 13: case 18:
	      case 19: case 24:
		{
		    goto ZL2_235;
		}
		/*UNREACHED*/
	      case 26:
		RESTORE_LEXER;
		goto ZL1;
	      default:
		break;
	    }
	}
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_item ();
    }
	}
	{

    while ((CURRENT_TERMINAL != LEXER_TOK_EOF) &&
	   (CURRENT_TERMINAL != LEXER_TOK_TERMINATOR) &&
	   (CURRENT_TERMINAL != LEXER_TOK_ALT_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_HANDLER_SEP) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BEGIN_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_RULE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_END_SCOPE) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_PRODUCTIONS) &&
	   (CURRENT_TERMINAL != LEXER_TOK_BLT_ENTRY)) {
	if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	    nstring_destroy (lexer_string_value (sid_current_stream));
	}
	ADVANCE_LEXER;
    }
    if (CURRENT_TERMINAL == LEXER_TOK_IDENTIFIER) {
	nstring_destroy (lexer_string_value (sid_current_stream));
    }
    if (CURRENT_TERMINAL != LEXER_TOK_EOF) {
	ADVANCE_LEXER;
    }
    sid_propagating_error = TRUE;
	}
	{

    sid_propagating_error = FALSE;
	}
    }
}

static void
ZR269(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	NStringT ZI156;

	switch (CURRENT_TERMINAL) {
	  case 4:
	    {

    nstring_assign (&ZI156, lexer_string_value (sid_current_stream));
	    }
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
	{

    EntryT * entry = table_get_rule (grammar_table(sid_current_grammar), (&ZI156));

    if (entry) {
	if (entry_list_contains (grammar_entry_list(sid_current_grammar), entry)) {
	    E_mult_entry (entry_key (entry));
	} else {
	    entry_list_add (grammar_entry_list(sid_current_grammar), entry);
	    rule_required (entry_get_rule (entry));
	}
    } else {
	E_unknown_rule ((&ZI156));
    }
    nstring_destroy (&(ZI156));
	}
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_identifier ();
    }
	}
    }
}

static void
ZR174(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_174:;
    {
	ZR171 (sid_current_grammar, ZI132);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		{

    (ZI0) = ((CURRENT_TERMINAL == LEXER_TOK_CLOSE_TUPLE) ||
		  (CURRENT_TERMINAL == LEXER_TOK_EOF) ||
		  (sid_propagating_error));
		}
		if (!ZI0)
		    goto ZL5;
		goto ZL3;
	    }
	    /*UNREACHED*/
	  ZL5:;
	    switch (CURRENT_TERMINAL) {
	      case 23:
		{
		    ADVANCE_LEXER;
		    goto ZL2_174;
		}
		/*UNREACHED*/
	      default:
		goto ZL4;
	    }
	    /*UNREACHED*/
	  ZL4:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_separator ();
    }
		}
		goto ZL2_174;
	    }
	    /*UNREACHED*/
	  ZL3:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

static void
ZR241(GrammarP sid_current_grammar)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
    {
	switch (CURRENT_TERMINAL) {
	  case 9:
	    break;
	  default:
	    goto ZL1;
	}
	ADVANCE_LEXER;
    }
    return;
  ZL1:;
    {
	{

    if (!sid_propagating_error) {
	E_expected_terminator ();
    }
	}
    }
}

static void
ZR186(GrammarP sid_current_grammar, TypeTupleT *ZI132)
{
    if ((CURRENT_TERMINAL) == 26) {
	return;
    }
  ZL2_186:;
    {
	ZR183 (sid_current_grammar, ZI132);
	{
	    if ((CURRENT_TERMINAL) == 26) {
		RESTORE_LEXER;
		goto ZL1;
	    }
	    {
		{

    (ZI0) = ((CURRENT_TERMINAL == LEXER_TOK_CLOSE_TUPLE) ||
		  (CURRENT_TERMINAL == LEXER_TOK_EOF) ||
		  (sid_propagating_error));
		}
		if (!ZI0)
		    goto ZL5;
		goto ZL3;
	    }
	    /*UNREACHED*/
	  ZL5:;
	    switch (CURRENT_TERMINAL) {
	      case 23:
		{
		    ADVANCE_LEXER;
		    goto ZL2_186;
		}
		/*UNREACHED*/
	      default:
		goto ZL4;
	    }
	    /*UNREACHED*/
	  ZL4:;
	    {
		{

    if (!sid_propagating_error) {
	E_expected_separator ();
    }
		}
		goto ZL2_186;
	    }
	    /*UNREACHED*/
	  ZL3:;
	}
    }
    return;
  ZL1:;
    SAVE_LEXER (26);
    return;
}

/* BEGINNING OF TRAILER */



/* END OF FILE */