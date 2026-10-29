/* HSTMATCH module=EBOOT.BIN start=0x00261a18 end=0x00261bbc symbol=FUN_00261a18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/target_items.h"

struct V4 {
    float x, y, z, w;
    V4() {}
};

struct M4 {
    V4 r0, r1, r2, r3;
};

/* Virtual view of the target view: slot 1 takes an int. */
struct TargetViewVirt {
    virtual void v0();
    virtual void v1(int);
};

extern "C" {
extern const int DAT_002ca818[];
extern const M4 DAT_002bc410;
void FUN_000ffb3c(Target *, int);
void FUN_00102c54(void *);
}

/* Moves one item (chosen through the index table) to the context's current position and resets its matrix. */
extern "C" void FUN_00261a18(TargetCtx *ctx, int which)
{
    TargetItem *item = (TargetItem *)((char *)ctx + DAT_002ca818[which] * TARGET_ITEM_SIZE);
    short vy = ctx->items[0].val_y;
    short vx = ctx->items[0].val_x;
    Target *t = item->target;
    short ox = t->x;
    short dx = vx - ox;
    t->x = vx;
    t->sum_x += (short)dx;
    short oy = t->y;
    short dy = vy - oy;
    t->y = vy;
    t->sum_y += (short)dy;

    item->view->fx = (float)(int)ctx->items[0].val_x;
    item->view->fy = (float)(int)ctx->items[0].val_y;

    FUN_000ffb3c(item->target, 0);
    ((TargetViewVirt *)item->view)->v1(0);

    M4 *m = (M4 *)&item->inner;
    if (m != 0) {
        m = (M4 *)((char *)m + 48);
    }
    *m = DAT_002bc410;

    FUN_00102c54(&item->inner);
}
