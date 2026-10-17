/* HSTMATCH module=hstp_trans_main.prx start=0x000dec80 end=0x000decd4 symbol=FUN_000dec80 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copy constructor of a vector of 6-byte elements: clear {data, size, capacity}, then append the source range through
   0xddc8c. Adapted from the matched EBOOT twin src/eboot/vec6_copy_ctor_000dacc0.cpp (callee address substituted).
   The tag argument is read from a never-written stack slot (`lb a3,28(sp)`): matching idiom: a tag type
   DERIVING from an empty class (fwd_tag : in_tag), as in 0x146e1c/0x11ec54. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Elem_000dec80 { short a, b, c; };
struct Vec_000dec80 { Elem_000dec80 *data; int size; int cap; };
extern "C" void FUN_000ddc8c(Vec_000dec80 *, Elem_000dec80 *, Elem_000dec80 *, fwd_tag);

extern "C" Vec_000dec80 *FUN_000dec80(Vec_000dec80 *v, Vec_000dec80 *o)
{
  v->data = 0;
  v->size = 0;
  v->cap = 0;
  FUN_000ddc8c(v, o->data, o->data + o->size, fwd_tag());
  return v;
}
