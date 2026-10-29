/* HSTMATCH module=EBOOT.BIN start=0x0009619c end=0x00096214 symbol=FUN_0009619c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag chain as int ok = (G != 0); if (ok) ok = (b != 0) ^ 1 (lbu/sltu/xori), callee result as int* indexed row[i+1] (offset-first addu); readability pass; exact match verified; names and types await human review. */
#include "hst/player_record.h"

extern unsigned char DAT_003386b8;
extern int DAT_00338af0;
extern int FUN_000c4ba0(int, int);

/* Stores a value into the player's slot row (at entry + 1) when the player is active. */
void FUN_0009619c(SlotPlayer *player, int entry, int value)
{
  int ok;

  ok = DAT_003386b8 != 0;
  if (ok) {
    ok = (player->unk1b4 != 0) ^ 1;
  }
  if (ok && DAT_00338af0 != 0) {
    int *row = (int *)FUN_000c4ba0(DAT_00338af0, player->index);
    row[entry + 1] = value;
  }
}
