/* HSTMATCH module=EBOOT.BIN start=0x0011bcb8 end=0x0011be88 symbol=FUN_0011bcb8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; distance() takes the iterators by value and accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_0011bcb8 { int pad[3]; void *err; };
Reent_0011bcb8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da0f8[]; /* "cdeque construction length error" */
extern char DAT_002c138c[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_0011bcb8;
struct Iter_0011bcb8 {
    Elem_0011bcb8 *ptr;
    Elem_0011bcb8 *beg;
    Elem_0011bcb8 *first;
    Elem_0011bcb8 *end;
    Iter_0011bcb8 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0011bcb8 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_0011bcb8 &x, const Iter_0011bcb8 &y)
{
    Elem_0011bcb8 *f = x.first;
    int d = x.ptr - y.ptr;
    if (x.ptr >= f) {
        if (y.ptr < f)
            d -= x.end - x.beg;
    } else {
        if (y.ptr >= f)
            d += x.end - x.beg;
    }
    return d;
}
template <class It> inline int distance_0011bcb8(It first, It last) { return last - first; }
inline bool operator!=(const Iter_0011bcb8 &x, const Iter_0011bcb8 &y) { return x.ptr != y.ptr; }

struct Alloc_0011bcb8 {
    Elem_0011bcb8 *allocate(unsigned n)
    {
        Elem_0011bcb8 *p = (Elem_0011bcb8 *)FUN_00000bcc(n * sizeof(Elem_0011bcb8));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c138c);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_0011bcb8 *p, const Elem_0011bcb8 &v) { new (p) Elem_0011bcb8(v); }
};

struct ForwardTag_0011bcb8 {};
struct Cdeque_0011bcb8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011bcb8 *data_;
};
extern "C" unsigned FUN_0011d570(const Cdeque_0011bcb8 *self); /* max_size */

extern "C" void FUN_0011bcb8(Cdeque_0011bcb8 *self, Iter_0011bcb8 first, Iter_0011bcb8 last,
                             ForwardTag_0011bcb8)
{
    unsigned n = (unsigned)distance_0011bcb8(first, last);
    if (n != 0) {
        if (n > FUN_0011d570(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da0f8);
            FUN_0000d518();
        }
        Alloc_0011bcb8 a;
        Elem_0011bcb8 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
