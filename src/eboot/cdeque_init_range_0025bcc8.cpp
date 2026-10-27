/* HSTMATCH module=EBOOT.BIN start=0x0025bcc8 end=0x0025be98 symbol=FUN_0025bcc8 lang=c++ data=0x002fd840 */
/* Clone of src/eboot/cdeque_init_range_0011bcb8.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fd840-0x002fd862) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: range initialisation from a pair of cdeque
   iterators (forward-iterator overload). The forward_iterator_tag by-value parameter gives the 16-byte
   frame slot; iterator distance accounts for wrap-around. Names provisional. */
extern "C" {
struct Reent_0025bcc8 { int pad[3]; void *err; };
Reent_0025bcc8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002ca7b8[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }

typedef int Elem_0025bcc8;
struct Iter_0025bcc8 {
    Elem_0025bcc8 *ptr;
    Elem_0025bcc8 *beg;
    Elem_0025bcc8 *first;
    Elem_0025bcc8 *end;
    Iter_0025bcc8 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Elem_0025bcc8 &operator*() const { return *ptr; }
};
inline int operator-(const Iter_0025bcc8 &x, const Iter_0025bcc8 &y)
{
    Elem_0025bcc8 *b = x.beg;
    Elem_0025bcc8 *e = x.end;
    Elem_0025bcc8 *f = x.first;
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
inline bool operator!=(const Iter_0025bcc8 &x, const Iter_0025bcc8 &y) { return x.ptr != y.ptr; }

struct Alloc_0025bcc8 {
    Elem_0025bcc8 *allocate(unsigned n)
    {
        Elem_0025bcc8 *p = (Elem_0025bcc8 *)FUN_00000bcc(n * sizeof(Elem_0025bcc8));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002ca7b8);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_0025bcc8 *p, const Elem_0025bcc8 &v) { new (p) Elem_0025bcc8(v); }
};

struct ForwardTag_0025bcc8 {};
struct Cdeque_0025bcc8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0025bcc8 *data_;
};
extern "C" unsigned FUN_0025c438(const Cdeque_0025bcc8 *self); /* max_size */

extern "C" void FUN_0025bcc8(Cdeque_0025bcc8 *self, Iter_0025bcc8 first, Iter_0025bcc8 last,
                             ForwardTag_0025bcc8)
{
    unsigned n = (unsigned)(last - first);
    if (n != 0) {
        if (n > FUN_0025c438(self)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, "cdeque::construction length error");
            FUN_0000d518();
        }
        Alloc_0025bcc8 a;
        Elem_0025bcc8 *p = a.allocate(n + 1);
        self->data_ = p;
        self->cap_ = n + 1;
        for (; first != last; ++first, ++p, ++self->size_)
            a.construct(p, *first);
    }
}
