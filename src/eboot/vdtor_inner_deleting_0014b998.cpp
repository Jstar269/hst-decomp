/* HSTMATCH module=EBOOT.BIN start=0x0014b998 end=0x0014ba1c symbol=FUN_0014b998 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: member at +8 is deleted through a virtual deleting destructor (`delete m;` on a class with `virtual ~VC_0()`), C++ rather than C; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_00308444;
extern char DAT_00308460;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" unsigned int *FUN_0014b998(unsigned int *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (unsigned int)&DAT_00308444;
    VC_0 *m = (VC_0 *)param_1[2];
    delete m;
    if (param_1 != 0) {
      *param_1 = (unsigned int)&DAT_00308460;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
