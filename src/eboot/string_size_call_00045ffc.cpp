/* HSTMATCH module=EBOOT.BIN start=0x00045ffc end=0x00046048 symbol=FUN_00045ffc lang=c++ */
/* Clone of src/sharing_main/string_size_call_000460fc.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the string size is a 7-bit bitfield view of the first byte (lbu; sll; srl), the halfword argument is passed by the address of the parameter itself, and the uninitialised char[4] slot is passed by address and by value (matching idiom: uninitialised char buf[4]); exact match verified; names and types await human review. */
struct ShortRep {
  unsigned char isLong : 1;
  unsigned char len : 7;
};
struct Str {
  unsigned v0;
  unsigned v1;
  unsigned v2;
};
extern "C" void FUN_00045af4(Str *, unsigned, unsigned, unsigned short *, char *, int);

extern "C" void FUN_00045ffc(Str *s, unsigned short c)
{
  char buf[4];
  unsigned n;
  if ((s->v0 & 1) != 0) {
    n = s->v1;
  } else {
    n = ((ShortRep *)s)->len;
  }
  FUN_00045af4(s, n, 0, &c, buf, buf[0]);
}
