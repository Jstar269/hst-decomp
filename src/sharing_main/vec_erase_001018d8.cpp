/* HSTMATCH module=hstp_trans_main.prx start=0x001018d8 end=0x0010194c symbol=FUN_001018d8 lang=c++ */
/* Clone of src/eboot/vec_erase_000be7f0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: erase(pos). Block-move the tail down one slot (0x111c0) through an inline helper
   taking an empty tag by value (that gives the 32-byte frame), shrink, return pos. The count must be written
   `end - pos - 1` (an element count scaled inside the helper); `(end - (pos + 1)) * 4` folds differently.
   Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
typedef void *Elem_001018d8;
struct Tag_001018d8 {};
struct Vec_001018d8 { Elem_001018d8 *data; int size; unsigned capacity; };
inline void Move_001018d8(Elem_001018d8 *d, Elem_001018d8 *f, unsigned n, Tag_001018d8)
{
    FUN_000111c0(d, f, n * sizeof(Elem_001018d8));
}
extern "C" Elem_001018d8 *FUN_001018d8(Vec_001018d8 *v, Elem_001018d8 *pos)
{
    Move_001018d8(pos, pos + 1, v->data + v->size - pos - 1, Tag_001018d8());
    --v->size;
    return pos;
}
