/* HSTMATCH module=hstp_trans_main.prx start=0x00277668 end=0x002776c0 symbol=FUN_00277668 lang=c99 */
/* Clone of src/eboot/FUN_00266760.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern u32 FUN_001377d0();
extern u32 FUN_00137a18();
extern void FUN_00277704();

void FUN_00277668(Mover *self)
{
  u8 ready;
  u8 result;
  
  ready = FUN_001377d0(self->unk80);
  if (ready != 0) {
    result = FUN_00137a18(self->unk80);
    self->unk120 = result;
    if (self->unk120 == 0) {
      FUN_00277704(self,1);
    }
  }
}
