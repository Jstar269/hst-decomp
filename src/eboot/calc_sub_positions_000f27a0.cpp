/* HSTMATCH module=EBOOT.BIN start=0x000f27a0 end=0x000f293c symbol=FUN_000f27a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/sabu_pane.h"

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

struct Player {
    char pad[1468];
    int target;
};

struct Game {
    char pad[112];
    Player *players[12];
};

struct Cam {
    char pad[408];
    int player_index;
};

extern "C" {
    extern u8 DAT_003386b8;
    extern Cam *DAT_00338ac4;
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

    void FUN_000f27a0(SabuPane *obj);
}

/* Project the selected player's target position to the screen and move all three layers next to it. */
void FUN_000f27a0(SabuPane *obj) {
    if (obj->unk84 != 0)
        return;

    int idx = (DAT_003386b8 != 0 && DAT_00338ac4 != 0) ? DAT_00338ac4->player_index : 0;

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

    float offset = (obj->unka4 >= 0) ? -160.0f : 32.0f;

    obj->layer[0]->x = v.x + offset;
    obj->layer[0]->y = v.y - 64.0f;
    obj->layer[1]->x = v.x + offset;
    obj->layer[1]->y = v.y - 64.0f;
    obj->layer[2]->x = v.x + offset;
    obj->layer[2]->y = v.y - 64.0f;

    FUN_00103480(obj);
    FUN_001031e8(obj);
}
