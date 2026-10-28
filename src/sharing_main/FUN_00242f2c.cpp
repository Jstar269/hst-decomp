/* HSTMATCH module=hstp_trans_main.prx start=0x00242f2c end=0x00242fc4 symbol=FUN_00242f2c lang=c++ */
/* Clone of src/eboot/FUN_00232e2c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" void FUN_00242f2c(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *param_1 = 0;
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    param_1[1] = 0;
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    delete ((VC_2 *)(piVar1));
    param_1[2] = 0;
  }
}
