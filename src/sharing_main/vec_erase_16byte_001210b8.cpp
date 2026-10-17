/* HSTMATCH module=hstp_trans_main.prx start=0x001210b8 end=0x001212c4 symbol=FUN_001210b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 16-byte elements: erase(pos). The inline forward copy loop is unrolled 8x by MWCC (its guard arithmetic is the compiler's); the skip test must be written `end - pos - 1 != 0`. Names provisional. */
struct Elem { int a, b, c, d; };
struct Vec { Elem *data; int size; };
inline void Copy(Elem *first, Elem *last, Elem *out)
{
  for (; first < last; ++first, ++out)
    *out = *first;
}
extern "C" Elem *FUN_001210b8(Vec *v, Elem *pos)
{
  Elem *end = v->data + v->size;
  if (end - pos - 1 != 0)
    Copy(pos + 1, end, pos);
  --v->size;
  return pos;
}
