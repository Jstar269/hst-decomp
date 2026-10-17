/* HSTMATCH module=EBOOT.BIN start=0x000d8b3c end=0x000d8b9c symbol=FUN_000d8b3c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00065104(int a, int b, int c);
extern int FUN_00065364(int a, int c);

int FUN_000d8b3c(int a, int b, int c)
{
  int r = 0;
  int n = FUN_00065364(a, c);
  if (n >= 0) {
    r = FUN_00065104(a, b, n);
  }
  return r;
}
