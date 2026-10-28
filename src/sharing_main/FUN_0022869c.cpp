/* HSTMATCH module=hstp_trans_main.prx start=0x0022869c end=0x00228728 symbol=FUN_0022869c lang=c++ */
/* Clone of src/eboot/FUN_00219184.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
extern void FUN_000006e8(...);
extern void FUN_00000a00(...);
extern void FUN_002285fc(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_0022869c(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    if (param_1[1] != 0) {
      FUN_000006e8(param_1[1],FUN_002285fc);
      param_1[1] = 0;
    }
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
