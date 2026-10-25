/* HSTMATCH module=EBOOT.BIN start=0x0024973c end=0x002499c0 symbol=FUN_0024973c lang=c++ */

struct V4 {
    float x, y, z, w;
    V4() {}
};

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
    extern Obj *DAT_0034a748;
    extern const M4 DAT_002bc410;

    unsigned char FUN_00057b58(Obj *o, int a, int b, float f);
    void FUN_00058ec4(Obj *o, int a, float f);
    void FUN_00058ddc(Obj *o, int a, int b);
    void FUN_00059084(Obj *o, int a);
    void FUN_00022498(V4 *out, V4 *in, float scale);
    void FUN_00022418(V4 *out, V4 *a, V4 *b);
    void FUN_00055044(Obj *dst, const M4 *src);
    void FUN_00059174(Obj *o);
    void FUN_0005f0d8(Obj *o);

    void FUN_0024973c(Self *self);
}

void FUN_0024973c(Self *self) {
    M4 mtx;
    V4 local_50;
    V4 local_60;
    V4 local_70;

    if (!DAT_0034a748->AnyActive()) {
        FUN_00057b58(DAT_0034a748, 0, 0, 0.0f);
        Obj *o = DAT_0034a748;
        FUN_00058ec4(o, -1, 1.0f);
        o->fc4 = 1.0f;
        o = DAT_0034a748;
        FUN_00058ddc(o, 1, -1);
        o->fc0 = 1;
        o = DAT_0034a748;
        FUN_00059084(o, -1);
        o->fd0 = o->fc4;
    }

    FUN_00022498(&local_70, &self->f490, 0.2f);
    local_50 = local_70;
    FUN_00022418(&local_60, &self->f4a0, &local_50);
    self->f4a0 = local_60;

    mtx = DAT_002bc410;
    mtx.r3 = self->f4a0;
    FUN_00055044(DAT_0034a748, &mtx);

    Obj *s1 = DAT_0034a748;
    FUN_00059174(s1);
    FUN_0005f0d8(s1);

    self->f4b4++;
}
// near miss from lane ag4 (unreviewed)
