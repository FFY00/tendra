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
 * key.c - Key ADT.
 *
 * This file implements the identifier key routines used by SID.
 */

#include <assert.h>

#include "../shared/check/check.h"
#include "key.h"

void
key_init_from_string(KeyT * key, NStringT * string, unsigned number)
{
    key->type   = KT_STRING;
    nstring_assign(&(key->string), string);
    key->number = number;
}

void
key_init_from_number(KeyT * key, unsigned number)
{
    key->type   = KT_NUMERIC;
    key->number = number;
}

CmpT
key_compare(KeyT * key1, KeyT * key2)
{
    if ((key1->type) < (key2->type)) {
	return(CMP_LT);
    } else if ((key1->type) > (key2->type)) {
	return(CMP_GT);
    }
    switch (key1->type)EXHAUSTIVE {
      case KT_STRING:
	return(nstring_compare(&(key1->string), &(key2->string)));
      case KT_NUMERIC:
	if (key1->number < key2->number) {
	    return(CMP_LT);
	} else if (key1->number > key2->number) {
	    return(CMP_GT);
	} else {
	    return(CMP_EQ);
	}
    }
    UNREACHED;
}

BoolT
key_is_string(KeyT * key)
{
    return(key->type == KT_STRING);
}

NStringT *
key_get_string(KeyT * key)
{
    assert(key->type == KT_STRING);
    return(&(key->string));
}

unsigned
key_get_number(KeyT * key)
{
    return(key->number);
}

unsigned
key_hash_value(KeyT * key)
{
    switch (key->type)EXHAUSTIVE {
      case KT_NUMERIC:
	return(key->number);
      case KT_STRING:
	return(nstring_hash_value(&(key->string)));
    }
    UNREACHED;
}

void
write_key(OStreamT * ostream, KeyT * key)
{
    switch (key->type)EXHAUSTIVE {
      case KT_STRING:
	write_nstring(ostream, &(key->string));
	break;
      case KT_NUMERIC:
	write_unsigned(ostream, key->number);
	break;
    }
}