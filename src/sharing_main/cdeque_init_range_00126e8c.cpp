/* HSTMATCH module=hstp_trans_main.prx start=0x00126e8c end=0x0012705c symbol=FUN_00126e8c lang=c++ */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_00126e8c { int pad[3]; void *err; };
Reent_00126e8c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003810d8[]; /* "cdeque construction length error" */
extern char DAT_002d176c[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_00126e8c;
struct Iter_00126e8c {
    Elem_00126e8c *ptr;
    Elem_00126e8c *beg;
    Elem_00126e8c *first;
    Elem_00126e8c *end;
    Iter_00126e8c &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_00126e8c &operator*() const { return *ptr; }
};
inline int operator-(const Iter_00126e8c &x, const Iter_00126e8c &y)
{
    Elem_00126e8c *b = x.beg;
    Elem_00126e8c *e = x.end;
    Elem_00126e8c *f = x.first;
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
inline bool operator!=(const Iter_00126e8c &x, const Iter_00126e8c &y) { return x.ptr != y.ptr; }

struct Alloc_00126e8c {
    Elem_00126e8c *allocate(unsigned n)
    {
        Elem_00126e8c *p = (Elem_00126e8c *)FUN_00000bcc(n * sizeof(Elem_00126e8c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d176c);
            FUN_0000d530();
        }
        return p;
    }
    void construct(Elem_00126e8c *p, const Elem_00126e8c &v) { new (p) Elem_00126e8c(v); }
};

struct ForwardTag_00126e8c {};
struct Cdeque_00126e8c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00126e8c *data_;
};
extern "C" unsigned FUN_00128744(const Cdeque_00126e8c *self); /* max_size */

extern "C" void FUN_00126e8c(Cdeque_00126e8c *self, Iter_00126e8c first, Iter_00126e8c last,
                             ForwardTag_00126e8c)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_00128744(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003810d8);
            FUN_0000d530();
        }
        Alloc_00126e8c a;
        Elem_00126e8c *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
