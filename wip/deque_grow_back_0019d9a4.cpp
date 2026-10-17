/* HSTMATCH module=hstp_trans_main.prx start=0x0019d9a4 end=0x0019de04 symbol=FUN_0019d9a4 lang=c++ */
#pragma inline_depth(8)
extern "C" {
struct Reent_0019d9a4 { int pad[3]; void *err; };
Reent_0019d9a4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d2ca4[]; /* "Memory allocation failure" */
}
typedef void *Block;
struct Buf_0019d9a4;
struct Iter_0019d9a4 {
    Block *ptr;
    Block *beg;
    Block *first;
    Block *end;
    Iter_0019d9a4(Buf_0019d9a4 *c, unsigned i);
    Iter_0019d9a4(const Iter_0019d9a4 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0019d9a4 &operator+=(int n)
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
    Iter_0019d9a4 &operator-=(int n) { return *this += -n; }
    Iter_0019d9a4 operator-(int n) const { return Iter_0019d9a4(*this) -= n; }
};
struct Buf_0019d9a4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block *data_;
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned size() const { return size_; }
    Iter_0019d9a4 begin() { return Iter_0019d9a4(this, start_); }
    Iter_0019d9a4 end() { return Iter_0019d9a4(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
    Block &front() { return data_[start_]; }
    void pop_front()
    {
        --size_;
        if (++start_ == cap_)
            start_ = 0;
    }
    Block &back() { return data_[(start_ + size_ - 1) % cap_]; }
};
inline Iter_0019d9a4::Iter_0019d9a4(Buf_0019d9a4 *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}
struct IterMem_0019d9a4 { Block *w[4]; };
struct Tag_0019d9a4 {};
struct Deque_0019d9a4 {
    Buf_0019d9a4 buf_;
    unsigned start_;
    unsigned size_;
};
template <class T> inline const T &max_0019d9a4(const T &a, const T &b) { return a < b ? b : a; }
struct Alloc_0019d9a4 {
    Block allocate()
    {
        Block p = FUN_00000bcc(512);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d2ca4);
            FUN_0000d530();
        }
        return p;
    }
};
extern "C" {
void FUN_0019ee00(Buf_0019d9a4 *self, const Block &x);                       /* push_back */
void FUN_0019f044(Buf_0019d9a4 *self, unsigned n);                           /* reserve */
void FUN_0019d760(Buf_0019d9a4 *self);                                       /* clear */
void FUN_0019edb0(Buf_0019d9a4 *a, Buf_0019d9a4 *b);                         /* swap */
Deque_0019d9a4 *FUN_0019d3b0(Deque_0019d9a4 *self, short flag);              /* ~Deque */
Alloc_0019d9a4 *FUN_0019e048(Alloc_0019d9a4 *ret, Deque_0019d9a4 *self);    /* get_allocator */
Buf_0019d9a4 *FUN_0019e030(Buf_0019d9a4 *self, Alloc_0019d9a4 *a);          /* Buf(alloc) */
Buf_0019d9a4 *FUN_0019deb4(Buf_0019d9a4 *self, Deque_0019d9a4 *owner, Buf_0019d9a4 *x); /* Buf(x) */
Buf_0019d9a4 *FUN_0019cc10(Buf_0019d9a4 *self, short flag);                  /* ~Buf */
IterMem_0019d9a4 *FUN_0019de8c(IterMem_0019d9a4 *dst, const Iter_0019d9a4 *src);   /* Iter(const Iter &) */
void FUN_0019de04(Buf_0019d9a4 *self, IterMem_0019d9a4 *pos, IterMem_0019d9a4 *first, IterMem_0019d9a4 *last, Tag_0019d9a4); /* insert(pos, first, last) */
}
inline void InitTmp_0019d9a4(Deque_0019d9a4 *tmp, Deque_0019d9a4 *self)
{
    Alloc_0019d9a4 al;
    Buf_0019d9a4 tb0;
    FUN_0019e030(&tb0, FUN_0019e048(&al, self));
    FUN_0019deb4(&tmp->buf_, self, &tb0);
    FUN_0019cc10(&tb0, -1);
}
inline void CallInsert_0019d9a4(Buf_0019d9a4 *t, Iter_0019d9a4 &tbeg, Iter_0019d9a4 &sbeg, Iter_0019d9a4 &send)
{
    IterMem_0019d9a4 c1, c2, c3;
    FUN_0019de04(t, FUN_0019de8c(&c1, &tbeg), FUN_0019de8c(&c2, &sbeg), FUN_0019de8c(&c3, &send), Tag_0019d9a4());
}
inline void CallInsertV2_0019d9a4(Buf_0019d9a4 *t, Iter_0019d9a4 &a, Iter_0019d9a4 &b, Iter_0019d9a4 &c) { CallInsert_0019d9a4(t, a, b, c); }
inline void CopyBlocks_0019d9a4(Buf_0019d9a4 *t, Buf_0019d9a4 *src)
{
    if (src->size() != 0) {
        Iter_0019d9a4 tbeg = t->begin();
        Iter_0019d9a4 sbeg = src->begin();
        Iter_0019d9a4 send = src->end() - 1;
        CallInsertV2_0019d9a4(t, tbeg, sbeg, send);
    }
}
inline void InitTmpV2_0019d9a4(Deque_0019d9a4 *tmp, Deque_0019d9a4 *self) { InitTmp_0019d9a4(tmp, self); }
inline void InitTmpV3_0019d9a4(Deque_0019d9a4 *tmp, Deque_0019d9a4 *self) { InitTmpV2_0019d9a4(tmp, self); }
extern "C" void FUN_0019d9a4(Deque_0019d9a4 *self, unsigned n)
{
    Deque_0019d9a4 tmp;
    int blocks = (n >> 7) + ((n & 0x7f) != 0);
    for (; ((blocks != 0) ^ 1) == 0 && self->start_ >= 128; --blocks) {
        Block b = self->buf_.front();
        self->buf_.pop_front();
        self->buf_.back() = b;
        FUN_0019ee00(&self->buf_, Block());
        self->start_ -= 128;
    }
    Alloc_0019d9a4 a;
    unsigned sz = self->buf_.size_;
    unsigned total = blocks + sz;
    if (total <= self->buf_.capacity()) {
        if (blocks == 0)
            return;
        do {
            Block *p = &self->buf_.back();
            *p = a.allocate();
            FUN_0019ee00(&self->buf_, Block());
        } while (--blocks != 0);
        return;
    }
    InitTmpV3_0019d9a4(&tmp, self);
    tmp.start_ = 0;
    tmp.size_ = 0;
    Buf_0019d9a4 *t = &tmp.buf_;
    FUN_0019f044(t, max_0019d9a4(self->buf_.capacity() << 1, blocks + self->buf_.size_ + 1));
    FUN_0019ee00(t, Block());
    if (blocks != 0) {
        do {
            Block *p = &t->back();
            *p = a.allocate();
            FUN_0019ee00(t, Block());
        } while (--blocks != 0);
    }
    CopyBlocks_0019d9a4(t, &self->buf_);
    FUN_0019edb0(&self->buf_, t);
    FUN_0019d760(t);
    FUN_0019d3b0(&tmp, -1);
}
// WIP (2026-10-16, agent snF2-00): 6 words from exact; the structure and frame match word for word, only register
// colours of the size/capacity test differ: retail loads size into v1, capacity into a1, sum blocks+size into a0
// (not in place) and the capacity result into v1; ours colours size a0 / capacity v1 and computes the sum in place
// (a0) and capacity in place (v1). Tried (all unchanged, 6 words): sz/total/cap locals in every order and type,
// sum-first and capacity-first, getters vs fields, `unsigned blocks`, a Fits() helper (worse), declaration
// placement of tmp/a/t.
// Matching idioms in this source: the loop test `((blocks != 0) ^ 1) == 0 && start_ >= 128` (retail materialises
// sltu/xori/bnezl), Iter::operator+= modifying its by-value parameter (retail keeps the -1 in a1: `li a1,-1; addu`),
// `Buf *t = &tmp.buf_` (saved reg), `size()` getter for the emptiness test (a direct size_ read is CSE'd with the
// end() sum), max() arguments as temporaries (slots 188/184 created cap2 first, evaluated need first), iterator
// copies for FUN_0019de04 made by explicit calls to the out-of-line copy 0x19de8c into POD IterMem slots, and the
// inline-nesting depth of the helpers (InitTmp 3 deep, CopyBlocks > CallInsert > operator- ) that fixes the order
// of the frame temporaries (C, al, tb0, c1..c3 = 112, 108, 92, 76, 60, 44).
