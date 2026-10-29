/* Object made of three growable arrays (of different element types) and a trailing word. */
#ifndef HST_VEC_TRIPLE_H
#define HST_VEC_TRIPLE_H

#include "hst/vec_reserve.h"

typedef struct VecTriple {
  RawVec first;               /* 0x00 */
  RawVec second;              /* 0x0c */
  RawVec third;               /* 0x18 */
  int unk24;                  /* 0x24 */
} VecTriple;

#endif
