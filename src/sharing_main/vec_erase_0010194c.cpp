/* HSTMATCH module=hstp_trans_main.prx start=0x0010194c end=0x001019c0 symbol=FUN_0010194c lang=c++ */
/* Clone of src/eboot/vec_erase_000be7f0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_0010194c;
struct Tag_0010194c {};
struct Vec_0010194c { Elem_0010194c *data; int size; unsigned capacity; };
inline void Move_0010194c(Elem_0010194c *d, Elem_0010194c *f, unsigned n, Tag_0010194c)
{
    FUN_000111c0(d, f, n * sizeof(Elem_0010194c));
}
extern "C" Elem_0010194c *FUN_0010194c(Vec_0010194c *v, Elem_0010194c *pos)
{
    Move_0010194c(pos, pos + 1, v->data + v->size - pos - 1, Tag_0010194c());
    --v->size;
    return pos;
}
