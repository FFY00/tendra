# $Id$

# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+IMPLEMENT "c/c89", "stdlib.h.ts", "bottom" ;

+NAT ~jmp_buf_size ;
+TYPE ~jmp_buf_elt ;
+TYPEDEF ~jmp_buf_elt jmp_buf [ ~jmp_buf_size ] ;

+FUNC ~bottom longjmp ( jmp_buf, int ) ;
+FUNC int setjmp ( jmp_buf ) ;
