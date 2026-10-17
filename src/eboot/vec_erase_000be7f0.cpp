/* HSTMATCH module=EBOOT.BIN start=0x000be7f0 end=0x000be864 symbol=FUN_000be7f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_000be7f0;
struct Tag_000be7f0 {};
struct Vec_000be7f0 { Elem_000be7f0 *data; int size; unsigned capacity; };
inline void Move_000be7f0(Elem_000be7f0 *d, Elem_000be7f0 *f, unsigned n, Tag_000be7f0)
{
    FUN_000111c0(d, f, n * sizeof(Elem_000be7f0));
}
extern "C" Elem_000be7f0 *FUN_000be7f0(Vec_000be7f0 *v, Elem_000be7f0 *pos)
{
    Move_000be7f0(pos, pos + 1, v->data + v->size - pos - 1, Tag_000be7f0());
    --v->size;
    return pos;
}
