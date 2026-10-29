/* Pair of words copied as a unit. */
#ifndef HST_WORD_PAIR_H
#define HST_WORD_PAIR_H

#include "hst/types.h"

typedef struct WordPair {
  u32 first;    /* 0x00 */
  u32 second;   /* 0x04 */
} WordPair;

#endif
