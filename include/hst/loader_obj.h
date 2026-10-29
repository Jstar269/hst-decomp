/* Data loader object: a bundle load tracked by a loaded flag, a result flag and a use-saved-copy flag. */
#ifndef HST_LOADER_OBJ_H
#define HST_LOADER_OBJ_H

#include "hst/types.h"

typedef struct LoaderObj {
    char pad00[0x1008];
    u8 loaded;        /* 0x1008, set once the load was attempted */
    u8 result;        /* 0x1009, load succeeded */
    u8 use_save;      /* 0x100a, load from the saved copy instead of the disc */
    char pad100b[1];
    u8 unk100c;       /* 0x100c */
} LoaderObj;

#endif
