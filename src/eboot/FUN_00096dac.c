/* HSTMATCH module=EBOOT.BIN start=0x00096dac end=0x00096e18 symbol=FUN_00096dac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/player_record.h"

extern PlayerList * DAT_003386b0;
extern void FUN_00097110();

/* Calls FUN_00097110 on every player in the list. */
void FUN_00096dac(void)
{
  SlotPlayer *player;
  int i;
  int offset;
  
  if (DAT_003386b0 != 0) {
    i = 0;
    offset = 0;
    do {
      player = *(SlotPlayer **)((char *)DAT_003386b0 + offset + 0x70);
      if (player != 0) {
        FUN_00097110(player);
      }
      i = i + 1;
      offset = offset + 4;
    } while (i < PLAYER_SLOTS);
  }
}
