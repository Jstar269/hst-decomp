/* HSTMATCH module=EBOOT.BIN start=0x001cd8dc end=0x001cd970 symbol=FUN_001cd8dc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); exact match verified; names and types await human review. */
struct False {};
extern "C" void *FUN_000111c0(void *, const void *, unsigned int);

extern "C" int FUN_001cd8dc(int *param_1, int param_2, int param_3, False)
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
