/* HSTMATCH module=EBOOT.BIN start=0x001037c8 end=0x00103898 symbol=FUN_001037c8 lang=c++ data=0x002d8c54 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

class Elem_001037c8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(short val);
};

template <class T> struct It_001037c8 {
    T *p_;
    It_001037c8(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_001037c8 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_001037c8<T> &a, const It_001037c8<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_001037c8<T> &a, const It_001037c8<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_001037c8 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_001037c8(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_001037c8<R, T, A> mem_fun_001037c8(R (T::*pm)(A)) { return MemFun1_001037c8<R, T, A>(pm); }

template <class Op> struct Binder2nd_001037c8 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_001037c8(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_001037c8<Op> bind2nd_001037c8(const Op &op, const T &x)
{
    return Binder2nd_001037c8<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_001037c8(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_001037c8 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_001037c8<T> begin() { return It_001037c8<T>(data_); }
    It_001037c8<T> end() { return It_001037c8<T>(data_ + size_); }
};

struct Owner_001037c8 {
    int pad_[1];
    Vec_001037c8<Elem_001037c8 *> list_;
};

extern "C" void FUN_001037c8(Owner_001037c8 *self, short val)
{
    for_each_001037c8(self->list_.begin(), self->list_.end(), bind2nd_001037c8(mem_fun_001037c8(&Elem_001037c8::v5), val));
}
