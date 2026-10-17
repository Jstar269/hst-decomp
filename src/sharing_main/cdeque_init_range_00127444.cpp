/* HSTMATCH module=hstp_trans_main.prx start=0x00127444 end=0x00127614 symbol=FUN_00127444 lang=c++ */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_00127444 { int pad[3]; void *err; };
Reent_00127444 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003810d8[]; /* "cdeque construction length error" */
extern char DAT_002d1734[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_00127444;
struct Iter_00127444 {
    Elem_00127444 *ptr;
    Elem_00127444 *beg;
    Elem_00127444 *first;
    Elem_00127444 *end;
    Iter_00127444 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_00127444 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_00127444 &x, const Iter_00127444 &y)
{
    Elem_00127444 *b = x.beg;
    Elem_00127444 *e = x.end;
    Elem_00127444 *f = x.first;
    int d = x.ptr - y.ptr;
    if (x.ptr >= f) {
        if (y.ptr < f)
            d -= e - b;
    } else {
        if (y.ptr >= f)
            d += e - b;
    }
    return d;
}
inline bool operator!=(const Iter_00127444 &x, const Iter_00127444 &y) { return x.ptr != y.ptr; }

struct Alloc_00127444 {
    Elem_00127444 *allocate(unsigned n)
    {
        Elem_00127444 *p = (Elem_00127444 *)FUN_00000bcc(n * sizeof(Elem_00127444));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1734);
            FUN_0000d530();
        }
        return p;
    }
    void construct(Elem_00127444 *p, const Elem_00127444 &v) { new (p) Elem_00127444(v); }
};

struct ForwardTag_00127444 {};
struct Cdeque_00127444 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00127444 *data_;
};
extern "C" unsigned FUN_001287d0(const Cdeque_00127444 *self); /* max_size */

extern "C" void FUN_00127444(Cdeque_00127444 *self, Iter_00127444 first, Iter_00127444 last,
                             ForwardTag_00127444)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_001287d0(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003810d8);
            FUN_0000d530();
        }
        Alloc_00127444 a;
        Elem_00127444 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
