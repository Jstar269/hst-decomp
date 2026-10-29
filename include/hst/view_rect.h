/* Pane rectangle and the view parameter block that is centred on it. */
#ifndef HST_VIEW_RECT_H
#define HST_VIEW_RECT_H

#include "hst/types.h"

typedef struct PaneRect {
    char pad[4];
    short left;         /* 0x4 */
    short top;          /* 0x6 */
    short right;        /* 0x8 */
    short bottom;       /* 0xa */
} PaneRect;

/* View object returned by the view lookup; only the setup words are named. */
typedef struct ViewWords {
    char pad[0x1d0];
    u32 words[0x11];    /* 0x1d0 */
} ViewWords;

/* Indices and raw values written into ViewWords::words when centring a view. */
enum {
    VIEW_WORD_MODE_A = 0xf,
    VIEW_WORD_MODE_B = 0x10,
    VIEW_MODE_A_VALUE = 0xff10,
    VIEW_MODE_B_VALUE = 0xf100
};

#endif
