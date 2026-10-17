/* HSTMATCH module=EBOOT.BIN start=0x001ca92c end=0x001caa90 symbol=FUN_001ca92c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S_001ca92c {
  S_001ca92c();
  int arr1[576];
  char arr2[16];
  int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
  unsigned char b0, b1, b2, b3, b4;
  int arr3[256];
  int arr4[256];
  int arr5[64];
};

extern "C" S_001ca92c *FUN_001ca92c(S_001ca92c *a, const S_001ca92c *b)
{
  *a = *b;
  return a;
}
