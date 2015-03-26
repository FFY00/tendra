/*
 * Automatically generated from the files:
 *	psyntax.sid
 * and
 *	psyntax.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#define __SID_SPLIT
#line 166 "psyntax.act"


/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997-1998, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <stdio.h>

#include <shared/check.h>

#include <utility/config.h>
#include "c_types.h"

#include "exp_ops.h"
#include "hashid_ops.h"
#include "id_ops.h"
#include "tok_ops.h"
#include "type_ops.h"
#include <utility/error.h>
#include <utility/catalog.h>
#include <utility/option.h>
#include <utility/buffer.h>
#include <construct/access.h>
#include <construct/allocate.h>
#include <construct/assign.h>
#include <construct/basetype.h>
#include <construct/cast.h>
#include <construct/chktype.h>
#include <construct/class.h>
#include <parse/preproc.h>
#include <parse/constant.h>
#include <construct/construct.h>
#include <construct/convert.h>
#include <construct/declare.h>
#include <construct/derive.h>
#include <construct/exception.h>
#include <construct/expression.h>
#include <construct/function.h>
#include <parse/hash.h>
#include <construct/identifier.h>
#include <construct/initialise.h>
#include <construct/inttype.h>
#include <construct/label.h>
#include <parse/lex.h>
#include <parse/literal.h>
#include <construct/member.h>
#include <construct/namespace.h>
#include <parse/parse.h>
#include <parse/pragma.h>
#include <parse/predict.h>
#include <parse/preproc.h>
#include <construct/printf.h>
#include <construct/redeclare.h>
#include <construct/rewrite.h>
#include <construct/statement.h>
#include <parse/symbols.h>
#include <construct/template.h>
#include <construct/tokdef.h>
#include <construct/token.h>
#include <construct/typeid.h>
#include <construct/variable.h>


/*
    These are the aliases for the compound types used in the parser.
*/

typedef LIST(IDENTIFIER) SID_LIST_ID;


/*
     The function declarations are included at this point so that the
     type definitions are in scope.
*/

#include <parse/psyntax.h>
extern void parse_tok_type(TYPE *);
extern void parse_mem_type(TYPE *);
extern void parse_operator(IDENTIFIER *);


#line 101 "psyntax3.c"

void
XR861(TYPE *XOt)
{
	TYPE XIt;

	switch (CURRENT_TERMINAL) {
	case 281:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: type_wprintf */
			{
#line 896 "psyntax.act"
 (XIt) = type_wprintf ; 
#line 116 "psyntax3.c"
			}
			/* END OF ACTION: type_wprintf */
		}
		break;
	case 297:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: type_wscanf */
			{
#line 897 "psyntax.act"
 (XIt) = type_wscanf ; 
#line 128 "psyntax3.c"
			}
			/* END OF ACTION: type_wscanf */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOt = XIt;
}

