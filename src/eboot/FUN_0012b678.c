/* HSTMATCH module=EBOOT.BIN start=0x0012b678 end=0x0012b6e8 symbol=FUN_0012b678 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern void FUN_0012a254();
extern u32 FUN_0012c364();
extern u32 FUN_0012c5ac();

/* If the parts object is ready, records its result and the flag; with no result, starts state 12. */
void FUN_0012b678(Avatar *self,u32 unusedA,u32 unusedB,u8 flag)
{
  u8 ready;
  u8 result;
  
  ready = FUN_0012c364(&self->parts370);
  if (ready != '\0') {
    result = FUN_0012c5ac(&self->parts370);
    self->unk410 = result;
    self->unk32c = flag;
    if (self->unk410 == '\0') {
      FUN_0012a254(self,0xc,0xffffffff,0);
    }
  }
}
