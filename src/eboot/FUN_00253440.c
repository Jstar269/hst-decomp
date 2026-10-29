/* HSTMATCH module=EBOOT.BIN start=0x00253440 end=0x0025346c symbol=FUN_00253440 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/sel_obj.h"

extern void FUN_0025346c(SelObj *, int);

/* Clears the flag and refreshes the handle; `enable` is forwarded unchanged (Ghidra dropped it). */
SelObj * FUN_00253440(SelObj *obj, int enable)
{
  obj->unk34 = 0;
  FUN_0025346c(obj, enable);
  return obj;
}
