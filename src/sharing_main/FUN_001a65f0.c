/* HSTMATCH module=hstp_trans_main.prx start=0x001a65f0 end=0x001a6634 symbol=FUN_001a65f0 lang=c99 */
/* Clone of src/eboot/FUN_00199afc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/install_flow.h"

extern u8 DAT_003f39a8;
extern void FUN_001a5e8c();
extern void FUN_002446f8();

/* Update the part; when it is active, run the global follow-up call. */
void FUN_001a65f0(InstallFlow *self)
{
  FUN_001a5e8c(self->part);
  if (self->part->active != '\0') {
    FUN_002446f8(&DAT_003f39a8);
  }
}
