/* HSTMATCH module=EBOOT.BIN start=0x00163a4c end=0x00163aac symbol=FUN_00163a4c lang=c99 */
/* Clone of src/eboot/call_if_nonneg_float_000d8b9c.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_00065140(int a, int b, int c);
extern int FUN_00065364(int a, int c);

float FUN_00163a4c(int a, int b, int c)
{
  float r = 0.0f;
  int n = FUN_00065364(a, c);
  if (n >= 0) {
    r = FUN_00065140(a, b, n);
  }
  return r;
}
