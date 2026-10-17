/* HSTMATCH module=hstp_trans_main.prx start=0x002389a0 end=0x002389e4 symbol=FUN_002389a0 lang=c++ */
/* Clone of src/eboot/map_contains_0022942c.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, char* pointer types, extern "C" linkage; exact match verified; names and types await human review. */

extern "C" void FUN_00238ddc(void*, const void*, const void*);

extern "C" bool FUN_002389a0(char *param_1, int param_2)
{
  char *local_4;
  int local_8 = param_2;
  
  FUN_00238ddc(&local_4, param_1, &local_8);
  return local_4 != param_1 + 4;
}
