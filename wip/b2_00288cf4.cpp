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
    virtual void v10();
    virtual int state();
};

static inline bool Active(Obj *o)
{
    return o->state() == 2 || o->state() == 3;
}

extern "C" void FUN_00288cf4(Obj *self)
{
    char local[36];

    if (Active(self)) {
        void *base = Active(self) ? (char *)self - 0xe0 : 0;

        FUN_0012a254(base, 0, -1, 0);
    }
    if (*(int *)((char *)self + 4) != 0) {
        FUN_0014c214(local, *(int *)((char *)self + 4), *(int *)((char *)self + 0x3c), self);
        FUN_0014c914(*(int *)((char *)self + 0xc), local);
        FUN_0014c820(local, -1);
    }
}
// near miss from lane ds9 (unreviewed)
