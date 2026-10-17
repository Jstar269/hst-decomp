/* HSTMATCH module=hstp_trans_main.prx start=0x001572ac end=0x00157330 symbol=FUN_001572ac lang=c++ */
/* Clone of src/eboot/vdtor_inner_deleting_0014b998.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: member at +8 is deleted through a virtual deleting destructor (`delete m;` on a class with `virtual ~VC_0()`), C++ rather than C; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b1710;
extern char DAT_003b172c;
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" unsigned int *FUN_001572ac(unsigned int *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (unsigned int)&DAT_003b1710;
    VC_0 *m = (VC_0 *)param_1[2];
    delete m;
    if (param_1 != 0) {
      *param_1 = (unsigned int)&DAT_003b172c;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
