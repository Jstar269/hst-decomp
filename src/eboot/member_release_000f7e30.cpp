/* HSTMATCH module=EBOOT.BIN start=0x000f7e30 end=0x000f8168 symbol=FUN_000f7e30 lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/deleting_dtor_four_holders_001ae7e8.cpp); matching idioms: every virtual-destructor member is released with if (m != 0) { delete m; m = 0; } (delete's own null test doubles the check), the two non-virtual members through a static inline Destroy() that calls the destructor with flag 0 and then operator delete after its own null test, and the two holders with an inline destructor deleting their virtual pointee; exact match verified; names and types await human review. */
extern "C" {
void FUN_001ec35c(void *, int);
void FUN_001ea854(void *, int);
void FUN_000f64d8(void *, int);
void FUN_00000a00(void *);
}

/* Polymorphic member with a virtual destructor. */
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

/* Owner: members from 0x54 on, all released by this function (the last two only when release_all is set). */
struct Obj {
    char pad0[0x54];
    VC *unk54;
    VC *unk58;
    VC *unk5c;
    VC *unk60;
    VC *unk64;
    VC *unk68;
    VC *unk6c;
    VC *unk70;
    VC *unk74;
    VC *unk78;
    HolderP8 *unk7c;
    HolderP4 *unk80;
    VC *unk84;
    VC *unk88;
    B_000f64d8 *unk8c;
    B_000f64d8 *unk90;
    void *unk94;
    void *unk98;
};

/* Releases every owned member and clears its pointer. */
extern "C" void FUN_000f7e30(Obj *self, int release_all)
{
    if (self->unk94 != 0) {
        FUN_001ec35c(self->unk94, 1);
        self->unk94 = 0;
    }
    if (self->unk8c != 0) {
        Destroy(self->unk8c);
        self->unk8c = 0;
    }
    if (self->unk88 != 0) {
        delete self->unk88;
        self->unk88 = 0;
    }
    if (self->unk70 != 0) {
        delete self->unk70;
        self->unk70 = 0;
    }
    if (self->unk6c != 0) {
        delete self->unk6c;
        self->unk6c = 0;
    }
    if (self->unk74 != 0) {
        delete self->unk74;
        self->unk74 = 0;
    }
    if (self->unk78 != 0) {
        delete self->unk78;
        self->unk78 = 0;
    }
    if (self->unk7c != 0) {
        delete self->unk7c;
        self->unk7c = 0;
    }
    if (self->unk80 != 0) {
        delete self->unk80;
        self->unk80 = 0;
    }
    if (self->unk68 != 0) {
        delete self->unk68;
        self->unk68 = 0;
    }
    if (self->unk5c != 0) {
        delete self->unk5c;
        self->unk5c = 0;
    }
    if (self->unk60 != 0) {
        delete self->unk60;
        self->unk60 = 0;
    }
    if (self->unk64 != 0) {
        delete self->unk64;
        self->unk64 = 0;
    }
    if (self->unk58 != 0) {
        delete self->unk58;
        self->unk58 = 0;
    }
    if (self->unk54 != 0) {
        delete self->unk54;
        self->unk54 = 0;
    }
    if (self->unk84 != 0) {
        delete self->unk84;
        self->unk84 = 0;
    }
    if (release_all != 0) {
        if (self->unk90 != 0) {
            Destroy(self->unk90);
            self->unk90 = 0;
        }
        if (self->unk98 != 0) {
            FUN_001ea854(self->unk98, 1);
            self->unk98 = 0;
        }
    }
}
