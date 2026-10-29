/* HSTMATCH module=EBOOT.BIN start=0x0025346c end=0x002534b4 symbol=FUN_0025346c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the nested mode and byte arms and made the byte unsigned; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sel_obj.h"

extern int FUN_001d9cfc(char *, int);

/* Refreshes the handle: mode 0 when `enable` is 0, otherwise 2 if unk34 is set and 1 if not. */
void FUN_0025346c(SelObj *obj,int enable)
{
  u32 mode;
  
  if (enable != 0) {
    if (obj->unk34 != 0) {
      mode = 2;
    }
    else {
      mode = 1;
    }
  }
  else {
    mode = 0;
  }
  mode = FUN_001d9cfc(obj->sub3c,mode);
  obj->handle = mode;
}
