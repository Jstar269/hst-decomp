/* Object holding a growable int array with a parallel one-bit-per-element bitmap. */
#ifndef HST_INDEXED_BITS_H
#define HST_INDEXED_BITS_H

typedef struct IndexedBits {
  char pad0[0x8c];
  int unk8c;            /* 0x8c passed to the item constructor */
  char pad90[0xa8 - 0x90];
  int *values;          /* 0xa8 element storage */
  unsigned count;       /* 0xac elements in use */
  unsigned capacity;    /* 0xb0 elements allocated */
  unsigned *bits;       /* 0xb4 bitmap storage, 32 bits per word */
  unsigned bitCount;    /* 0xb8 */
  unsigned bitWords;    /* 0xbc words allocated for the bitmap */
} IndexedBits;

#endif
