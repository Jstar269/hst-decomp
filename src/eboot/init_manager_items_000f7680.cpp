/* HSTMATCH module=EBOOT.BIN start=0x000f7680 end=0x000f78ac symbol=FUN_000f7680 lang=c++ */
/* Clone of src/sharing_main/init_manager_items_000fcd74.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Obj;
struct Vec3 { float x, y, z; };
struct Item {
    Vec3 a;
    int pad12;
    Vec3 b;
    float f28;
    int f32;
    int f36;
    unsigned char f40;
    Item()
    {
        a.x = 0; a.y = 0; a.z = 0;
        b.x = 0; b.y = 0; b.z = 0;
        f28 = 1.0f;
        f32 = 1;
        f36 = 3;
        f40 = 0;
    }
} __attribute__((aligned(16)));

struct PtrVec {
    Obj **data;
    unsigned size;
    unsigned cap;
    Obj *&at(unsigned i) { return data[i]; }
    Obj *&back() { return at(size - 1); }
};
struct ItemVec {
    Item **data;
    unsigned size;
    unsigned cap;
    Item *&operator[](unsigned i) { return data[i]; }
};
struct Mgr {
    int f0;
    PtrVec objs;
    char pad1[0x830 - 0x10];
    ItemVec items;
    float f83c, f840, f844, f848, f84c, f850, f854, f858;
    int f85c;
    float f860, f864, f868, f86c;
};

extern "C" {
extern char DAT_002d8204[];
void *FUN_00000bcc(unsigned);
Obj *FUN_00050fc0(void *);
void FUN_000511c4(Obj *, void *, int);
void FUN_0006ea5c(PtrVec *, Obj **, Tag);
Mgr *FUN_000f6400(Mgr *);
void FUN_000f6774(Mgr *, int);
}

extern "C" Mgr *FUN_000f7680(Mgr *self)
{
    FUN_000f6400(self);
    Obj *mem = (Obj *)FUN_00000bcc(0x48);
    if (mem) mem = FUN_00050fc0(mem);
    Obj *o = mem;
    FUN_000511c4(o, DAT_002d8204, 0);
    if (self->objs.size < self->objs.cap) {
        self->objs.size++;
        self->objs.back() = o;
    } else {
        FUN_0006ea5c(&self->objs, &o, Tag());
    }
    FUN_000f6774(self, 4);
    Item items[4];
    items[0].a.z = 30.0f;
    items[3].a.y = 10.0f;
    for (int i = 0; i < 4; i++) {
        Item *d = self->items[i];
        d->a = items[i].a;
        d->b = items[i].b;
        d->f28 = items[i].f28;
        d->f32 = items[i].f32;
        d->f36 = items[i].f36;
        d->f40 = items[i].f40;
    }
    self->f83c = 20.0f;
    self->f840 = 0.0f;
    self->f844 = 0.0f;
    self->f848 = 0.6f;
    self->f84c = 1.2f;
    self->f850 = 0.6f;
    self->f854 = 5.0f;
    self->f858 = 20.0f;
    self->f860 = 128.0f;
    self->f864 = 64.0f;
    self->f868 = 64.0f;
    self->f86c = 32.0f;
    return self;
}
