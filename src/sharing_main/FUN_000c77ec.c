/* HSTMATCH module=hstp_trans_main.prx start=0x000c77ec end=0x000c77fc symbol=FUN_000c77ec lang=c99 */
/* Clone of src/eboot/FUN_000c3f84.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022570();

/* Forwards to the matrix-times-vector helper with the vector and matrix operands swapped. */
void FUN_000c77ec(u32 out,u32 vec,u32 mtx)
{
  FUN_00022570(out,mtx,vec);
}
