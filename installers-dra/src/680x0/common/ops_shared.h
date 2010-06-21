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
    		 Crown Copyright (c) 1996

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
			    VERSION INFORMATION
			    ===================

--------------------------------------------------------------------------
$Header: /u/g/release/CVSROOT/Source/src/installers/680x0/common/ops_shared.h,v 1.1.1.1 1998/01/17 15:55:50 release Exp $
--------------------------------------------------------------------------
$Log: ops_shared.h,v $
 * Revision 1.1.1.1  1998/01/17  15:55:50  release
 * First version to be checked into rolling release.
 *
Revision 1.1.1.1  1997/10/13 12:42:57  ma
First version.

Revision 1.3  1997/10/13 08:50:06  ma
Made all pl_tests for general proc & exception handling pass.

Revision 1.2  1997/09/25 06:45:30  ma
All general_proc tests passed

Revision 1.1.1.1  1997/03/14 07:50:16  ma
Imported from DRA

 * Revision 1.1.1.1  1996/09/20  10:56:57  john
 *
 * Revision 1.2  1996/07/05  14:25:35  john
 * Changes for spec 3.1
 *
 * Revision 1.1.1.1  1996/03/26  15:45:16  john
 *
 * Revision 1.2  93/03/03  14:50:17  14:50:17  ra (Robert Andrews)
 * Added support for jump_overflow routine.
 *
 * Revision 1.1  93/02/22  17:16:28  17:16:28  ra (Robert Andrews)
 * Initial revision
 *
--------------------------------------------------------------------------
*/


#ifndef OPS_SHARED_INCLUDED
#define OPS_SHARED_INCLUDED


/*
    KEY TO OVERFLOW JUMPS

    The argument to jump_overflow is one of the following.
*/

typedef enum {
   UNCONDITIONAL,
   ON_OVERFLOW,
   ON_CARRY,
   ON_FP_OVERFLOW,
   ON_FP_CARRY,
   ON_FP_OPERAND_ERROR
} overflow_type;

#define ON_SHAPE(s)	(is_signed(s)? ON_OVERFLOW : ON_CARRY)


/*
    PROTOTYPES

    This file is a relic of the old operations.c which was split into
    the four ops_*.c files.  These routines were previously static but
    now must be external.
*/

extern void branch(long, exp, int, int, int);
extern int branch_ins(long, int, int, int);
extern void jump_overflow(int);
extern void test_overflow(overflow_type);
extern void test_overflow2(int);
extern void push(shape, long, where);
extern void push_float(long, where);
extern void pop(shape, long, where);
extern void pop_float(long, where);
extern void shift_aux(shape, where, where, where, int, int);
extern void checkalloc_stack(where, int);
extern int set_overflow(exp);
extern int have_overflow(void);
extern void clear_overflow(int);
extern void reset_round_mode(void);
extern void cmp_zero(shape, long, where);


/*
    CONDITION CODES

    These condition codes are used to eliminate unnecessary comparison
    instructions.
*/

extern where last_cond;
extern where last_cond2;
extern where last_cond_alt;
extern long last_cond_sz;


/*
    SET CONDITION CODES

    This macro is used to set the condition codes for the where X of
    size Y.
*/

#define  set_cond(X, Y)		\
    {					\
	have_cond = 1; \
	last_cond = (X);		\
	last_cond_sz = (Y);		\
    }


/*
    SET ALTERNATIVE CONDITION CODES

    This macro is used to set the alterative last condition to X.
*/

#define  set_cond_alt(X)		\
    {					\
	have_cond = 3; \
	last_cond_alt = (X);		\
    }


/*
    OUTPUT A COMPARISON INSTRUCTION

    Some assemblers (e.g. HP) reverse the order of the operands in
    comparison instructions.  This macro handles this fact.
*/

#ifndef asm_cmp_reversed
#define ins2_cmp(I, S1, S2, X1, X2, M)ins2(I, S1, S2, X1, X2, M)
#else
#define ins2_cmp(I, S1, S2, X1, X2, M)ins2(I, S2, S1, X2, X1, M)
#endif


#endif