/* HSTMATCH module=EBOOT.BIN start=0x000463e4 end=0x0004642c symbol=FUN_000463e4 lang=c++ */
/* Clone of src/sharing_main/string_size_tag_call_000464e4.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the string size is a 7-bit bitfield view of the first byte (lbu; sll; srl), the sixth argument is a derived empty tag temporary (fwd_tag(), passed as lb from a never-written slot; same family as 0x460fc); exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct ShortRep {
  unsigned char isLong : 1;
  unsigned char len : 7;
};
struct Str {
  unsigned v0;
  unsigned v1;
  unsigned v2;
};
extern "C" void FUN_00045af4(Str *, unsigned, unsigned, unsigned, unsigned, fwd_tag);

extern "C" void FUN_000463e4(Str *s, unsigned a, unsigned b)
{
  unsigned n;
  if ((s->v0 & 1) != 0) {
    n = s->v1;
  } else {
    n = ((ShortRep *)s)->len;
  }
  FUN_00045af4(s, 0, n, a, b, fwd_tag());
}
