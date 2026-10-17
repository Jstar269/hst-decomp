/* HSTMATCH module=EBOOT.BIN start=0x000904dc end=0x00090560 symbol=FUN_000904dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Game/Player structs, the dropped call argument is the Game pointer (live in a0), int %4 with sign fix, b declared before a; exact match verified; names and types await human review. */
typedef struct Pl { char pad[0x230]; int side; } Pl;
typedef struct Game { char pad[0x70]; Pl *players[12]; } Game;
extern Game *DAT_003386b0;
extern Pl *FUN_0008882c(Game *);

Pl *FUN_000904dc(Pl *o)
{
  Pl *b;
  Pl *a;
  int i = o->side ^ 1;
  a = DAT_003386b0->players[(i + 2) % 4];
  b = DAT_003386b0->players[i];
  if (a != 0 && a == FUN_0008882c(DAT_003386b0))
    b = a;
  return b;
}
