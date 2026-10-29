/* HSTMATCH module=EBOOT.BIN start=0x001e9cb8 end=0x001e9e80 symbol=FUN_001e9cb8 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Computes target view origin from offsets and device state flag, initializes 4x4 transform matrix at DAT_003415ac and updates view scale; exact match verified. */

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
    extern int DAT_0034a134;
    extern int DAT_002ed2bc;
    extern Other *DAT_00338b44;
    extern Game *DAT_003415ac;
    extern const M4 DAT_002bc410;

    void FUN_001e9cb8(Self *self);
}

/* Half of the 480x272 screen: the view origin is measured from the centre. */
enum { SCREEN_CENTER_X = 240, SCREEN_CENTER_Y = 136, ORIGIN_LIFT = 26 };

void FUN_001e9cb8(Self *self) {
    int x = self->f54 + SCREEN_CENTER_X + DAT_0034a134;
    int y = self->f58 + SCREEN_CENTER_Y + DAT_002ed2bc;

    bool flag = !DAT_00338b44->f45;
    int count = self->f419 ? 1 : self->f398;
    if (flag || !(count = (count < 4))) {
        y -= ORIGIN_LIFT;
    }

    Game *g = DAT_003415ac;
    if (g) {
        Holder *&hr = g->h;
        MatHolder *mh = hr->obj;
        mh->m = DAT_002bc410;
        hr->obj->m.r3.x = (float)x;
        DAT_003415ac->h->obj->m.r3.y = (float)y;
        DAT_003415ac->SetOrigin(DAT_003415ac->h->obj->m.r3.x, DAT_003415ac->h->obj->m.r3.y);
        DAT_003415ac->SetScale(1.0f);
    }
}
