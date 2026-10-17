/* HSTMATCH module=hstp_trans_main.prx start=0x000dc948 end=0x000dc9a8 symbol=FUN_000dc948 lang=c99 */
/* Clone of src/eboot/call_if_nonneg_int_000d8b3c.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00066038(int a, int b, int c);
extern int FUN_00066400(int a, int c);

int FUN_000dc948(int a, int b, int c)
{
  int r = 0;
  int n = FUN_00066400(a, c);
  if (n >= 0) {
    r = FUN_00066038(a, b, n);
  }
  return r;
}
