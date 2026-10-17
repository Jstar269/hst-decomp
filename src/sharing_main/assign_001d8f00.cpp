/* HSTMATCH module=hstp_trans_main.prx start=0x001d8f00 end=0x001d9064 symbol=FUN_001d8f00 lang=c++ */
/* Clone of src/eboot/assign_001ca92c.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S_001d8f00 {
  S_001d8f00();
  int arr1[576];
  char arr2[16];
  int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
  unsigned char b0, b1, b2, b3, b4;
  int arr3[256];
  int arr4[256];
  int arr5[64];
};

extern "C" S_001d8f00 *FUN_001d8f00(S_001d8f00 *a, const S_001d8f00 *b)
{
  *a = *b;
  return a;
}
