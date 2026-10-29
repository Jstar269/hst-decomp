/* HSTMATCH module=hstp_trans_main.prx start=0x00098d64 end=0x00098e54 symbol=FUN_00098d64 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/FUN_00096c2c.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/player_record.h"

extern int DAT_003e1e84;
extern unsigned char DAT_003eab6f[];
extern int DAT_003f3aac;
extern int FUN_000dfc74(int, int);
extern int FUN_0025e0c0(int, int, int);

/* Returns 1 straight away for modes 1, 3, 8, 11 and 14 when any of the three checks 17..19 passes; otherwise defers to FUN_0025e0c0. */
int FUN_00098d64(SlotPlayer *player, int mode)
{
  switch (mode) {
  case 1:
  case 3:
  case 8:
  case 11:
  case 14:
    if ((FUN_000dfc74(DAT_003e1e84, 17) != 0) ||
        (FUN_000dfc74(DAT_003e1e84, 18) != 0) ||
        (FUN_000dfc74(DAT_003e1e84, 19) != 0))
      return 1;
    break;
  default:
    break;
  }
  return FUN_0025e0c0(DAT_003f3aac, mode,
                      DAT_003eab6f[player->index * 0x120]);
}
