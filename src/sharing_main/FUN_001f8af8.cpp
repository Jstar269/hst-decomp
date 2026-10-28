/* HSTMATCH module=hstp_trans_main.prx start=0x001f8af8 end=0x001f8b68 symbol=FUN_001f8af8 lang=c++ */
/* Clone of src/eboot/FUN_0011aa84.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_001f8af8(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *param_1 = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
