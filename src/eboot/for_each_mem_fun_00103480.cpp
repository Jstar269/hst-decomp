/* HSTMATCH module=EBOOT.BIN start=0x00103480 end=0x00103540 symbol=FUN_00103480 lang=c++ data=0x002d8c24 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::method)) over a vector<Elem *> member at +4 {data, size, cap}:
   wrapped-pointer iterators (copied with lwc1/swc1), operator!= as !(a == b), mem_fun_t holding a 12-byte
   MWCC pointer-to-member {this_delta, vtbl_offset, func} emitted in .data and called through the runtime
   helper __ptmf_scall (0x100c, t9 = &ptmf). Names provisional. */
class Elem_00103480 {
public:
    void f_00102c54();
};

template <class T> struct It_00103480 {
    T *p_;
    It_00103480(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00103480 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00103480<T> &a, const It_00103480<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00103480<T> &a, const It_00103480<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00103480 {
    R (T::*pm_)();
    explicit MemFun_00103480(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00103480<R, T> mem_fun_00103480(R (T::*pm)()) { return MemFun_00103480<R, T>(pm); }

template <class I, class F> inline F for_each_00103480(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00103480 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00103480<T> begin() { return It_00103480<T>(data_); }
    It_00103480<T> end() { return It_00103480<T>(data_ + size_); }
};

struct Owner_00103480 {
    int head_;
    Vec_00103480<Elem_00103480 *> list_;
};

extern "C" void FUN_00103480(Owner_00103480 *self)
{
    for_each_00103480(self->list_.begin(), self->list_.end(), mem_fun_00103480(&Elem_00103480::f_00102c54));
}
// EXACT (hstmatch) only with --symbols-extra holding `__ptmf_scall = 0x0000100c;` and
// `f_00102c54__13Elem_00103480Fv = 0x00102c54;` (the PTMF here names the non-virtual member 0x102c54; the
// relocation in .data needs a mangled member name). Family member of 0x103068, not a pure address clone.
