/* HSTMATCH module=EBOOT.BIN start=0x000fc19c end=0x000fc210 symbol=FUN_000fc19c lang=c++ */
/* Clone of src/eboot/vec_erase_000be7f0.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_000fc19c;
struct Tag_000fc19c {};
struct Vec_000fc19c { Elem_000fc19c *data; int size; unsigned capacity; };
inline void Move_000fc19c(Elem_000fc19c *d, Elem_000fc19c *f, unsigned n, Tag_000fc19c)
{
    FUN_000111c0(d, f, n * sizeof(Elem_000fc19c));
}
extern "C" Elem_000fc19c *FUN_000fc19c(Vec_000fc19c *v, Elem_000fc19c *pos)
{
    Move_000fc19c(pos, pos + 1, v->data + v->size - pos - 1, Tag_000fc19c());
    --v->size;
    return pos;
}
