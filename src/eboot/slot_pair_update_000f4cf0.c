/* HSTMATCH module=EBOOT.BIN start=0x000f4cf0 end=0x000f4eb0 symbol=FUN_000f4cf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3, variant v0c) corrected by hand: the flag byte and the two byte globals typed unsigned char, the flag-set case laid out first and the join loads restructured as if/else-if with no else, loop locals declared counter/table/slot/cursor, the sum computed before the slot load and the join read as one load into uVar7; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int uint;
typedef unsigned int undefined4;
typedef unsigned char undefined1;

extern undefined DAT_002d7cf4;
extern undefined * DAT_00338b44;
extern unsigned char DAT_0034189b;
extern unsigned char DAT_003419bb;
extern void FUN_000de100();

void FUN_000f4cf0(int param_1)
{
  int iVar4;
  undefined4 *puVar3;
  int iVar2;
  uint *puVar1;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  unsigned char local_1;
  uint local_c [2];
  int local_10;
  
  FUN_000de100(DAT_00338b44,(int *)local_c,&local_1,&local_10);
  *(undefined1 *)(param_1 + 0x210) = 0;
  *(int *)(param_1 + 0x214) = local_10;
  iVar4 = 0;
  *(undefined1 *)(param_1 + 0x218) = 1;
  puVar3 = (unsigned int *)(&DAT_002d7cf4);
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
      *(uint *)(iVar5 + 0x24) = uVar6;
      *(uint *)(iVar5 + 0x28) = uVar6;
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
    uVar7 = *(undefined4 *)(*(int *)(iVar2 + 0x168) + 0x24);
    iVar5 = *(int *)(iVar2 + 0x170);
    *(undefined4 *)(iVar5 + 0x24) = uVar7;
    *(undefined4 *)(iVar5 + 0x28) = uVar7;
    if (local_1 != 0) {
      *(undefined1 *)(param_1 + iVar4 + 0x204) = 0;
      *(undefined1 *)(param_1 + 0x210) = 1;
    }
    if ((local_c[0] == DAT_0034189b) && (local_c[1] == DAT_003419bb)) {
      *(undefined1 *)(param_1 + iVar4 + 0x204) = 0;
      *(undefined1 *)(param_1 + 0x210) = 1;
      *(undefined1 *)(param_1 + 0x218) = 0;
    }
    else if (local_c[0] == local_c[1]) {
      *(unsigned char *)(param_1 + iVar4 + 0x204) = *(int *)(DAT_00338b44 + 0x9c) == iVar4;
      *(undefined1 *)(param_1 + 0x210) = 1;
    }
    else {
      *(unsigned char *)(param_1 + iVar4 + 0x204) = *(int *)(DAT_00338b44 + 0x9c) == iVar4;
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 3;
    iVar2 = iVar2 + 4;
    puVar1 = puVar1 + 1;
  } while (iVar4 < 2);
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  return;
}
