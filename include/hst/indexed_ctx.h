/* Singleton context view: a callback slot, a current index and the table that index selects from. */
#ifndef HST_INDEXED_CTX_H
#define HST_INDEXED_CTX_H

#include "hst/types.h"

#define INDEXED_CTX_ENTRY_NONE 4   /* entry value after which the follow-up call is skipped */

typedef struct IndexedCtx {
    char pad00[0x558];
    int (*callback)(void);    /* 0x558 */
    char pad55c[0x5b8 - 0x55c];
    int index;                /* 0x5b8, current position in entries */
    char pad5bc[0x5c0 - 0x5bc];
    int *entries;             /* 0x5c0 */
} IndexedCtx;

#endif
