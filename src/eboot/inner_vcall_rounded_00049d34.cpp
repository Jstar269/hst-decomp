/* HSTMATCH module=EBOOT.BIN start=0x00049d34 end=0x00049da4 symbol=FUN_00049d34 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float *v4();
};

struct Outer
{
    Inner *inner;
    int pad04;
    int state;
    int pad0c;
    int pad10;
    int index;
    int other;
};

extern "C" int FUN_00049d34(Outer *self)
{
    int n = 0;
    if (self->state >= 0 && self->other >= 0)
    {
        float *base = self->inner->v4();
        n = (int)(0.5f - *(float *)((char *)base + (self->index << 6) + 48));
    }
    return n;
}
