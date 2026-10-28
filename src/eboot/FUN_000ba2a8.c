/* HSTMATCH module=EBOOT.BIN start=0x000ba2a8 end=0x000ba3ac symbol=FUN_000ba2a8 lang=c99 data=0x002d4ab4 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_000ba2a8.c) corrected by hand: inverted the create-result branch and used block-scoped cursor and count locals for the array-clear loop; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002d4ab4-0x002d4b0a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003073f0;
extern u32 * FUN_000114c0();
extern void FUN_000ba3ac();
extern void FUN_000bb9d4();
extern int FUN_002b7890();

u32 * FUN_000ba2a8(u32 *param_1)
{
  int iVar1;
  
  *param_1 = (unsigned int)(&DAT_003073f0);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(u8 *)(param_1 + 0x5e) = 0;
  param_1[0x5b] = 0xffffffff;
  param_1[0x5f] = 0xffffffff;
  param_1[0x66] = 0xffffffff;
  param_1[0x9c] = 0;
  param_1[0xa1] = 0;
  FUN_000bb9d4();
  param_1[0xd] = 0xffffffff;
  iVar1 = FUN_002b7890("AdhocSema",0,1,1,0);
  if (iVar1 > 0) {
    param_1[0xd] = iVar1;
    FUN_000ba3ac("sceKernelCreateSema() success\n");
    param_1[0x9b] = 0;
  } else {
    FUN_000ba3ac("sceKernelCreateSema() failed. ret = 0x%x\n",iVar1);
    param_1[0x9b] = 0;
  }
  {
    int count = 0;
    u32 *cursor = param_1;
    do {
      cursor[0x8b] = 0;
      cursor[0x8c] = 0;
      cursor[0x8d] = 0;
      cursor[0x8e] = 0;
      cursor[0x8f] = 0;
      cursor[0x90] = 0;
      cursor[0x91] = 0;
      count = count + 8;
      cursor[0x92] = 0;
      cursor = cursor + 8;
    } while (count < 0x10);
  }
  *(u8 *)(param_1 + 0x9e) = 0;
  FUN_000114c0(param_1 + 0x9f,0,8);
  return param_1;
}
