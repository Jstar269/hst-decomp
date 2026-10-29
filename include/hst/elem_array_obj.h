/* Object with a vtable followed by a fixed array of small constructed elements. */
#ifndef HST_ELEM_ARRAY_OBJ_H
#define HST_ELEM_ARRAY_OBJ_H

#include "hst/types.h"

#define ELEM_ARRAY_COUNT 6  /* elements in the array */
#define ELEM_ARRAY_STRIDE 0xc /* bytes per element */

typedef struct ElemArrayObj {
  u32 vtable;                                          /* 0x00 */
  char elems[ELEM_ARRAY_COUNT][ELEM_ARRAY_STRIDE];     /* 0x04 */
} ElemArrayObj;

#endif
