/* HSTMATCH module=hstp_trans_main.prx start=0x00092148 end=0x000921cc symbol=FUN_00092148 lang=c99 */
/* Clone of src/eboot/select_partner_player_000904dc.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Game/Player structs, the dropped call argument is the Game pointer (live in a0), int %4 with sign fix, b declared before a; exact match verified; names and types await human review. */
typedef struct Pl { char pad[0x230]; int side; } Pl;
typedef struct Game { char pad[0x70]; Pl *players[12]; } Game;
extern Game *DAT_003e19f0;
extern Pl *FUN_00089f84(Game *);

Pl *FUN_00092148(Pl *o)
{
  Pl *b;
  Pl *a;
  int i = o->side ^ 1;
  a = DAT_003e19f0->players[(i + 2) % 4];
  b = DAT_003e19f0->players[i];
  if (a != 0 && a == FUN_00089f84(DAT_003e19f0))
    b = a;
  return b;
}
