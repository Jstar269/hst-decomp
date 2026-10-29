/* Court prop object: a state id, position and velocity vectors, a matrix, two embedded sub-objects and a bounce counter. */
#ifndef HST_COURT_PROP_H
#define HST_COURT_PROP_H

#include "hst/types.h"
#include "hst/vec.h"

typedef struct CourtProp {
  char pad00[0x3c];
  int state;            /* 0x3c */
  Float4 pos;           /* 0x40 */
  char pad50[0x10];
  char mat[0x30];       /* 0x60 matrix, rotated each step */
  Float4 unk90;         /* 0x90 copy of pos */
  char pada0[0x10];
  char unkb0[0x40];     /* 0xb0 embedded object, passed by address */
  char padf0[0x260 - 0xf0];
  char unk260[0x10];    /* 0x260 embedded object, passed by address */
  char pad270[0x430 - 0x270];
  int bounces;          /* 0x430 */
  u8 unk434;            /* 0x434 */
  u8 unk435;            /* 0x435 */
  u8 unk436;            /* 0x436 */
  char pad437[0x440 - 0x437];
  Float4 vel;           /* 0x440 velocity */
} CourtProp;

#endif
