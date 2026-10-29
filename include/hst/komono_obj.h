/* Lobby komono object: a loaded model stream plus the model holder that shows it. */
#ifndef HST_KOMONO_OBJ_H
#define HST_KOMONO_OBJ_H

#include "hst/model_holder.h"

typedef struct KomonoObj {
  void *vtable;               /* 0x00 */
  char pad04[0x70 - 4];
  I3rStream *stream;          /* 0x70 owned */
  void *unk74;                /* 0x74 owned, released with a delete flag */
  ModelHolder *sub;           /* 0x78 owned */
  int target;                 /* 0x7c */
  int unk80;                  /* 0x80 -1 when unset */
} KomonoObj;

#endif
