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


#ifndef OSSG_API_INCLUDED
#define OSSG_API_INCLUDED


/*
    STANDARD API HEADER

    This header contains the basic API headers used by the program
    software.  The flag FS_POSIX is set to indicate that POSIX features
    should be enabled (see system.h).  Some likely values for objects
    which are not defined by all systems are provided.  Also any
    unwarranted namespace pollution is removed.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef FS_EXTENDED_CHAR
#define FS_EXTENDED_CHAR	0
#endif

#ifndef FS_MULTIBYTE
#define FS_MULTIBYTE		0
#endif

#ifndef FS_POSIX
#define FS_POSIX		1
#endif

#ifndef FS_UTSNAME
#define FS_UTSNAME		FS_POSIX
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS		0
#define EXIT_FAILURE		1
#endif

#ifndef SEEK_SET
#define SEEK_SET		0
#define SEEK_CUR		1
#define SEEK_END		2
#endif

#ifndef BUFSIZ
#define BUFSIZ			1024
#endif

#ifdef index
#undef index
#endif

#ifdef major
#undef major
#endif

#ifdef minor
#undef minor
#endif


#endif