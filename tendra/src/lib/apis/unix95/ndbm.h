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
+USE "ansi", "stddef.h", "size_t";

# Corrigenda U013 1170/02: define mode_t
+IMPLEMENT "posix", "sys/types.h", "mode_t";

+FIELD (struct) datum {
    void *dptr;
    size_t dsize;
};

+TYPE (struct) DBM;

+CONST int DBM_INSERT, DBM_REPLACE;

+FUNC DBM *dbm_open(const char *, int, mode_t);
+FUNC void dbm_close(DBM *);
+FUNC datum dbm_fetch(DBM *, datum);
+FUNC int dbm_store(DBM *, datum, datum, int);
+FUNC int dbm_delete(DBM *, datum);
+FUNC datum dbm_firstkey(DBM *);
+FUNC datum dbm_nextkey(DBM *);
+FUNC int dbm_error(DBM *);
+FUNC int dbm_clearerr(DBM *);
