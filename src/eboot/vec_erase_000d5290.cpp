/* HSTMATCH module=EBOOT.BIN start=0x000d5290 end=0x000d5304 symbol=FUN_000d5290 lang=c++ */
/* Clone of src/eboot/vec_erase_000be7f0.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_000d5290;
struct Tag_000d5290 {};
struct Vec_000d5290 { Elem_000d5290 *data; int size; unsigned capacity; };
inline void Move_000d5290(Elem_000d5290 *d, Elem_000d5290 *f, unsigned n, Tag_000d5290)
{
    FUN_000111c0(d, f, n * sizeof(Elem_000d5290));
}
extern "C" Elem_000d5290 *FUN_000d5290(Vec_000d5290 *v, Elem_000d5290 *pos)
{
    Move_000d5290(pos, pos + 1, v->data + v->size - pos - 1, Tag_000d5290());
    --v->size;
    return pos;
}
