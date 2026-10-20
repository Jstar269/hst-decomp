/* HSTMATCH module=EBOOT.BIN start=0x00288cf4 end=0x00288dec symbol=FUN_00288cf4 lang=c++ */
extern "C" void FUN_0012a254(void *, int, int, int);
extern "C" void FUN_0014c214(void *, int, int, void *);
extern "C" void FUN_0014c914(int, void *);
extern "C" void FUN_0014c820(void *, int);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int state();
};

extern "C" void FUN_00288cf4(Obj *self)
{
    char local[36];

    if (self->state() == 2 || self->state() == 3) {
        void *target = (self->state() == 2 || self->state() == 3) ? (char *)self - 0xe0 : 0;

        FUN_0012a254(target, 0, -1, 0);
    }
    if (*(int *)((char *)self + 4) != 0) {
        FUN_0014c214(local, *(int *)((char *)self + 4), *(int *)((char *)self + 0x3c), self);
        FUN_0014c914(*(int *)((char *)self + 0xc), local);
        FUN_0014c820(local, -1);
    }
}
// Near miss: retail compares with xori/sltiu pairs (two calls per test) and the `self - 0xe0`
// selection is a nested pair of tests; the exact expression shape is still unknown.
// near miss from lane ds8 (unreviewed)
