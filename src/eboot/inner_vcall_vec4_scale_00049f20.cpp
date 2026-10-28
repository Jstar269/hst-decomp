/* HSTMATCH module=EBOOT.BIN start=0x00049f20 end=0x00049fbc symbol=FUN_00049f20 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4
{
    float x, y, z, w;
};

struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float *v4();
    char pad0[132];
    float scale;
};

struct Outer
{
    Inner *inner;
    int pad04;
    int state;
    int pad0c;
    int index;
};

extern "C" void FUN_00022498(Vec4 *out, const Vec4 *a, float s);

extern "C" int FUN_00049f20(Outer *self, Vec4 *out)
{
    if (self->state >= 0)
    {
        float *base = self->inner->v4();
        Vec4 *src = (Vec4 *)((char *)base + (self->index << 6) + 48);
        out->x = src->x;
        out->y = src->y;
        out->z = src->z;
        out->w = src->w;
        FUN_00022498(out, out, self->inner->scale);
        out->w = 1.0f;
        return 1;
    }
    return 0;
}
