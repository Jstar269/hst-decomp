/* HSTMATCH module=EBOOT.BIN start=0x0028637c end=0x002863e4 symbol=FUN_0028637c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0028637c.c) corrected by hand: three further incoming arguments forwarded unchanged to the callee, which keeps a1-a3 live so the context pointer lands in t0; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415ac;
extern void FUN_002805fc(int a, int b, int c, int d);

/* matching idiom: param_2..param_4 are only forwarded (Ghidra dropped them) */
void FUN_0028637c(int param_1, int param_2, int param_3, int param_4)
{
  *(unsigned char *)(param_1 + 0xc5) = 1;
  if ((*(unsigned char *)(param_1 + 4) == 0) &&
     (((*(unsigned short *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0 ||
      (*(int *)(DAT_003415ac + 0x68) != 6)))) {
    FUN_002805fc(param_1 + 5, param_2, param_3, param_4);
  }
}
