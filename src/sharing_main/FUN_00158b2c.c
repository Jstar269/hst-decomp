/* HSTMATCH module=hstp_trans_main.prx start=0x00158b2c end=0x00158b90 symbol=FUN_00158b2c lang=c99 helpers=FUN_00157280@0x00157280-0x001572ac */
/* Clone of src/eboot/FUN_0014d044.c (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (the same-file helper of src/eboot/get_mode_00152bec.c as its own source, with its static log stub FUN_00157280 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern char DAT_003836b8[];
extern char DAT_003836c4[];

static void FUN_00157280(...)
{
}

void FUN_00158b2c(u32 *param_1)
{
  int i;
  if (DAT_003e9630 != 0) {
    FUN_00157280(DAT_003836b8);
    for (i = 0; i < (int)param_1[6] + 1; i++) {
      FUN_00157280(DAT_003836c4);
    }
  }
}
