/* HSTMATCH module=EBOOT.BIN start=0x0006e110 end=0x0006e28c symbol=FUN_0006e110 lang=c99 */
/* Clone of src/sharing_main/FUN_0006f80c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v15) corrected by hand: typed the float global and destinations and factored the indexed offset into Lookup; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_00331c30;
extern void FUN_0005a650();
extern void FUN_0005a670();

static inline int *Lookup(int base)
{
  int offset = *(int *)(base + 0x54) * 4;
  return (int *)(offset + base + 100);
}

void FUN_0006e110(float param_1,float param_2,int param_3)
{
  float uVar1;
  int iVar2;
  
  if (*(int *)(param_3 + 4) != 0) {
    FUN_0005a650(*(int *)(param_3 + 4));
    uVar1 = DAT_00331c30;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x10) = -param_1;
    *(float *)(*Lookup(iVar2) + 0x14) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x18) = param_2;
    uVar1 = DAT_00331c30;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x2c) = param_1;
    *(float *)(*Lookup(iVar2) + 0x30) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x34) = param_2;
    uVar1 = DAT_00331c30;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x48) = -param_1;
    *(float *)(*Lookup(iVar2) + 0x4c) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x50) = -param_2;
    uVar1 = DAT_00331c30;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 100) = param_1;
    *(float *)(*Lookup(iVar2) + 0x68) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x6c) = -param_2;
    FUN_0005a670(*(u32 *)(param_3 + 4),4);
  }
}
