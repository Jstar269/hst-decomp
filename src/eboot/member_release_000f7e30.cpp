/* HSTMATCH module=EBOOT.BIN start=0x000f7e30 end=0x000f8168 symbol=FUN_000f7e30 lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/deleting_dtor_four_holders_001ae7e8.cpp); matching idioms: every virtual-destructor member is released with if (m != 0) { delete m; m = 0; } (delete's own null test doubles the check), the two non-virtual members through a static inline Destroy() that calls the destructor with flag 0 and then operator delete after its own null test, and the two holders with an inline destructor deleting their virtual pointee; exact match verified; names and types await human review. */
extern "C" {
void FUN_001ec35c(void *, int);
void FUN_001ea854(void *, int);
void FUN_000f64d8(void *, int);
void FUN_00000a00(void *);
}

struct VC {
    virtual ~VC();
};

struct B_000f64d8;

static inline void Destroy(B_000f64d8 *p)
{
    if (p != 0) {
        FUN_000f64d8(p, 0);
        FUN_00000a00(p);
    }
}

struct HolderP8 {
    int a, b;
    VC *obj;
    ~HolderP8()
    {
        if (obj != 0) {
            delete obj;
            obj = 0;
        }
    }
};

struct HolderP4 {
    int a;
    VC *obj;
    ~HolderP4()
    {
        if (obj != 0) {
            delete obj;
            obj = 0;
        }
    }
};

struct Obj {
    char pad0[0x54];
    VC *m54;
    VC *m58;
    VC *m5c;
    VC *m60;
    VC *m64;
    VC *m68;
    VC *m6c;
    VC *m70;
    VC *m74;
    VC *m78;
    HolderP8 *m7c;
    HolderP4 *m80;
    VC *m84;
    VC *m88;
    B_000f64d8 *m8c;
    B_000f64d8 *m90;
    void *m94;
    void *m98;
};

extern "C" void FUN_000f7e30(Obj *self, int param_2)
{
    if (self->m94 != 0) {
        FUN_001ec35c(self->m94, 1);
        self->m94 = 0;
    }
    if (self->m8c != 0) {
        Destroy(self->m8c);
        self->m8c = 0;
    }
    if (self->m88 != 0) {
        delete self->m88;
        self->m88 = 0;
    }
    if (self->m70 != 0) {
        delete self->m70;
        self->m70 = 0;
    }
    if (self->m6c != 0) {
        delete self->m6c;
        self->m6c = 0;
    }
    if (self->m74 != 0) {
        delete self->m74;
        self->m74 = 0;
    }
    if (self->m78 != 0) {
        delete self->m78;
        self->m78 = 0;
    }
    if (self->m7c != 0) {
        delete self->m7c;
        self->m7c = 0;
    }
    if (self->m80 != 0) {
        delete self->m80;
        self->m80 = 0;
    }
    if (self->m68 != 0) {
        delete self->m68;
        self->m68 = 0;
    }
    if (self->m5c != 0) {
        delete self->m5c;
        self->m5c = 0;
    }
    if (self->m60 != 0) {
        delete self->m60;
        self->m60 = 0;
    }
    if (self->m64 != 0) {
        delete self->m64;
        self->m64 = 0;
    }
    if (self->m58 != 0) {
        delete self->m58;
        self->m58 = 0;
    }
    if (self->m54 != 0) {
        delete self->m54;
        self->m54 = 0;
    }
    if (self->m84 != 0) {
        delete self->m84;
        self->m84 = 0;
    }
    if (param_2 != 0) {
        if (self->m90 != 0) {
            Destroy(self->m90);
            self->m90 = 0;
        }
        if (self->m98 != 0) {
            FUN_001ea854(self->m98, 1);
            self->m98 = 0;
        }
    }
}
