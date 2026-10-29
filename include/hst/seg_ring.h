/* Two layouts of an object that records pairs of 4-float points into a fixed-size ring. */
#ifndef HST_SEG_RING_H
#define HST_SEG_RING_H

#include "hst/vec.h"

/* One recorded entry: a start and an end point. */
typedef struct Float4Seg {
  Float4 a;  /* 0x00 */
  Float4 b;  /* 0x10 */
} Float4Seg; /* size 0x20 */

/* First layout. */
typedef struct SegRingA {
  char pad00[0x24];
  unsigned char unk24;   /* 0x24 copied into pending after each call */
  char pad25[0x3c - 0x25];
  Float4Seg *entries;    /* 0x3c ring storage */
  char pad40[0x5c - 0x40];
  int capacity;          /* 0x5c number of entries in the ring */
  int head;              /* 0x60 next write position, wraps at capacity */
  int total;             /* 0x64 entries recorded so far */
  char pad68[0xf0 - 0x68];
  unsigned char pending; /* 0xf0 an entry is recorded on the next call */
} SegRingA;

/* Second layout. */
typedef struct SegRingB {
  char pad00[0x24];
  unsigned char unk24;   /* 0x24 copied into pending after each call */
  char pad25[0x3c - 0x25];
  Float4Seg *entries;    /* 0x3c ring storage */
  char pad40[0x60 - 0x40];
  int capacity;          /* 0x60 number of entries in the ring */
  int head;              /* 0x64 next write position, wraps at capacity */
  int total;             /* 0x68 entries recorded so far */
  char pad6c[0xb0 - 0x6c];
  unsigned char pending; /* 0xb0 an entry is recorded on the next call */
} SegRingB;

#endif
