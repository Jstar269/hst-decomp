/* HSTMATCH module=hstp_trans_main.prx start=0x002726ac end=0x00272840 symbol=FUN_002726ac lang=c99 */
/* Clone of src/eboot/reset_target_items_00261884.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-decompiled: declaration order vy/vx/t, 4x4 float matrix copy from DAT_002cc260 with null-checked offset, -240.0f translation store, 3-iteration do-while loop; exact match verified. */

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Mat4 {
    Vec4 r0, r1, r2, r3;
} Mat4;

typedef struct Target {
    int pad0;
    short x;
    short y;
    short sum_x;
    short sum_y;
} Target;

typedef struct FloatTarget {
    char pad[0x60];
    float fx;
    float fy;
} FloatTarget;

typedef struct Item {
    Target *target;
    FloatTarget *f4;
    short val_x;
    short val_y;
    char pad[0x20 - 12];
    char inner[0x30];
    Mat4 matrix;
    char pad3[240 - 0x90];
} Item;

typedef struct Context {
    Item items[3];
    int pad[2];
    int f2d8;
} Context;

extern Mat4 DAT_002cc260;
extern void FUN_00108558(void *p);

void FUN_002726ac(Context *param_1)
{
    unsigned int i = 0;
    Item *item = param_1->items;
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

        item->f4->fx = (float)(int)item->val_x;
        item->f4->fy = (float)(int)item->val_y;

        if (m != 0) {
            m = (Mat4 *)((char *)m + 48);
        }
        m->r0 = DAT_002cc260.r0;
        m->r1 = DAT_002cc260.r1;
        m->r2 = DAT_002cc260.r2;
        m->r3 = DAT_002cc260.r3;

        *(int *)((char *)item + 128) = -0x3c900000;
        FUN_00108558(&item->inner);
        i++;
        item++;
    } while (i < 3);
    param_1->f2d8 = 0;
}
