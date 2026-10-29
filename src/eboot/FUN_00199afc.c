/* HSTMATCH module=EBOOT.BIN start=0x00199afc end=0x00199b40 symbol=FUN_00199afc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/install_flow.h"

extern u8 DAT_0034a678;
extern void FUN_00199398();
extern void FUN_002345f8();

/* Update the part; when it is active, run the global follow-up call. */
void FUN_00199afc(InstallFlow *self)
{
  FUN_00199398(self->part);
  if (self->part->active != '\0') {
    FUN_002345f8(&DAT_0034a678);
  }
}
