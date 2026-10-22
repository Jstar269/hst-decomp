/* HSTMATCH module=EBOOT.BIN start=0x0022c9f4 end=0x0022ca58 symbol=FUN_0022c9f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003415a8;
extern void FUN_001bf62c();
extern int FUN_0022ca58();

/* When the predicate is false, resets the per-index halfword to 200, then forwards. */
void FUN_0022c9f4(int param_1)
{
  short *p;

  if (FUN_0022ca58() == 0) {
    p = (short *)(DAT_003415a8 + 0xd4e6);
    p[param_1] = 200;
  }
  FUN_001bf62c(DAT_003415a8 + 0x80, param_1, 4);
}
