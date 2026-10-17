/* HSTMATCH module=EBOOT.BIN start=0x001639ec end=0x00163a4c symbol=FUN_001639ec lang=c99 */
/* Clone of src/eboot/call_if_nonneg_int_000d8b3c.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00065104(int a, int b, int c);
extern int FUN_00065364(int a, int c);

int FUN_001639ec(int a, int b, int c)
{
  int r = 0;
  int n = FUN_00065364(a, c);
  if (n >= 0) {
    r = FUN_00065104(a, b, n);
  }
  return r;
}
