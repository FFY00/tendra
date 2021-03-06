# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+USE "x5/mit", "X11/Xfuncs.h.ts" (!?) ;

+USE ( "c/c89" ), "time.h.ts" (!?) ;

+IFDEF ~protect ( "posix/posix", "time.h.ts" )
+USE ( "posix/posix" ), "sys/types.h.ts" (!?) ;
+USE ( "posix/posix" ), "fcntl.h.ts" (!?) ;
+USE ( "posix/posix" ), "unistd.h.ts" (!?) ;
+ENDIF

+IFNDEF __TDF_STRUCT_TIMEVAL
+DEFINE __TDF_STRUCT_TIMEVAL 1 ;
+TYPE (int) ~tv_sec_t ;
+TYPE (int) ~tv_usec_t ;
+FIELD struct timeval {
    ~tv_sec_t tv_sec ;
    ~tv_usec_t tv_usec ;
} ;
+ENDIF

+IFNDEF __TDF_STRUCT_TIMEZONE
+DEFINE __TDF_STRUCT_TIMEZONE 1 ;
+FIELD struct timezone {
    int tz_minuteswest ;
    int tz_dsttime ;
} ;

+ENDIF
