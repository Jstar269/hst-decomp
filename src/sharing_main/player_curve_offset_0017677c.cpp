/* HSTMATCH module=hstp_trans_main.prx start=0x0017677c end=0x0017682c symbol=FUN_0017677c lang=c++ */
/* Clone of src/eboot/player_curve_offset_0016a508.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Adds a scaled (curve - 1) term to x: curve value from 0x195a18 for the given player's object at +0x154,
   or, with no player, for the current player (index from 0x3e1e04 when the 0x3e19f8 flag is set, else 0).
   Names provisional. */
struct Obj_0017677c;
struct Player_0017677c { char pad[0x154]; Obj_0017677c *o; };
struct Game_0017677c { char pad[0x70]; Player_0017677c *players[4]; };
struct Cur_0017677c { char pad[0x198]; int idx; };
extern "C" {
extern float DAT_00387a0c;
extern float DAT_00387a10;
extern float DAT_00387a18;
extern Game_0017677c *DAT_003e19f0;
extern bool DAT_003e19f8;
extern Cur_0017677c *DAT_003e1e04;
float FUN_001a22b4(float a, float b, Obj_0017677c *o);
}
extern "C" float FUN_0017677c(float x, Player_0017677c *p)
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
    return x + DAT_00387a18 * (f - 1.0f);
}
