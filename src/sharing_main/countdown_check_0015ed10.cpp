/* HSTMATCH module=hstp_trans_main.prx start=0x0015ed10 end=0x0015ed74 symbol=FUN_0015ed10 lang=c++ */
/* Clone of src/eboot/countdown_check_00152b88.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003f344c;
extern void *FUN_001d5398(void *, int, int);
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

extern "C" int FUN_0015ed10(Obj *self)
{
    if (self->count > 0) {
        self->count--;
        return 0;
    }
    Target *obj = (Target *)FUN_001d5398(DAT_003f344c, self->f4, self->f8);
    return obj != 0 ? obj->m10() : 1;
}
