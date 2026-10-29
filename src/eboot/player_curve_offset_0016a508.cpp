/* HSTMATCH module=EBOOT.BIN start=0x0016a508 end=0x0016a5b8 symbol=FUN_0016a508 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Adds a scaled (curve - 1) term to x: curve value from 0x195a18 for the given player's object at +0x154,
   or, with no player, for the current player (index from 0x338ac4 when the 0x3386b8 flag is set, else 0).
   Names provisional. */
struct Obj_0016a508;
struct Player_0016a508 { char pad[0x154]; Obj_0016a508 *obj; /* 0x154 */ };
struct Game_0016a508 { char pad[0x70]; Player_0016a508 *players[4]; };
struct Cur_0016a508 { char pad[0x198]; int idx; /* 0x198 */ };
extern "C" {
extern float DAT_002e0450;
extern float DAT_002e0454;
extern float DAT_002e0458;
extern Game_0016a508 *DAT_003386b0;
extern bool DAT_003386b8;
extern Cur_0016a508 *DAT_00338ac4;
float FUN_00195a18(float a, float b, Obj_0016a508 *o);
}
extern "C" float FUN_0016a508(float x, Player_0016a508 *player)
{
    float curve;
    if (player) {
        curve = FUN_00195a18(DAT_002e0450, DAT_002e0454, player->obj);
    } else {
        int index = 0;
        if (DAT_003386b8 && DAT_00338ac4)
            index = DAT_00338ac4->idx;
        curve = FUN_00195a18(DAT_002e0450, DAT_002e0454, DAT_003386b0->players[index]->obj);
    }
    return x + DAT_002e0458 * (curve - 1.0f);
}
