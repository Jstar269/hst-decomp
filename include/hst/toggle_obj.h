/* Object with an on/off byte that records the last switch state. */
#ifndef HST_TOGGLE_OBJ_H
#define HST_TOGGLE_OBJ_H

#include "hst/types.h"

typedef struct ToggleObj {
  char pad00[0x78];
  u8 off;                     /* 0x78 1 when the last update turned the state off */
} ToggleObj;

#endif
