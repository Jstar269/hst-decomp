/* HSTMATCH module=EBOOT.BIN start=0x00054f4c end=0x00054fb0 symbol=FUN_00054f4c lang=c++ */
/* Clone of src/sharing_main/vtable_call_00055a6c.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: modeled the indirect dispatch as a typed virtual call and retained C linkage for the delete helper; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fd4;
extern "C" void FUN_00000a00(int *);

struct VC_00054f4c {
  virtual ~VC_00054f4c();
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};

extern "C" int * FUN_00054f4c(int *param_1,short param_2)
{
  if (param_1 != (int *)0x0) {
    *param_1 = (int)&DAT_00306fd4;
    ((VC_00054f4c *)param_1)->s2();
    if (0 < param_2) FUN_00000a00(param_1);
  }
  return param_1;
}
