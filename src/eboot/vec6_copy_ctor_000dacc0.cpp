/* HSTMATCH module=EBOOT.BIN start=0x000dacc0 end=0x000dad14 symbol=FUN_000dacc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copy constructor of a vector of 6-byte elements: clear {data, size, capacity}, then append the source range through
   0xd9ccc. The tag argument is read from a never-written stack slot (`lb a3,28(sp)`): matching idiom: a tag type
   DERIVING from an empty class (fwd_tag : in_tag), as in 0x146e1c/0x11ec54. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Elem_000dacc0 { short a, b, c; };
struct Vec_000dacc0 { Elem_000dacc0 *data; int size; int cap; };
extern "C" void FUN_000d9ccc(Vec_000dacc0 *, Elem_000dacc0 *, Elem_000dacc0 *, fwd_tag);

extern "C" Vec_000dacc0 *FUN_000dacc0(Vec_000dacc0 *v, Vec_000dacc0 *o)
{
  v->data = 0;
  v->size = 0;
  v->cap = 0;
  FUN_000d9ccc(v, o->data, o->data + o->size, fwd_tag());
  return v;
}
