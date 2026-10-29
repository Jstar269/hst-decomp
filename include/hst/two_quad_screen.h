/* Screen object with eight sprites, four quads, two selector pairs, a flag and a counter. */
#ifndef HST_TWO_QUAD_SCREEN_H
#define HST_TWO_QUAD_SCREEN_H

#define TWO_QUAD_SPRITE_COUNT 8
#define TWO_QUAD_QUAD_COUNT 4
#define TWO_QUAD_PAIR_COUNT 2    /* entries of the cleared record array and of the selector arrays */
#define TWO_QUAD_RECORD_WORDS 6  /* words per cleared record */

/* Sprite: a position pair and an alpha level (0..1, scaled to a byte when drawn). */
typedef struct TwoQuadSprite {
  char pad0[0x60];
  float unk60;            /* 0x60 */
  float unk64;            /* 0x64 */
  char pad68[0x78 - 0x68];
  float alpha;            /* 0x78 */
} TwoQuadSprite;

/* Quad: packed colour and its two corners. */
typedef struct TwoQuadRec {
  unsigned int color;     /* 0x0 */
  short x;                /* 0x4 */
  short y;                /* 0x6 */
  short x2;               /* 0x8 */
  short y2;               /* 0xa */
} TwoQuadRec;

typedef struct TwoQuadScreen {
  char pad0[0x5c];
  TwoQuadSprite *spr[TWO_QUAD_SPRITE_COUNT];     /* 0x5c */
  TwoQuadRec *quad[TWO_QUAD_QUAD_COUNT];         /* 0x7c */
  char pad8c[0x3e8 - 0x8c];
  int record[TWO_QUAD_PAIR_COUNT][TWO_QUAD_RECORD_WORDS]; /* 0x3e8 reset to -1 */
  unsigned char unk418;                          /* 0x418 */
  char pad419[0x42c - 0x419];
  int selA[TWO_QUAD_PAIR_COUNT];                 /* 0x42c */
  int selB[TWO_QUAD_PAIR_COUNT];                 /* 0x434 */
  unsigned char active;                          /* 0x43c */
  char pad43d[3];
  int counter;                                   /* 0x440 */
} TwoQuadScreen;

/* Holder whose first word points at the screen. */
typedef struct TwoQuadRef {
  TwoQuadScreen *screen;  /* 0x0 */
} TwoQuadRef;

#endif
