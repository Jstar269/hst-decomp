/* HSTMATCH module=hstp_trans_main.prx start=0x000f7e68 end=0x000f8004 symbol=FUN_000f7e68 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/calc_sub_positions_000f27a0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
    extern u8 DAT_003e19f8;
    extern Cam *DAT_003e1e04;
    extern Game *DAT_003e19f0;
    extern char DAT_003ba4b0;
    extern void *DAT_003da704;
    extern char DAT_003d4510;

    extern struct Vec3 *FUN_0009575c(int arg);
    extern void FUN_00051138(void *a, void *b);
    extern void FUN_00022570(struct Vec4 *out, void *mat, struct Vec4 *in);
    extern void FUN_000224c0(struct Vec4 *out, struct Vec4 *in, float scale);
    extern void FUN_00108dac(void *obj);
    extern void FUN_00108aec(void *obj);

    void FUN_000f7e68(SabuPane *obj);
}

/* Project the selected player's target position to the screen and move all three layers next to it. */
void FUN_000f7e68(SabuPane *obj) {
    if (obj->unk84 != 0)
        return;

    int idx = (DAT_003e19f8 != 0 && DAT_003e1e04 != 0) ? DAT_003e1e04->player_index : 0;

    Player *p = DAT_003e19f0->players[idx];
    struct Vec3 *pos = FUN_0009575c(p->target);

    struct Vec4 v;
    v.x = pos->x;
    v.y = pos->y;
    v.z = pos->z;
    v.w = 1.0f;

    FUN_00051138(&DAT_003ba4b0, DAT_003da704);
    FUN_00022570(&v, &DAT_003d4510, &v);

    if (!(v.w > 0.0f))
        return;

    FUN_000224c0(&v, &v, 1.0f / v.w);

    v.x -= 1808.0f;
    v.y -= 1912.0f;

    float offset = (obj->unka4 >= 0) ? -160.0f : 32.0f;

    obj->layer[0]->x = v.x + offset;
    obj->layer[0]->y = v.y - 64.0f;
    obj->layer[1]->x = v.x + offset;
    obj->layer[1]->y = v.y - 64.0f;
    obj->layer[2]->x = v.x + offset;
    obj->layer[2]->y = v.y - 64.0f;

    FUN_00108dac(obj);
    FUN_00108aec(obj);
}
