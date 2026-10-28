/* HSTMATCH module=EBOOT.BIN start=0x00051118 end=0x000511c4 symbol=FUN_00051118 lang=c99 */
/* Clone of src/sharing_main/init_fields_00051a2c.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_00051398 as taking a float and passed 2000.0f; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051398(float);
extern void FUN_000513a0();
extern void FUN_000513e4();
extern void FUN_000513ec();
extern void FUN_000513f4();
extern void FUN_000513fc();

void FUN_00051118(int param_1)
{
  *(u32 *)(param_1 + 4) = 0xffffffff;
  *(u32 *)(param_1 + 8) = 0;
  *(u32 *)(param_1 + 0xc) = 0;
  *(u32 *)(param_1 + 0x10) = 0x3f800000;
  *(u32 *)(param_1 + 0x14) = 0x3f800000;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  *(u32 *)(param_1 + 0x30) = 0;
  *(u32 *)(param_1 + 0x34) = 0;
  *(u32 *)(param_1 + 0x38) = 0;
  FUN_00051398(2000.0f);
  FUN_000513a0(param_1,0);
  *(u8 *)(param_1 + 0x21) = 1;
  FUN_000513fc(param_1,0);
  *(u8 *)(param_1 + 0x22) = 1;
  FUN_000513e4(param_1,0);
  FUN_000513ec(param_1,0);
  FUN_000513f4(param_1,0);
}
