/* HSTMATCH module=hstp_trans_main.prx start=0x00151e94 end=0x00151f3c symbol=FUN_00151e94 lang=c++ */
/* Clone of src/eboot/vec_assign_range_001465ac.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: assign(first, last) from a pointer range (3-arg variant of 0x179fb0 with out-of-line grow 0x14a6d8 and reserve 0x14a7bc); the empty tag temporary of the inline copy gives the extra 16 bytes of frame. Names provisional. */
extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);
struct Tag_00151e94 {};
typedef void *Elem_00151e94;
struct Vec_00151e94 { Elem_00151e94 *data; int size; unsigned capacity; };
extern "C" unsigned FUN_00155fc0(Vec_00151e94 *v, unsigned n);
extern "C" void FUN_001560a4(Vec_00151e94 *v, unsigned n, unsigned cap);
inline void Copy_00151e94(Elem_00151e94 *d, Elem_00151e94 *f, Elem_00151e94 *l, Tag_00151e94)
{
    FUN_000111c0(d, f, (l - f) * sizeof(Elem_00151e94));
}
extern "C" void FUN_00151e94(Vec_00151e94 *v, Elem_00151e94 *first, Elem_00151e94 *last)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_00151e94);
    if (n > v->capacity)
        FUN_001560a4(v, n, FUN_00155fc0(v, n - v->capacity));
    Copy_00151e94(v->data, first, last, Tag_00151e94());
    v->size = n;
}
