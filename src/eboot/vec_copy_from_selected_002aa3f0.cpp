/* HSTMATCH module=EBOOT.BIN start=0x002aa3f0 end=0x002aa444 symbol=FUN_002aa3f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copy-constructs a vector of 4-byte elements from one of two 12-byte {data,size,cap} records (selected by `(flag != 0) ^ 1`) inside the object; the tag argument is the derived empty fwd_tag (lb a3,28(sp)). Matching idiom: byte offset `i * 12` added to the object pointer first (offset-first addu). */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Vec { int *data; int size; int cap; };
struct Obj { char pad[0x30ec]; Vec v[2]; };
extern "C" void FUN_000d5304(Vec *, int *, int *, fwd_tag);

extern "C" void FUN_002aa3f0(Vec *out, Obj *o, int flag)
{
  out->data = 0;
  out->size = 0;
  out->cap = 0;
  unsigned char i = (flag != 0) ^ 1;
  int off = i * 12;
  off += (int)o;
  Vec *s = (Vec *)(off + 0x30ec);
  FUN_000d5304(out, s->data, s->data + s->size, fwd_tag());
}
