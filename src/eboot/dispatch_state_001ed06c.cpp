/* HSTMATCH module=EBOOT.BIN start=0x001ed06c end=0x001ed1dc symbol=FUN_001ed06c lang=c++ rodata=0x2c8dd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00338c20;
struct Ret {
    char pad[0x4c];
    int f4c;                /* 0x4c */
};
extern "C" Ret *FUN_000fb810(int);
extern "C" void FUN_001ec564(void *, int, int);
extern "C" int FUN_001fcef4(void *);

/* Updatable part with virtual methods; slot 3 is called here. */
struct Part {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

enum { KIND_LIST = 0, KIND_AUX = 1, KIND_NONE = 2 };

struct Obj {
    Part *main;             /* 0x00 */
    Part *aux;              /* 0x04 */
    Part **list;            /* 0x08 first part of the kind-0 list */
    int state;              /* 0x0c */
    int kind;               /* 0x10 selects which extra part is updated */
    int unk14;              /* 0x14 */
    int unk18;              /* 0x18 */
    unsigned char unk1c;    /* 0x1c */
    unsigned char unk1d;    /* 0x1d */
    unsigned char unk1e;    /* 0x1e checked before updating the aux part */
};

/* Per-frame dispatch on state: in states 3 and 4, when the queried record's field 0x4c is 5, a transition call
   is made; in states 0-2 and 5-7 the main part and then the part chosen by kind are updated. */
extern "C" void FUN_001ed06c(Obj *self) {
    switch (self->state) {
    case 3:
        if (FUN_000fb810(DAT_00338c20)->f4c == 5) FUN_001ec564(self, 0, 1);
        break;
    case 4:
        if (FUN_000fb810(DAT_00338c20)->f4c == 5) FUN_001ec564(self, 0, 1);
        break;
    }
    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
        self->main->m3();
        switch (self->kind) {
        case KIND_LIST:
            (*self->list)->m3();
            break;
        case KIND_AUX:
            if (self->unk1e == 0) self->aux->m3();
            break;
        case KIND_NONE:
            break;
        }
        if (self->unk1c == 0 && self->kind != KIND_NONE) {
            FUN_001fcef4(FUN_000fb810(DAT_00338c20));
        }
        break;
    case 3:
    case 4:
    case 8:
    case 9:
    case 10:
        break;
    }
}
