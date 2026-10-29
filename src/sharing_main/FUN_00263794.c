/* HSTMATCH module=hstp_trans_main.prx start=0x00263794 end=0x002637c0 symbol=FUN_00263794 lang=c99 */
/* Clone of src/eboot/FUN_00253440.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/sel_obj.h"

extern void FUN_002637c0(SelObj *, int);

/* Clears the flag and refreshes the handle; `enable` is forwarded unchanged (Ghidra dropped it). */
SelObj * FUN_00263794(SelObj *obj, int enable)
{
  obj->unk34 = 0;
  FUN_002637c0(obj, enable);
  return obj;
}
