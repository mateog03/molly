#pragma once

#include <assert.h>

#define SQ_A1  68
#define SQ_A2  84
#define SQ_A3  100
#define SQ_A4  116
#define SQ_A5  132
#define SQ_A6  148
#define SQ_A7  164
#define SQ_A8  180

#define SQ_STM 240
#define SQ_EP  241

#define SQ_OK(sq)		!(((sq) - SQ_A1) & 0x88)
#define SQ_FILE(sq)		((sq) % 16)
#define SQ_RANK(sq)		((sq) / 16)

#define EMPTY  0
#define KING   1
#define PAWN   2
#define KNIGHT 3
#define BISHOP 4
#define ROOK   5
#define QUEEN  6

#define WHITE 32
#define BLACK 16
#define BOTH  (WHITE + BLACK)

#define PIECE_TYPE(p)		((p) & 7)
#define PIECE_FLAG(p)		((p) & 48)
#define PIECE_IS_SLIDER(p)	((p) & 4)

#define RELATIVE_NORTH(stm)			(((stm) & WHITE) - BLACK)
#define RELATIVE_DPRANK(sq, stm)	((stm) * SQ_RANK(sq) == 160)
#define RELATIVE_PPRANK(sq, stm)	(RELATIVE_DPRANK(sq, (stm) ^ BOTH))

#define BOARDSIZ 256

struct position {
	unsigned char board[BOARDSIZ];
	unsigned char data[BOARDSIZ];
};

#define MV_DOUBLEPUSH 1
#define MV_ENPASSANT  2
#define MV_PROMON	  3
#define MV_PROMOB	  4
#define MV_PROMOR	  5
#define MV_PROMOQ	  6
#define MV_CASTLESH   7
#define MV_CASTLELO   8

struct move {
	unsigned char from;
	unsigned char to;
	unsigned char flag;
};

#define GENSIZ 256

struct gen {
	struct move moves[GENSIZ];
	int size;
};

/* gen.c */
void genall(const struct position *, struct gen *);

/* fen.c */
void setup(struct position *, const char *);
void clear(struct position *);

/* make.c */
void poscpy(struct position *, const struct position *);
void make(struct position *, const struct move *);
int legal(struct position *, const struct move *);
int attacked(const struct position *, int, int);
int checked(const struct position *);

/* io.c */
void mtos(const struct move *, char *);
void sqtos(int, char *);
int stosq(const char *);
int starts_with(const char *s, const char *);

/* vector.c */
void vector_init(void);
int direction(int, int);
int pseudo_attack(int, int, int);
