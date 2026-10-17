/* HSTMATCH module=EBOOT.BIN start=0x001afa80 end=0x001afad8 symbol=FUN_001afa80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: if/else order swapped (the flag-set branch first), typed pointers; exact match verified; names and types await human review. */
extern char *FUN_0019d474();
extern void FUN_001ab530(int, int);
extern void FUN_001abd8c(int, int);

void FUN_001afa80(char *param_1, int param_2)
{
  unsigned char *p = (unsigned char *)FUN_0019d474();
  if (p[0x3a1] != 0) {
    FUN_001abd8c(*(int *)(param_1 + 8), param_2);
  }
  else {
    FUN_001ab530(*(int *)(param_1 + 8), param_2);
  }
}
