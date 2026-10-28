/* The menu object driven by the 0x2016xx-0x2019xx sources (C++ only: it has virtual widgets). */
#ifndef HST_MENU_OBJ_H
#define HST_MENU_OBJ_H

#include "hst/types.h"
#include "hst/menu_rec.h"

/* Widget with three virtual methods (slot 1 takes an int, slot 2 none). */
struct MenuWidget {
    virtual void v0();
    virtual void v1(int on);
    virtual void v2();
};

/* Object that holds a float at 0x60. */
struct MenuSub60 {
    char pad00[0x60];
    float unk60;  /* 0x60 */
};

struct MenuObj {
    char pad00[4];
    MenuWidget *w04;       /* 0x04 */
    char pad08[4];
    MenuWidget *w0c;       /* 0x0c */
    MenuSub60 *sub10;      /* 0x10 */
    MenuSub60 *sub14;      /* 0x14 */
    MenuSub60 *sub18;      /* 0x18 */
    MenuSub60 *sub1c;      /* 0x1c */
    MenuSub60 *sub20;      /* 0x20 */
    MenuWidget *w24;       /* 0x24 */
    char pad28[0x558 - 0x28];
    Cell *cell558;         /* 0x558 */
    char pad55c[0x56c - 0x55c];
    Cell *cell56c;         /* 0x56c */
    char pad570[0x708 - 0x570];
    MenuWidget *w708;      /* 0x708 */
    int counter;           /* 0x70c, wraps at MENU_COUNTER_WRAP */
    int state;             /* 0x710 */
    int timer;             /* 0x714 */
    Rec8c recs[MENU_REC_COUNT]; /* 0x718 */
};

/* Counter wrap and state machine constants. */
enum { MENU_COUNTER_WRAP = 0x20, MENU_STATE_TIMEOUT = 11 };
enum { MENU_STATE_SLIDE_IN = 1, MENU_STATE_SETTLE = 2, MENU_STATE_DONE = 3 };

#endif
