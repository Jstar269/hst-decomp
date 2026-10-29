/* HSTMATCH module=EBOOT.BIN start=0x00179718 end=0x001797b4 symbol=FUN_00179718 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the table symbol passed as &DAT_0034179c (addiu, not ori), the callee 0x1b1f7c takes the tested member as its dropped second argument, and the sign test is >= 0; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_host.h"

extern u8 DAT_0034179c;
extern void FUN_00171714();
extern void FUN_001755b8();
extern void FUN_0017c968();
extern void FUN_0017e9c0();
extern void FUN_001808c4();
extern int FUN_001b1f7c(void *, int);
extern void FUN_001fef04();

#define STATE_SKIP_SUBS 0x17 /* state in which the sub-objects are not updated */

/* Per-frame update: step the sub-objects, then drop the sound handle once its sound has ended. */
void FUN_00179718(ListHost *host)
{
  int alive;
  u32 state;
  
  FUN_00171714();
  if (host->unk6c >= 2) {
    FUN_001755b8(host);
  }
  if (host->state != STATE_SKIP_SUBS) {
    FUN_001808c4(host->sub174);
    FUN_0017c968(host->sub178);
    FUN_0017e9c0(host->sub17c);
  }
  state = host->state;
  FUN_001fef04(state,host->unk90,0);
  if (host->soundHandle >= 0 && (alive = FUN_001b1f7c(&DAT_0034179c, host->soundHandle), alive == 0)) {
    host->soundHandle = -1;
  }
}
