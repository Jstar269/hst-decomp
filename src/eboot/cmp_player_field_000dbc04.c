/* HSTMATCH module=EBOOT.BIN start=0x000dbc04 end=0x000dbc54 symbol=FUN_000dbc04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the if/else-if chain with r = 0/1 arms is one && chain assigned to r (if (a != 0 && b >= 0 && c != X) r = 1; else r = 0), typed Game/Player/Obj structs; exact match verified; names and types await human review. */
typedef struct Player { char pad[0x144]; int f144; } Player;
typedef struct Game { char pad[0x70]; Player *players[4]; } Game;
typedef struct Obj { char pad0[0x61]; unsigned char f61; char pad1[0x36]; int f98; int f9c; } Obj;
extern Game *DAT_003386b0;

int FUN_000dbc04(Obj *o)
{
  int r;
  if (o->f61 != 0 && o->f98 >= 0 && o->f9c != DAT_003386b0->players[o->f98]->f144) r = 1; else r = 0;
  return r;
}
