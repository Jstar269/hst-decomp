/* HSTMATCH module=hstp_trans_main.prx start=0x002c71f0 end=0x002c7258 symbol=FUN_002c71f0 lang=c++ */
/* Clone of src/eboot/vec_destroy_tail_002b7450.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); exact match verified; names and types await human review. */
struct False {};
struct VC_0 { virtual void m(int); };

extern "C" void FUN_002c71f0(int *param_1, int param_2, False)
{
  int *piVar1;

  piVar1 = (int *)(*param_1 + param_1[1] * 8);
  param_1[1] = param_1[1] - param_2;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    piVar1 = piVar1 + -2;
    ((VC_0 *)(piVar1))->m((int)(0xffffffff));
  }
}
