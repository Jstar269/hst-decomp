/* HSTMATCH module=hstp_trans_main.prx start=0x00108f54 end=0x00109024 symbol=FUN_00108f54 lang=c++ data=0x0037fa10 */
/* Hand-written reconstruction (port of src/eboot/for_each_bind2nd_00103628.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), bind2nd(mem_fun(&Elem::method), flag)) over a vector<Elem *> member at +4
   {data, size, cap}; method is virtual slot 1 taking a bool. The binder (12-byte MWCC pointer-to-member in
   .data + the bool) is copied by value into for_each and called through __ptmf_scall (0x100c) with the bool
   in a1. Same shape as for_each_mem_fun_00103068. Names provisional. */
class Elem_00108f54 {
public:
    virtual void v00();
    virtual void v01(bool on);
};

template <class T> struct It_00108f54 {
    T *p_;
    It_00108f54(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00108f54 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00108f54<T> &a, const It_00108f54<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00108f54<T> &a, const It_00108f54<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_00108f54 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_00108f54(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_00108f54<R, T, A> mem_fun_00108f54(R (T::*pm)(A)) { return MemFun1_00108f54<R, T, A>(pm); }

template <class Op> struct Binder2nd_00108f54 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_00108f54(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_00108f54<Op> bind2nd_00108f54(const Op &op, const T &x)
{
    return Binder2nd_00108f54<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_00108f54(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00108f54 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00108f54<T> begin() { return It_00108f54<T>(data_); }
    It_00108f54<T> end() { return It_00108f54<T>(data_ + size_); }
};

struct Owner_00108f54 {
    int head_;
    Vec_00108f54<Elem_00108f54 *> list_;
};

extern "C" void FUN_00108f54(Owner_00108f54 *self, bool on)
{
    for_each_00108f54(self->list_.begin(), self->list_.end(), bind2nd_00108f54(mem_fun_00108f54(&Elem_00108f54::v01), on));
}
