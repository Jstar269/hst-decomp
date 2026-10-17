/* HSTMATCH module=EBOOT.BIN start=0x000d8b9c end=0x000d8bfc symbol=FUN_000d8b9c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_00065140(int a, int b, int c);
extern int FUN_00065364(int a, int c);

float FUN_000d8b9c(int a, int b, int c)
{
  float r = 0.0f;
  int n = FUN_00065364(a, c);
  if (n >= 0) {
    r = FUN_00065140(a, b, n);
  }
  return r;
}
