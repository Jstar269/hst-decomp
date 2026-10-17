/* HSTMATCH module=EBOOT.BIN start=0x00103128 end=0x001031e8 symbol=FUN_00103128 lang=c++ data=0x002d8bc4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::method)) over a vector<Elem *> member at +4 {data, size, cap}:
   wrapped-pointer iterators (copied with lwc1/swc1), operator!= as !(a == b), mem_fun_t holding a 12-byte
   MWCC pointer-to-member {this_delta, vtbl_offset, func} emitted in .data and called through the runtime
   helper __ptmf_scall (0x100c, t9 = &ptmf). Names provisional. */
class Elem_00103128 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};

template <class T> struct It_00103128 {
    T *p_;
    It_00103128(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00103128 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00103128<T> &a, const It_00103128<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00103128<T> &a, const It_00103128<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00103128 {
    R (T::*pm_)();
    explicit MemFun_00103128(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00103128<R, T> mem_fun_00103128(R (T::*pm)()) { return MemFun_00103128<R, T>(pm); }

template <class I, class F> inline F for_each_00103128(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00103128 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00103128<T> begin() { return It_00103128<T>(data_); }
    It_00103128<T> end() { return It_00103128<T>(data_ + size_); }
};

struct Owner_00103128 {
    int head_;
    Vec_00103128<Elem_00103128 *> list_;
};

extern "C" void FUN_00103128(Owner_00103128 *self)
{
    for_each_00103128(self->list_.begin(), self->list_.end(), mem_fun_00103128(&Elem_00103128::v11));
}
// EXACT (hstmatch) only with --symbols-extra holding `__ptmf_scall = 0x0000100c;`. Family member of 0x103068
// whose PTMF names vtable slot 0x34 (v11) instead of 0x30, so a pure address-substituting clone cannot make it.
