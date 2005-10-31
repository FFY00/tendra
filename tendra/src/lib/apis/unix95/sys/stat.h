#   		 Crown Copyright (c) 1997
#
#   This TenDRA(r) Computer Program is subject to Copyright
#   owned by the United Kingdom Secretary of State for Defence
#   acting through the Defence Evaluation and Research Agency
#   (DERA).  It is made available to Recipients with a
#   royalty-free licence for its use, reproduction, transfer
#   to other parties and amendment for any purpose not excluding
#   product development provided that any such use et cetera
#   shall be deemed to be acceptance of the following conditions:-
#
#       (1) Its Recipients shall ensure that this Notice is
#       reproduced upon any copies or amended versions of it;
#
#       (2) Any amended version of it shall be clearly marked to
#       show both the nature of and the organisation responsible
#       for the relevant amendment or amendments;
#
#       (3) Its onward transfer from a recipient to another
#       party shall be deemed to be that party's acceptance of
#       these conditions;
#
#       (4) DERA gives no warranty or assurance as to its
#       quality or suitability for any purpose and DERA accepts
#       no liability whatsoever in relation to any use to which
#       it may be put.
#
# $TenDRA$
#
+IMPLEMENT "posix", "sys/types.h", "stat_t";
+IMPLEMENT "ansi", "time.h", "time_t";

+SUBSET "st_proto" := {
    +IMPLEMENT "xpg4", "sys/stat.h";
    +IMPLEMENT "xpg3", "sys/stat.h", "s_isvtx";

    +FIELD struct stat {
	long st_blksize;
	long st_blocks;
    };

    +CONST int S_IFLNK;

    +MACRO int S_ISLNK (mode_t);

    # CAE, Networking Services, Issue 4
    +CONST int S_IFSOCK;

    +MACRO int S_ISSOCK (mode_t);
};

+FUNC int fchmod(int, mode_t);
+FUNC int lstat(const char *, struct stat *);
+FUNC int mknod(const char *, mode_t, dev_t);
