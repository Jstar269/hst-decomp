/* HSTMATCH module=hstp_trans_main.prx start=0x001bc520 end=0x001bc52c symbol=FUN_001bc520 lang=c99 */
/* Clone of src/eboot/FUN_001aee48.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001bc520(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 8) + 0xaa4);
}
