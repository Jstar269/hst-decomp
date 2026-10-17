/* HSTMATCH module=EBOOT.BIN start=0x00127a68 end=0x00127ac0 symbol=FUN_00127a68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the member argument Ghidra dropped from the call restored, the float prototype given, and the comma condition split into nested ifs; exact match verified; names and types await human review. */
extern void FUN_0005f110(int obj, float value);
void FUN_00127a68(int param_1,int param_2,int param_3)
{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_0005f110(*(int *)(param_1 + 0x50), (float)param_2);
    if (param_3 != 0) {
      *(int *)(param_1 + 0x198) = param_2;
    }
  }
}
