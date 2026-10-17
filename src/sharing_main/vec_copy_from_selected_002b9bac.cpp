/* HSTMATCH module=hstp_trans_main.prx start=0x002b9bac end=0x002b9c00 symbol=FUN_002b9bac lang=c++ */
/* Clone of src/eboot/vec_copy_from_selected_002aa3f0.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copy-constructs a vector of 4-byte elements from one of two 12-byte {data,size,cap} records (selected by `(flag != 0) ^ 1`) inside the object; the tag argument is the derived empty fwd_tag (lb a3,28(sp)). Matching idiom: byte offset `i * 12` added to the object pointer first (offset-first addu). */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Vec { int *data; int size; int cap; };
struct Obj { char pad[0x30ec]; Vec v[2]; };
extern "C" void FUN_000d8ff4(Vec *, int *, int *, fwd_tag);

extern "C" void FUN_002b9bac(Vec *out, Obj *o, int flag)
{
  out->data = 0;
  out->size = 0;
  out->cap = 0;
  unsigned char i = (flag != 0) ^ 1;
  int off = i * 12;
  off += (int)o;
  Vec *s = (Vec *)(off + 0x30ec);
  FUN_000d8ff4(out, s->data, s->data + s->size, fwd_tag());
}
