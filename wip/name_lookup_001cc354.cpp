/* HSTMATCH module=EBOOT.BIN start=0x001cc354 end=0x001cc510 symbol=FUN_001cc354 lang=c++ */
struct StrVec {
    char **data;
    int count;
};

struct StrTable {
    int pad0;
    int f4;
    struct { int pad0, pad4, f8; } *f8;
    StrVec *vec;
};

struct Mon {
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

struct Item {
    char pad00[0x20];
    void *f20;
    char pad24[0x3f];
    char f63;
    char f64;
    char pad65[3];
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
};

struct Obj {
    char pad00[0x98];
    Mon *mon;
    char pad9c[0x24];
    int index;
    char padc4[0x98];
    Item *item;
};

extern "C" {
extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern int DAT_0034a10c;
extern char DAT_002eab78[];
void FUN_000143b0(char *, char *, ...);
void FUN_0018a950(void *, char *);
StrTable *FUN_0018c9f4(int);
void FUN_001cd88c(Item *, int, int);
void FUN_00229470(void *, void *, char *);
int FUN_002294f4(void *, void *, char *, int);
void FUN_002297d8(void *, char *, int);
}

extern "C" void FUN_001cc354(Obj *self, int arg)
{
    char buf[256];
    char *name;
    StrTable *t = FUN_0018c9f4(12);
    int idx = self->index;

    if (t->f4 == 0) {
        name = DAT_002c0e20;
    } else if (t->f8->f8 < 1) {
        name = DAT_002c0e1c;
    } else if (idx < 0 || idx >= t->vec->count) {
        name = DAT_002c0e18;
    } else {
        name = t->vec->data[idx];
    }
    FUN_000143b0(buf, DAT_002eab78, arg);
    FUN_00229470((char *)self->item + 0x34, *(void **)((char *)self->item + 0x24), buf);
    DAT_0034a10c = DAT_0034a10c * 0x343fd + 0x269ec3;
    Item *item = self->item;
    int r = FUN_002294f4((void *)((int)item + 0x34), *(void **)((char *)item + 0x24), buf, 0);
    if (r != 0) {
        item->f63 = 0;
        item->f64 = 0;
        item->f68 = r;
        item->f6c = 0;
        item->f70 = 0;
        FUN_0018a950(item->f20, name);
        FUN_001cd88c(item, 2, 1);
    }
    item->f74 = -1;
    item->f78 = -1;
    FUN_002297d8((char *)item + 0x34, buf, 0);
    Mon *m = self->mon;
    if (m != 0) {
        bool ok = m->state() == 2;
        if (!ok)
            ok = m->state() == 3;
        if (ok)
            *(Mon **)((char *)self->item + 0x5c) = self->mon;
    }
}

// lane sx4: 7 of 111 words differ (+0x2c..): only the temporaries of the name lookup: ours idx=a1, vec=a0; retail idx=a3, vec=v1 (a0-a2 avoided).
// Natural C++ rewrite: DAT_0034a10c is an int LCG (mult/mflo, not float), calls through a 12-slot virtual class (slot 11 = lw t9,52(t9)); item sub-object address
// must not be CSE'd: the second call spells it `(void*)((int)item + 0x34)`, the others `(char*)item + 0x34` (matching idiom).
// Ruled out: inline Lookup helper (plain/ternary), idx/vec locals, self->index re-read (99 off), non-variadic sprintf prototype, extra unused params, load order idx/table.
// near miss from lane sx4 (unreviewed)
