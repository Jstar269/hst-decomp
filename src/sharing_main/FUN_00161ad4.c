/* HSTMATCH module=hstp_trans_main.prx start=0x00161ad4 end=0x00161afc symbol=FUN_00161ad4 lang=c99 */
/* Clone of src/eboot/FUN_00155604.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00299f90();

u32 FUN_00161ad4(int param_1)
{
  FUN_00299f90(*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0xc),1000);
  return 0;
}
