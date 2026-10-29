/* HSTMATCH module=hstp_trans_main.prx start=0x0022a868 end=0x0022a89c symbol=FUN_0022a868 lang=c99 */
/* Clone of src/eboot/FUN_0021b2f4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

/* Runs the base action while the tick count at 0x8c is positive and the flag at 0x5c is clear. */
void FUN_0022a868(int self)
{
  if ((0 < *(int *)(self + 0x8c)) && (*(u8 *)(self + 0x5c) == '\0')) {
    FUN_00108aec();
  }
}
