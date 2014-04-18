
/*
 * Automatically generated by lexi version 2.0
 */

#ifndef LEXI_GENERATED_HEADER_lexi__INCLUDED
#define LEXI_GENERATED_HEADER_lexi__INCLUDED



	/* $Id$ */

	/*
	 * Copyright 2002-2011, The TenDRA Project.
	 *
	 * See doc/copyright/ for the full copyright terms.
	 */

	#include <stdio.h> /* TODO: This is necessary because lexi automatically prepend #include "lexer.h" to the header. Maybe we should remove this unecessary feature */

	char token_buff[];
	char *token_end;
	int crt_lex_token;
	int saved_lex_token;
	unsigned int number_buffer;
	struct lexi_state lexer_state;

	typedef FILE *FILE_P;

	#define CURRENT_LXI_TERMINAL crt_lex_token
	#define ADVANCE_LXI_LEXER    crt_lex_token = lexi_read_token(&lexer_state)
	#define SAVE_LXI_LEXER(T)    (saved_lex_token = crt_lex_token, crt_lex_token = (T))
	#define RESTORE_LXI_LEXER    (crt_lex_token = saved_lex_token)

#include <stdbool.h>

/*
 * This struct holds state for the lexer; its representation is
 * private, but present here for ease of allocation.
 */
struct lexi_state {
	int (*zone)(struct lexi_state *);

	/*
	 * Lexi's buffer is a simple stack.
	 */
	int buffer[4];
	int buffer_index;
	FILE_P input;
};

/* Read a character */
int lexi_readchar(struct lexi_state *state);

/* Push a character to lexi's buffer */
void lexi_push(struct lexi_state *state, const int c);

/* Pop a character from lexi's buffer */
int lexi_pop(struct lexi_state *state);

/* Flush lexi's buffer */
void lexi_flush(struct lexi_state *state);

#ifndef LEXI_EOF
#define LEXI_EOF -1
#endif

enum lexi_groups {
	lexi_group_alnumhy = 0x1,
	lexi_group_alnum = 0x2,
	lexi_group_digit = 0x4,
	lexi_group_alpha = 0x8,
	lexi_group_white = 0x10,
	lexi_sididentifierzone_white = 0,
	lexi_identifierzone_white = 0,
	lexi_stringzone_white = 0,
	lexi_linecomment_white = 0,
	lexi_comment_white = 0,
};

/* true if the given character is present in the given group */
bool lexi_group(enum lexi_groups group, int c);

/* Identify a keyword */
int lexi_keyword(const char *identifier, int notfound);

/* Identify a token */
int lexi_read_token(struct lexi_state *state);

/* Initialise a lexi_state structure */
void lexi_init(struct lexi_state *state, FILE_P input);


#endif

