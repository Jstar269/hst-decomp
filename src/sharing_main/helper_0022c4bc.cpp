/* HSTMATCH module=hstp_trans_main.prx start=0x0022c4bc end=0x0022c5a0 symbol=FUN_0022c4bc lang=c++ */
/* Clone of src/eboot/helper_0021cf48.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: typed the four-slot interface and materialized the 64-unit divisor; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
void FUN_000f3588(float param_1,float param_2,float param_3,float param_4,float param_5,int param_6,u32 *param_7,int param_8,int param_9);
void FUN_00108aec(int);
}

struct VC_21cf48 {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
};

extern "C" void FUN_0022c4bc(int param_1)
{
  int iVar1;
  u32 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(unsigned char *)(param_1 + 0x54) == 0) {
    FUN_00108aec(param_1);
    if (*(VC_21cf48 **)(param_1 + 0xbc) != (VC_21cf48 *)0x0) {
      (*(VC_21cf48 **)(param_1 + 0xbc))->slot3();
    }
    iVar1 = *(int *)(param_1 + 0xb8);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
      puVar2 = *(u32 **)(param_1 + 0x78);
      iVar4 = *(int *)(param_1 + 0x68);
      iVar5 = iVar1 / 64;
      iVar3 = *(int *)(param_1 + 0xd8);
      *puVar2 = (unsigned char)(int)(*(float *)(iVar4 + 0x78) * 128.0f) << 0x18 | 0x808080;
      FUN_000f3588(*(float *)(iVar4 + 0x60),*(float *)(iVar4 + 100),0.5625f,1.0f,1.0f,
                   *(int *)(param_1 + 0xb8),puVar2,iVar3 % iVar5 << 6,
                   iVar3 / iVar5 << 6);
    }
  }
}
