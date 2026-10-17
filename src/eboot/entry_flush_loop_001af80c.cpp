/* HSTMATCH module=EBOOT.BIN start=0x001af80c end=0x001af8d8 symbol=FUN_001af80c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: declaration order (sets the saved registers), a pointer to the iVar1+0x360 block for the loop count reads, and the entry address grouped as (iVar4 + (iVar5 + 0x7bc)) + 9; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_0010b980(...);
extern undefined4 FUN_0019d474(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001af80c(int param_1)
{
  uint uVar7;
  uint uVar6;
  int iVar5;
  int iVar4;
  uint *puVar5;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar1 = FUN_0019d474();
  uVar6 = *(uint *)(iVar1 + 0x2dc);
  ((VC_0 *)(*(int **)(iVar4 + 0x914)))->m((int)(0));
  FUN_0010b980(*(undefined4 *)(iVar4 + 0x914),uVar6,0);
  iVar1 = FUN_0019d474();
  puVar5 = (uint *)(iVar1 + 0x360);
  uVar7 = 0;
  if (*(int *)(iVar1 + 0x364) != 0) {
    iVar5 = 0;
    do {
      puVar2 = (undefined4 *)(iVar4 + (iVar5 + 0x7bc)) + 9;
      if (uVar6 == uVar7) {
        FUN_000ffb3c(*puVar2,0);
        uVar3 = puVar5[1];
      }
      else {
        FUN_000ffb3c(*puVar2,1);
        uVar3 = puVar5[1];
      }
      uVar7 = uVar7 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar7 < uVar3);
  }
  return;
}