void
XRpragma_Hrule(void)
{
	switch (CURRENT_TERMINAL) {
	case 168:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: ellipsis-aux */
			{
				switch (CURRENT_TERMINAL) {
				case 47:
					{
						ADVANCE_LEXER;
					}
					break;
				case 210:
					{
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: ellipsis-aux */
			switch (CURRENT_TERMINAL) {
			case 232:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_ellipsis_ident */
			{
#line 1020 "psyntax.act"
 (XIn) = OPT_ellipsis_ident ; 
#line 185 "psyntax3.c"
			}
			/* END OF ACTION: opt_ellipsis_ident */
			/* BEGINNING OF ACTION: error_off */
			{
#line 822 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_OFF ; 
#line 192 "psyntax3.c"
			}
			/* END OF ACTION: error_off */
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 200 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 173:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 275:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 294:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_overload_ambig */
			{
#line 1057 "psyntax.act"
 (XIn) = OPT_overload_ambig ; 
#line 229 "psyntax3.c"
			}
			/* END OF ACTION: opt_overload_ambig */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 242 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 175:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 121:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_anon_union */
			{
#line 979 "psyntax.act"
 (XIn) = OPT_anon_union ; 
#line 264 "psyntax3.c"
			}
			/* END OF ACTION: opt_anon_union */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 277 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 181:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 179:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 127:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_bool_assign */
			{
#line 982 "psyntax.act"
 (XIn) = OPT_bool_assign ; 
#line 306 "psyntax3.c"
			}
			/* END OF ACTION: opt_bool_assign */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 319 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 182:
		{
			ADVANCE_LEXER;
			XR784 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 183:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 274:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_bitf_overflow */
			{
#line 980 "psyntax.act"
 (XIn) = OPT_bitf_overflow ; 
#line 351 "psyntax3.c"
			}
			/* END OF ACTION: opt_bitf_overflow */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 364 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 184:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 228:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 117:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_func_block */
			{
#line 1028 "psyntax.act"
 (XIn) = OPT_func_block ; 
#line 393 "psyntax3.c"
			}
			/* END OF ACTION: opt_func_block */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 406 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 128:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 171:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_wall */
			{
#line 1084 "psyntax.act"
 (XIn) = OPT_wall ; 
#line 428 "psyntax3.c"
			}
			/* END OF ACTION: opt_wall */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 441 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 187:
		{
			ADVANCE_LEXER;
			XR810 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 191:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 312:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_token_redef */
			{
#line 1076 "psyntax.act"
 (XIn) = OPT_token_redef ; 
#line 473 "psyntax3.c"
			}
			/* END OF ACTION: opt_token_redef */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 486 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 192:
		{
			ADVANCE_LEXER;
			XR803 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 194:
		{
			ADVANCE_LEXER;
			XR799 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 98:
		{
			ADVANCE_LEXER;
			XR802 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 195:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XRconversion_Hspec (&XIn);
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 545 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 197:
		{
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 184:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XR785 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 203:
		{
			ADVANCE_LEXER;
			XR800 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 204:
		{
			IDENTIFIER XIdir;
			IDENTIFIER XIid;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: rescan_id */
			{
#line 1173 "psyntax.act"

    int t = crt_lex_token ;
    if ( t >= FIRST_KEYWORD && t <= LAST_KEYWORD ) {
	crt_lex_token = lex_identifier ;
    }
#line 591 "psyntax3.c"
			}
			/* END OF ACTION: rescan_id */
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XIdir = crt_token->pp_data.id.use ;
#line 604 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XIdir = crt_token->pp_data.id.use ;
#line 617 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XIdir = crt_token->pp_data.id.use ;
#line 630 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XIdir = crt_token->pp_data.id.use ;
#line 643 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			switch (CURRENT_TERMINAL) {
			case 325:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 213:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: rescan_id */
			{
#line 1173 "psyntax.act"

    int t = crt_lex_token ;
    if ( t >= FIRST_KEYWORD && t <= LAST_KEYWORD ) {
	crt_lex_token = lex_identifier ;
    }
#line 676 "psyntax3.c"
			}
			/* END OF ACTION: rescan_id */
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 689 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 702 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 715 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 728 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: check_directory */
			{
#line 774 "psyntax.act"

    directory_option ( (XIdir), (XIid) ) ;
#line 744 "psyntax3.c"
			}
			/* END OF ACTION: check_directory */
		}
		break;
	case 206:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XRdiscard_Hspec (&XIn);
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 773 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 207:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 179:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 231:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_dollar_ident */
			{
#line 1016 "psyntax.act"
 (XIn) = OPT_dollar_ident ; 
#line 802 "psyntax3.c"
			}
			/* END OF ACTION: opt_dollar_ident */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 815 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 211:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: check_end */
			{
#line 771 "psyntax.act"

    end_option ( 1 ) ;
#line 828 "psyntax3.c"
			}
			/* END OF ACTION: check_end */
		}
		break;
	case 104:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 119:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_enum_switch */
			{
#line 1023 "psyntax.act"
 (XIn) = OPT_enum_switch ; 
#line 857 "psyntax3.c"
			}
			/* END OF ACTION: opt_enum_switch */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 870 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 216:
		{
			EXP XIa;
			EXP XIb;

			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: character-literal */
			{
				switch (CURRENT_TERMINAL) {
				case 17:
					{
						/* BEGINNING OF EXTRACT: char-exp */
						{
#line 291 "psyntax.act"

    XIa = crt_token->pp_data.exp ;
#line 891 "psyntax3.c"
						}
						/* END OF EXTRACT: char-exp */
						ADVANCE_LEXER;
					}
					break;
				case 18:
					{
						/* BEGINNING OF EXTRACT: wchar-exp */
						{
#line 295 "psyntax.act"

    XIa = crt_token->pp_data.exp ;
#line 904 "psyntax3.c"
						}
						/* END OF EXTRACT: wchar-exp */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: character-literal */
			XR755 (&XIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: escape_set */
			{
#line 935 "psyntax.act"

    set_escape ( (XIa), (XIb) ) ;
#line 925 "psyntax3.c"
			}
			/* END OF ACTION: escape_set */
		}
		break;
	case 133:
		{
			unsigned XIc;
			unsigned XIe;
			int XIn;
			int XIm;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 186:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XR743 (&XIc);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: opt_cast_explicit */
			{
#line 984 "psyntax.act"
 (XIn) = OPT_cast_explicit ; 
#line 955 "psyntax3.c"
			}
			/* END OF ACTION: opt_cast_explicit */
			/* BEGINNING OF ACTION: opt_val_cast_explicit */
			{
#line 1087 "psyntax.act"
 (XIm) = OPT_VAL_cast_explicit ; 
#line 962 "psyntax3.c"
			}
			/* END OF ACTION: opt_val_cast_explicit */
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 970 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
			/* BEGINNING OF ACTION: analysis_value */
			{
#line 965 "psyntax.act"

    set_value ( (XIm), NULL_exp, ( unsigned long ) (XIc) ) ;
#line 978 "psyntax3.c"
			}
			/* END OF ACTION: analysis_value */
		}
		break;
	case 221:
		{
			ADVANCE_LEXER;
			XR801 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 222:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR787 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1010 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 223:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 249:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 96:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_case_fall */
			{
#line 983 "psyntax.act"
 (XIn) = OPT_case_fall ; 
#line 1039 "psyntax3.c"
			}
			/* END OF ACTION: opt_case_fall */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1052 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 107:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 245:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 184:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_for_scope */
			{
#line 1027 "psyntax.act"
 (XIn) = OPT_for_scope ; 
#line 1081 "psyntax3.c"
			}
			/* END OF ACTION: opt_for_scope */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1094 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 226:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 104:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 197:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_enum_decl */
			{
#line 1022 "psyntax.act"
 (XIn) = OPT_enum_decl ; 
#line 1123 "psyntax3.c"
			}
			/* END OF ACTION: opt_enum_decl */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1136 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 228:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 276:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 179:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 276:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_conv_ptr_func */
			{
#line 1000 "psyntax.act"
 (XIn) = OPT_conv_ptr_func ; 
#line 1172 "psyntax3.c"
			}
			/* END OF ACTION: opt_conv_ptr_func */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1185 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 231:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR788 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1207 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 235:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 118:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 44:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 121:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 44:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 104:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 307:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_type_tag_ignore */
			{
#line 1081 "psyntax.act"
 (XIn) = OPT_type_tag_ignore ; 
#line 1264 "psyntax3.c"
			}
			/* END OF ACTION: opt_type_tag_ignore */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1277 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 237:
		{
			ADVANCE_LEXER;
			XR804 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 240:
		{
			int XIn;
			EXP XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 202:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_val_include_depth */
			{
#line 1088 "psyntax.act"
 (XIn) = OPT_VAL_include_depth ; 
#line 1309 "psyntax3.c"
			}
			/* END OF ACTION: opt_val_include_depth */
			/* BEGINNING OF INLINE: integer-literal */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 21:
						/* BEGINNING OF EXTRACT: integer-exp */
						{
#line 274 "psyntax.act"

    XIe = crt_token->pp_data.exp ;
#line 1322 "psyntax3.c"
						}
						/* END OF EXTRACT: integer-exp */
						break;
					default:
						goto XL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: integer-literal */
			/* BEGINNING OF ACTION: analysis_exp */
			{
#line 969 "psyntax.act"

    set_value ( (XIn), (XIe), ( unsigned long ) 0 ) ;
#line 1338 "psyntax3.c"
			}
			/* END OF ACTION: analysis_exp */
		}
		break;
	case 242:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR790 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1360 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 243:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 313:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 179:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 268:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 313:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_type_obj_incompl */
			{
#line 1078 "psyntax.act"
 (XIn) = OPT_type_obj_incompl ; 
#line 1403 "psyntax3.c"
			}
			/* END OF ACTION: opt_type_obj_incompl */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1416 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 244:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR791 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1438 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 245:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 270:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 118:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 44:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 121:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 94:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_init_struct */
			{
#line 1042 "psyntax.act"
 (XIn) = OPT_init_struct ; 
#line 1502 "psyntax3.c"
			}
			/* END OF ACTION: opt_init_struct */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1515 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 137:
		{
			unsigned XIe;
			int XIn;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 254:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XRlinkage_Hdescr (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: opt_inline_internal */
			{
#line 1043 "psyntax.act"
 (XIn) = OPT_inline_internal ; 
#line 1542 "psyntax3.c"
			}
			/* END OF ACTION: opt_inline_internal */
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1550 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 246:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR797 (&XIn);
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1572 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 254:
		{
			unsigned XIe;
			unsigned XIi;
			int XIn;
			int XIm;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 294:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XRlinkage_Hstate (&XIe, &XIi);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: opt_link_resolve */
			{
#line 1049 "psyntax.act"
 (XIn) = OPT_link_resolve ; 
#line 1608 "psyntax3.c"
			}
			/* END OF ACTION: opt_link_resolve */
			/* BEGINNING OF ACTION: opt_link_internal */
			{
#line 1048 "psyntax.act"
 (XIm) = OPT_link_internal ; 
#line 1615 "psyntax3.c"
			}
			/* END OF ACTION: opt_link_internal */
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1623 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIm), (XIi) ) ;
#line 1631 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 256:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 313:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_longlong */
			{
#line 1050 "psyntax.act"
 (XIn) = OPT_longlong ; 
#line 1653 "psyntax3.c"
			}
			/* END OF ACTION: opt_longlong */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1666 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 264:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 190:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_nest_comment */
			{
#line 1056 "psyntax.act"
 (XIn) = OPT_nest_comment ; 
#line 1695 "psyntax3.c"
			}
			/* END OF ACTION: opt_nest_comment */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1708 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 266:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR792 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1730 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 141:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 279:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_paren */
			{
#line 1062 "psyntax.act"
 (XIn) = OPT_paren ; 
#line 1759 "psyntax3.c"
			}
			/* END OF ACTION: opt_paren */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1772 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 273:
		{
			ADVANCE_LEXER;
			XR811 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 275:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 294:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_overload_res */
			{
#line 1059 "psyntax.act"
 (XIn) = OPT_overload_res ; 
#line 1804 "psyntax3.c"
			}
			/* END OF ACTION: opt_overload_res */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1817 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 276:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 141:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_ptr_operator */
			{
#line 1069 "psyntax.act"
 (XIn) = OPT_ptr_operator ; 
#line 1846 "psyntax3.c"
			}
			/* END OF ACTION: opt_ptr_operator */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1859 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 285:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR793 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1881 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 295:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 312:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 179:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 98:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_token_const */
			{
#line 1075 "psyntax.act"
 (XIn) = OPT_token_const ; 
#line 1917 "psyntax3.c"
			}
			/* END OF ACTION: opt_token_const */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1930 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 77:
		{
			ADVANCE_LEXER;
		}
		break;
	case 298:
		{
			ADVANCE_LEXER;
			XR809 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 310:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 169:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 203:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_ppdir_text */
			{
#line 1066 "psyntax.act"
 (XIn) = OPT_ppdir_text ; 
#line 1974 "psyntax3.c"
			}
			/* END OF ACTION: opt_ppdir_text */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 1987 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 148:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 257:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_this_lvalue */
			{
#line 1073 "psyntax.act"
 (XIn) = OPT_this_lvalue ; 
#line 2009 "psyntax3.c"
			}
			/* END OF ACTION: opt_this_lvalue */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2022 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 149:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 174:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_throw_bad */
			{
#line 1074 "psyntax.act"
 (XIn) = OPT_throw_bad ; 
#line 2044 "psyntax3.c"
			}
			/* END OF ACTION: opt_throw_bad */
			XRerror_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2057 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 316:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			XR794 (&XIn);
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2079 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 319:
		{
			ADVANCE_LEXER;
			XR805 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 321:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 288:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_unmatched */
			{
#line 1082 "psyntax.act"
 (XIn) = OPT_unmatched ; 
#line 2111 "psyntax3.c"
			}
			/* END OF ACTION: opt_unmatched */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2124 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 323:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 189:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_reached */
			{
#line 1070 "psyntax.act"
 (XIn) = OPT_reached ; 
#line 2146 "psyntax3.c"
			}
			/* END OF ACTION: opt_reached */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2159 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 325:
		{
			ADVANCE_LEXER;
			XR808 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 327:
		{
			ADVANCE_LEXER;
			XR806 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 332:
		{
			ADVANCE_LEXER;
			XR807 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 333:
		{
			int XIn;
			unsigned XIe;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 304:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 255:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: opt_const_string */
			{
#line 991 "psyntax.act"
 (XIn) = OPT_const_string ; 
#line 2218 "psyntax3.c"
			}
			/* END OF ACTION: opt_const_string */
			XRallow_Hstate (&XIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: analysis_state */
			{
#line 961 "psyntax.act"

    set_option ( (XIn), (XIe) ) ;
#line 2231 "psyntax3.c"
			}
			/* END OF ACTION: analysis_state */
		}
		break;
	case 215:
		{
			int XIn;

			XRerror_Hnumber (&XIn);
			XR783 (&XIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 251: case 318:
		{
			XRkeyword_Hrule ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	return;
XL1:;
	SAVE_LEXER (355);
	return;
}

void
XRkeyword_Hspec(int *XOt)
{
	int XIt;

	switch (CURRENT_TERMINAL) {
	case 126:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_asm */
			{
#line 403 "psyntax.act"
 (XIt) = lex_asm ; 
#line 2281 "psyntax3.c"
			}
			/* END OF ACTION: lex_asm */
		}
		break;
	case 206:
		{
			ADVANCE_LEXER;
			XR854 (&XIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 217:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_exhaustive */
			{
#line 405 "psyntax.act"
 (XIt) = lex_exhaustive ; 
#line 2303 "psyntax3.c"
			}
			/* END OF ACTION: lex_exhaustive */
		}
		break;
	case 223:
		{
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 249:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 96:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_fall */
			{
#line 406 "psyntax.act"
 (XIt) = lex_fall ; 
#line 2329 "psyntax3.c"
			}
			/* END OF ACTION: lex_fall */
		}
		break;
	case 137:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_inline */
			{
#line 407 "psyntax.act"
 (XIt) = lex_inline ; 
#line 2341 "psyntax3.c"
			}
			/* END OF ACTION: lex_inline */
		}
		break;
	case 141:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_symbol */
			{
#line 420 "psyntax.act"

    (XIt) = crt_lex_token ;
    if ( (XIt) >= FIRST_SYMBOL && (XIt) <= LAST_SYMBOL ) crt_lex_token = lex_plus ;
#line 2355 "psyntax3.c"
			}
			/* END OF ACTION: lex_symbol */
			switch (CURRENT_TERMINAL) {
			case 69:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 298:
		{
			ADVANCE_LEXER;
			XR855 (&XIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 313:
		{
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 292:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_representation */
			{
#line 412 "psyntax.act"
 (XIt) = lex_representation ; 
#line 2391 "psyntax3.c"
			}
			/* END OF ACTION: lex_representation */
		}
		break;
	case 332:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_weak */
			{
#line 417 "psyntax.act"
 (XIt) = lex_weak ; 
#line 2403 "psyntax3.c"
			}
			/* END OF ACTION: lex_weak */
		}
		break;
	case 251:
		{
			IDENTIFIER XIid;

			XRkeyword_Hid (&XIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: keyword_spec */
			{
#line 911 "psyntax.act"

    (XIt) = find_keyword ( (XIid) ) ;
#line 2422 "psyntax3.c"
			}
			/* END OF ACTION: keyword_spec */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOt = XIt;
}

void
XRaccess_Hspecifier_Hopt(DECL_SPEC *XOa)
{
	DECL_SPEC XIa;

	switch (CURRENT_TERMINAL) {
	case 142:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_private */
			{
#line 483 "psyntax.act"
 (XIa) = dspec_private ; 
#line 2453 "psyntax3.c"
			}
			/* END OF ACTION: access_private */
		}
		break;
	case 143:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_protected */
			{
#line 484 "psyntax.act"
 (XIa) = dspec_protected ; 
#line 2465 "psyntax3.c"
			}
			/* END OF ACTION: access_protected */
		}
		break;
	case 144:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_public */
			{
#line 485 "psyntax.act"
 (XIa) = dspec_public ; 
#line 2477 "psyntax3.c"
			}
			/* END OF ACTION: access_public */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: access_public */
			{
#line 485 "psyntax.act"
 (XIa) = dspec_public ; 
#line 2488 "psyntax3.c"
			}
			/* END OF ACTION: access_public */
		}
		break;
	case 355:
		return;
	}
	*XOa = XIa;
}

void
XRerror_Hnumber(int *XOn)
{
	int XIn;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP XIs;

		switch (CURRENT_TERMINAL) {
		case 215:
			break;
		default:
			goto XL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF INLINE: string-literal */
		{
			switch (CURRENT_TERMINAL) {
			case 19:
				{
					/* BEGINNING OF EXTRACT: string-exp */
					{
#line 299 "psyntax.act"

    XIs = crt_token->pp_data.exp ;
#line 2527 "psyntax3.c"
					}
					/* END OF EXTRACT: string-exp */
					ADVANCE_LEXER;
				}
				break;
			case 20:
				{
					/* BEGINNING OF EXTRACT: wstring-exp */
					{
#line 303 "psyntax.act"

    XIs = crt_token->pp_data.exp ;
#line 2540 "psyntax3.c"
					}
					/* END OF EXTRACT: wstring-exp */
					ADVANCE_LEXER;
				}
				break;
			default:
				goto XL1;
			}
		}
		/* END OF INLINE: string-literal */
		/* BEGINNING OF ACTION: error_number */
		{
#line 798 "psyntax.act"

    STRING s = DEREF_str ( exp_string_lit_str ( (XIs) ) ) ;
    (XIn) = find_error_no ( s, 0 ) ;
    if ( (XIn) == -1 ) {
	report ( preproc_loc, ERR_pragma_error_bad ( s ) ) ;
    }
#line 2560 "psyntax3.c"
		}
		/* END OF ACTION: error_number */
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOn = XIn;
}

void
XRtokdef_Hrule(void)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		TYPE XIt;
		IDENTIFIER XIid;

		/* BEGINNING OF ACTION: tokdef_start */
		{
#line 670 "psyntax.act"

    in_token_decl = 1 ;
#line 2587 "psyntax3.c"
		}
		/* END OF ACTION: tokdef_start */
		switch (CURRENT_TERMINAL) {
		case 260:
			break;
		default:
			goto XL1;
		}
		ADVANCE_LEXER;
		switch (CURRENT_TERMINAL) {
		case 201:
			break;
		default:
			goto XL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF ACTION: parse_type */
		{
#line 366 "psyntax.act"

    (XIt) = type_error ;
    parse_tok_type ( &(XIt) ) ;
    object_type ( (XIt), null_tag ) ;
#line 2611 "psyntax3.c"
		}
		/* END OF ACTION: parse_type */
		switch (CURRENT_TERMINAL) {
		case 41:
			break;
		default:
			goto XL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF INLINE: any-identifier */
		{
			switch (CURRENT_TERMINAL) {
			case 1:
				{
					/* BEGINNING OF EXTRACT: identifier */
					{
#line 195 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2631 "psyntax3.c"
					}
					/* END OF EXTRACT: identifier */
					ADVANCE_LEXER;
				}
				break;
			case 3:
				{
					/* BEGINNING OF EXTRACT: namespace-name */
					{
#line 203 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2644 "psyntax3.c"
					}
					/* END OF EXTRACT: namespace-name */
					ADVANCE_LEXER;
				}
				break;
			case 4:
				{
					/* BEGINNING OF EXTRACT: statement-name */
					{
#line 207 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2657 "psyntax3.c"
					}
					/* END OF EXTRACT: statement-name */
					ADVANCE_LEXER;
				}
				break;
			case 2:
				{
					/* BEGINNING OF EXTRACT: type-name */
					{
#line 199 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2670 "psyntax3.c"
					}
					/* END OF EXTRACT: type-name */
					ADVANCE_LEXER;
				}
				break;
			default:
				goto XL1;
			}
		}
		/* END OF INLINE: any-identifier */
		/* BEGINNING OF ACTION: tokdef_end */
		{
#line 674 "psyntax.act"

    in_token_decl = 0 ;
#line 2686 "psyntax3.c"
		}
		/* END OF ACTION: tokdef_end */
		/* BEGINNING OF ACTION: token_member_def */
		{
#line 665 "psyntax.act"

    if ( define_mem_macro ( (XIid), (XIt) ) ) no_declarations++ ;
#line 2694 "psyntax3.c"
		}
		/* END OF ACTION: token_member_def */
	}
	return;
XL1:;
	SAVE_LEXER (355);
	return;
}

void
XRpostpone_Hlist(int XIa)
{
XL2_postpone_Hlist:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
		{
			IDENTIFIER XIid;

			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2723 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2736 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2749 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 2762 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: id_postpone */
			{
#line 685 "psyntax.act"

    preserve_id ( (XIid), (XIa) ) ;
#line 2778 "psyntax3.c"
			}
			/* END OF ACTION: id_postpone */
			/* BEGINNING OF INLINE: postpone-list */
			goto XL2_postpone_Hlist;
			/* END OF INLINE: postpone-list */
		}
		UNREACHED;
	case 355:
		return;
	default:
		break;
	}
	return;
XL1:;
	SAVE_LEXER (355);
	return;
}

void
XR743(unsigned *XOc)
{
	unsigned XIc;

	switch (CURRENT_TERMINAL) {
	case 179:
		{
			ADVANCE_LEXER;
			XRcast_Hstate (&XIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: cast_explicit */
			{
#line 949 "psyntax.act"
 (XIc) = CAST_EXPLICIT ; 
#line 2819 "psyntax3.c"
			}
			/* END OF ACTION: cast_explicit */
		}
		break;
	case 355:
		return;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOc = XIc;
}

void
XRoption_Hstate(unsigned *XOe)
{
	unsigned XIe;

	switch (CURRENT_TERMINAL) {
	case 172:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_off */
			{
#line 822 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_OFF ; 
#line 2848 "psyntax3.c"
			}
			/* END OF ACTION: error_off */
		}
		break;
	case 205:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_on */
			{
#line 821 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_ON ; 
#line 2860 "psyntax3.c"
			}
			/* END OF ACTION: error_on */
		}
		break;
	case 271:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_off */
			{
#line 822 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_OFF ; 
#line 2872 "psyntax3.c"
			}
			/* END OF ACTION: error_off */
		}
		break;
	case 272:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_on */
			{
#line 821 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_ON ; 
#line 2884 "psyntax3.c"
			}
			/* END OF ACTION: error_on */
		}
		break;
	case 331:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_warning */
			{
#line 823 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_WARN ; 
#line 2896 "psyntax3.c"
			}
			/* END OF ACTION: error_warning */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOe = XIe;
}

void
XRsimple_Htok_Hpars(SID_LIST_ID *XOp)
{
	SID_LIST_ID XIp;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		IDENTIFIER XIid;
		SID_LIST_ID XIq;

		XRsimple_Htok_Hparam (&XIid);
		/* BEGINNING OF INLINE: 415 */
		{
			switch (CURRENT_TERMINAL) {
			case 42:
				{
					ADVANCE_LEXER;
					XR833 (&XIq);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto XL1;
					}
				}
				break;
			default:
				{
					/* BEGINNING OF ACTION: list_id_null */
					{
#line 520 "psyntax.act"

    (XIq) = NULL_list ( IDENTIFIER ) ;
#line 2947 "psyntax3.c"
					}
					/* END OF ACTION: list_id_null */
				}
				break;
			case 355:
				RESTORE_LEXER;
				goto XL1;
			}
		}
		/* END OF INLINE: 415 */
		/* BEGINNING OF ACTION: list_id_cons */
		{
#line 524 "psyntax.act"

    CONS_id ( (XIid), (XIq), (XIp) ) ;
#line 2963 "psyntax3.c"
		}
		/* END OF ACTION: list_id_cons */
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOp = XIp;
}

void
XRkeyword_Hrule(void)
{
	switch (CURRENT_TERMINAL) {
	case 318:
		{
			IDENTIFIER XIid;

			ADVANCE_LEXER;
			XRkeyword_Hid (&XIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: keyword_undef */
			{
#line 919 "psyntax.act"

    undef_keyword ( (XIid) ) ;
#line 2994 "psyntax3.c"
			}
			/* END OF ACTION: keyword_undef */
		}
		break;
	case 251:
		{
			IDENTIFIER XIid;
			int XIt;

			XRkeyword_Hid (&XIid);
			switch (CURRENT_TERMINAL) {
			case 107:
				break;
			case 355:
				RESTORE_LEXER;
				goto XL1;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			XRkeyword_Hspec (&XIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: keyword_define */
			{
#line 915 "psyntax.act"

    define_keyword ( (XIid), (XIt) ) ;
#line 3025 "psyntax3.c"
			}
			/* END OF ACTION: keyword_define */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	return;
XL1:;
	SAVE_LEXER (355);
	return;
}

void
XRsuspend_Hlist(void)
{
XL2_suspend_Hlist:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
		{
			IDENTIFIER XIid;

			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 3060 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 3073 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 3086 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XIid = crt_token->pp_data.id.use ;
#line 3099 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: id_susp */
			{
#line 697 "psyntax.act"

    preserve_id ( (XIid), lex_suspend ) ;
#line 3115 "psyntax3.c"
			}
			/* END OF ACTION: id_susp */
			/* BEGINNING OF INLINE: suspend-list */
			goto XL2_suspend_Hlist;
			/* END OF INLINE: suspend-list */
		}
		UNREACHED;
	case 355:
		return;
	default:
		break;
	}
	return;
XL1:;
	SAVE_LEXER (355);
	return;
}

void
XRallow_Hstate(unsigned *XOe)
{
	unsigned XIe;

	switch (CURRENT_TERMINAL) {
	case 172:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_off */
			{
#line 822 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_OFF ; 
#line 3147 "psyntax3.c"
			}
			/* END OF ACTION: error_off */
		}
		break;
	case 205:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_on */
			{
#line 821 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_ON ; 
#line 3159 "psyntax3.c"
			}
			/* END OF ACTION: error_on */
		}
		break;
	case 331:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_warning */
			{
#line 823 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_WARN ; 
#line 3171 "psyntax3.c"
			}
			/* END OF ACTION: error_warning */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOe = XIe;
}

void
XRexp_Hstorage(int *XOb, int *XOc)
{
	int XIb;
	int XIc;

	switch (CURRENT_TERMINAL) {
	case 98:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIb) = 0 ; 
#line 3203 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: bool_true */
			{
#line 1157 "psyntax.act"
 (XIc) = 1 ; 
#line 3210 "psyntax3.c"
			}
			/* END OF ACTION: bool_true */
		}
		break;
	case 257:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_true */
			{
#line 1157 "psyntax.act"
 (XIb) = 1 ; 
#line 3222 "psyntax3.c"
			}
			/* END OF ACTION: bool_true */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIc) = 0 ; 
#line 3229 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 295:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIb) = 0 ; 
#line 3241 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIc) = 0 ; 
#line 3248 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIb) = 0 ; 
#line 3259 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 1156 "psyntax.act"
 (XIc) = 0 ; 
#line 3266 "psyntax3.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 355:
		return;
	}
	*XOb = XIb;
	*XOc = XIc;
}

void
XR755(EXP *XOb)
{
	EXP XIb;

	switch (CURRENT_TERMINAL) {
	case 179:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: character-literal */
			{
				switch (CURRENT_TERMINAL) {
				case 17:
					{
						/* BEGINNING OF EXTRACT: char-exp */
						{
#line 291 "psyntax.act"

    XIb = crt_token->pp_data.exp ;
#line 3297 "psyntax3.c"
						}
						/* END OF EXTRACT: char-exp */
						ADVANCE_LEXER;
					}
					break;
				case 18:
					{
						/* BEGINNING OF EXTRACT: wchar-exp */
						{
#line 295 "psyntax.act"

    XIb = crt_token->pp_data.exp ;
#line 3310 "psyntax3.c"
						}
						/* END OF EXTRACT: wchar-exp */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: character-literal */
			switch (CURRENT_TERMINAL) {
			case 172:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 205:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_none */
			{
#line 446 "psyntax.act"

    (XIb) = NULL_exp ;
#line 3338 "psyntax3.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOb = XIb;
}

void
XRprog_Htok_Hparam(SID_LIST_ID XIr, IDENTIFIER *XOid)
{
	IDENTIFIER XIid;

	switch (CURRENT_TERMINAL) {
	case 218:
		{
			IDENTIFIER XItid;

			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3377 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3390 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3403 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3416 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: token_exp_par */
			{
#line 604 "psyntax.act"

    (XIid) = prog_tok_param ( (XItid), NULL_type, tok_exp_tag, (XIr) ) ;
#line 3432 "psyntax3.c"
			}
			/* END OF ACTION: token_exp_par */
		}
		break;
	case 261:
		{
			TYPE XIt;
			IDENTIFIER XItid;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: parse_type */
			{
#line 366 "psyntax.act"

    (XIt) = type_error ;
    parse_tok_type ( &(XIt) ) ;
    object_type ( (XIt), null_tag ) ;
#line 3450 "psyntax3.c"
			}
			/* END OF ACTION: parse_type */
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3470 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3483 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3496 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3509 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: token_member_par */
			{
#line 617 "psyntax.act"

    (XIid) = prog_tok_param ( (XItid), (XIt), tok_member_tag, (XIr) ) ;
#line 3525 "psyntax3.c"
			}
			/* END OF ACTION: token_member_par */
		}
		break;
	case 282:
		{
			IDENTIFIER XItid;

			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3545 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3558 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3571 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3584 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: token_proc_par */
			{
#line 621 "psyntax.act"

    (XIid) = prog_tok_param ( (XItid), NULL_type, tok_proc_tag, (XIr) ) ;
#line 3600 "psyntax3.c"
			}
			/* END OF ACTION: token_proc_par */
		}
		break;
	case 303:
		{
			IDENTIFIER XItid;

			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 195 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3620 "psyntax3.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 203 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3633 "psyntax3.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 207 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3646 "psyntax3.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 199 "psyntax.act"

    XItid = crt_token->pp_data.id.use ;
#line 3659 "psyntax3.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto XL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: token_stmt_par */
			{
#line 608 "psyntax.act"

    (XIid) = prog_tok_param ( (XItid), NULL_type, tok_stmt_tag, (XIr) ) ;
#line 3675 "psyntax3.c"
			}
			/* END OF ACTION: token_stmt_par */
		}
		break;
	case 314:
		{
			TYPE XIt;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: parse_type */
			{
#line 366 "psyntax.act"

    (XIt) = type_error ;
    parse_tok_type ( &(XIt) ) ;
    object_type ( (XIt), null_tag ) ;
#line 3692 "psyntax3.c"
			}
			/* END OF ACTION: parse_type */
			/* BEGINNING OF ACTION: token_type_par */
			{
#line 612 "psyntax.act"

    IDENTIFIER tid = DEREF_id ( type_name ( (XIt) ) ) ;
    (XIid) = prog_tok_param ( tid, (XIt), tok_type_tag, (XIr) ) ;
#line 3701 "psyntax3.c"
			}
			/* END OF ACTION: token_type_par */
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOid = XIid;
}

void
XRtoken_Hintroduction(TOKEN *XOtok)
{
	TOKEN XItok;

	switch (CURRENT_TERMINAL) {
	case 177:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_arith */
			{
#line 568 "psyntax.act"

    (XItok) = make_type_token ( btype_arith ) ;
#line 3733 "psyntax3.c"
			}
			/* END OF ACTION: token_arith */
		}
		break;
	case 188:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_class */
			{
#line 572 "psyntax.act"

    (XItok) = make_type_token ( btype_lang ) ;
#line 3746 "psyntax3.c"
			}
			/* END OF ACTION: token_class */
		}
		break;
	case 218:
		{
			int XIb;
			int XIc;
			TYPE XIt;

			ADVANCE_LEXER;
			XRexp_Hstorage (&XIb, &XIc);
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			case 355:
				RESTORE_LEXER;
				goto XL1;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: parse_type */
			{
#line 366 "psyntax.act"

    (XIt) = type_error ;
    parse_tok_type ( &(XIt) ) ;
    object_type ( (XIt), null_tag ) ;
#line 3776 "psyntax3.c"
			}
			/* END OF ACTION: parse_type */
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_exp */
			{
#line 588 "psyntax.act"

    (XItok) = make_exp_token ( (XIt), (XIb), (XIc) ) ;
#line 3791 "psyntax3.c"
			}
			/* END OF ACTION: token_exp */
		}
		break;
	case 225:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_float */
			{
#line 564 "psyntax.act"

    (XItok) = make_type_token ( btype_float ) ;
#line 3804 "psyntax3.c"
			}
			/* END OF ACTION: token_float */
		}
		break;
	case 227:
		{
			TYPE XIt;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: parse_func_type */
			{
#line 372 "psyntax.act"

    (XIt) = type_error ;
    parse_tok_type ( &(XIt) ) ;
    object_type ( (XIt), id_function_tag ) ;
#line 3821 "psyntax3.c"
			}
			/* END OF ACTION: parse_func_type */
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_func */
			{
#line 596 "psyntax.act"

    (XItok) = make_func_token ( (XIt) ) ;
#line 3836 "psyntax3.c"
			}
			/* END OF ACTION: token_func */
		}
		break;
	case 250:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_snat */
			{
#line 540 "psyntax.act"

    MAKE_tok_snat ( NULL_nat, (XItok) ) ;
#line 3849 "psyntax3.c"
			}
			/* END OF ACTION: token_snat */
		}
		break;
	case 261:
		{
			DECL_SPEC XIa;
			TYPE XIt;
			TYPE XIs;

			ADVANCE_LEXER;
			XRaccess_Hspecifier_Hopt (&XIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
			/* BEGINNING OF ACTION: parse_mem_type */
			{
#line 378 "psyntax.act"

    (XIt) = type_error ;
    parse_mem_type ( &(XIt) ) ;
    object_type ( (XIt), null_tag ) ;
#line 3873 "psyntax3.c"
			}
			/* END OF ACTION: parse_mem_type */
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: parse_type */
			{
#line 366 "psyntax.act"

    (XIs) = type_error ;
    parse_tok_type ( &(XIs) ) ;
    object_type ( (XIs), null_tag ) ;
#line 3890 "psyntax3.c"
			}
			/* END OF ACTION: parse_type */
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			default:
				goto XL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_member */
			{
#line 592 "psyntax.act"

    (XItok) = make_member_token ( (XIt), (XIs), (XIa) ) ;
#line 3905 "psyntax3.c"
			}
			/* END OF ACTION: token_member */
		}
		break;
	case 263:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_nat */
			{
#line 536 "psyntax.act"

    MAKE_tok_nat ( NULL_nat, (XItok) ) ;
#line 3918 "psyntax3.c"
			}
			/* END OF ACTION: token_nat */
		}
		break;
	case 282:
		{
			ADVANCE_LEXER;
			XR832 (&XItok);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 296:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_scalar */
			{
#line 576 "psyntax.act"

    (XItok) = make_type_token ( btype_scalar ) ;
#line 3941 "psyntax3.c"
			}
			/* END OF ACTION: token_scalar */
		}
		break;
	case 303:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_stmt */
			{
#line 544 "psyntax.act"

    MAKE_tok_stmt ( NULL_exp, (XItok) ) ;
#line 3954 "psyntax3.c"
			}
			/* END OF ACTION: token_stmt */
		}
		break;
	case 305:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_struct */
			{
#line 580 "psyntax.act"

    (XItok) = make_type_token ( btype_struct ) ;
#line 3967 "psyntax3.c"
			}
			/* END OF ACTION: token_struct */
		}
		break;
	case 314:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_type */
			{
#line 548 "psyntax.act"

    (XItok) = make_type_token ( btype_none ) ;
#line 3980 "psyntax3.c"
			}
			/* END OF ACTION: token_type */
		}
		break;
	case 320:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: token_union */
			{
#line 584 "psyntax.act"

    (XItok) = make_type_token ( btype_union ) ;
#line 3993 "psyntax3.c"
			}
			/* END OF ACTION: token_union */
		}
		break;
	case 328:
		{
			ADVANCE_LEXER;
			XR831 (&XItok);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto XL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto XL1;
	}
	goto XL0;
XL1:;
	SAVE_LEXER (355);
	return;
XL0:;
	*XOtok = XItok;
}

void
XRwarning_Hopt(unsigned *XOe)
{
	unsigned XIe;

	switch (CURRENT_TERMINAL) {
	case 331:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: error_warning */
			{
#line 823 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_WARN ; 
#line 4034 "psyntax3.c"
			}
			/* END OF ACTION: error_warning */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: error_on */
			{
#line 821 "psyntax.act"
 (XIe) = ( unsigned ) OPTION_ON ; 
#line 4045 "psyntax3.c"
			}
			/* END OF ACTION: error_on */
		}
		break;
	case 355:
		return;
	}
	*XOe = XIe;
}

/* BEGINNING OF TRAILER */

#line 1217 "psyntax.act"

#line 4060 "psyntax3.c"

/* END OF FILE */
