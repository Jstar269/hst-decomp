/* HSTMATCH module=hstp_trans_main.prx start=0x00259944 end=0x00259bc8 symbol=FUN_00259944 lang=c++ */
/* Clone of src/eboot/trajectory_step_0024973c.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct V4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct M4 {
    V4 r0, r1, r2, r3;
};

struct Obj {
    char pad0[0xc0];
    char fc0;        // 0xc0 (192)
    char padc1[3];
    float fc4;       // 0xc4 (196)
    char padc8[8];
    float fd0;       // 0xd0 (208)
    char padd4[0x158 - 0xd4];
    int lo;          // 0x158 (344)
    int hi;          // 0x15c (348)

    int Last() const { return hi; }
    bool AnyActive() {
        for (int i = lo; i <= Last(); i++) {
            if (*(float *)((char *)this + i * 0x34 + 0x10c) != 0.0f) return true;
        }
        return false;
    }
};

struct Self {
    char pad0[0x490];
    V4 f490;         // 0x490 (1168)
    V4 f4a0;         // 0x4a0 (1184)
    char pad1[0x4b4 - 0x4b0];
    int f4b4;        // 0x4b4 (1204)
};

extern "C" {
    extern Obj *DAT_003f3a78;
    extern M4 DAT_002cc260;

    unsigned char FUN_000587ac(Obj *o, int a, int b, float f);
    void FUN_00059ba8(Obj *o, int a, float f);
    void FUN_00059ac0(Obj *o, int a, int b);
    void FUN_00059d68(Obj *o, int a);
    void FUN_000224c0(V4 *out, const V4 *in, float scale);
    void FUN_00022440(V4 *out, const V4 *a, const V4 *b);
    void FUN_00055b64(Obj *dst, const M4 *src);
    void FUN_00059e58(Obj *o);
    void FUN_0005fec8(Obj *o);

    void FUN_00259944(Self *self);
}

static inline V4 Scale(const V4 &a, float s)
{
    V4 r;
    FUN_000224c0(&r, &a, s);
    return r;
}
static inline V4 Add(const V4 &a, const V4 &b)
{
    V4 r;
    FUN_00022440(&r, &a, &b);
    return r;
}

void FUN_00259944(Self *self) {
    M4 mtx;

    if (!DAT_003f3a78->AnyActive()) {
        FUN_000587ac(DAT_003f3a78, 0, 0, 0.0f);
        Obj *o = DAT_003f3a78;
        FUN_00059ba8(o, -1, 1.0f);
        o->fc4 = 1.0f;
        o = DAT_003f3a78;
        FUN_00059ac0(o, 1, -1);
        o->fc0 = 1;
        o = DAT_003f3a78;
        FUN_00059d68(o, -1);
        o->fd0 = o->fc4;
    }

    self->f4a0 = Add(self->f4a0, Scale(self->f490, 0.2f));
    mtx = DAT_002cc260;
    mtx.r3 = self->f4a0;
    FUN_00055b64(DAT_003f3a78, &mtx);

    Obj *s1 = DAT_003f3a78;
    FUN_00059e58(s1);
    FUN_0005fec8(s1);

    self->f4b4++;
}
