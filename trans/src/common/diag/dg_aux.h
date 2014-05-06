/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef dg_aux_key
#define dg_aux_key

#include "dg_first.h"

#include "diaginfo.h"
#include <local/exptypes.h>
#include <construct/installtypes.h>
#include "dg_types.h"		/* NEW DIAGS */
#include <reader/toktypes.h>

extern dg_name new_dg_name(dg_name_key k);
extern dg_type new_dg_type(dg_type_key k);
extern dg_info new_dg_info(dg_info_key k);
extern void extend_dg_name(dg_name nm);
extern void extend_dg_type(dg_type nm);
extern void init_dgtag(dg_tag tg);
extern dg_tag gen_tg_tag(void);
extern dg_type get_qual_dg_type(dg_qual_type_key qual, dg_type typ);
extern dg_type get_dg_bitfield_type(dg_type typ, shape sha,
				    bitfield_variety bv);
extern char *idname_chars(dg_idname nam);
extern dg_filename get_filename(long dat, char *host, char *path, char *name);
extern short_sourcepos shorten_sourcepos(dg_sourcepos pos);
extern short_sourcepos end_sourcepos(dg_sourcepos pos);
extern dg_type find_proc_type(dg_type t);

extern exp diaginfo_exp(exp e);

extern exp relative_exp(shape s, token t);

#endif
