/* HSTMATCH module=EBOOT.BIN start=0x00131e00 end=0x00132124 symbol=FUN_00131e00 lang=c++ */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Key {
    int t;
    int p4;
    int f8;
    int pc;
    Vec4 v;
    Key() {}
};
struct KeyVec {
    Key *data;
    unsigned size;
    unsigned cap;
};
struct Cam {
    char pad0[0x23c];
    int f23c;
    char pad1[0x26c - 0x240];
    KeyVec a;
    KeyVec b;
};
struct Node {
    char pad[0x144];
    int f144;
};
struct Game {
    char pad0[0x70];
    Node *nodes[6];
    Cam *cam;
    char pad1[0x9c - 0x8c];
    int f9c;
};
struct Rt {
    char pad0[0x50];
    int f50;
    char pad1[0x84 - 0x54];
    unsigned char f84;
    char pad2[0x98 - 0x85];
    int f98;
    int f9c;
};
struct Self {
    char pad0[0x90];
    int f90;
    char pad1[0xa0 - 0x94];
    Vec4 bv;
    int fb0;
    int fb4;
    char pad2[0xc0 - 0xb8];
    Vec4 av;
    int fd0;
    char pad3[0xe0 - 0xd4];
    Vec4 cv;
    char pad4[0xf1 - 0xf0];
    unsigned char ff1;
    char pad5[0x130 - 0xf2];
    int f130;
};
extern Game *DAT_003386b0;
extern Rt *DAT_00338b44;
extern "C" {
float fabsf(float);
int FUN_000de268(Rt *, int);
int FUN_000dbc04();
int FUN_00118144(int);
int FUN_001181c0(int);
}

extern "C" void FUN_00131e00(Self *self)
{
    Cam *cam = DAT_003386b0->cam;
    unsigned n = cam->b.size;
    KeyVec *av = &cam->a;
    int ia = 0;
    if (av->size == 0) {
        ia = av->size - 1;
    }
    Key *ka = av->data + ia;
    float aw0, az0, ay0, ax0;
    ax0 = ka->v.x;
    ay0 = ka->v.y;
    az0 = ka->v.z;
    aw0 = ka->v.w;
    int ib = 0;
    if (n == 0) {
        ib = n - 1;
    }
    Key *kb = av[1].data + ib;
    Key B = *kb;
    Key C;
    if (FUN_000de268(DAT_00338b44, -1) != 0 || DAT_00338b44->f84 != 0 || FUN_000dbc04() != 0 || self->ff1 != 0) {
        unsigned sz = av[1].size;
        int ic = 0;
        if (sz == 0) {
            ic = sz - 1;
        }
        C = av[1].data[ic];
    } else {
        unsigned i = n;
        if (!(n < av[1].size)) {
            i = av[1].size - 1;
        }
        C = av[1].data[i];
        if (!(fabsf(C.v.x) < 5.3f && fabsf(C.v.z) < 11.0f)) {
            C = B;
        }
    }
    self->fb0 = FUN_00118144(DAT_003386b0->f9c);
    self->fb4 = FUN_001181c0(DAT_003386b0->f9c);
    self->av.x = ax0;
    self->av.y = ay0;
    self->av.z = az0;
    self->av.w = aw0;
    self->f90 = self->fb4 + B.t;
    self->bv.x = B.v.x;
    self->bv.y = B.v.y;
    self->bv.z = B.v.z;
    self->bv.w = B.v.w;
    self->fd0 = self->fb4 + C.t;
    self->cv.x = C.v.x;
    self->cv.y = C.v.y;
    self->cv.z = C.v.z;
    self->cv.w = C.v.w;
    int r = DAT_00338b44->f98;
    self->f130 = r;
    if (r < 0) {
        self->f130 = DAT_00338b44->f50;
    }
    bool r2 = cam->f23c == 12;
    if (r2) {
        r2 = DAT_003386b0->nodes[self->f130]->f144 != DAT_00338b44->f9c;
    }
    self->ff1 = r2;
}
// NEAR ~73 words (shift-tolerant; 166 by position, 194 vs 201 words). Control flow, frame (112), saved registers (s0-s4, f20-f23) and the tail all match.
// Remaining difference: the two Key copies. Retail copies only t (kept in s2/s0), f8 (spilled word at sp+88 / sp+56, stored even though never read) and v (two lwc1/lwc1/swc1/swc1 PAIRS to sp+96 / sp+64) and reloads v from the stack;
//  ours copies v as a 3-wide batch (f2,f1,f0 + f1) and drops the dead f8 copy.
// Learned: (1) `struct Key {int t, p4, f8, pc; Vec4 v; Key() {}};` with `Key B = *k; Key C; C = ...; C = B;` (implicit memberwise copy of a class WITH a constructor) keeps v in memory (retail's 112-byte frame, only f20-f23 saved for the 4-float `a`);
//  a plain POD Key, a user copy ctor/operator=, field-by-field copies, or `Vec4() {}` all promote everything to f24-f31 registers (frame 80).
//  (2) the four floats of `a` are separate scalars declared in reverse order (`float aw, az, ay, ax;` then assigned x..w) to get x=f20..w=f23.
//  (3) Ghidra's goto web is `if (F1(..) != 0 || G->f84 != 0 || F2() != 0 || self->f != 0) { else-arm (front/back of b) } else { clamp arm }`: else arm physically first.
//  (4) `fabsf` (extern "C" float fabsf(float)) is the abs.s intrinsic; the final bool is `bool r = cam->f23c == 12; if (r) r = ...;`.
// Not found: how to get the 2-wide pair copy and the stored dead f8 for the memory-resident copy.
// near miss from lane sn6 (unreviewed)
