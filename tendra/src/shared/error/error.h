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


#ifndef ERROR_INCLUDED
#define ERROR_INCLUDED


#include <stdio.h>


/*
    ERROR SEVERITY LEVELS

    These macros give the various error types recognised by the error
    routines.
*/

enum error_severity {
	ERROR_NONE,	   /* Error reporting off */
	ERROR_WARNING, /* Warning */
	ERROR_SERIOUS, /* Error, does exit after N errors */
	ERROR_FATAL    /* Fatal exits immediately */
};


/*
    DECLARATIONS FOR ERROR ROUTINES
*/

void error(enum error_severity, const char *, ...);
void error_posn(enum error_severity, const char *, int, const char *, ...);
void set_progname(const char *, const char *);
void report_version(void);
void fmt_register(char c, void (*f)(FILE *fp, void *));

extern const char *progname;
extern const char *progvers;
extern int exit_status;
extern int maximum_errors;
extern int crt_line_no;
extern const char *crt_file_name;


/*
    DECLARATIONS FOR ASSERTION ROUTINES
*/

#ifdef ASSERTS
extern void assertion(const char *, const char *, int);
#if FS_STDC_HASH
#define ASSERT(A)	if (!(A))assertion(#A, __FILE__, __LINE__)
#define FAIL(A)	assertion(#A, __FILE__, __LINE__)
#else
#define ASSERT(A)	if (!(A))assertion("A", __FILE__, __LINE__)
#define FAIL(A)	assertion("A", __FILE__, __LINE__)
#endif
#else
#define ASSERT(A)	((void)0)
#define FAIL(A)	((void)0)
#endif


#endif /* ERROR_INCLUDED */
