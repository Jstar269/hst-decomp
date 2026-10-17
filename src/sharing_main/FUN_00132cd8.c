/* HSTMATCH module=hstp_trans_main.prx start=0x00132cd8 end=0x00132d30 symbol=FUN_00132cd8 lang=c99 */
/* Clone of src/eboot/FUN_00127a68.c (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the member argument Ghidra dropped from the call restored, the float prototype given, and the comma condition split into nested ifs; exact match verified; names and types await human review. */
extern void FUN_0005ff00(int obj, float value);
void FUN_00132cd8(int param_1,int param_2,int param_3)
{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_0005ff00(*(int *)(param_1 + 0x50), (float)param_2);
    if (param_3 != 0) {
      *(int *)(param_1 + 0x198) = param_2;
    }
  }
}
