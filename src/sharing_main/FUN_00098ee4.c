/* HSTMATCH module=hstp_trans_main.prx start=0x00098ee4 end=0x00098f50 symbol=FUN_00098ee4 lang=c99 */
/* Clone of src/eboot/FUN_00096dac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/player_record.h"

extern PlayerList * DAT_003e19f0;
extern void FUN_00099248();

/* Calls FUN_00099248 on every player in the list. */
void FUN_00098ee4(void)
{
  SlotPlayer *player;
  int i;
  int offset;
  
  if (DAT_003e19f0 != 0) {
    i = 0;
    offset = 0;
    do {
      player = *(SlotPlayer **)((char *)DAT_003e19f0 + offset + 0x70);
      if (player != 0) {
        FUN_00099248(player);
      }
      i = i + 1;
      offset = offset + 4;
    } while (i < PLAYER_SLOTS);
  }
}
