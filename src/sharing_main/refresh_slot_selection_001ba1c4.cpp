/* HSTMATCH module=hstp_trans_main.prx start=0x001ba1c4 end=0x001ba298 symbol=FUN_001ba1c4 lang=c++ */
/* Clone of src/eboot/refresh_slot_selection_001acb5c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5, variant v17) corrected by hand: the loop bound read through a pointer to the sub-object at +0x360 (reloaded each iteration), the element address written (param_1 + (offset + 0x7bc)) + 9 words, locals declared counter/selected/offset; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern "C" {
extern void FUN_00105470(...);
extern void FUN_00111b58(...);
extern undefined4 FUN_001aa91c(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct List { int pad; unsigned size; };
struct Obj { char pad[0x360]; List l; };

extern "C" void FUN_001ba1c4(int param_1,int param_2)
{
  int iVar1;
  int *puVar2;
  List *pl;
  unsigned uVar6;
  unsigned uVar5;
  int iVar4;

  iVar1 = FUN_001aa91c();
  uVar5 = *(unsigned *)(iVar1 + 0x2dc);
  if (param_2 != 0) {
    ((VC_0 *)(*(int **)(param_1 + 0x914)))->m((int)(0));
    FUN_00111b58(*(undefined4 *)(param_1 + 0x914),uVar5,0);
  }
  iVar1 = FUN_001aa91c();
  pl = (List *)(iVar1 + 0x360);
  uVar6 = 0;
  if (*(int *)(iVar1 + 0x364) != 0) {
    iVar4 = 0;
    do {
      puVar2 = (int *)(param_1 + (iVar4 + 0x7bc)) + 9;
      if (uVar5 == uVar6) {
        FUN_00105470(*puVar2,0);
      }
      else {
        FUN_00105470(*puVar2,1);
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x14;
    } while (uVar6 < pl->size);
  }
}
