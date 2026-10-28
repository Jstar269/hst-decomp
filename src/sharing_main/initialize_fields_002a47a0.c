/* HSTMATCH module=hstp_trans_main.prx start=0x002a47a0 end=0x002a47fc symbol=FUN_002a47a0 lang=c99 */
/* Clone of src/eboot/initialize_fields_00293194.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object and float parameters and an unsigned flag; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003daec4;
extern void FUN_000648f4();

void FUN_002a47a0(void *param_1,float param_2)
{
  *(u8 *)((char *)param_1 + 0x40) = 0;
  *(u32 *)((char *)param_1 + 4) = 0x41f00000;
  *(u32 *)((char *)param_1 + 8) = 0x41f00000;
  *(u32 *)((char *)param_1 + 0x38) = 0;
  *(u32 *)((char *)param_1 + 0x38) = 0x41f80000;
  *(u8 *)((char *)param_1 + 0x4c) = 0;
  *(u8 *)((char *)param_1 + 0x4d) = 0;
  *(float *)((char *)param_1 + 0x50) = param_2;
  *(u8 *)((char *)param_1 + 0x54) = 0;
  if (*(unsigned char *)((char *)param_1 + 0x4e) == 0) {
    FUN_000648f4(DAT_003daec4,0xf);
  }
}
