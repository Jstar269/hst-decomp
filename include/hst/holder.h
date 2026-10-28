/* Polymorphic holder with two 12-byte member objects (used by its constructor and destructors). */
#ifndef HST_HOLDER_H
#define HST_HOLDER_H

#include "hst/types.h"

typedef struct HolderBase {
  void *vptr;       /* 0x00 */
  u32 unk04;        /* 0x04 */
  u32 member08[3];  /* 0x08 sub-object destroyed by FUN_00165840 */
} HolderBase;       /* size 0x14 */

typedef struct HolderDerived {
  HolderBase base;  /* 0x00 */
  u32 member14[3];  /* 0x14 sub-object destroyed by FUN_00236fe8 */
} HolderDerived;    /* size 0x20 */

#endif
