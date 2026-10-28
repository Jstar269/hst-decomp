/* HSTMATCH module=hstp_trans_main.prx start=0x001fa758 end=0x001fa7c8 symbol=FUN_001fa758 lang=c++ */
/* Clone of src/eboot/FUN_001ec418.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_001fa758(int *param_1)
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
}
