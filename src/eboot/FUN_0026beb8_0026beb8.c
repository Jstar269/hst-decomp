/* HSTMATCH module=EBOOT.BIN start=0x0026beb8 end=0x0026bf18 symbol=FUN_0026beb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the second initialization-helper argument; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();
extern void FUN_0026bf18(SharingScreen *self, int param_2);
extern void FUN_00281128();

/* Re-initialises the sharing screen: sets its two flag bytes, runs the helper and passes the first word on. */
void FUN_0026beb8(SharingScreen *self)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  self->unkbbc = 1;
  self->unkbc4 = 0;
  FUN_0026bf18(self,1);
  FUN_00281128(self->unk0);
}
