/* HSTMATCH module=EBOOT.BIN start=0x00179fb0 end=0x0017a11c symbol=FUN_00179fb0 lang=c++ */
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
template <class T> inline const T &Max_00179fb0(const T &a, const T &b) { return a < b ? b : a; }
typedef void *Elem_00179fb0;
struct Tag_00179fb0 {};
struct Flag_00179fb0 { char v; };
struct Vec_00179fb0 { Elem_00179fb0 *data; int size; unsigned capacity; };
extern "C" void FUN_0017aba0(Vec_00179fb0 *v, unsigned n, unsigned cap); /* drop contents, reallocate */
static inline unsigned Grow_00179fb0(Vec_00179fb0 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00179fb0((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00179fb0((cap + 1) / 2, need);
    return 0x3fffffff;
}
inline void Copy_00179fb0(Elem_00179fb0 *d, Elem_00179fb0 *f, Elem_00179fb0 *l, Tag_00179fb0)
{
    FUN_000111c0(d, f, (l - f) * sizeof(Elem_00179fb0));
}
extern "C" void FUN_00179fb0(Vec_00179fb0 *v, Elem_00179fb0 *first, Elem_00179fb0 *last, Flag_00179fb0)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_00179fb0);
    if (n > v->capacity)
        FUN_0017aba0(v, n, Grow_00179fb0(v, n - v->capacity));
    Copy_00179fb0(v->data, first, last, Tag_00179fb0());
    v->size = n;
}
