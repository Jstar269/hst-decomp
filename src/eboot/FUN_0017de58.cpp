/* HSTMATCH module=EBOOT.BIN start=0x0017de58 end=0x0017df2c symbol=FUN_0017de58 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed the float stack record and modeled the singleton member call; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" int FUN_0016bc7c();
struct Receiver {
  void FUN_0018ba64(float,float,float,int *,int,int,int,float *);
};

extern "C" Receiver *FUN_0018b804();
extern "C" int FUN_00193474(u32);
extern "C" int FUN_00204400(u32);

extern "C" void FUN_0017de58(int param_1,u32 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 uVar5;
  float f0;
  float f1;
  float f2;
  float local[4];
  
  iVar1 = FUN_0016bc7c();
  iVar2 = FUN_00204400(param_2);
  iVar3 = FUN_00193474(param_2);
  if (*(u8 *)(iVar3 + 0x24) == '\0') {
    uVar5 = 4;
  }
  else {
    uVar5 = 2;
  }
  f0 = *(float *)(iVar1 + 0x24);
  f1 = *(float *)(iVar1 + 0x2c);
  f2 = *(float *)(iVar1 + 0x28);
  local[0] = f0;
  local[1] = f2;
  local[2] = f1;
  local[3] = 0.0f;
  FUN_0018b804()->FUN_0018ba64(*(float *)(iVar2 + 4),*(float *)(iVar2 + 8),*(float *)(iVar2 + 0xc),
                               (int *)(*(int *)(*(int *)(param_1 + 8) + param_3 * 4) + 0x10),param_2,param_3,uVar5,
                               local);
}
