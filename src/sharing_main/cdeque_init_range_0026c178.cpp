/* HSTMATCH module=hstp_trans_main.prx start=0x0026c178 end=0x0026c348 symbol=FUN_0026c178 lang=c++ */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; distance() takes the iterators by value and accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_0026c178 { int pad[3]; void *err; };
Reent_0026c178 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a63e8[]; /* "cdeque construction length error" */
extern char DAT_002dad78[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_0026c178;
struct Iter_0026c178 {
    Elem_0026c178 *ptr;
    Elem_0026c178 *beg;
    Elem_0026c178 *first;
    Elem_0026c178 *end;
    Iter_0026c178 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0026c178 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_0026c178 &x, const Iter_0026c178 &y)
{
    Elem_0026c178 *f = x.first;
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
template <class It> inline int distance_0026c178(It first, It last) { return last - first; }
inline bool operator!=(const Iter_0026c178 &x, const Iter_0026c178 &y) { return x.ptr != y.ptr; }

struct Alloc_0026c178 {
    Elem_0026c178 *allocate(unsigned n)
    {
        Elem_0026c178 *p = (Elem_0026c178 *)FUN_00000bcc(n * sizeof(Elem_0026c178));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dad78);
            FUN_0000d530();
        }
        return p;
    }
    void construct(Elem_0026c178 *p, const Elem_0026c178 &v) { new (p) Elem_0026c178(v); }
};

struct ForwardTag_0026c178 {};
struct Cdeque_0026c178 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0026c178 *data_;
};
extern "C" unsigned FUN_0026c8e8(const Cdeque_0026c178 *self); /* max_size */

extern "C" void FUN_0026c178(Cdeque_0026c178 *self, Iter_0026c178 first, Iter_0026c178 last,
                             ForwardTag_0026c178)
{
    unsigned n = (unsigned)distance_0026c178(first, last);
    if (n != 0) {
        if (n > FUN_0026c8e8(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003a63e8);
            FUN_0000d530();
        }
        Alloc_0026c178 a;
        Elem_0026c178 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
