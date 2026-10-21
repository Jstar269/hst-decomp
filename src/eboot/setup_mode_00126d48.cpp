/* HSTMATCH module=EBOOT.BIN start=0x00126d48 end=0x00127004 symbol=FUN_00126d48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Info {
    char pad0[0x24];
    unsigned char f24, f25, f26, f27, f28, f29, f2a, f2b;
};
struct Elem { char pad[0x1b4]; int f1b4; };
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));

struct Node8 { char pad[8]; int f8; };
struct Holder { char pad[8]; Node8 *f8; };

class Skel {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void GetPos(Vec4 *, int);
    char pad4[0x8c - 4];
    Holder *f8c;
};

class Self {
public:
    virtual void m0();
    virtual void Refresh();
    char pad4[0x50 - 4];
    Elem *f50;
    char pad54[4];
    Skel *f58;
    char pad5c[0x70 - 0x5c];
    int f70;
    char pad74[0x254 - 0x74];
    unsigned char f254;
    char pad255[0x328 - 0x255];
    float f328;
    char pad32c[0x354 - 0x32c];
    int f354;
    char pad358[4];
    int f35c;
    char pad360[4];
    unsigned char f364, f365, f366, f367, f368, f369;
};

extern int DAT_0033b4a8;
extern char DAT_002da7f0[];
extern char DAT_002da800[];

extern "C" {
void FUN_00194e20();
void FUN_00194e34(Self *, int);
void FUN_001277e8(Self *);
void FUN_0005ed18(Elem *, int, int);
void FUN_0005f030(Elem *, int, float);
Info *FUN_00193474(int);
Info *FUN_00193024(void *);
void FUN_000143b0(void *, void *);
void FUN_0019494c(Self *, void *, int, int, int, int);
int FUN_0002fe08(Node8 *);
void *FUN_0002fe18(Node8 *, int);
int FUN_00014934(void *, void *);
void FUN_00127004(Self *);
void FUN_0012a254(Self *, int, int, int);

static inline void CopyInfo(Self *s, Info *i)
{
    s->f354 = i->f24;
    s->f35c = i->f2b;
    s->f364 = i->f25;
    s->f365 = i->f26;
    s->f366 = i->f27;
    s->f367 = i->f28;
    s->f368 = i->f29;
    s->f369 = i->f2a;
}

static inline int Count(Self *s)
{
    Node8 *n = s->f58->f8c->f8;
    return n ? FUN_0002fe08(n) : 0;
}

static inline void *NameAt(Self *s, int i)
{
    Node8 *n = s->f58->f8c->f8;
    return n ? FUN_0002fe18(n, i) : 0;
}

void FUN_00126d48(Self *self, int mode, int arg)
{
    char buf[32];
    Vec4 v;
    self->f254 = mode == 0;
    if (mode == 0) {
        FUN_00194e20();
        FUN_0005ed18(self->f50, 0, self->f70);
        FUN_0005f030(self->f50, 0, 0.0f);
        Info *inf = FUN_00193474(self->f50->f1b4);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    } else if (mode == 1) {
        FUN_000143b0(buf, DAT_002da7f0);
        FUN_0019494c(self, buf, DAT_0033b4a8, 800, 0, 0);
        FUN_0005ed18(self->f50, 0, self->f70);
        FUN_0005f030(self->f50, 0, 0.0f);
        Info *inf = FUN_00193024(buf);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    } else {
        FUN_00194e34(self, arg);
        FUN_001277e8(self);
        FUN_0005ed18(self->f50, 0, self->f70);
        FUN_0005f030(self->f50, 0, 0.0f);
        Info *inf = FUN_00193474(self->f50->f1b4);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    }
    for (int i = 0; i < Count(self); i++) {
        if (FUN_00014934(NameAt(self, i), DAT_002da800) == 0) {
            self->f58->GetPos(&v, i);
            self->f328 = (v.z + (v.x + v.y)) / 3.0f;
        }
    }
    FUN_00127004(self);
    FUN_0012a254(self, 0, -1, 0);
    self->Refresh();
}
}
