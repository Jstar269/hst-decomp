/* Info message layout: a vtable object holding two text panes that scroll as a ticker. */
#ifndef HST_MESSE_LAYOUT_H
#define HST_MESSE_LAYOUT_H

#include "hst/types.h"

/* Ticker states of MesseLayout.state. */
enum {
    MESSE_WAIT = 0,    /* parked off screen, counting down */
    MESSE_EASE_IN = 1, /* easing towards its rest position */
    MESSE_HOLD = 2,    /* resting until the timer expires */
    MESSE_SCROLL = 3   /* scrolling left each frame */
};

/* A text pane of the layout (only the touched fields are named). */
typedef struct MessePane {
    char pad00[0x60];
    float x;          /* 0x60 */
    float y;          /* 0x64 */
    char pad68[0xf8 - 0x68];
    u8 *unkf8;        /* 0xf8 */
    short pos_x;      /* 0xfc */
    short pos_y;      /* 0xfe */
    short unk100;     /* 0x100 moves with pos_x */
    short unk102;     /* 0x102 moves with pos_y */
    char pad104[4];
    float unk108;     /* 0x108 */
    float unk10c;     /* 0x10c */
    char pad110[0x138 - 0x110];
    u32 unk138;       /* 0x138 */
    u32 unk13c;       /* 0x13c set to 1.0f */
    u32 unk140;       /* 0x140 */
    char pad144[0x14c - 0x144];
    volatile u8 flag; /* 0x14c */
} MessePane;

typedef struct MesseLayout {
    u32 *vtable;      /* 0x00 */
    char pad04[0x54 - 4];
    u8 *unk54;        /* 0x54 */
    MessePane *text0; /* 0x58 */
    MessePane *text1; /* 0x5c */
    int state;        /* 0x60 */
    u32 unk64;        /* 0x64 */
    int timer;        /* 0x68 countdown in frames */
    float pos0;       /* 0x6c scroll position of text0 */
    float pos1;       /* 0x70 scroll position of text1 */
    float gap;        /* 0x74 */
    float width;      /* 0x78 */
} MesseLayout;

#endif
