/* HSTMATCH module=hstp_trans_main.prx start=0x000ec4d0 end=0x000ec4e0 symbol=FUN_000ec4d0 lang=c99 */
/* Clone of src/eboot/FUN_000c3f84.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022598();

/* Forwards to the matrix-times-vector helper with the vector and matrix operands swapped. */
void FUN_000ec4d0(u32 out,u32 vec,u32 mtx)
{
  FUN_00022598(out,mtx,vec);
}
