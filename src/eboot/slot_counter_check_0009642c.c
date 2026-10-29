/* HSTMATCH module=EBOOT.BIN start=0x0009642c end=0x00096588 symbol=FUN_0009642c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: for/guard loop shapes with the 4-or-2 count as if (flag != 0) 2 else 4, ints for the char temporaries, gate flag as int ((byte != 0) ^ 1) with the player pointer loaded first, sums written iVar6 + FUN(...) with the call inside the expression, the compared byte read into a temporary first; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/player_record.h"

extern PlayerList * DAT_003386b0;
extern u8 DAT_003386b8;
extern u32 DAT_00338af0;
extern char * DAT_00338b44;
extern int FUN_000c4ba0();
extern void FUN_000c50c4();

/* Checks that every other slot's n holds the same byte as this player's n at the given entry, then bumps that byte
   in the rows of all active players. Returns 0 (after calling FUN_000c50c4) on the first disagreement. */
u32 FUN_0009642c(SlotPlayer *player,int entry)
{
  int ref;
  int active;
  int n;       /* row pointer first, then the player count */
  int cell;
  int idx;     /* own slot index, later the player loop counter */
  int entry_off;
  int i;       /* loop counter, later the byte offset into the player list */
  SlotPlayer *other;
  int value;
  
  n = FUN_000c4ba0(DAT_00338af0,player->index);
  entry_off = entry * 4;
  idx = player->index;
  ref = *(char *)(idx + (entry_off + n) + 0xc);
  if (*(u8 *)(DAT_00338b44 + 0x45) != 0) {
    n = 2;
  }
  else {
    n = 4;
  }
  for (i = 0; i < n; i++) {
    if (i != idx) {
      cell = entry_off + FUN_000c4ba0(DAT_00338af0,i);
      idx = player->index;
      value = *(char *)(cell + idx + 0xc);
      if (value != ref) {
        FUN_000c50c4(DAT_00338af0);
        return 0;
      }
    }
  }
  idx = 0;
  if (n > 0) {
    i = 0;
    do {
      other = *(SlotPlayer **)((char *)DAT_003386b0 + i + 0x70);
      active = DAT_003386b8 != 0;
      if (active) {
        active = (other->unk1b4 != 0) ^ 1;
      }
      if (active) {
        cell = entry_off + FUN_000c4ba0(DAT_00338af0,idx);
        cell += player->index;
        *(char *)(cell + 0xc) = *(char *)(cell + 0xc) + 1;
      }
      idx++;
      i += 4;
    } while (idx < n);
  }
  return 1;
}
