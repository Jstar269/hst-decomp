/* HSTMATCH module=EBOOT.BIN start=0x00120cc8 end=0x001210e4 symbol=FUN_00120cc8 lang=c++ */
#pragma inline_depth(8)
typedef void *T_00120cc8;

template <class P>
struct It_00120cc8 {
    P *ptr;
    P *beg;
    P *first;
    P *end;
    It_00120cc8() {}
    It_00120cc8(P *d, unsigned cap, unsigned start, unsigned i) { first = d + start; end = d + cap; beg = d; ptr = d + i; }
    It_00120cc8(const It_00120cc8<T_00120cc8> &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    P &operator*() const { return *ptr; }
    It_00120cc8 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    It_00120cc8 &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    It_00120cc8 &operator+=(int n)
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
    It_00120cc8 operator+(int n) const
    {
        It_00120cc8 t(*this);
        t += n;
        return t;
    }
};
typedef It_00120cc8<T_00120cc8> Iter_00120cc8;
typedef It_00120cc8<T_00120cc8 const> CIter_00120cc8;

template <class X, class Y> inline int operator-(const It_00120cc8<X> &x, const It_00120cc8<Y> &y)
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
template <class X, class Y> inline bool operator==(const It_00120cc8<X> &x, const It_00120cc8<Y> &y) { return x.ptr == y.ptr; }
template <class X, class Y> inline bool operator!=(const It_00120cc8<X> &x, const It_00120cc8<Y> &y) { return x.ptr != y.ptr; }

template <class I1, class I2, class O> inline O copy_00120cc8(I1 first, I2 last, O result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return result;
}
template <class I1, class I2, class O> inline O copy_backward_00120cc8(I1 first, I2 last, O result)
{
    while (last != first)
        *--result = *--last;
    return result;
}

struct Cdeque_00120cc8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_00120cc8 *data_;
    Iter_00120cc8 begin() { return Iter_00120cc8(data_, cap_, start_, start_); }
    CIter_00120cc8 cend() { return CIter_00120cc8(data_, cap_, start_, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
    void destroy(T_00120cc8 *) {}
};

extern "C" Iter_00120cc8 FUN_00120cc8(Cdeque_00120cc8 *self, Iter_00120cc8 first, Iter_00120cc8 last)
{
    if (first == last)
        return first;
    Iter_00120cc8 b = self->begin();
    CIter_00120cc8 e = self->cend();
    unsigned pos = first - b;
    unsigned back = e - last;
    unsigned n = last - first;
    if (pos < back) {
        copy_backward_00120cc8(b, first, last);
        Iter_00120cc8 nb = b + n;
        for (first = b; first != nb; ++first)
            self->destroy(&*first);
        self->start_ = (self->start_ + n) % self->cap_;
    } else {
        copy_00120cc8(last, e, first);
        for (first += back; first != e; ++first)
            self->destroy(&*first);
    }
    self->size_ -= n;
    return self->begin() + pos;
}
// WIP (2026-10-15, agent fam1-00): 9 words from exact. MSL cdeque<T*>::erase(first, last): by-value iterators
// (a user-declared copy ctor stops MWCC copying the parameters into the frame), copy_backward written
// `while (last != first)`, operator+= normalising `if (i < 0) i += cap; else if (i >= cap) i -= cap;`.
// end() is taken as a const_iterator: retail recomputes end()'s first/end sums after the ?: diamond while
// reusing the loads and shifts, and only a sum of a different pointer type (const T*) escapes MWCC's CSE
// (a local copy of data_ does not). Remaining: after the diamond retail computes end.ptr, end.end, then
// end.first (idx in v1, end.ptr in t6); with this assignment order (first, end, beg, ptr) the end.end sum
// is hoisted into the ?: delay slots and idx lands in t6; ptr-first orders fix that but rotate
// start/start*4/cap*4 among t6/t7/t8 (48-51 words). Tried all 24 ctor argument orders, all 24 ctor
// assignment orders, the 4-pointer ctor with casts, begin() temporaries, signed pos/back/n.
