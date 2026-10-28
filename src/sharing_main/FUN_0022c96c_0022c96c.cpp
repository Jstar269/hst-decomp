/* HSTMATCH module=hstp_trans_main.prx start=0x0022c96c end=0x0022c9ec symbol=FUN_0022c96c lang=c++ */
/* Clone of src/eboot/FUN_0021d3f8_0021d3f8.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5/v17) corrected by hand: declared the loop index before the cursor and materialized the lookup offset before adding the base; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0022c96c(int param_1)
{
  int *piVar1;
  int iVar3;
  int iVar2;
  int iVar4;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    ((VC_0 *)(*(int **)(iVar2 + 0x70)))->m((int)(1));
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 3);
  iVar4 = *(int *)(param_1 + 0x68) * 4;
  piVar1 = *(int **)(iVar4 + param_1 + 0x70);
  ((VC_1 *)(piVar1))->m((int)(0));
  *(u8 *)(param_1 + 0x54) = 0;
}

