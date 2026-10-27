/* HSTMATCH module=EBOOT.BIN start=0x001923d0 end=0x001925a0 symbol=FUN_001923d0 lang=c++ data=0x002e1390 */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e1390-0x002e13b2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_001923d0 { int pad[3]; void *err; };
Reent_001923d0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c2788[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_001923d0;
struct Iter_001923d0 {
    Elem_001923d0 *ptr;
    Elem_001923d0 *beg;
    Elem_001923d0 *first;
    Elem_001923d0 *end;
    Iter_001923d0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_001923d0 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_001923d0 &x, const Iter_001923d0 &y)
{
    Elem_001923d0 *b = x.beg;
    Elem_001923d0 *e = x.end;
    Elem_001923d0 *f = x.first;
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
inline bool operator!=(const Iter_001923d0 &x, const Iter_001923d0 &y) { return x.ptr != y.ptr; }

struct Alloc_001923d0 {
    Elem_001923d0 *allocate(unsigned n)
    {
        Elem_001923d0 *p = (Elem_001923d0 *)FUN_00000bcc(n * sizeof(Elem_001923d0));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2788);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_001923d0 *p, const Elem_001923d0 &v) { new (p) Elem_001923d0(v); }
};

struct ForwardTag_001923d0 {};
struct Cdeque_001923d0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_001923d0 *data_;
};
extern "C" unsigned FUN_00192b40(const Cdeque_001923d0 *self); /* max_size */

extern "C" void FUN_001923d0(Cdeque_001923d0 *self, Iter_001923d0 first, Iter_001923d0 last,
                             ForwardTag_001923d0)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_00192b40(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, "cdeque::construction length error");
            FUN_0000d518();
        }
        Alloc_001923d0 a;
        Elem_001923d0 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
