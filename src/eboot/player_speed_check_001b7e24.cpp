/* HSTMATCH module=EBOOT.BIN start=0x001b7e24 end=0x001b7fe4 symbol=FUN_001b7e24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Player;
struct Sub;

struct Mgr {
    char pad[0x70];
    Player *players[8];
};

extern "C" {
extern float DAT_002e9a6c;
extern Mgr *DAT_003386b0;
extern void *DAT_00338b44;

extern void FUN_00022450(void *out, const void *a, const void *b);
extern float FUN_000224d8(const void *a, const void *b);
extern float FUN_00022e44(float f);
extern int FUN_000ddd64(void *ctx, const void *vec, int pad);
extern int FUN_000de298(void *ctx, int mode);
extern void FUN_001b8890(void *param_1, float f);
}

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Player {
    char pad[0x4e8];
    int f4e8;
    char pad4ec[0x5a0 - 0x4ec];
    Vec4 v5a0;
};

struct Sub {
    char pad[4];
    int f4;
    char pad8[0x10 - 8];
    Vec4 v10;
    Vec4 v20;
    char pad30[0x1d4 - 0x30];
    int f1d4;
    char pad1d8[0x234 - 0x1d8];
    int f234;
    char pad238[0x284 - 0x238];
    unsigned char f284;
};

extern "C" void FUN_001b7e24(void *param_1)
{
    Mgr *m = *(Mgr *volatile *)&DAT_003386b0;
    Sub *s0 = m != 0 ? (Sub *)m->players[6] : 0;
    if (s0 == 0) return;
    if (s0->f234 < 0) return;
    if (s0->f4 != 1) return;
    Player *player = DAT_003386b0->players[s0->f234];
    if (player == 0) return;
    if (s0->f1d4 != 1) return;
    if (s0->f284 != 0) return;
    if (player->f4e8 != 2) return;

    Vec4 copy;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
    Vec4 res;

    v2 = player->v5a0;
    v1 = s0->v10;
    FUN_00022450(&res, &v1, &v2);

    copy = res;
    if (FUN_000ddd64(DAT_00338b44, &copy, 0) == 0) {
        if (!FUN_000de298(DAT_00338b44, -1)) return;
    }

    v3 = s0->v20;
    float dot = FUN_000224d8(&v3, &v3);
    float len = FUN_00022e44(dot);

    if (!(len >= (DAT_002e9a6c * 1000.0f) / 3600.0f)) return;

    FUN_001b8890(param_1, 1.0f);
}
