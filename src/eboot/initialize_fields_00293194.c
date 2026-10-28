/* HSTMATCH module=EBOOT.BIN start=0x00293194 end=0x002931f0 symbol=FUN_00293194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object and float parameters and an unsigned flag; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331b84;
extern void FUN_00063a30();

void FUN_00293194(void *param_1,float param_2)
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
    FUN_00063a30(DAT_00331b84,0xf);
  }
}
