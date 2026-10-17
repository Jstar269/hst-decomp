/* HSTMATCH module=hstp_trans_main.prx start=0x001b41e0 end=0x001b43c8 symbol=FUN_001b41e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: assign(first, last) from a pointer range with the reallocation inlined (compare vec_assign_range_001b43c8.cpp, which calls the out-of-line reset 0x1b6240): growth policy cap + max((cap+1)*3/5, need) / cap + max((cap+1)/2, need) / 0x3fffffff, then shrink the old size, free the block, check max_size (length_error thrower 0x43b4), allocate, report an allocation failure on stderr and abort, copy with 0x111c0. Matching idiom: reserve() takes the empty allocator BY VALUE (`reserve(unsigned n, Alloc al)` called as `v->reserve(cap, Alloc())`); building `Alloc()` inside reserve() gives a 48-byte frame and different slot offsets for the std::max temporaries (retail 64 bytes, need at sp+52). Names provisional. */
#pragma inline_depth(8)
extern "C" {
struct Reent_001b41e0 { int pad[3]; void *err; };
void FUN_000043b4(void);
void *FUN_000111c0(void *dst, const void *src, unsigned n);
Reent_001b41e0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc2a0[];
}
template <class T> inline const T &Max_001b41e0(const T &a, const T &b) { return a < b ? b : a; }
typedef void *Elem_001b41e0;
struct Alloc_001b41e0 {
    Elem_001b41e0 *allocate(unsigned n) { return (Elem_001b41e0 *)FUN_00000bcc(n * sizeof(Elem_001b41e0)); }
};
struct Vec_001b41e0 {
    Elem_001b41e0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b41e0) { size -= n; }
    void reserve(unsigned n, Alloc_001b41e0 al)
    {
        if (n > 0x3fffffffu)
            FUN_000043b4();
        Elem_001b41e0 *p = al.allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc2a0);
            FUN_0000d530();
        }
        data = p;
        capacity = n;
    }
};
static inline unsigned Grow_001b41e0(Vec_001b41e0 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_001b41e0((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_001b41e0((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_001b41e0(Vec_001b41e0 *v, Elem_001b41e0 *first, Elem_001b41e0 *last)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_001b41e0);
    if (n > v->capacity) {
        unsigned cap = Grow_001b41e0(v, n - v->capacity);
        int k = v->size;
        v->shrink(k, Alloc_001b41e0());
        if (v->data) {
            delete v->data;
            v->data = 0;
            v->capacity = 0;
        }
        v->reserve(cap, Alloc_001b41e0());
    }
    FUN_000111c0(v->data, first, (last - first) * sizeof(Elem_001b41e0));
    v->size = n;
}
