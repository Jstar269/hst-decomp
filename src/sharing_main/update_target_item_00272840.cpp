/* HSTMATCH module=hstp_trans_main.prx start=0x00272840 end=0x002729e4 symbol=FUN_00272840 lang=c++ */
/* Clone of src/eboot/update_target_item_00261a18.cpp (hstclone.py tag s10172123g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct V4 {
    float x, y, z, w;
    V4() {}
};

struct M4 {
    V4 r0, r1, r2, r3;
};

struct Target {
    int pad0;
    short x;
    short y;
    short sum_x;
    short sum_y;
};

struct FloatTarget {
    virtual void v0();
    virtual void v1(int);
    char pad[0x60 - 4];
    float fx;
    float fy;
};

struct Item {
    Target *target;
    FloatTarget *f4;
    short val_x;
    short val_y;
    char pad[0x20 - 12];
    char inner[0x30];
    M4 matrix;
    char pad3[240 - 0x90];
};

struct Context {
    char pad[8];
    short val_x;
    short val_y;
};

extern "C" {
extern const int DAT_002dadd8[];
extern const M4 DAT_002cc260;
void FUN_00105470(Target *, int);
void FUN_00108558(void *);
}

extern "C" void FUN_00272840(Context *param_1, int param_2)
{
    Item *item = (Item *)((char *)param_1 + DAT_002dadd8[param_2] * 0xf0);
    short vy = param_1->val_y;
    short vx = param_1->val_x;
    Target *t = item->target;
    short ox = t->x;
    short dx = vx - ox;
    t->x = vx;
    t->sum_x += (short)dx;
    short oy = t->y;
    short dy = vy - oy;
    t->y = vy;
    t->sum_y += (short)dy;

    item->f4->fx = (float)(int)param_1->val_x;
    item->f4->fy = (float)(int)param_1->val_y;

    FUN_00105470(item->target, 0);
    item->f4->v1(0);

    M4 *m = (M4 *)&item->inner;
    if (m != 0) {
        m = (M4 *)((char *)m + 48);
    }
    *m = DAT_002cc260;

    FUN_00108558(&item->inner);
}
