/* HSTMATCH module=hstp_trans_main.prx start=0x00212bfc end=0x00212c68 symbol=FUN_00212bfc lang=c++ */
/* Clone of src/eboot/FUN_00204394_00204394.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: used a typed C++ virtual method call; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 * DAT_003f3480;
extern int * DAT_003f3484;
extern void FUN_000009e4(void *);
void FUN_00212bfc(void);
}

struct VC_0 { virtual void m(int); };

extern "C" void FUN_00212bfc(void)
{
  if (DAT_003f3480 != 0) {
    if (DAT_003f3480 != 0) {
      FUN_000009e4(DAT_003f3480 + -0x10);
    }
    DAT_003f3480 = 0;
  }
  if (DAT_003f3484 != (int *)0x0) {
    if (DAT_003f3484 != (int *)0x0) {
      ((VC_0 *)DAT_003f3484)->m(1);
    }
    DAT_003f3484 = (int *)0x0;
  }
}
