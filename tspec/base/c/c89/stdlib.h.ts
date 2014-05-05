# $Id$

# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+IMPLEMENT "c/c89", "stddef.h.ts", "null" (!?) ;
+IMPLEMENT "c/c89", "stddef.h.ts", "size_t" (!?) ;
+IMPLEMENT "c/c89", "stddef.h.ts", "wchar_t" (!?) ;

+SUBSET "bottom" := {
    +TYPEDEF ~special ( "bottom" ) ~bottom ;
} ;

+CONST int EXIT_FAILURE, EXIT_SUCCESS ;
+CONST int RAND_MAX ;

+FUNC ~bottom abort ( void ) ;
+FUNC int abs ( int ) ;
+FUNC double atof ( const char * ) ;
+FUNC int atoi ( const char * ) ;
+FUNC long atol ( const char * ) ;
+FUNC ~bottom exit ( int ) ;
+SUBSET "free" := { +FUNC void free ( void * ) ; } ;
+FUNC char *getenv ( const char * ) ;
+FUNC int rand ( void ) ;
+FUNC void srand ( unsigned int ) ;

+IFNDEF __JUST_POSIX
+FUNC double strtod ( const char *, char ** ) ;
+FUNC long strtol ( const char *, char **, int ) ;
+SUBSET "system" := { +FUNC int system ( const char * ) ; } ;

+IFNDEF __JUST_XPG3
+EXP int MB_CUR_MAX ;
+FIELD ( struct ) div_t { int quot, rem ; } ;
+FIELD ( struct ) ldiv_t { long quot, rem ; } ;
+FUNC int atexit ( void (*) ( void ) ) ;
+FUNC div_t div ( int, int ) ;
+FUNC long labs ( long ) ;
+FUNC ldiv_t ldiv ( long, long ) ;
+FUNC unsigned long strtoul ( const char *, char **, int ) ;
+FUNC int wctomb ( char *, wchar_t ) ;
+ENDIF
+ENDIF

+SUBSET "alloc" := {
    +USE "c/c89", "stddef.h.ts", "size_t" (!?) ;
    +FUNC void *calloc ( size_t, size_t ) ;
    +FUNC void *malloc ( size_t ) ;
    +FUNC void *realloc ( void *, size_t ) ;
} ;

+FUNC void *bsearch ( const void *, const void *, size_t, size_t,
		      int (*) ( const void *, const void * ) ) ;
+FUNC void qsort ( void *, size_t, size_t,
		   int (*) ( const void *, const void * ) ) ;

+IFNDEF __JUST_POSIX
+IFNDEF __JUST_XPG3
+FUNC int mblen ( const char *, size_t ) ;
+FUNC size_t mbstowcs ( wchar_t *, const char *, size_t ) ;
+FUNC int mbtowc ( wchar_t *, const char *, size_t ) ;
+FUNC size_t wcstombs ( char *, const wchar_t *, size_t ) ;
+ENDIF
+ENDIF
