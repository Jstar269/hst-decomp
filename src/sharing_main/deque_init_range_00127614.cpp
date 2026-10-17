/* HSTMATCH module=hstp_trans_main.prx start=0x00127614 end=0x001279fc symbol=FUN_00127614 lang=c++ */
/* Clone of src/eboot/deque_init_range_0011be88.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per 504-byte block, block pointers held in a cdeque with a
   trailing null slot): range initialisation from a pair of deque iterators (forward-iterator overload).
   distance() takes the iterators by value; max_size() is an inline function with a guarded static local
   (guard 0x3e47d1, value 0x2d170c). Names provisional. */
extern "C" {
struct Reent_00127614 { int pad[3]; void *err; };
Reent_00127614 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003810fc[]; /* "deque construction length error" */
extern char DAT_002d1718[]; /* "Memory allocation failure" */
extern char DAT_003e47d1;       /* max_size() static-local guard */
extern unsigned DAT_002d170c;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_00127614 {
    int a; int b; float c;
    Elem_00127614(const Elem_00127614 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_00127614 *Block_00127614;

struct BlkIter_00127614 {
    Block_00127614 *ptr;
    Block_00127614 *beg;
    Block_00127614 *first;
    Block_00127614 *end;
    BlkIter_00127614 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Block_00127614 &operator*() const { return *ptr; }
};
inline int operator-(const BlkIter_00127614 &x, const BlkIter_00127614 &y)
{
    Block_00127614 *f = x.first;
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

struct Iter_00127614 {
    BlkIter_00127614 i_;
    Elem_00127614 *cur_;
    Elem_00127614 *end_;
    Iter_00127614 &operator++()
    {
        if (++cur_ == end_) {
            ++i_;
            cur_ = *i_;
            end_ = cur_ + 42;
        }
        return *this;
    }
    Elem_00127614 &operator*() const { return *cur_; }
    Iter_00127614() {}
};
inline int operator-(const Iter_00127614 &x, const Iter_00127614 &y)
{
    return (y.end_ - y.cur_) + ((x.i_ - y.i_) * 42 - (x.end_ - x.cur_));
}

template <class It> inline int distance_00127614(It first, It last) { return last - first; }

struct Buf_00127614 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00127614 *data_;
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Block_00127614 &back() { return data_[(start_ + size_ - 1) % cap_]; }
};
extern "C" {
void FUN_00129384(Buf_00127614 *self, unsigned n);              /* reserve */
void FUN_00128ee4(Buf_00127614 *self, unsigned n);              /* resize */
void FUN_00129140(Buf_00127614 *self, const Block_00127614 &x);          /* push_back */
}

struct Alloc_00127614 {
    Elem_00127614 *allocate(unsigned n)
    {
        Elem_00127614 *p = (Elem_00127614 *)FUN_00000bcc(n * sizeof(Elem_00127614));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1718);
            FUN_0000d530();
        }
        return p;
    }
    void construct(Elem_00127614 *p, const Elem_00127614 &v) { new (p) Elem_00127614(v); }
};

struct ForwardTag_00127614 {};
struct Deque_00127614 {
    Buf_00127614 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_003e47d1) {
            DAT_002d170c = 0xffffffd2;
            DAT_003e47d1 = 1;
        }
        return DAT_002d170c;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" Iter_00127614 FUN_0012a530(Deque_00127614 *self, unsigned pos);

extern "C" void FUN_00127614(Deque_00127614 *self, Iter_00127614 first, Iter_00127614 last, ForwardTag_00127614)
{
    unsigned n = (unsigned)distance_00127614(first, last);
    if (n != 0) {
        if (n > self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003810fc);
            FUN_0000d530();
        }
        FUN_00129384(&self->buf_, 2);
        FUN_00128ee4(&self->buf_, 1);
        Alloc_00127614 a;
        do {
            if (self->buf_.size() == self->buf_.capacity())
                FUN_00129384(&self->buf_, 2 * self->buf_.size());
            self->buf_.back() = a.allocate(42);
            FUN_00129140(&self->buf_, 0);
        } while (self->capacity() < n);
        self->start_ = (self->capacity() - n) / 2;
        Iter_00127614 i = FUN_0012a530(self, 0);
        for (; self->size_ < n; ++i, ++self->size_, ++first)
            a.construct(&*i, *first);
    }
}
