/* HSTMATCH module=EBOOT.BIN start=0x000ddbb0 end=0x000ddc6c symbol=FUN_000ddbb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_tally.h"

extern TallyOwner *DAT_003386b0;
extern SideInfo *FUN_0008882c();

/* Bumps tally counters depending on whether id_a and id_b equal the current side identifier. */
void FUN_000ddbb0(u32 unused,int id_b,int id_a)
{
  SideInfo *side;
  
  side = FUN_0008882c(DAT_003386b0);
  if (id_a == side->unk144) {
    DAT_003386b0->tally->unk1f4 = DAT_003386b0->tally->unk1f4 + 1;
    side = FUN_0008882c(DAT_003386b0);
    if (id_b == side->unk144) {
      DAT_003386b0->tally->unk1f0 = DAT_003386b0->tally->unk1f0 + 1;
    }
  }
  else {
    side = FUN_0008882c(DAT_003386b0);
    if (id_b == side->unk144) {
      DAT_003386b0->tally->unk1f8 = DAT_003386b0->tally->unk1f8 + 1;
    }
  }
}
