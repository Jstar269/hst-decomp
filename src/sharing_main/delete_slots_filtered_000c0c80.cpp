/* HSTMATCH module=hstp_trans_main.prx start=0x000c0c80 end=0x000c0d20 symbol=FUN_000c0c80 lang=c++ */
/* Clone of src/eboot/delete_slots_filtered_000bd704.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the walking pointer (s-register order); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000c0c80(int param_1,int param_2)
{
  int iVar3;
  int iVar2;
  int *piVar1;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    if ((*(int *)(iVar2 + 0x1dc) != 0) && ((param_2 == iVar3 || (param_2 < 0)))) {
      *(u8 *)(param_1 + iVar3 + 0x21c) = 0;
      piVar1 = *(int **)(iVar2 + 0x1dc);
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        *(u32 *)(iVar2 + 0x1dc) = 0;
      }
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0x10);
}
