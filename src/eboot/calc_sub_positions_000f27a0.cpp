/* HSTMATCH module=EBOOT.BIN start=0x000f27a0 end=0x000f293c symbol=FUN_000f27a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Sub {
    char pad[96];
    float x;
    float y;
};

struct Obj {
    char pad0[84];
    struct Sub *sub84;
    struct Sub *sub88;
    struct Sub *sub92;
    char pad1[36];
    u8 f132;
    char pad2[31];
    int f164;
};

struct Player {
    char pad[1468];
    int target;
};

struct Game {
    char pad[112];
    Player *players[12];
};

extern "C" {
    extern u8 DAT_003386b8;
    extern void *DAT_00338ac4;
    extern Game *DAT_003386b0;
    extern char DAT_00311170;
    extern void *DAT_003313c4;
    extern char DAT_0032b1d0;

    extern struct Vec3 *FUN_00093838(int arg);
    extern void FUN_00050824(void *a, void *b);
    extern void FUN_00022548(struct Vec4 *out, void *mat, struct Vec4 *in);
    extern void FUN_00022498(struct Vec4 *out, struct Vec4 *in, float scale);
    extern void FUN_00103480(void *obj);
    extern void FUN_001031e8(void *obj);

    void FUN_000f27a0(struct Obj *obj);
}

void FUN_000f27a0(struct Obj *obj) {
    if (obj->f132 != 0)
        return;

    int idx = (DAT_003386b8 != 0 && DAT_00338ac4 != 0) ? *(int *)((char *)DAT_00338ac4 + 408) : 0;

    Player *p = DAT_003386b0->players[idx];
    struct Vec3 *pos = FUN_00093838(p->target);

    struct Vec4 v;
    v.x = pos->x;
    v.y = pos->y;
    v.z = pos->z;
    v.w = 1.0f;

    FUN_00050824(&DAT_00311170, DAT_003313c4);
    FUN_00022548(&v, &DAT_0032b1d0, &v);

    if (!(v.w > 0.0f))
        return;

    FUN_00022498(&v, &v, 1.0f / v.w);

    v.x -= 1808.0f;
    v.y -= 1912.0f;

    float offset = (obj->f164 >= 0) ? -160.0f : 32.0f;

    obj->sub84->x = v.x + offset;
    obj->sub84->y = v.y - 64.0f;
    obj->sub88->x = v.x + offset;
    obj->sub88->y = v.y - 64.0f;
    obj->sub92->x = v.x + offset;
    obj->sub92->y = v.y - 64.0f;

    FUN_00103480(obj);
    FUN_001031e8(obj);
}
