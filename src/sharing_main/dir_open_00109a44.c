/* HSTMATCH module=hstp_trans_main.prx start=0x00109a44 end=0x00109b08 symbol=FUN_00109a44 lang=c99 */
/* Clone of src/eboot/dir_open_00104118.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: constructed object kept as a pointer and passed on (null stays null, no zero-extend through u32); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037f7fc;
extern char DAT_0037fa34[];
extern void * FUN_00000bcc();
extern u32 * FUN_000149a8();
extern int FUN_00014cfc();
extern int * FUN_00065884();
extern u32 FUN_00065ab8();
extern u32 FUN_00065fa4();
extern void FUN_0010532c();
extern void FUN_00109b20();

void FUN_00109a44(int param_1,u32 param_2,u32 param_3)
{
  int iVar1;
  int *mem;
  u8 auStack_100 [256];
  
  mem = (int *)FUN_00000bcc(0x10);
  if (mem != 0) {
    mem = FUN_00065884(mem);
  }
  *(int **)(param_1 + 0x1c) = mem;
  FUN_00065ab8(mem,param_2,1,&DAT_0037f7fc);
  iVar1 = FUN_00065fa4(*(u32 *)(param_1 + 0x1c));
  if (iVar1 < 1) {
    FUN_0010532c(DAT_0037fa34,param_2);
  }
  else {
    FUN_000149a8(auStack_100,param_2);
    iVar1 = FUN_00014cfc(auStack_100,0x2f);
    *(u8 *)(iVar1 + 1) = 0;
    *(u8 **)(param_1 + 0x20) = auStack_100;
    FUN_00109b20(param_1,param_2,param_3);
  }
}
