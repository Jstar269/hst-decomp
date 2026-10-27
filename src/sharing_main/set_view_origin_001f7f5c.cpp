/* HSTMATCH module=hstp_trans_main.prx start=0x001f7f5c end=0x001f8124 symbol=FUN_001f7f5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sharing twin of src/eboot/set_view_origin_001e9cb8.cpp (EBOOT 0x1e9cb8), the same source with the addresses substituted. */
/* Computes target view origin from offsets and device state flag, initializes 4x4 transform matrix at DAT_003ea8ec and updates view scale; exact match verified. */

struct V4 {
    float x, y, z, w;
    V4() {}
};

struct M4 {
    V4 r0, r1, r2, r3;
};

struct Base0 {
    char pad[0x30];
};

struct MatHolder {
    M4 m;
};

struct Obj : Base0, MatHolder {};

struct Holder {
    Obj *obj;
};

struct Game {
    char pad0[4];
    Holder *h;
    char pad1[0x74 - 8];
    float f74;
    float f78;
    void SetOrigin(float x, float y) {
        h->obj->m.r3.x = x;
        h->obj->m.r3.y = y;
    }
    void SetScale(float s) {
        f74 = s;
        f78 = s;
    }
};

struct Other {
    char pad[0x45];
    unsigned char f45;
};

struct Self {
    char pad0[0x54];
    int f54;             // 0x54
    int f58;             // 0x58
    char pad5c[0x398 - 0x5c];
    int f398;            // 0x398
    char pad39c[0x419 - 0x39c];
    unsigned char f419;  // 0x419
};

extern "C" {
    extern int DAT_003f346c;
    extern int DAT_003951e8;
    extern Other *DAT_003e1e84;
    extern Game *DAT_003ea8ec;
    extern const M4 DAT_002cc260;

    void FUN_001f7f5c(Self *self);
}

void FUN_001f7f5c(Self *self) {
    int x = self->f54 + 240 + DAT_003f346c;
    int y = self->f58 + 136 + DAT_003951e8;

    bool flag = !DAT_003e1e84->f45;
    int count = self->f419 ? 1 : self->f398;
    if (flag || !(count = (count < 4))) {
        y -= 26;
    }

    Game *g = DAT_003ea8ec;
    if (g) {
        Holder *&hr = g->h;
        MatHolder *mh = hr->obj;
        mh->m = DAT_002cc260;
        hr->obj->m.r3.x = (float)x;
        DAT_003ea8ec->h->obj->m.r3.y = (float)y;
        DAT_003ea8ec->SetOrigin(DAT_003ea8ec->h->obj->m.r3.x, DAT_003ea8ec->h->obj->m.r3.y);
        DAT_003ea8ec->SetScale(1.0f);
    }
}
