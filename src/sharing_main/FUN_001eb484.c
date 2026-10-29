/* HSTMATCH module=hstp_trans_main.prx start=0x001eb484 end=0x001eb4b0 symbol=FUN_001eb484 lang=c99 */
/* Clone of src/eboot/FUN_001dd260.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/main_result_obj.h"

extern void FUN_00108a2c();
extern void FUN_001f8e00();

void FUN_001eb484(MainResultObj *self)
{
  FUN_00108a2c();
  FUN_001f8e00(self->unk8c);
}
