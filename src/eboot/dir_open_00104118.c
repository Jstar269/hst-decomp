/* HSTMATCH module=EBOOT.BIN start=0x00104118 end=0x001041dc symbol=FUN_00104118 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: constructed object kept as a pointer and passed on (null stays null, no zero-extend through uint); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d8a5c;
extern char DAT_002d8c60[];
extern void * FUN_00000bcc();
extern u32 * FUN_000149a8();
extern int FUN_00014cfc();
extern int * FUN_000649c0();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern void FUN_001006b0();
extern void FUN_001041f4();

void FUN_00104118(int param_1,u32 param_2,u32 param_3)
{
  int iVar1;
  int *mem;
  u8 auStack_100 [256];
  
  mem = (int *)FUN_00000bcc(0x10);
  if (mem != 0) {
    mem = FUN_000649c0(mem);
  }
  *(int **)(param_1 + 0x1c) = mem;
  FUN_00064bf4(mem,param_2,1,&DAT_002d8a5c);
  iVar1 = FUN_000650e0(*(u32 *)(param_1 + 0x1c));
  if (iVar1 < 1) {
    FUN_001006b0(DAT_002d8c60,param_2);
  }
  else {
    FUN_000149a8(auStack_100,param_2);
    iVar1 = FUN_00014cfc(auStack_100,0x2f);
    *(u8 *)(iVar1 + 1) = 0;
    *(u8 **)(param_1 + 0x20) = auStack_100;
    FUN_001041f4(param_1,param_2,param_3);
  }
}
