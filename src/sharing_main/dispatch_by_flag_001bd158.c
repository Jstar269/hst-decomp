/* HSTMATCH module=hstp_trans_main.prx start=0x001bd158 end=0x001bd1b0 symbol=FUN_001bd158 lang=c99 */
/* Clone of src/eboot/dispatch_by_flag_001afa80.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: if/else order swapped (the flag-set branch first), typed pointers; exact match verified; names and types await human review. */
extern char *FUN_001aa91c();
extern void FUN_001b8b60(int, int);
extern void FUN_001b93f4(int, int);

void FUN_001bd158(char *param_1, int param_2)
{
  unsigned char *p = (unsigned char *)FUN_001aa91c();
  if (p[0x3a1] != 0) {
    FUN_001b93f4(*(int *)(param_1 + 8), param_2);
  }
  else {
    FUN_001b8b60(*(int *)(param_1 + 8), param_2);
  }
}
