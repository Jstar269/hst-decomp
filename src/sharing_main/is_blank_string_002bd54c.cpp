/* HSTMATCH module=hstp_trans_main.prx start=0x002bd54c end=0x002bd594 symbol=FUN_002bd54c lang=c++ */
/* Clone of src/eboot/is_blank_string_002add24.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: int local holding the code unit with (unsigned short) casts at the compares, result preset to 1 and cleared on break. */
// Returns 1 when every code unit of the zero-terminated 16-bit string is 0x20 or 0x3000 (empty string included).
extern "C" int FUN_002bd54c(unsigned short *s)
{
  int r = 1;
  int c = *s;
  while (c != 0) {
    if ((unsigned short)c != 0x20 && (unsigned short)c != 0x3000) { r = 0; break; }
    s++;
    c = *s;
  }
  return r;
}
