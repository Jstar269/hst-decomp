/* HSTMATCH module=EBOOT.BIN start=0x00049ec4 end=0x00049f20 symbol=FUN_00049ec4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g1) corrected by hand: a real virtual call on the object at offset 0 (this in a0, the callee through t9), positive test first so the -1.0f arm stays out of line; exact match verified; names and types await human review. */
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
};

extern "C" float FUN_00049ec4(Outer *self)
{
    if (self->state >= 0)
        return -*(float *)((char *)self->inner->v4() + (self->index << 6) + 20);
    return -1.0f;
}
