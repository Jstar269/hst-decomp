/* Object with a "disabled" byte that gates its per-frame update; shared by its enable/disable helpers. */
#ifndef HST_PAUSABLE_OBJ_H
#define HST_PAUSABLE_OBJ_H

#include "hst/types.h"

typedef struct PausableObj {
    char pad00[0x54];
    u8 disabled;            /* 0x54 nonzero while the per-frame update is skipped */
    char pad55[0x90 - 0x55];
    u32 unk90;              /* 0x90 */
    char pad94[0x9c - 0x94];
    u32 unk9c;              /* 0x9c */
} PausableObj;

#endif
