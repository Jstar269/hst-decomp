/* HSTMATCH module=hstp_trans_main.prx start=0x00290e24 end=0x00290f00 symbol=FUN_00290e24 lang=c++ */
/* Clone of src/eboot/FUN_0027f9b0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00000a00(...);
extern int FUN_00290f00(...);
}
struct VC_0 {  virtual void m(int); };

extern "C" int * FUN_00290e24(int *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)(*param_1 + param_1[4] * 0x28);
    piVar2 = piVar1 + param_1[1] * 10;
    if (piVar1 < piVar2) {
      do {
        piVar2 = piVar2 + -10;
        ((VC_0 *)(piVar2))->m((int)(0xffffffff));
      } while (piVar1 < piVar2);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if ((param_1 != (int *)0x0) && (FUN_00290f00(param_1), *param_1 != 0)) {
      FUN_00000a00(*(int *)((int)param_1 + 0));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
