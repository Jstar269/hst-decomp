/* HSTMATCH module=hstp_trans_main.prx start=0x000982d4 end=0x0009834c symbol=FUN_000982d4 lang=c99 */
/* Clone of src/eboot/store_unless_flag_0009619c.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag chain as int ok = (G != 0); if (ok) ok = (b != 0) ^ 1 (lbu/sltu/xori), callee result as int* indexed p[i+1] (offset-first addu); exact match verified; names and types await human review. */
extern unsigned char DAT_003e19f8;
extern int DAT_003e1e30;
extern int FUN_000c8538(int, int);

void FUN_000982d4(char *param_1, int param_2, int param_3)
{
  int ok;

  ok = DAT_003e19f8 != 0;
  if (ok) {
    ok = (*(unsigned char *)(param_1 + 0x1b4) != 0) ^ 1;
  }
  if (ok && DAT_003e1e30 != 0) {
    int *p = (int *)FUN_000c8538(DAT_003e1e30, *(int *)(param_1 + 0x148));
    p[param_2 + 1] = param_3;
  }
}
