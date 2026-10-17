/* HSTMATCH module=EBOOT.BIN start=0x0011be88 end=0x0011c270 symbol=FUN_0011be88 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per 504-byte block, block pointers held in a cdeque with a
   trailing null slot): range initialisation from a pair of deque iterators (forward-iterator overload).
   distance() takes the iterators by value; max_size() is an inline function with a guarded static local
   (guard 0x33b490, value 0x2c1328). Names provisional. */
extern "C" {
struct Reent_0011be88 { int pad[3]; void *err; };
Reent_0011be88 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da11c[]; /* "deque construction length error" */
extern char DAT_002c1370[]; /* "Memory allocation failure" */
extern char DAT_0033b490;       /* max_size() static-local guard */
extern unsigned DAT_002c1328;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_0011be88 {
    int a; int b; float c;
    Elem_0011be88(const Elem_0011be88 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_0011be88 *Block_0011be88;

struct BlkIter_0011be88 {
    Block_0011be88 *ptr;
    Block_0011be88 *beg;
    Block_0011be88 *first;
    Block_0011be88 *end;
    BlkIter_0011be88 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Block_0011be88 &operator*() const { return *ptr; }
};
inline int operator-(const BlkIter_0011be88 &x, const BlkIter_0011be88 &y)
{
    Block_0011be88 *f = x.first;
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

struct Iter_0011be88 {
    BlkIter_0011be88 i_;
    Elem_0011be88 *cur_;
    Elem_0011be88 *end_;
    Iter_0011be88 &operator++()
    {
        if (++cur_ == end_) {
            ++i_;
            cur_ = *i_;
            end_ = cur_ + 42;
        }
        return *this;
    }
    Elem_0011be88 &operator*() const { return *cur_; }
    Iter_0011be88() {}
};
inline int operator-(const Iter_0011be88 &x, const Iter_0011be88 &y)
{
    return (y.end_ - y.cur_) + ((x.i_ - y.i_) * 42 - (x.end_ - x.cur_));
}

template <class It> inline int distance_0011be88(It first, It last) { return last - first; }

struct Buf_0011be88 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011be88 *data_;
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Block_0011be88 &back() { return data_[(start_ + size_ - 1) % cap_]; }
};
extern "C" {
void FUN_0011dad8(Buf_0011be88 *self, unsigned n);              /* reserve */
void FUN_0011d638(Buf_0011be88 *self, unsigned n);              /* resize */
void FUN_0011d894(Buf_0011be88 *self, const Block_0011be88 &x);          /* push_back */
}

struct Alloc_0011be88 {
    Elem_0011be88 *allocate(unsigned n)
    {
        Elem_0011be88 *p = (Elem_0011be88 *)FUN_00000bcc(n * sizeof(Elem_0011be88));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1370);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_0011be88 *p, const Elem_0011be88 &v) { new (p) Elem_0011be88(v); }
};

struct ForwardTag_0011be88 {};
struct Deque_0011be88 {
    Buf_0011be88 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_0033b490) {
            DAT_002c1328 = 0xffffffd2;
            DAT_0033b490 = 1;
        }
        return DAT_002c1328;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" Iter_0011be88 FUN_0011ed04(Deque_0011be88 *self, unsigned pos);

extern "C" void FUN_0011be88(Deque_0011be88 *self, Iter_0011be88 first, Iter_0011be88 last, ForwardTag_0011be88)
{
    unsigned n = (unsigned)distance_0011be88(first, last);
    if (n != 0) {
        if (n > self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da11c);
            FUN_0000d518();
        }
        FUN_0011dad8(&self->buf_, 2);
        FUN_0011d638(&self->buf_, 1);
        Alloc_0011be88 a;
        do {
            if (self->buf_.size() == self->buf_.capacity())
                FUN_0011dad8(&self->buf_, 2 * self->buf_.size());
            self->buf_.back() = a.allocate(42);
            FUN_0011d894(&self->buf_, 0);
        } while (self->capacity() < n);
        self->start_ = (self->capacity() - n) / 2;
        Iter_0011be88 i = FUN_0011ed04(self, 0);
        for (; self->size_ < n; ++i, ++self->size_, ++first)
            a.construct(&*i, *first);
    }
}
