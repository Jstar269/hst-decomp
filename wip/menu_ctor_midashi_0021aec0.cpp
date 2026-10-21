/* HSTMATCH module=EBOOT.BIN start=0x0021aec0 end=0x0021b080 symbol=FUN_0021aec0 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (110/112 words: the 2 missing words are the unfolded global reads, see trailing comments); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));

class VObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
};

struct Part {
    char pad0[0x20];
    int pad20;
};

struct Pane : VObj {
    char pad4[0x54 - 4];
    int f54;
    int f58;
    char pad5c[0x64 - 0x5c];
    int a64[6];
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
};

struct Entry {
    int idx;
    char *name;
    int out;
};

extern int DAT_003097e4;
extern char DAT_002f0000[];
extern float DAT_002eff88;
extern char *DAT_002effa0;
extern Entry DAT_002effcc[];
extern int DAT_002efffc;

extern "C" {
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(void *, float);
VObj *FUN_001039d8(void *, char *, int);
int *FUN_001026b8(int, char *);
Vec4 *FUN_00022498(Vec4 *, Vec4 *, float);
void FUN_0021b1c8(void *);

static inline Vec4 Scale(const Vec4 &v, float k)
{
    Vec4 r;
    FUN_00022498(&r, (Vec4 *)&v, k);
    return r;
}

Pane *FUN_0021aec0(Pane *self)
{
    FUN_00102e38(self);
    *(int **)self = &DAT_003097e4;
    FUN_00104118(self, DAT_002f0000, 1);
    FUN_00103540(self, DAT_002eff88);
    VObj *mid = FUN_001039d8(self, DAT_002effa0, 0);
    *(VObj **)&self->a64[0] = mid;
    mid->m5(-3);
    int i = 0;
    Entry *tab = DAT_002effcc;
    int off = 0;
    do {
        int *n = FUN_001026b8(self->a64[tab->idx], tab->name);
        *(int *)((unsigned int)self + off + 0x68) = (int)n;
        tab->out = n[9];
        i++;
        off += 4;
        tab++;
    } while (i < 4);
    int *sub = (int *)self->a64[DAT_002efffc + 1];
    int *s0 = (int *)sub[8];
    self->a64[5] = (int)s0;
    s0[0x118 / 4] = 0x80808080;
    Vec4 g(128.0f, 128.0f, 128.0f, 128.0f);
    *(Vec4 *)((char *)s0 + 0x120) = Scale(g, 0.008f);
    ((VObj *)self->a64[5])->m5(-2);
    self->f54 = -999;
    self->f58 = -999;
    self->f8c = 0;
    self->f7c = *(short *)(self->a64[2] + 4);
    self->f80 = *(short *)(self->a64[2] + 8);
    self->f84 = *(short *)(self->a64[4] + 4);
    self->f88 = *(short *)(self->a64[4] + 8);
    FUN_0021b1c8(self);
    return self;
}
}

// sn1 SKIP/NEAR: everything else is word-for-word (loop with counter/table/offset order i, tab, off and the `(unsigned)self + off + 0x68` store, vtable
// calls via VObj::m5 = slot 28, `Vec4 g(128..)`, inline `Scale` returning Vec4 by value for the +4,+8,+12,+0 copy). Retail reads two globals UNFOLDED
// (`lui v0,0x2f; addiu v0,v0,-96; lw a1,0(v0)` for the string pointer DAT_002effa0 and `addiu v0,v0,-4; lw v1,0(v0)` for DAT_002efffc): the documented
// dead end (MWCC-NOTES 2026-10-21), two words short. One probe (`char **pp = &DAT_002effa0; ... *pp`) folded as expected.
// near miss from lane sn1 (unreviewed)
