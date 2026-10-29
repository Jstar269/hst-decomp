/* Layout lookup records filled by the result-screen setup functions. */
#ifndef HST_RESULT_LAYOUT_H
#define HST_RESULT_LAYOUT_H

#include "hst/types.h"
#include "hst/layout_list.h"
#include "hst/animator.h"

/* One row of a name table: a pane id followed by the entry name. */
typedef struct LayoutEnt {
    u8 id;        /* 0x00 */
    char name[32]; /* 0x01 */
} LayoutEnt;      /* size 0x21 */

/* Result of a by-name lookup (12 bytes). */
typedef struct LayoutRef {
    void *res; /* 0x0 */
    int b;     /* 0x4 */
    int a;     /* 0x8 */
} LayoutRef;

#endif
