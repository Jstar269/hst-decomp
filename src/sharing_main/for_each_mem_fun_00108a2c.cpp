/* HSTMATCH module=hstp_trans_main.prx start=0x00108a2c end=0x00108aec symbol=FUN_00108a2c lang=c++ data=0x0037f990 */
/* Hand-written reconstruction (port of src/eboot/for_each_mem_fun_00103128.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::method)) over a vector<Elem *> member at +4 {data, size, cap}:
   wrapped-pointer iterators (copied with lwc1/swc1), operator!= as !(a == b), mem_fun_t holding a 12-byte
   MWCC pointer-to-member {this_delta, vtbl_offset, func} emitted in .data and called through the runtime
   helper __ptmf_scall (0x100c, t9 = &ptmf). Names provisional. */
class Elem_00108a2c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};

template <class T> struct It_00108a2c {
    T *p_;
    It_00108a2c(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00108a2c &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00108a2c<T> &a, const It_00108a2c<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00108a2c<T> &a, const It_00108a2c<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00108a2c {
    R (T::*pm_)();
    explicit MemFun_00108a2c(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00108a2c<R, T> mem_fun_00108a2c(R (T::*pm)()) { return MemFun_00108a2c<R, T>(pm); }

template <class I, class F> inline F for_each_00108a2c(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00108a2c {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00108a2c<T> begin() { return It_00108a2c<T>(data_); }
    It_00108a2c<T> end() { return It_00108a2c<T>(data_ + size_); }
};

struct Owner_00108a2c {
    int head_;
    Vec_00108a2c<Elem_00108a2c *> list_;
};

extern "C" void FUN_00108a2c(Owner_00108a2c *self)
{
    for_each_00108a2c(self->list_.begin(), self->list_.end(), mem_fun_00108a2c(&Elem_00108a2c::v11));
}
// EXACT (hstmatch) only with --symbols-extra holding `__ptmf_scall = 0x0000100c;`. Family member of 0x103068
// whose PTMF names vtable slot 0x34 (v11) instead of 0x30, so a pure address-substituting clone cannot make it.
