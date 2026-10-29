/* HSTMATCH module=EBOOT.BIN start=0x0027aa4c end=0x0027aadc symbol=FUN_0027aa4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Record {
  unsigned char bytes[5];
  unsigned char padding[3];
  unsigned int words[5];
  float values[5];
};
extern "C" Record *FUN_0027aadc(Record *dst, Record *src);

/* Swap of two 48-byte records through a temporary: copy-construct (inline), then the out-of-line assignment
   operator 0x27aadc twice. Matching idiom: an unused empty Tag by-value parameter (never-written 4-byte slot) gives
   retail's 80-byte frame with the temporary at sp+32; without it the frame is 64. */
struct Tag {};
extern "C" void FUN_0027aa4c(Record *a, Record *b, Tag)
{
  Record tmp = *a;
  FUN_0027aadc(a, b);
  FUN_0027aadc(b, &tmp);
}
