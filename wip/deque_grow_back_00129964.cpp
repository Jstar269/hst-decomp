/* HSTMATCH module=hstp_trans_main.prx start=0x00129964 end=0x00129e28 symbol=FUN_00129964 lang=c++ */
#pragma inline_depth(8)
extern "C" {
struct Reent_00129964 { int pad[3]; void *err; };
Reent_00129964 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d1750[]; /* "Memory allocation failure" */
}
typedef void *Block;
struct Buf_00129964;
struct Iter_00129964 {
    Block *ptr;
    Block *beg;
    Block *first;
    Block *end;
    Iter_00129964(Buf_00129964 *c, unsigned i);
    Iter_00129964(const Iter_00129964 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_00129964 &operator+=(int n)
    {
        int cap = end - beg;
        n += ptr - beg;
        if (n < 0)
            n += cap;
        else if (n >= cap)
            n -= cap;
        ptr = beg + n;
        return *this;
    }
    Iter_00129964 &operator-=(int n) { return *this += -n; }
    Iter_00129964 operator-(int n) const { return Iter_00129964(*this) -= n; }
};
struct Buf_00129964 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block *data_;
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned size() const { return size_; }
    void swap(Buf_00129964 &x)
    {
        if (this != &x) {
            unsigned t;
            Block *d;
            t = cap_; cap_ = x.cap_; x.cap_ = t;
            t = size_; size_ = x.size_; x.size_ = t;
            t = start_; start_ = x.start_; x.start_ = t;
            d = data_; data_ = x.data_; x.data_ = d;
        }
    }
    Iter_00129964 begin() { return Iter_00129964(this, start_); }
    Iter_00129964 end() { return Iter_00129964(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
    Block &front() { return data_[start_]; }
    void pop_front()
    {
        --size_;
        if (++start_ == cap_)
            start_ = 0;
    }
    Block &back() { return data_[(start_ + size_ - 1) % cap_]; }
};
inline Iter_00129964::Iter_00129964(Buf_00129964 *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}
struct IterMem_00129964 { Block *w[4]; };
struct Tag_00129964 {};
struct Deque_00129964 {
    Buf_00129964 buf_;
    unsigned start_;
    unsigned size_;
};
template <class T> inline const T &max_00129964(const T &a, const T &b) { return a < b ? b : a; }
struct Alloc_00129964 {
    Block allocate()
    {
        Block p = FUN_00000bcc(504);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1750);
            FUN_0000d530();
        }
        return p;
    }
};
extern "C" {
void FUN_00128a68(Buf_00129964 *self, const Block &x);                       /* push_back */
void FUN_00128cac(Buf_00129964 *self, unsigned n);                           /* reserve */
void FUN_001289b8(Buf_00129964 *self);                                       /* clear */
Deque_00129964 *FUN_00128364(Deque_00129964 *self, short flag);              /* ~Deque */
Alloc_00129964 *FUN_00124148(Alloc_00129964 *ret, Deque_00129964 *self);    /* get_allocator */
Buf_00129964 *FUN_00124130(Buf_00129964 *self, Alloc_00129964 *a);          /* Buf(alloc) */
Buf_00129964 *FUN_00123fb4(Buf_00129964 *self, Deque_00129964 *owner, Buf_00129964 *x); /* Buf(x) */
Buf_00129964 *FUN_00123668(Buf_00129964 *self, short flag);                  /* ~Buf */
IterMem_00129964 *FUN_00129eb0(IterMem_00129964 *dst, const Iter_00129964 *src);   /* Iter(const Iter &) */
void FUN_00129e28(Buf_00129964 *self, IterMem_00129964 *pos, IterMem_00129964 *first, IterMem_00129964 *last, Tag_00129964); /* insert(pos, first, last) */
}
inline void InitTmp_00129964(Deque_00129964 *tmp, Deque_00129964 *self)
{
    Alloc_00129964 al;
    Buf_00129964 tb0;
    FUN_00124130(&tb0, FUN_00124148(&al, self));
    FUN_00123fb4(&tmp->buf_, self, &tb0);
    FUN_00123668(&tb0, -1);
}
inline void CallInsert_00129964(Buf_00129964 *t, Iter_00129964 &tbeg, Iter_00129964 &sbeg, Iter_00129964 &send)
{
    IterMem_00129964 c1, c2, c3;
    FUN_00129e28(t, FUN_00129eb0(&c1, &tbeg), FUN_00129eb0(&c2, &sbeg), FUN_00129eb0(&c3, &send), Tag_00129964());
}
inline void CallInsertV2_00129964(Buf_00129964 *t, Iter_00129964 &a, Iter_00129964 &b, Iter_00129964 &c) { CallInsert_00129964(t, a, b, c); }
inline void CopyBlocks_00129964(Buf_00129964 *t, Buf_00129964 *src)
{
    if (src->size() != 0) {
        Iter_00129964 tbeg = t->begin();
        Iter_00129964 sbeg = src->begin();
        Iter_00129964 send = src->end() - 1;
        CallInsertV2_00129964(t, tbeg, sbeg, send);
    }
}
inline void InitTmpV2_00129964(Deque_00129964 *tmp, Deque_00129964 *self) { InitTmp_00129964(tmp, self); }
inline void InitTmpV3_00129964(Deque_00129964 *tmp, Deque_00129964 *self) { InitTmpV2_00129964(tmp, self); }
extern "C" void FUN_00129964(Deque_00129964 *self, unsigned n)
{
    Deque_00129964 tmp;
    int blocks = n / 42 + (n % 42 != 0);
    for (; ((blocks != 0) ^ 1) == 0 && self->start_ >= 42; --blocks) {
        Block b = self->buf_.front();
        self->buf_.pop_front();
        self->buf_.back() = b;
        FUN_00128a68(&self->buf_, Block());
        self->start_ -= 42;
    }
    Alloc_00129964 a;
    unsigned sz = self->buf_.size_;
    unsigned total = blocks + sz;
    if (total <= self->buf_.capacity()) {
        if (blocks == 0)
            return;
        do {
            Block *p = &self->buf_.back();
            *p = a.allocate();
            FUN_00128a68(&self->buf_, Block());
        } while (--blocks != 0);
        return;
    }
    InitTmpV3_00129964(&tmp, self);
    tmp.start_ = 0;
    tmp.size_ = 0;
    Buf_00129964 *t = &tmp.buf_;
    FUN_00128cac(t, max_00129964(self->buf_.capacity() << 1, blocks + self->buf_.size_ + 1));
    FUN_00128a68(t, Block());
    if (blocks != 0) {
        do {
            Block *p = &t->back();
            *p = a.allocate();
            FUN_00128a68(t, Block());
        } while (--blocks != 0);
    }
    CopyBlocks_00129964(t, &self->buf_);
    self->buf_.swap(*t);
    FUN_001289b8(t);
    FUN_00128364(&tmp, -1);
}
// WIP (2026-10-16, agent snF2-00): 6 words from exact; same function as wip/deque_grow_back_0019d9a4.cpp with the
// 42-per-block geometry (n / 42 + (n % 42 != 0), start -= 42, 504-byte blocks) and an inline map swap
// (`this` = the deque's map: loads self's fields first). Structure and frame match word for word; only the colours of
// the size/capacity test differ: retail size v1 / capacity a1 / sum a0 (not in place) / capacity result v1, ours
// size a0 / capacity v1 / sum a0 in place / capacity result v1. See the other wip file for everything tried.
