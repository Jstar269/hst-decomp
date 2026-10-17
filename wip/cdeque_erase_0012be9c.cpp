/* HSTMATCH module=hstp_trans_main.prx start=0x0012be9c end=0x0012c2b8 symbol=FUN_0012be9c lang=c++ */
#pragma inline_depth(8)
typedef void *T_0012be9c;

template <class P>
struct It_0012be9c {
    P *ptr;
    P *beg;
    P *first;
    P *end;
    It_0012be9c() {}
    It_0012be9c(P *d, unsigned cap, unsigned start, unsigned i) { first = d + start; end = d + cap; beg = d; ptr = d + i; }
    It_0012be9c(const It_0012be9c<T_0012be9c> &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    P &operator*() const { return *ptr; }
    It_0012be9c &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    It_0012be9c &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    It_0012be9c &operator+=(int n)
    {
        int cap = end - beg;
        int i = n + (ptr - beg);
        if (i < 0)
            i += cap;
        else if (i >= cap)
            i -= cap;
        ptr = beg + i;
        return *this;
    }
    It_0012be9c operator+(int n) const
    {
        It_0012be9c t(*this);
        t += n;
        return t;
    }
};
typedef It_0012be9c<T_0012be9c> Iter_0012be9c;
typedef It_0012be9c<T_0012be9c const> CIter_0012be9c;

template <class X, class Y> inline int operator-(const It_0012be9c<X> &x, const It_0012be9c<Y> &y)
{
    X *f = x.first;
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
template <class X, class Y> inline bool operator==(const It_0012be9c<X> &x, const It_0012be9c<Y> &y) { return x.ptr == y.ptr; }
template <class X, class Y> inline bool operator!=(const It_0012be9c<X> &x, const It_0012be9c<Y> &y) { return x.ptr != y.ptr; }

template <class I1, class I2, class O> inline O copy_0012be9c(I1 first, I2 last, O result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return result;
}
template <class I1, class I2, class O> inline O copy_backward_0012be9c(I1 first, I2 last, O result)
{
    while (last != first)
        *--result = *--last;
    return result;
}

struct Cdeque_0012be9c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0012be9c *data_;
    Iter_0012be9c begin() { return Iter_0012be9c(data_, cap_, start_, start_); }
    CIter_0012be9c cend() { return CIter_0012be9c(data_, cap_, start_, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
    void destroy(T_0012be9c *) {}
};

extern "C" Iter_0012be9c FUN_0012be9c(Cdeque_0012be9c *self, Iter_0012be9c first, Iter_0012be9c last)
{
    if (first == last)
        return first;
    Iter_0012be9c b = self->begin();
    CIter_0012be9c e = self->cend();
    unsigned pos = first - b;
    unsigned back = e - last;
    unsigned n = last - first;
    if (pos < back) {
        copy_backward_0012be9c(b, first, last);
        Iter_0012be9c nb = b + n;
        for (first = b; first != nb; ++first)
            self->destroy(&*first);
        self->start_ = (self->start_ + n) % self->cap_;
    } else {
        copy_0012be9c(last, e, first);
        for (first += back; first != e; ++first)
            self->destroy(&*first);
    }
    self->size_ -= n;
    return self->begin() + pos;
}
// WIP (2026-10-16, agent snF2-00): 9 words from exact; the Sharing twin of wip/cdeque_erase_00120cc8.cpp (same code).
// MSL cdeque<T*>::erase(first, last). Everything matches except the diamond that builds end(): retail schedules
// `sll v1,v1,2` (idx*4) into the delay slot of the `b` and the else arm and puts idx in v1 (end.end `addu v1,t1,t7`
// after the join); ours hoists end.end into the delay slot and holds idx in t6. Assigning end()'s ptr first
// (orders p,f,e,b / p,e,f,b) fixes the diamond, but then start/start*4/cap*4 rotate among t6/t7/t8 (48-51 words:
// retail start=t6, start*4=t8, cap*4=t7, end.ptr reuses t6, end.first goes to t5; ours start=t8, start*4 t6/t7,
// end.ptr t5, end.first computed in place over start*4).
// Ruled out here (all >= 9 words): separate ctor assignment orders for the iterator (K=0) and const_iterator (K=1)
// types (288 combinations), 4-pointer ctors with every parameter order for the const_iterator (24), a (Cdeque *, idx)
// ctor reading the fields itself (non-const and const container, local typed pointer, all 24 orders), local `i` for
// the ?: result, begin()/cend() as named locals (112 words), all 6 orders of the pos/back/n statements.
