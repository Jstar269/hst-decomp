/* HSTMATCH module=hstp_trans_main.prx start=0x0019ebe0 end=0x0019edb0 symbol=FUN_0019ebe0 lang=c++ */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_0019ebe0 { int pad[3]; void *err; };
Reent_0019ebe0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00388a6c[]; /* "cdeque construction length error" */
extern char DAT_002d2c88[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_0019ebe0;
struct Iter_0019ebe0 {
    Elem_0019ebe0 *ptr;
    Elem_0019ebe0 *beg;
    Elem_0019ebe0 *first;
    Elem_0019ebe0 *end;
    Iter_0019ebe0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0019ebe0 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_0019ebe0 &x, const Iter_0019ebe0 &y)
{
    Elem_0019ebe0 *b = x.beg;
    Elem_0019ebe0 *e = x.end;
    Elem_0019ebe0 *f = x.first;
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
inline bool operator!=(const Iter_0019ebe0 &x, const Iter_0019ebe0 &y) { return x.ptr != y.ptr; }

struct Alloc_0019ebe0 {
    Elem_0019ebe0 *allocate(unsigned n)
    {
        Elem_0019ebe0 *p = (Elem_0019ebe0 *)FUN_00000bcc(n * sizeof(Elem_0019ebe0));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d2c88);
            FUN_0000d530();
        }
        return p;
    }
    void construct(Elem_0019ebe0 *p, const Elem_0019ebe0 &v) { new (p) Elem_0019ebe0(v); }
};

struct ForwardTag_0019ebe0 {};
struct Cdeque_0019ebe0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0019ebe0 *data_;
};
extern "C" unsigned FUN_0019f350(const Cdeque_0019ebe0 *self); /* max_size */

extern "C" void FUN_0019ebe0(Cdeque_0019ebe0 *self, Iter_0019ebe0 first, Iter_0019ebe0 last,
                             ForwardTag_0019ebe0)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_0019f350(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00388a6c);
            FUN_0000d530();
        }
        Alloc_0019ebe0 a;
        Elem_0019ebe0 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
