/* HSTMATCH module=EBOOT.BIN start=0x00101f48 end=0x00102018 symbol=FUN_00101f48 lang=c++ data=0x002d8b28 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

class Elem_00101f48 {
public:
    void f_000ffc3c(short val);
};

template <class T> struct It_00101f48 {
    T *p_;
    It_00101f48(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00101f48 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00101f48<T> &a, const It_00101f48<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00101f48<T> &a, const It_00101f48<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_00101f48 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_00101f48(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_00101f48<R, T, A> mem_fun_00101f48(R (T::*pm)(A)) { return MemFun1_00101f48<R, T, A>(pm); }

template <class Op> struct Binder2nd_00101f48 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_00101f48(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_00101f48<Op> bind2nd_00101f48(const Op &op, const T &x)
{
    return Binder2nd_00101f48<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_00101f48(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00101f48 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00101f48<T> begin() { return It_00101f48<T>(data_); }
    It_00101f48<T> end() { return It_00101f48<T>(data_ + size_); }
};

struct Owner_00101f48 {
    int pad_[4];
    Vec_00101f48<Elem_00101f48 *> list_;
};

extern "C" void FUN_00101f48(Owner_00101f48 *self, short val)
{
    for_each_00101f48(self->list_.begin(), self->list_.end(), bind2nd_00101f48(mem_fun_00101f48(&Elem_00101f48::f_000ffc3c), val));
}
