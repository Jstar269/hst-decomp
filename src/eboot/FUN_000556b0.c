/* HSTMATCH module=EBOOT.BIN start=0x000556b0 end=0x00055724 symbol=FUN_000556b0 lang=c99 */
/* Clone of src/sharing_main/FUN_0005625c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022498(float, int, int);
extern void FUN_00054010();

void FUN_000556b0(int param_1,int param_2)
{
  float fVar1;
  
  FUN_00054010(*(u32 *)(param_1 + 0x8c));
  fVar1 = *(float *)(param_1 + 0x88) / *(float *)(param_1 + 0x84);
  FUN_00022498((float)(fVar1),(int)(param_2),(int)(param_2));
  FUN_00022498((float)(fVar1),(int)(param_2 + 0x10),(int)(param_2 + 0x10));
  *(float *)(param_2 + 0x1c) = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc);
}
