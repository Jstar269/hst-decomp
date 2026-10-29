/* HSTMATCH module=EBOOT.BIN start=0x0023c338 end=0x0023c520 symbol=FUN_0023c338 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: FUN_00216e70 returns a one-word Color by value (hidden pointer in a0) and the word is read straight off the call's temporary (`F(..).Get()`); naming the result in a local folds the load to sp-relative and adds the lwc1/swc1 struct copy. */

struct VBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct QuadData {
    int x0;
    int x1;
    int x2;
    int x3;
    int y0;
    int y1;
    int y2;
    int y3;
};

struct Obj {
    char pad[4];
    VBase *sub4;
    char pad2[0x14c4 - 8];
    QuadData quads[18];
    char pad3[0x1744 - (0x14c4 + 18 * sizeof(QuadData))];
    unsigned char flag_1744;
    char pad4[3];
    void *tex_1748;
    char pad5[4];
    VBase *sub_1750;
};

struct Color {
    int rgba;
    int Get() const { return rgba; }
};

extern "C" {
void FUN_00051490(void *tex, int, int, int w, int h, int, int);
const int *FUN_00238d64();
Color FUN_00216e70(const int *rgb, int alpha);
void FUN_00052154(float, float, float, float, float, float, float, float, float, void *tex, int, int, int);
void FUN_00051b5c(float, float, float, float, float, float, void *tex, int, int);
void FUN_0005185c(void *tex);
}

extern "C" void FUN_0023c338(Obj *self)
{
    self->sub4->m3();
    if (self->sub_1750 != 0) {
        self->sub_1750->m3();
    }
    if (self->flag_1744 == 0)
        return;

    FUN_00051490(self->tex_1748, 0, 0, 480, 272, 0, 0);

    int c1 = FUN_00216e70(FUN_00238d64() + 3, 0x50).Get();
    int c2 = FUN_00216e70(FUN_00238d64(), 0xff).Get();

    for (int i = 0; i < 18; ++i) {
        QuadData *q = &self->quads[i];
        FUN_00052154((float)q->x0, (float)q->y0, 65280.0f,
                     (float)q->x1, (float)q->y1, 65280.0f,
                     (float)q->x2, (float)q->y2, 65280.0f,
                     self->tex_1748, c1, c1, c1);

        FUN_00052154((float)q->x0, (float)q->y0, 65280.0f,
                     (float)q->x2, (float)q->y2, 65280.0f,
                     (float)q->x3, (float)q->y3, 65280.0f,
                     self->tex_1748, c1, c1, c1);

        FUN_00051b5c((float)q->x0, (float)q->y0, 65280.0f,
                     (float)q->x3, (float)q->y3, 65280.0f,
                     self->tex_1748, c2, c2);
    }

    FUN_0005185c(self->tex_1748);
}
// near miss from lane s10171846g1r1-0 (unreviewed)
