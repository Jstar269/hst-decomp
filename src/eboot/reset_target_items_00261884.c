/* HSTMATCH module=EBOOT.BIN start=0x00261884 end=0x00261a18 symbol=FUN_00261884 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-decompiled: declaration order vy/vx/t, 4x4 float matrix copy from DAT_002bc410 with null-checked offset, -240.0f translation store, 3-iteration do-while loop; exact match verified. */
#include "hst/target_items.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Mat4 {
    Vec4 r0, r1, r2, r3;
} Mat4;

extern Mat4 DAT_002bc410;
extern void FUN_00102c54(void *p);

/* Moves every item's target to the item's own value position and resets each item's matrix. */
void FUN_00261884(TargetCtx *ctx)
{
    unsigned int i = 0;
    TargetItem *item = ctx->items;
    do {
        short vy = item->val_y;
        short vx = item->val_x;
        Target *t = item->target;
        short ox = t->x;
        Mat4 *m = (Mat4 *)&item->inner;
        short dx = vx - ox;
        t->x = vx;
        t->sum_x += (short)dx;
        short oy = t->y;
        short dy = vy - oy;
        t->y = vy;
        t->sum_y += (short)dy;

        item->view->fx = (float)(int)item->val_x;
        item->view->fy = (float)(int)item->val_y;

        if (m != 0) {
            m = (Mat4 *)((char *)m + 48);
        }
        m->r0 = DAT_002bc410.r0;
        m->r1 = DAT_002bc410.r1;
        m->r2 = DAT_002bc410.r2;
        m->r3 = DAT_002bc410.r3;

        item->matrix[12] = -240.0f;
        FUN_00102c54(&item->inner);
        i++;
        item++;
    } while (i < TARGET_ITEM_COUNT);
    ctx->unk2d8 = 0;
}
