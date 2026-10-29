/* HSTMATCH module=hstp_trans_main.prx start=0x000e1d9c end=0x000e1e58 symbol=FUN_000e1d9c lang=c99 */
/* Clone of src/eboot/FUN_000ddbb0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_tally.h"

extern TallyOwner *DAT_003e19f0;
extern SideInfo *FUN_00089f84();

/* Bumps tally counters depending on whether id_a and id_b equal the current side identifier. */
void FUN_000e1d9c(u32 unused,int id_b,int id_a)
{
  SideInfo *side;
  
  side = FUN_00089f84(DAT_003e19f0);
  if (id_a == side->unk144) {
    DAT_003e19f0->tally->unk1f4 = DAT_003e19f0->tally->unk1f4 + 1;
    side = FUN_00089f84(DAT_003e19f0);
    if (id_b == side->unk144) {
      DAT_003e19f0->tally->unk1f0 = DAT_003e19f0->tally->unk1f0 + 1;
    }
  }
  else {
    side = FUN_00089f84(DAT_003e19f0);
    if (id_b == side->unk144) {
      DAT_003e19f0->tally->unk1f8 = DAT_003e19f0->tally->unk1f8 + 1;
    }
  }
}
