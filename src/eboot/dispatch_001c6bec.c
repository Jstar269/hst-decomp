/* HSTMATCH module=EBOOT.BIN start=0x001c6bec end=0x001c6cac symbol=FUN_001c6bec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct nonnegative signed guard; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/gimmick_mgr.h"

extern void FUN_001c25b0();
extern void FUN_001c2714();
extern void FUN_0022bf94();

enum { ID_LIMIT = 0x11 };

/* Forwards a request with id below ID_LIMIT to the manager's state (two helper variants depending on variant < 0), then resets unk154. */
void FUN_001c6bec(GimmickMgr *self,int id,u32 value,int variant,u32 arg4, u32 arg5)
{
  if (id < ID_LIMIT) {
    if (id >= 0) {
      FUN_0022bf94(id,value);
    }
    if (variant < 0) {
      FUN_001c25b0(self->state,id,value,arg4,arg5);
    }
    else {
      FUN_001c2714(self->state,variant,id,value,arg4,arg5);
    }
    self->unk154 = -1;
  }
}
