/* HSTMATCH module=EBOOT.BIN start=0x00152b88 end=0x00152bec symbol=FUN_00152b88 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_0034a114;
extern void *FUN_001c6f70(void *, int, int);
}

struct Target {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual int m10();
};

struct Obj {
    int pad0;
    int f4;
    int f8;
    int count;
};

extern "C" int FUN_00152b88(Obj *self)
{
    if (self->count > 0) {
        self->count--;
        return 0;
    }
    Target *obj = (Target *)FUN_001c6f70(DAT_0034a114, self->f4, self->f8);
    return obj != 0 ? obj->m10() : 1;
}
