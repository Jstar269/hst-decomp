/* Small object that owns a 0x40-byte buffer (constructor and destructor). */
#ifndef HST_BUFFER_OBJ_H
#define HST_BUFFER_OBJ_H

#include "hst/types.h"

#define BUFFER_OBJ_BUFFER_SIZE 0x40  /* bytes allocated for the buffer */

typedef struct BufferObj {
  const void *vtable;  /* 0x00 */
  void *buffer;        /* 0x04 allocated by the constructor, freed by the destructor */
  u32 unk8;            /* 0x08 constructor argument */
  u32 unkc;            /* 0x0c */
  u32 unk10;           /* 0x10 */
} BufferObj;

#endif
