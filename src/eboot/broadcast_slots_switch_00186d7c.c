/* HSTMATCH module=EBOOT.BIN start=0x00186d7c end=0x00186ea4 symbol=FUN_00186d7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: Ghidra's if/else-if chain over param_2 is a switch (case 0, 1, 2+3, 4 in source order; retail tests 4,3,2,1,0), with the 0xd0-offset call repeated per case; exact match verified; names and types await human review. */
extern void FUN_00217548(int, int, int, int);

void FUN_00186d7c(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  FUN_00217548(*(int *)(param_1 + 0x2878) + 0xd0,param_3,param_4,param_5);
  FUN_00217548(*(int *)(param_1 + 0x2880) + 0xd0,param_3,param_4,param_5);
  FUN_00217548(*(int *)(param_1 + 0x28a8) + 0xd0,param_3,param_4,param_5);
  switch (param_2) {
  case 0: FUN_00217548(*(int *)(param_1 + 0x2888) + 0xd0,param_3,param_4,param_5); break;
  case 1: FUN_00217548(*(int *)(param_1 + 0x2894) + 0xd0,param_3,param_4,param_5); break;
  case 2:
  case 3: FUN_00217548(*(int *)(param_1 + 0x28a0) + 0xd0,param_3,param_4,param_5); break;
  case 4: break;
  }
}
