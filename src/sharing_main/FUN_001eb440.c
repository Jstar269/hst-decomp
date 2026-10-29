/* HSTMATCH module=hstp_trans_main.prx start=0x001eb440 end=0x001eb484 symbol=FUN_001eb440 lang=c99 */
/* Clone of src/eboot/FUN_001dd21c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/main_result_obj.h"

extern void FUN_00108dac();
extern void FUN_001f8b80();
extern void FUN_001f8bd4();
extern void FUN_001f8ca4();

void FUN_001eb440(MainResultObj *self)
{
  FUN_00108dac();
  FUN_001f8bd4(self->unk8c,0);
  FUN_001f8ca4(self->unk8c,0);
  FUN_001f8b80(self->unk8c);
}
