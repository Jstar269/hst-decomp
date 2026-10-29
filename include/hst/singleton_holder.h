/* Holder object of the global singleton: the object it creates, a pending state and a flag. */
#ifndef HST_SINGLETON_HOLDER_H
#define HST_SINGLETON_HOLDER_H

#include "hst/types.h"

/* Value of `pending` that makes the holder notify its target when it is cleared. */
#define HOLDER_PENDING_SET 1

typedef struct SingletonHolder {
  void *target;       /* 0x00 object created with the holder's flag, destroyed with it */
  int pending;        /* 0x04 */
  u8 flag;            /* 0x08 passed to the target's constructor */
} SingletonHolder;

#endif
