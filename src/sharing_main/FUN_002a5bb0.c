/* HSTMATCH module=hstp_trans_main.prx start=0x002a5bb0 end=0x002a5bbc symbol=FUN_002a5bb0 lang=c99 */
/* Clone of src/eboot/FUN_00296920.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_002a5bb0(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 0x3c) + 0x331);
}
