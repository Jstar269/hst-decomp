/* Object that tracks which side currently owns it (with a priority) and two action codes. */
#ifndef HST_ACTION_PAIR_OBJ_H
#define HST_ACTION_PAIR_OBJ_H

#include "hst/types.h"

#define ACTION_SLOT_COUNT 2     /* action codes stored in the object */

typedef struct ActionPairObj {
    char pad00[0x2d0];
    int side;                           /* 0x2d0 */
    int claimed_side;                   /* 0x2d4 */
    int priority;                       /* 0x2d8 */
    char pad2dc[0x310 - 0x2dc];
    u8 unk310;                          /* 0x310 */
    u8 unk311;                          /* 0x311 */
    char pad312[2];
    int action[ACTION_SLOT_COUNT];      /* 0x314 */
} ActionPairObj;

#endif
