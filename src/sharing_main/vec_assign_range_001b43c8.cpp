/* HSTMATCH module=hstp_trans_main.prx start=0x001b43c8 end=0x001b4534 symbol=FUN_001b43c8 lang=c++ */
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
template <class T> inline const T &Max_001b43c8(const T &a, const T &b) { return a < b ? b : a; }
typedef void *Elem_001b43c8;
struct Tag_001b43c8 {};
struct Flag_001b43c8 { char v; };
struct Vec_001b43c8 { Elem_001b43c8 *data; int size; unsigned capacity; };
extern "C" void FUN_001b6240(Vec_001b43c8 *v, unsigned n, unsigned cap); /* drop contents, reallocate */
static inline unsigned Grow_001b43c8(Vec_001b43c8 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_001b43c8((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_001b43c8((cap + 1) / 2, need);
    return 0x3fffffff;
}
inline void Copy_001b43c8(Elem_001b43c8 *d, Elem_001b43c8 *f, Elem_001b43c8 *l, Tag_001b43c8)
{
    FUN_000111c0(d, f, (l - f) * sizeof(Elem_001b43c8));
}
extern "C" void FUN_001b43c8(Vec_001b43c8 *v, Elem_001b43c8 *first, Elem_001b43c8 *last, Flag_001b43c8)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_001b43c8);
    if (n > v->capacity)
        FUN_001b6240(v, n, Grow_001b43c8(v, n - v->capacity));
    Copy_001b43c8(v->data, first, last, Tag_001b43c8());
    v->size = n;
}
