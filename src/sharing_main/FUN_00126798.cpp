/* HSTMATCH module=hstp_trans_main.prx start=0x00126798 end=0x00126808 symbol=FUN_00126798 lang=c++ */
/* Clone of src/eboot/FUN_0011aa84.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_00126798(int *param_1,short param_2)
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
