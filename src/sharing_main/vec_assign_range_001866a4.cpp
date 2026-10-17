/* HSTMATCH module=hstp_trans_main.prx start=0x001866a4 end=0x00186810 symbol=FUN_001866a4 lang=c++ */
/* Clone of src/eboot/vec_assign_range_00179fb0.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: assign(first, last) from a pointer range (trivially-copyable overload; the
   caller 0x179ad8 passes a one-char flag struct in a3). Reallocate through 0x17aba0 with the usual growth
   policy when the count exceeds the capacity, then copy the block with 0x111c0. Frame: the by-value flag
   parameter plus the empty tag of the inline copy give the slot above `need` and the 64-byte frame; the count
   must be a byte difference divided by the element size so the copy length is recomputed. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
void *FUN_000111c0(void *dst, const void *src, unsigned n);
}
template <class T> inline const T &Max_001866a4(const T &a, const T &b) { return a < b ? b : a; }
typedef void *Elem_001866a4;
struct Tag_001866a4 {};
struct Flag_001866a4 { char v; };
struct Vec_001866a4 { Elem_001866a4 *data; int size; unsigned capacity; };
extern "C" void FUN_00187294(Vec_001866a4 *v, unsigned n, unsigned cap); /* drop contents, reallocate */
static inline unsigned Grow_001866a4(Vec_001866a4 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_001866a4((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_001866a4((cap + 1) / 2, need);
    return 0x3fffffff;
}
inline void Copy_001866a4(Elem_001866a4 *d, Elem_001866a4 *f, Elem_001866a4 *l, Tag_001866a4)
{
    FUN_000111c0(d, f, (l - f) * sizeof(Elem_001866a4));
}
extern "C" void FUN_001866a4(Vec_001866a4 *v, Elem_001866a4 *first, Elem_001866a4 *last, Flag_001866a4)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_001866a4);
    if (n > v->capacity)
        FUN_00187294(v, n, Grow_001866a4(v, n - v->capacity));
    Copy_001866a4(v->data, first, last, Tag_001866a4());
    v->size = n;
}
