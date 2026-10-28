/* HSTMATCH module=hstp_trans_main.prx start=0x002412cc end=0x00241314 symbol=FUN_002412cc lang=c++ */
/* Clone of src/eboot/FUN_0021ab00.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_002412cc(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *param_1 = 0;
  }
}
