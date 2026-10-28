/* HSTMATCH module=EBOOT.BIN start=0x00148ee8 end=0x00148fd0 symbol=FUN_00148ee8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: passed empty tag objects by value to both calls and retained address-named callees; exact match verified; names and types await human review. */

struct EmptyTag {};
extern "C" void FUN_00148fd0(int *, int, int, EmptyTag);
extern "C" void FUN_00149078(int *, int, int, EmptyTag);

extern "C" int FUN_00148ee8(int *param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  FUN_00149078(param_2,param_3,iVar2 + param_1[1] * 0x28,EmptyTag());
  FUN_00148fd0(param_2,*param_1,param_3,EmptyTag());
  iVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = iVar1;
  iVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = iVar1;
  iVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = iVar1;
  return *param_1 + ((param_3 - iVar2) / 0x28) * 0x28;
}
