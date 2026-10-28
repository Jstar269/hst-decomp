/* HSTMATCH module=EBOOT.BIN start=0x00184afc end=0x00184dd8 symbol=FUN_00184afc lang=c++ */
/* Clone of src/sharing_main/pack_two_colors_00191248.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the or chain is right-nested (a | (b | (c | 0x80000000))); a left-nested chain gives 56-68 differing words. Labels 0..3 are written in ascending order (MWCC tests them in reverse). */
#include "hst/types.h"
extern "C" {
extern int *FUN_0016bc8c();
extern int FUN_00216de8(int);
}
static inline u32 PackColor(u16 r, u16 g, u16 b)
{
  return (r & 0xff) | (((g & 0xff) << 8) | (((b & 0xff) << 16) | 0x80000000));
}

extern "C" void FUN_00184afc(int param_1, u32 *param_2, u32 *param_3, int param_4)
{
  int *puVar1 = FUN_0016bc8c();
    u16 uVar2;
  u16 uVar3;
  u16 uVar4;
  u16 uVar5;
  u16 uVar6;
  u16 uVar7;
  switch (param_4) {
  case 0:
    uVar2 = FUN_00216de8(puVar1[0]);
    uVar3 = FUN_00216de8(puVar1[1]);
    uVar4 = FUN_00216de8(puVar1[2]);
    uVar5 = FUN_00216de8(puVar1[12]);
    uVar6 = FUN_00216de8(puVar1[13]);
    uVar7 = FUN_00216de8(puVar1[14]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 1:
    uVar2 = FUN_00216de8(puVar1[3]);
    uVar3 = FUN_00216de8(puVar1[4]);
    uVar4 = FUN_00216de8(puVar1[5]);
    uVar5 = FUN_00216de8(puVar1[15]);
    uVar6 = FUN_00216de8(puVar1[16]);
    uVar7 = FUN_00216de8(puVar1[17]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 2:
    uVar2 = FUN_00216de8(puVar1[6]);
    uVar3 = FUN_00216de8(puVar1[7]);
    uVar4 = FUN_00216de8(puVar1[8]);
    uVar5 = FUN_00216de8(puVar1[18]);
    uVar6 = FUN_00216de8(puVar1[19]);
    uVar7 = FUN_00216de8(puVar1[20]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 3:
    uVar2 = FUN_00216de8(puVar1[9]);
    uVar3 = FUN_00216de8(puVar1[10]);
    uVar4 = FUN_00216de8(puVar1[11]);
    uVar5 = FUN_00216de8(puVar1[21]);
    uVar6 = FUN_00216de8(puVar1[22]);
    uVar7 = FUN_00216de8(puVar1[23]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  }
}
