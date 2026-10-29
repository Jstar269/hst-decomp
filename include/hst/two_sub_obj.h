/* Object with a vtable, a 0x3c-word constructor argument, a block of float constants and two owned sub-objects. */
#ifndef HST_TWO_SUB_OBJ_H
#define HST_TWO_SUB_OBJ_H

#include "hst/types.h"

typedef struct TwoSubObj {
  const void *vtable;  /* 0x00 */
  char pad04[0x38];    /* base part set up by its own constructor */
  u32 arg;             /* 0x3c constructor argument */
  char pad40[0x10];
  u32 unk50;           /* 0x50 holds the bit pattern of 1.0f */
  char pad54[0xc];
  u32 unk60;           /* 0x60 bit pattern of 128.0f */
  u32 unk64;           /* 0x64 bit pattern of 128.0f */
  u32 unk68;           /* 0x68 bit pattern of 128.0f */
  u32 unk6c;           /* 0x6c bit pattern of 64.0f */
  void *subA;          /* 0x70 owned sub-object, allocated 0x70 bytes */
  void *subB;          /* 0x74 owned sub-object, allocated 0x70 bytes */
  u32 unk78;           /* 0x78 */
} TwoSubObj;

#endif
