/* HSTMATCH module=EBOOT.BIN start=0x0011c440 end=0x0011c828 symbol=FUN_0011c440 lang=c++ */
/* Clone of src/eboot/deque_init_range_0011be88.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per 504-byte block, block pointers held in a cdeque with a
   trailing null slot): range initialisation from a pair of deque iterators (forward-iterator overload).
   distance() takes the iterators by value; max_size() is an inline function with a guarded static local
   (guard 0x33b491, value 0x2c132c). Names provisional. */
extern "C" {
struct Reent_0011c440 { int pad[3]; void *err; };
Reent_0011c440 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da11c[]; /* "deque construction length error" */
extern char DAT_002c1338[]; /* "Memory allocation failure" */
extern char DAT_0033b491;       /* max_size() static-local guard */
extern unsigned DAT_002c132c;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_0011c440 {
    int a; int b; float c;
    Elem_0011c440(const Elem_0011c440 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_0011c440 *Block_0011c440;

struct BlkIter_0011c440 {
    Block_0011c440 *ptr;
    Block_0011c440 *beg;
    Block_0011c440 *first;
    Block_0011c440 *end;
    BlkIter_0011c440 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Block_0011c440 &operator*() const { return *ptr; }
};
inline int operator-(const BlkIter_0011c440 &x, const BlkIter_0011c440 &y)
{
    Block_0011c440 *f = x.first;
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

struct Iter_0011c440 {
    BlkIter_0011c440 i_;
    Elem_0011c440 *cur_;
    Elem_0011c440 *end_;
    Iter_0011c440 &operator++()
    {
        if (++cur_ == end_) {
            ++i_;
            cur_ = *i_;
            end_ = cur_ + 42;
        }
        return *this;
    }
    Elem_0011c440 &operator*() const { return *cur_; }
    Iter_0011c440() {}
};
inline int operator-(const Iter_0011c440 &x, const Iter_0011c440 &y)
{
    return (y.end_ - y.cur_) + ((x.i_ - y.i_) * 42 - (x.end_ - x.cur_));
}

template <class It> inline int distance_0011c440(It first, It last) { return last - first; }

struct Buf_0011c440 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011c440 *data_;
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Block_0011c440 &back() { return data_[(start_ + size_ - 1) % cap_]; }
};
extern "C" {
void FUN_0011e1b0(Buf_0011c440 *self, unsigned n);              /* reserve */
void FUN_0011dd10(Buf_0011c440 *self, unsigned n);              /* resize */
void FUN_0011df6c(Buf_0011c440 *self, const Block_0011c440 &x);          /* push_back */
}

struct Alloc_0011c440 {
    Elem_0011c440 *allocate(unsigned n)
    {
        Elem_0011c440 *p = (Elem_0011c440 *)FUN_00000bcc(n * sizeof(Elem_0011c440));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1338);
            FUN_0000d518();
        }
        return p;
    }
    void construct(Elem_0011c440 *p, const Elem_0011c440 &v) { new (p) Elem_0011c440(v); }
};

struct ForwardTag_0011c440 {};
struct Deque_0011c440 {
    Buf_0011c440 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_0033b491) {
            DAT_002c132c = 0xffffffd2;
            DAT_0033b491 = 1;
        }
        return DAT_002c132c;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" Iter_0011c440 FUN_0011f35c(Deque_0011c440 *self, unsigned pos);

extern "C" void FUN_0011c440(Deque_0011c440 *self, Iter_0011c440 first, Iter_0011c440 last, ForwardTag_0011c440)
{
    unsigned n = (unsigned)distance_0011c440(first, last);
    if (n != 0) {
        if (n > self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da11c);
            FUN_0000d518();
        }
        FUN_0011e1b0(&self->buf_, 2);
        FUN_0011dd10(&self->buf_, 1);
        Alloc_0011c440 a;
        do {
            if (self->buf_.size() == self->buf_.capacity())
                FUN_0011e1b0(&self->buf_, 2 * self->buf_.size());
            self->buf_.back() = a.allocate(42);
            FUN_0011df6c(&self->buf_, 0);
        } while (self->capacity() < n);
        self->start_ = (self->capacity() - n) / 2;
        Iter_0011c440 i = FUN_0011f35c(self, 0);
        for (; self->size_ < n; ++i, ++self->size_, ++first)
            a.construct(&*i, *first);
    }
}
