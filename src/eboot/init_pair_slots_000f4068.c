/* HSTMATCH module=EBOOT.BIN start=0x000f4068 end=0x000f4100 symbol=FUN_000f4068 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order reversed (iVar6 first), pointer inits in reverse order, uVar2 loaded before iVar1 in the last two blocks; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

void FUN_000f4068(int param_1)
{
  int iVar6;
  int iVar5;
  int iVar4;
  int iVar3;
  undefined4 uVar2;
  int iVar1;
  
  iVar6 = 0;
  iVar5 = param_1;
  iVar4 = param_1;
  iVar3 = param_1;
  do {
    iVar6 = iVar6 + 1;
    **(undefined4 **)(iVar5 + 0x140) = 0x33000000;
    **(undefined4 **)(iVar5 + 0x148) = 0x33000000;
    uVar2 = *(undefined4 *)(iVar4 + 0x1e0);
    iVar1 = *(int *)(iVar3 + 0x128);
    iVar5 = iVar5 + 4;
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = uVar2;
    uVar2 = *(undefined4 *)(iVar4 + 0x1e4);
    iVar1 = *(int *)(iVar3 + 300);
    iVar4 = iVar4 + 8;
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = uVar2;
    uVar2 = *(undefined4 *)(*(int *)(iVar3 + 0x128) + 0x24);
    iVar1 = *(int *)(iVar3 + 0x120);
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = uVar2;
    uVar2 = *(undefined4 *)(*(int *)(iVar3 + 300) + 0x24);
    iVar1 = *(int *)(iVar3 + 0x124);
    iVar3 = iVar3 + 0x10;
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = uVar2;
  } while (iVar6 < 2);
  *(undefined4 *)(param_1 + 0x1c4) = 0x14;
  *(undefined4 *)(param_1 + 0x1c8) = 0x3f800000;
  return;
}
