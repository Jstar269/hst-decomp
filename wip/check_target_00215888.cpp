/* HSTMATCH module=EBOOT.BIN start=0x00215888 end=0x00215a20 symbol=FUN_00215888 lang=c++ */
// Best match: 102/102 words, 15 differ (pure s1/s2 register colouring swap).

typedef unsigned char u8;

struct Vec4 {
    float x, y, z, w;
};

struct Other {
    char pad[0x144];
    int f144;
    char pad2[0x5a0 - 0x148];
    Vec4 pos;
    char pad3[0x5bc - (0x5a0 + 16)];
    void *f5bc;
};

struct ManagerSub {
    char pad[0x230];
    int f230;
};

struct Manager {
    char pad[0x70];
    Other *others[4];
    char pad2[0x88 - (0x70 + 16)];
    ManagerSub *f88;
};

struct Obj {
    char pad[0x144];
    int f144;
};

extern "C" {
extern Manager *DAT_003386b0;
extern char DAT_00338760;
extern float DAT_0033876c;
extern void *DAT_00338b44;

int FUN_000dbc54(void *obj, int arg);
void FUN_00022450(Vec4 *out, void *base, Vec4 *in);
bool FUN_000a8494(Other *other, Vec4 *in);
void *FUN_00093838(void *arg);
void FUN_00022434(Vec4 *out, void *base, void *in);
}

extern "C" int FUN_00215888(Obj *self) {
    if ((u8)FUN_000dbc54(DAT_00338b44, 4) == 0) {
        void *s2 = (DAT_0033876c > 0.0f) ? &DAT_00338760 : (void*)0;
        if (s2 != 0 && self->f144 == DAT_003386b0->f88->f230) {
            Vec4 t2;
            Vec4 other_pos;
            Vec4 t1;
            Vec4 pt;

            int i, off;
            for (i = 0, off = 0; i < 4; i++, off += 4) {
                Other *other = *(Other **)((char *)DAT_003386b0 + off + 0x70);
                if (other == 0)
                    continue;
                if (self->f144 == other->f144)
                    continue;

                other_pos = other->pos;
                FUN_00022450(&t1, s2, &other_pos);
                t2 = t1;
                if (!FUN_000a8494(other, &t2))
                    continue;

                FUN_00022434(&pt, s2, FUN_00093838(other->f5bc));
                if (pt.x * pt.x + pt.z * pt.z <= 4.0f)
                    return 1;
            }
        }
    }

    return 0;
}

// lane sx4: 9 words differ (was 15). Explicit offset/index in the for header
//   `for (i = 0, off = 0; i < 4; i++, off += 4) { Other *other = *(Other **)((char *)DAT_003386b0 + off + 0x70);`
// gives retail's off=s0 / other=s1 / i=s3 / self=s4 shape except ptr(s2 var) and off swap: ours ptr=s0, off=s2; retail ptr=s2, off=s0.
// Ruled out: all 24 function-top declaration orders of {ptr, i, off, other}; ptr/off initialisers; for-header update order; +0x70 before/after off.
// improved by lane sx4 (unreviewed): 15 -> 9 differing words
