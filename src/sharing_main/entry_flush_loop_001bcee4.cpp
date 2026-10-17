/* HSTMATCH module=hstp_trans_main.prx start=0x001bcee4 end=0x001bcfb0 symbol=FUN_001bcee4 lang=c++ */
/* Clone of src/eboot/entry_flush_loop_001af80c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: declaration order (sets the saved registers), a pointer to the iVar1+0x360 block for the loop count reads, and the entry address grouped as (iVar4 + (iVar5 + 0x7bc)) + 9; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned int undefined4;
extern "C" {
extern void FUN_00105470(...);
extern void FUN_00111b58(...);
extern undefined4 FUN_001aa91c(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001bcee4(int param_1)
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
  iVar1 = FUN_001aa91c();
  uVar6 = *(uint *)(iVar1 + 0x2dc);
  ((VC_0 *)(*(int **)(iVar4 + 0x914)))->m((int)(0));
  FUN_00111b58(*(undefined4 *)(iVar4 + 0x914),uVar6,0);
  iVar1 = FUN_001aa91c();
  puVar5 = (uint *)(iVar1 + 0x360);
  uVar7 = 0;
  if (*(int *)(iVar1 + 0x364) != 0) {
    iVar5 = 0;
    do {
      puVar2 = (undefined4 *)(iVar4 + (iVar5 + 0x7bc)) + 9;
      if (uVar6 == uVar7) {
        FUN_00105470(*puVar2,0);
        uVar3 = puVar5[1];
      }
      else {
        FUN_00105470(*puVar2,1);
        uVar3 = puVar5[1];
      }
      uVar7 = uVar7 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar7 < uVar3);
  }
  return;
}
