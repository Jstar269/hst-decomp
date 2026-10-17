/* HSTMATCH module=EBOOT.BIN start=0x00103068 end=0x00103128 symbol=FUN_00103068 lang=c++ data=0x002d8bb8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::method)) over a vector<Elem *> member at +4 {data, size, cap}:
   wrapped-pointer iterators (copied with lwc1/swc1), operator!= as !(a == b), mem_fun_t holding a 12-byte
   MWCC pointer-to-member {this_delta, vtbl_offset, func} emitted in .data and called through the runtime
   helper __ptmf_scall (0x100c, t9 = &ptmf). Names provisional. */
class Elem_00103068 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
};

template <class T> struct It_00103068 {
    T *p_;
    It_00103068(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00103068 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00103068<T> &a, const It_00103068<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00103068<T> &a, const It_00103068<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00103068 {
    R (T::*pm_)();
    explicit MemFun_00103068(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00103068<R, T> mem_fun_00103068(R (T::*pm)()) { return MemFun_00103068<R, T>(pm); }

template <class I, class F> inline F for_each_00103068(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00103068 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00103068<T> begin() { return It_00103068<T>(data_); }
    It_00103068<T> end() { return It_00103068<T>(data_ + size_); }
};

struct Owner_00103068 {
    int head_;
    Vec_00103068<Elem_00103068 *> list_;
};

extern "C" void FUN_00103068(Owner_00103068 *self)
{
    for_each_00103068(self->list_.begin(), self->list_.end(), mem_fun_00103068(&Elem_00103068::v10));
}
// EXACT (hstmatch) only with --symbols-extra holding `__ptmf_scall = 0x0000100c;` (MWCC PTMF call helper the
// compiler references implicitly; no way to rename it in source). Needs that entry in symbols/EBOOT.BIN.txt.
