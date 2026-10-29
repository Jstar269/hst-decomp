/* HSTMATCH module=EBOOT.BIN start=0x00096588 end=0x000966ac symbol=FUN_00096588 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: gate flag as int (DAT != 0, then (byte != 0) ^ 1), unsigned char flag globals, the 0x39-byte record copied as typed struct (two Float4 members assigned whole, then scalar members one by one); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/player_record.h"

extern u8 DAT_003386b8;
extern char * DAT_00338af0;
extern s32 FUN_0009642c();
extern void FUN_000969c0();
extern SlotRow * FUN_000c4ba0();

/* Stores the record into the player's slot row (and mirrors it) when the player is active and FUN_0009642c accepts. */
void FUN_00096588(SlotPlayer *player, SlotRecord *src)
{
  int ok;
  int accepted;
  SlotRow *row;
  SlotRecord *dst;

  ok = DAT_003386b8 != 0;
  if (ok) {
    ok = (player->unk1b4 != 0) ^ 1;
  }
  if (((ok) && (DAT_00338af0 != 0)) && (accepted = FUN_0009642c(player,0), accepted != 0)) {
    row = FUN_000c4ba0(DAT_00338af0,player->index);
    dst = &row->rec;
    dst->a = src->a;
    dst->b = src->b;
    dst->c0 = src->c0;
    dst->c1 = src->c1;
    dst->c2 = src->c2;
    dst->c3 = src->c3;
    dst->d0 = src->d0;
    dst->d1 = src->d1;
    dst->d2 = src->d2;
    dst->d3 = src->d3;
    dst->d4 = src->d4;
    dst->d4 = *(int *)(DAT_00338af0 + 0x780);
    FUN_000969c0(row);
  }
}
