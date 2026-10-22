/* HSTMATCH module=EBOOT.BIN start=0x000457b4 end=0x000458d0 symbol=FUN_000457b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Decodes the character string of a text object: the string is either the bytes behind the object or the
   pointer in its third word, and every character is appended through FUN_00045ffc (a 2/3/4-byte lead
   encoding, 0xc0-0xef two- and three-byte forms, 0xf0 an empty code point).
   Matching idioms: the cursor is a volatile char pointer (the loop re-reads the character instead of
   reusing the value of the loop test) and the switch writes its default case first (the compare chain
   then tests the cases in reverse source order). Names provisional. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Str {
  unsigned v0;
  unsigned v1;
  unsigned v2;
};
extern "C" void FUN_00045af4(Str *, unsigned, unsigned, unsigned, unsigned, fwd_tag);
extern "C" void FUN_00046048(Str *, unsigned);
extern "C" void FUN_00045ffc(Str *, unsigned short);

extern "C" void FUN_000457b4(Str *s)
{
  volatile char *p;
  int c;
  int hi;
  unsigned short v;
  if ((s->v0 & 1) != 0) {
    p = (char *)s->v2;
  } else {
    p = (char *)s + 1;
  }
  FUN_00045af4(s + 1, 0, -1, 0, 0, fwd_tag());
  FUN_00046048(s + 1, 0x100);
  while (*p != 0) {
    c = *p;
    hi = c & 0xf0;
    switch (hi) {
    default:
      v = c & 0x7f;
      p += 1;
      break;
    case 0xc0:
    case 0xd0:
      v = ((c & 0x1f) << 6) + (p[1] & 0x3f);
      p += 2;
      break;
    case 0xe0:
      v = ((c & 0xf) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
      p += 3;
      break;
    case 0xf0:
      v = 0;
      p += 1;
      break;
    }
    FUN_00045ffc(s + 1, v);
  }
}
