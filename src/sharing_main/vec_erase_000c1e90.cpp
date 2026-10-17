/* HSTMATCH module=hstp_trans_main.prx start=0x000c1e90 end=0x000c1f04 symbol=FUN_000c1e90 lang=c++ */
/* Clone of src/eboot/vec_erase_000be7f0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_000c1e90;
struct Tag_000c1e90 {};
struct Vec_000c1e90 { Elem_000c1e90 *data; int size; unsigned capacity; };
inline void Move_000c1e90(Elem_000c1e90 *d, Elem_000c1e90 *f, unsigned n, Tag_000c1e90)
{
    FUN_000111c0(d, f, n * sizeof(Elem_000c1e90));
}
extern "C" Elem_000c1e90 *FUN_000c1e90(Vec_000c1e90 *v, Elem_000c1e90 *pos)
{
    Move_000c1e90(pos, pos + 1, v->data + v->size - pos - 1, Tag_000c1e90());
    --v->size;
    return pos;
}
