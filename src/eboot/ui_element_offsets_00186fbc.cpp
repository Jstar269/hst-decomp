/* HSTMATCH module=EBOOT.BIN start=0x00186fbc end=0x00187114 symbol=FUN_00186fbc lang=c++ */
/* Hand-written reconstruction from the disassembly (lane ds10 near miss reworked, layout shared with 0x00187114); exact match verified; names and types await human review. */
#include "hst/slide_screen.h"

struct Cfg {
    char pad[0x3d];
    unsigned char flag;
};
struct Info {
    char pad[0x64];
    int t;
};
extern "C" Info *FUN_0016bc7c();
extern "C" Cfg *FUN_0016bc70();
extern "C" void FUN_002177d4(SlideItem *item, int from_x, int from_y, int to_x, int to_y, int delay);

/* Starts every element sliding in from off screen, staggering the start delay per element. */
extern "C" void FUN_00186fbc(SlideScreen *self) {
    int delay = FUN_0016bc7c()->t;
    if (FUN_0016bc70()->flag != 0) {
        FUN_002177d4(&self->items[1], self->items[1].x2 - SLIDE_SCREEN_WIDTH, self->items[1].y2, self->items[1].x2, self->items[1].y2, 5);
    } else {
        FUN_002177d4(&self->items[0], self->items[0].x - SLIDE_SCREEN_WIDTH, self->items[0].y, self->items[0].x, self->items[0].y, 5);
    }
    FUN_002177d4(&self->items[2], self->items[2].x - SLIDE_SCREEN_WIDTH, (int)self->pos20->y, self->items[2].x, (int)self->pos20->y, delay);
    FUN_002177d4(&self->items[5], self->items[5].x - SLIDE_SCREEN_WIDTH, self->items[5].y, self->items[5].x, self->items[5].y, delay);
    FUN_002177d4(&self->items[3], self->items[3].x - SLIDE_SCREEN_WIDTH, self->items[3].y, self->items[3].x, self->items[3].y, delay + 4);
    FUN_002177d4(&self->items[4], (int)self->pos28->x - SLIDE_SCREEN_WIDTH, self->items[4].y, (int)self->pos28->x, self->items[4].y, delay + 4);
    FUN_002177d4(&self->items[6], self->items[6].x + SLIDE_SCREEN_WIDTH, self->items[6].y, self->items[6].x, self->items[6].y, delay);
    FUN_002177d4(&self->items[7], self->items[7].x + SLIDE_SCREEN_WIDTH, self->items[7].y, self->items[7].x, self->items[7].y, delay + 3);
    FUN_002177d4(&self->items[8], self->items[8].x + SLIDE_SCREEN_WIDTH, self->items[8].y, self->items[8].x, self->items[8].y, delay + 4);
}
