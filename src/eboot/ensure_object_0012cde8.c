/* HSTMATCH module=EBOOT.BIN start=0x0012cde8 end=0x0012ce50 symbol=FUN_0012cde8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0033b580;
extern int DAT_0034a114;
extern int FUN_00000bcc(int);
extern int *FUN_0012dc4c(int *);
extern void FUN_0012d890(int);
extern void FUN_00145cfc(void);
extern void FUN_001c68a8(int, int *);
void FUN_0012cde8(int param_1)
{
  int *p;
  FUN_00145cfc();
  if (DAT_0033b580 == 0) {
    p = (int *)FUN_00000bcc(0x250);
    if (p != 0)
      p = FUN_0012dc4c(p);
    FUN_001c68a8(DAT_0034a114, p);
  }
  FUN_0012d890(param_1);
}
