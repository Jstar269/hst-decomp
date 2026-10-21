/* HSTMATCH module=hstp_trans_main.prx start=0x00131fb8 end=0x00132274 symbol=FUN_00131fb8 lang=c++ */
/* Clone of src/eboot/setup_mode_00126d48.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_003e47e8;
extern char DAT_00381870[];
extern char DAT_00381880[];

extern "C" {
void FUN_001a1630();
void FUN_001a1644(Self *, int);
void FUN_00132a58(Self *);
void FUN_0005fb08(Elem *, int, int);
void FUN_0005fe20(Elem *, int, float);
Info *FUN_0019fc84(int);
Info *FUN_0019f834(void *);
void FUN_000143b0(void *, void *);
void FUN_001a115c(Self *, void *, int, int, int, int);
int FUN_0002fe30(Node8 *);
void *FUN_0002fe40(Node8 *, int);
int FUN_00014934(void *, void *);
void FUN_00132274(Self *);
void FUN_001354c4(Self *, int, int, int);

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
    return n ? FUN_0002fe30(n) : 0;
}

static inline void *NameAt(Self *s, int i)
{
    Node8 *n = s->f58->f8c->f8;
    return n ? FUN_0002fe40(n, i) : 0;
}

void FUN_00131fb8(Self *self, int mode, int arg)
{
    char buf[32];
    Vec4 v;
    self->f254 = mode == 0;
    if (mode == 0) {
        FUN_001a1630();
        FUN_0005fb08(self->f50, 0, self->f70);
        FUN_0005fe20(self->f50, 0, 0.0f);
        Info *inf = FUN_0019fc84(self->f50->f1b4);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    } else if (mode == 1) {
        FUN_000143b0(buf, DAT_00381870);
        FUN_001a115c(self, buf, DAT_003e47e8, 800, 0, 0);
        FUN_0005fb08(self->f50, 0, self->f70);
        FUN_0005fe20(self->f50, 0, 0.0f);
        Info *inf = FUN_0019f834(buf);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    } else {
        FUN_001a1644(self, arg);
        FUN_00132a58(self);
        FUN_0005fb08(self->f50, 0, self->f70);
        FUN_0005fe20(self->f50, 0, 0.0f);
        Info *inf = FUN_0019fc84(self->f50->f1b4);
        if (inf != 0) {
            CopyInfo(self, inf);
        }
    }
    for (int i = 0; i < Count(self); i++) {
        if (FUN_00014934(NameAt(self, i), DAT_00381880) == 0) {
            self->f58->GetPos(&v, i);
            self->f328 = (v.z + (v.x + v.y)) / 3.0f;
        }
    }
    FUN_00132274(self);
    FUN_001354c4(self, 0, -1, 0);
    self->Refresh();
}
}
