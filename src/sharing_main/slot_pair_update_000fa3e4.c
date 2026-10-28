/* HSTMATCH module=hstp_trans_main.prx start=0x000fa3e4 end=0x000fa5a4 symbol=FUN_000fa3e4 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/slot_pair_update_000f4cf0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037eacc;
extern u8 * DAT_003e1e84;
extern unsigned char DAT_003eabd3;
extern unsigned char DAT_003eacf3;
extern void FUN_000e22ec();

void FUN_000fa3e4(int param_1)
{
  int iVar4;
  u32 *puVar3;
  int iVar2;
  u32 *puVar1;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  int iVar8;
  unsigned char local_1;
  u32 local_c [2];
  int local_10;
  
  FUN_000e22ec(DAT_003e1e84,(int *)local_c,&local_1,&local_10);
  *(u8 *)(param_1 + 0x210) = 0;
  *(int *)(param_1 + 0x214) = local_10;
  iVar4 = 0;
  *(u8 *)(param_1 + 0x218) = 1;
  puVar3 = (unsigned int *)(&DAT_0037eacc);
  iVar2 = param_1;
  puVar1 = local_c;
  do {
    iVar8 = puVar3[0xc2];
    if (local_1 != 0) {
      iVar5 = *(int *)(iVar2 + 0x168);
      *(int *)(iVar5 + 0x24) = iVar8 + 4;
      *(int *)(iVar5 + 0x28) = iVar8 + 4;
    }
    else if (local_10 == -1) {
      uVar6 = iVar8 + *puVar1;
      iVar5 = *(int *)(iVar2 + 0x168);
      *(u32 *)(iVar5 + 0x24) = uVar6;
      *(u32 *)(iVar5 + 0x28) = uVar6;
    }
    else if (local_10 == 0) {
      iVar5 = *(int *)(param_1 + 0x168);
      *(int *)(iVar5 + 0x24) = iVar8 + 5;
      *(int *)(iVar5 + 0x28) = iVar8 + 5;
      iVar5 = *(int *)(param_1 + 0x16c);
      *(int *)(iVar5 + 0x24) = iVar8 + 3;
      *(int *)(iVar5 + 0x28) = iVar8 + 3;
    }
    else if (local_10 == 1) {
      iVar5 = *(int *)(param_1 + 0x168);
      *(int *)(iVar5 + 0x24) = iVar8 + 3;
      *(int *)(iVar5 + 0x28) = iVar8 + 3;
      iVar5 = *(int *)(param_1 + 0x16c);
      *(int *)(iVar5 + 0x24) = iVar8 + 5;
      *(int *)(iVar5 + 0x28) = iVar8 + 5;
    }
    uVar7 = *(u32 *)(*(int *)(iVar2 + 0x168) + 0x24);
    iVar5 = *(int *)(iVar2 + 0x170);
    *(u32 *)(iVar5 + 0x24) = uVar7;
    *(u32 *)(iVar5 + 0x28) = uVar7;
    if (local_1 != 0) {
      *(u8 *)(param_1 + iVar4 + 0x204) = 0;
      *(u8 *)(param_1 + 0x210) = 1;
    }
    if ((local_c[0] == DAT_003eabd3) && (local_c[1] == DAT_003eacf3)) {
      *(u8 *)(param_1 + iVar4 + 0x204) = 0;
      *(u8 *)(param_1 + 0x210) = 1;
      *(u8 *)(param_1 + 0x218) = 0;
    }
    else if (local_c[0] == local_c[1]) {
      *(unsigned char *)(param_1 + iVar4 + 0x204) = *(int *)(DAT_003e1e84 + 0x9c) == iVar4;
      *(u8 *)(param_1 + 0x210) = 1;
    }
    else {
      *(unsigned char *)(param_1 + iVar4 + 0x204) = *(int *)(DAT_003e1e84 + 0x9c) == iVar4;
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 3;
    iVar2 = iVar2 + 4;
    puVar1 = puVar1 + 1;
  } while (iVar4 < 2);
  *(u32 *)(param_1 + 0x1f8) = 0;
}
