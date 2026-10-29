/* HSTMATCH module=hstp_trans_main.prx start=0x0028d104 end=0x0028d128 symbol=FUN_0028d104 lang=c99 */
/* Clone of src/eboot/FUN_001233bc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0028dacc();
extern void FUN_0028df98();

/* Passes the result of FUN_0028dacc on to FUN_0028df98. */
void FUN_0028d104(void)
{
  u32 value;
  
  value = FUN_0028dacc();
  FUN_0028df98(value);
}
