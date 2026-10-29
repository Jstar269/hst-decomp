/* HSTMATCH module=hstp_trans_main.prx start=0x00136ae4 end=0x00136b54 symbol=FUN_00136ae4 lang=c99 */
/* Clone of src/eboot/FUN_0012b678.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern void FUN_001354c4();
extern u32 FUN_001377d0();
extern u32 FUN_00137a18();

/* If the parts object is ready, records its result and the flag; with no result, starts state 12. */
void FUN_00136ae4(Avatar *self,u32 unusedA,u32 unusedB,u8 flag)
{
  u8 ready;
  u8 result;
  
  ready = FUN_001377d0(&self->parts370);
  if (ready != '\0') {
    result = FUN_00137a18(&self->parts370);
    self->unk410 = result;
    self->unk32c = flag;
    if (self->unk410 == '\0') {
      FUN_001354c4(self,0xc,0xffffffff,0);
    }
  }
}
