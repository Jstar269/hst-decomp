/* HSTMATCH module=EBOOT.BIN start=0x0011c270 end=0x0011c440 symbol=FUN_0011c270 lang=c++ */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_0011c270 { int pad[3]; void *err; };
Reent_0011c270 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da0f8[]; /* "cdeque construction length error" */
extern char DAT_002c1354[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_0011c270;
struct Iter_0011c270 {
    Elem_0011c270 *ptr;
    Elem_0011c270 *beg;
    Elem_0011c270 *first;
    Elem_0011c270 *end;
    Iter_0011c270 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0011c270 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_0011c270 &x, const Iter_0011c270 &y)
{
    Elem_0011c270 *b = x.beg;
    Elem_0011c270 *e = x.end;
    Elem_0011c270 *f = x.first;
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
inline bool operator!=(const Iter_0011c270 &x, const Iter_0011c270 &y) { return x.ptr != y.ptr; }

struct Alloc_0011c270 {
    Elem_0011c270 *allocate(unsigned n)
    {
        Elem_0011c270 *p = (Elem_0011c270 *)FUN_00000bcc(n * sizeof(Elem_0011c270));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1354);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_0011c270 *p, const Elem_0011c270 &v) { new (p) Elem_0011c270(v); }
};

struct ForwardTag_0011c270 {};
struct Cdeque_0011c270 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011c270 *data_;
};
extern "C" unsigned FUN_0011d5fc(const Cdeque_0011c270 *self); /* max_size */

extern "C" void FUN_0011c270(Cdeque_0011c270 *self, Iter_0011c270 first, Iter_0011c270 last,
                             ForwardTag_0011c270)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_0011d5fc(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da0f8);
            FUN_0000d518();
        }
        Alloc_0011c270 a;
        Elem_0011c270 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
