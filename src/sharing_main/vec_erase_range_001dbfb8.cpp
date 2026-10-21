/* HSTMATCH module=hstp_trans_main.prx start=0x001dbfb8 end=0x001dc04c symbol=FUN_001dbfb8 lang=c++ */
/* Clone of src/eboot/vec_erase_range_001cd8dc.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); exact match verified; names and types await human review. */
struct False {};
extern "C" void *FUN_000111c0(void *, const void *, unsigned int);

extern "C" int FUN_001dbfb8(int *param_1, int param_2, int param_3, False)
{
  int iVar1;

  if (param_2 != param_3) {
    iVar1 = (*param_1 + param_1[1] * 4) - param_3;
    FUN_000111c0((void *)param_2, (const void *)param_3, (unsigned int)((iVar1 / 4) << 2));
    param_3 = param_3 - param_2;
    param_1[1] = param_1[1] - (param_3 / 4);
  }
  return param_2;
}
