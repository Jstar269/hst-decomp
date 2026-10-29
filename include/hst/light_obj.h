/* Light controller object (the 0x17e5xx-0x17eaxx sources) and the start of the shared camera/light globals block. */
#ifndef HST_LIGHT_OBJ_H
#define HST_LIGHT_OBJ_H

#include "hst/types.h"
#include "hst/vec.h"

#define LIGHT_SUB_SIZE 0x2c0 /* size of each embedded sub-object */

typedef struct LightObj {
  const void *vtable;               /* 0x00 */
  char pad04[0xc];
  char sub10[LIGHT_SUB_SIZE];       /* 0x10 */
  float progress;                   /* 0x2d0 fade progress, 0 to 1 */
  u8 active;                        /* 0x2d4 progress is advancing */
  char pad2d5[0xb];
  char sub2e0[LIGHT_SUB_SIZE];      /* 0x2e0 */
  Float4 pos;                       /* 0x5a0 */
} LightObj;

/* Start of the global block the light code writes its vectors into. */
typedef struct CameraPose {
  char pad00[0x1d0];
  Float4 pos;                       /* 0x1d0 */
  Float4 at;                        /* 0x1e0 */
} CameraPose;

#endif
