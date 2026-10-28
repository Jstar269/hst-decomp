/* HSTMATCH module=hstp_trans_main.prx start=0x001d50d4 end=0x001d511c symbol=FUN_001d50d4 lang=c99 */
/* Clone of src/eboot/check_001c6cac.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: return condition variable directly and negate equality !(x == 1); exact match verified; names and types await human review. */

int FUN_001d50d4(int param_1)
{
  int iVar3 = *(int *)(param_1 + 0x15c);
  int cond = *(int *)(iVar3 + 0x6c) >= 0;
  if (!cond) {
    cond = *(int *)(iVar3 + 4) == 2;
  }
  if (cond) {
    cond = !(*(int *)(*(int *)(iVar3 + 0x20) + 0x54) == 1);
  }
  return cond;
}
