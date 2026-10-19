/* HSTMATCH module=hstp_trans_main.prx start=0x001090f4 end=0x001091c4 symbol=FUN_001090f4 lang=c++ data=0x0037fa28 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), bind2nd(mem_fun(&Elem::v5), value)) over a vector<Elem *> member at +4
   {data, size, cap}; the method is virtual slot 5 taking a short, so the 12-byte pointer-to-member in .data
   is {0, 28, 0} and is called through the runtime helper __ptmf_scall (0x100c). Names provisional. */
class Elem_001090f4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(short val);
};

template <class T> struct It_001090f4 {
    T *p_;
    It_001090f4(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_001090f4 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_001090f4<T> &a, const It_001090f4<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_001090f4<T> &a, const It_001090f4<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_001090f4 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_001090f4(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_001090f4<R, T, A> mem_fun_001090f4(R (T::*pm)(A)) { return MemFun1_001090f4<R, T, A>(pm); }

template <class Op> struct Binder2nd_001090f4 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_001090f4(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_001090f4<Op> bind2nd_001090f4(const Op &op, const T &x)
{
    return Binder2nd_001090f4<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_001090f4(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_001090f4 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_001090f4<T> begin() { return It_001090f4<T>(data_); }
    It_001090f4<T> end() { return It_001090f4<T>(data_ + size_); }
};

struct Owner_001090f4 {
    int pad_[1];
    Vec_001090f4<Elem_001090f4 *> list_;
};

extern "C" void FUN_001090f4(Owner_001090f4 *self, short value)
{
    for_each_001090f4(self->list_.begin(), self->list_.end(), bind2nd_001090f4(mem_fun_001090f4(&Elem_001090f4::v5), value));
}
