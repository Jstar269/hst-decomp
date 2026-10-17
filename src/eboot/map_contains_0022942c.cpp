/* HSTMATCH module=EBOOT.BIN start=0x0022942c end=0x00229470 symbol=FUN_0022942c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, char* pointer types, extern "C" linkage; exact match verified; names and types await human review. */

extern "C" void FUN_00229868(void*, const void*, const void*);

extern "C" bool FUN_0022942c(char *param_1, int param_2)
{
  char *local_4;
  int local_8 = param_2;
  
  FUN_00229868(&local_4, param_1, &local_8);
  return local_4 != param_1 + 4;
}
