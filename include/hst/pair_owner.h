/* Object that owns two heap-allocated children, created together and deleted together. */
#ifndef HST_PAIR_OWNER_H
#define HST_PAIR_OWNER_H

#include "hst/types.h"

typedef struct PairOwner {
  const void *vtable; /* 0x00 */
  char pad04[0x3c];
  void *first;        /* 0x40 first owned child */
  void *second;       /* 0x44 second owned child */
} PairOwner;

#endif
