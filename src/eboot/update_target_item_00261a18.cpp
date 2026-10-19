/* HSTMATCH module=EBOOT.BIN start=0x00261a18 end=0x00261bbc symbol=FUN_00261a18 lang=c++ */
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
extern const int DAT_002ca818[];
extern const M4 DAT_002bc410;
void FUN_000ffb3c(Target *, int);
void FUN_00102c54(void *);
}

extern "C" void FUN_00261a18(Context *param_1, int param_2)
{
    Item *item = (Item *)((char *)param_1 + DAT_002ca818[param_2] * 0xf0);
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

    FUN_000ffb3c(item->target, 0);
    item->f4->v1(0);

    M4 *m = (M4 *)&item->inner;
    if (m != 0) {
        m = (M4 *)((char *)m + 48);
    }
    *m = DAT_002bc410;

    FUN_00102c54(&item->inner);
}
