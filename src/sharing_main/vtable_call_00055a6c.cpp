/* HSTMATCH module=hstp_trans_main.prx start=0x00055a6c end=0x00055ad0 symbol=FUN_00055a6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: modeled the indirect dispatch as a typed virtual call and retained C linkage for the delete helper; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02a0;
extern "C" void FUN_00000a00(int *);

struct VC_00055a6c {
  virtual ~VC_00055a6c();
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};

extern "C" int * FUN_00055a6c(int *param_1,short param_2)
{
  if (param_1 != (int *)0x0) {
    *param_1 = (int)&DAT_003b02a0;
    ((VC_00055a6c *)param_1)->s2();
    if (0 < param_2) FUN_00000a00(param_1);
  }
  return param_1;
}
