/* HSTMATCH module=hstp_trans_main.prx start=0x001766cc end=0x0017677c symbol=FUN_001766cc lang=c++ */
/* Clone of src/eboot/player_curve_offset_0016a508.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Adds a scaled (curve - 1) term to x: curve value from 0x195a18 for the given player's object at +0x154,
   or, with no player, for the current player (index from 0x3e1e04 when the 0x3e19f8 flag is set, else 0).
   Names provisional. */
struct Obj_001766cc;
struct Player_001766cc { char pad[0x154]; Obj_001766cc *o; };
struct Game_001766cc { char pad[0x70]; Player_001766cc *players[4]; };
struct Cur_001766cc { char pad[0x198]; int idx; };
extern "C" {
extern float DAT_00387a0c;
extern float DAT_00387a10;
extern float DAT_00387a14;
extern Game_001766cc *DAT_003e19f0;
extern bool DAT_003e19f8;
extern Cur_001766cc *DAT_003e1e04;
float FUN_001a22b4(float a, float b, Obj_001766cc *o);
}
extern "C" float FUN_001766cc(float x, Player_001766cc *p)
{
    float f;
    if (p) {
        f = FUN_001a22b4(DAT_00387a0c, DAT_00387a10, p->o);
    } else {
        int i = 0;
        if (DAT_003e19f8 && DAT_003e1e04)
            i = DAT_003e1e04->idx;
        f = FUN_001a22b4(DAT_00387a0c, DAT_00387a10, DAT_003e19f0->players[i]->o);
    }
    return x + DAT_00387a14 * (f - 1.0f);
}
