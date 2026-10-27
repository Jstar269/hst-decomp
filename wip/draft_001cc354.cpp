/* HSTMATCH module=EBOOT.BIN start=0x001cc354 end=0x001cc510 symbol=FUN_001cc354 lang=c++ */
struct Names { char **items; int count; };
struct Table { int pad0; int count; int *info; Names *names; };
struct VObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual int State();
};
struct Slot {
    char pad0[0x20];
    int h20;
    int f24;
    char pad28[0x34 - 0x28];
    char buf34[0x5c - 0x34];
    VObj *owner;
    char pad60[3];
    unsigned char b63;
    unsigned char b64;
    char pad65[3];
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
};
struct Self {
    char pad0[0x98];
    VObj *obj;
    char pad9c[0xc0 - 0x9c];
    int idx;
    char padc4[0x15c - 0xc4];
    Slot *slot;
};

extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern int DAT_0034a10c;
extern char DAT_002eab78[];
extern "C" void FUN_000143b0(char *, const char *, int);
extern "C" void FUN_0018a950(int, char *);
extern "C" Table *FUN_0018c9f4(int);
extern "C" void FUN_001cd88c(Slot *, int, int);
extern "C" void FUN_00229470(char *, int, char *);
extern "C" int FUN_002294f4(char *, int, char *, int);
extern "C" void FUN_002297d8(char *, char *, int);

extern "C" void FUN_001cc354(Self *self, int arg)
{
    char text[256];
    Table *t = FUN_0018c9f4(0xc);
    int i = self->idx;
    char *name;
    if (t->count == 0) {
        name = &DAT_002c0e20;
    } else if (t->info[2] < 1) {
        name = &DAT_002c0e1c;
    } else if (i < 0 || i >= t->names->count) {
        name = &DAT_002c0e18;
    } else {
        name = t->names->items[i];
    }
    FUN_000143b0(text, DAT_002eab78, arg);
    FUN_00229470(self->slot->buf34, self->slot->f24, text);
    DAT_0034a10c = DAT_0034a10c * 0x343fd + 0x269ec3;
    Slot *s = self->slot;
    int h = FUN_002294f4(s->buf34, s->f24, text, 0);
    if (h != 0) {
        s->b63 = 0;
        s->b64 = 0;
        s->f68 = h;
        s->f6c = 0;
        s->f70 = 0;
        FUN_0018a950(s->h20, name);
        FUN_001cd88c(s, 2, 1);
    }
    s->f74 = -1;
    s->f78 = -1;
    FUN_002297d8(s->buf34, text, 0);
    VObj *o = self->obj;
    if (o != 0) {
        bool hit = o->State() == 2;
        if (!hit)
            hit = o->State() == 3;
        if (hit)
            self->slot->owner = self->obj;
    }
}
// lane wf20261026-e01-03 (rewritten in C++ from fm9's 74-word C draft): 7 words left, pure temp colouring of the
// name lookup: retail idx in a3 and the names pointer in v1, ours a1/a0. Fixes that got here: int LCG global
// (DAT_0034a10c), virtual State() at slot 11, `i >= count` (slt v0). Tried: inline NameAt() helper (18),
// names via comma local (7), `*(items + i)` (7), `count <= i` (8, slt at).
// near miss from lane wf20261026-e01-03 (unreviewed)
