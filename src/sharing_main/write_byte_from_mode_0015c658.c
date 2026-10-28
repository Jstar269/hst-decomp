/* HSTMATCH module=hstp_trans_main.prx start=0x0015c658 end=0x0015c6c4 symbol=FUN_0015c658 lang=c99 */
/* Clone of src/eboot/write_byte_from_mode_00150620.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: early `if (FUN(...) == 0) { ...; return 1; } return 0;` shape, int (not bool) return on the gate; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f344c;
extern int FUN_00157e10();
extern int FUN_001db8b8();
extern u8 FUN_001db96c();

bool FUN_0015c658(int param_1,u32 *param_2)
{
  u32 v;

  if (FUN_001db8b8(DAT_003f344c) == 0) {
    v = *param_2;
    *(u32 *)FUN_00157e10(v,*(u32 *)(*(int *)(param_1 + 4) + 0xc)) =
         FUN_001db96c(DAT_003f344c) & 0xff;
    return 1;
  }
  return 0;
}
