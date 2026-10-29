/* Stream object with a virtual base sub-object at +0x70 and the base's own layout. */
#ifndef HST_STREAM_OBJ_H
#define HST_STREAM_OBJ_H

#include "hst/types.h"

/* Virtual base of the stream: vtable, a nested member at +0x120 and the offset back to the derived object. */
typedef struct StreamBase {
  const void *vtable;     /* 0x000 */
  char pad04[0x11c];
  char member120[0x10];   /* 0x120 nested sub-object with its own constructor and destructor */
  int derived_offset;     /* 0x130 distance from the base to the derived object */
} StreamBase;             /* size 0x134 */

typedef struct StreamObj {
  StreamBase *vbase;      /* 0x00 pointer to the virtual base */
  const void *vtable;     /* 0x04 */
  int unk08;              /* 0x08 */
  int unk0c;              /* 0x0c */
  char pad10[0x58];
  int unk68;              /* 0x68 */
  u8 unk6c;               /* 0x6c */
  u8 unk6d;               /* 0x6d */
  char pad6e[2];
  StreamBase base;        /* 0x70 virtual base sub-object */
} StreamObj;

#endif
