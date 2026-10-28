/* HSTMATCH module=hstp_trans_main.prx start=0x00203128 end=0x00203184 symbol=FUN_00203128 lang=c++ */
/* Clone of src/eboot/FUN_001f4b60_001f4b60.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed the walking object cursor and the integer argument to its virtual method; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003e1a54;
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_00203128(int param_1)
{
  int *piVar1;
  int iVar2;
  int *cursor;
  
  iVar2 = 0;
  cursor = (int *)param_1;
  do {
    piVar1 = *(int **)((int)cursor + 0x3a0);
    if (piVar1 != (int *)0x0) {
      ((VC_0 *)(piVar1))->m((int)(DAT_003e1a54));
    }
    iVar2 = iVar2 + 1;
    cursor = (int *)((int)cursor + 4);
  } while (iVar2 < 4);
}
