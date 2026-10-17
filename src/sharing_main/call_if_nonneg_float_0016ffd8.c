/* HSTMATCH module=hstp_trans_main.prx start=0x0016ffd8 end=0x00170038 symbol=FUN_0016ffd8 lang=c99 */
/* Clone of src/eboot/call_if_nonneg_float_000d8b9c.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_000660f0(int a, int b, int c);
extern int FUN_00066400(int a, int c);

float FUN_0016ffd8(int a, int b, int c)
{
  float r = 0.0f;
  int n = FUN_00066400(a, c);
  if (n >= 0) {
    r = FUN_000660f0(a, b, n);
  }
  return r;
}
