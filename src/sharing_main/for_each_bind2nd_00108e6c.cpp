/* HSTMATCH module=hstp_trans_main.prx start=0x00108e6c end=0x00108f54 symbol=FUN_00108e6c lang=c++ data=0x0037fa04 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Stores the float at +0x4c, then for_each(v.begin(), v.end(), bind2nd(mem_fun(&Elem::v6), value)) over the
   vector<Elem *> member at +4 {data, size, cap}, then calls FUN_001091c4(self). The method is virtual slot 6
   taking a float, so the 12-byte pointer-to-member in .data is {0, 32, 0}, called through __ptmf_scall (0x100c).
   Adapted from the sibling for_each_bind2nd_001090f4.cpp (same TU shape; EBOOT twin 0x00103540). Names provisional. */
class Elem_00108e6c {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float val);
};

template <class T> struct It_00108e6c {
    T *p_;
    It_00108e6c(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00108e6c &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00108e6c<T> &a, const It_00108e6c<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00108e6c<T> &a, const It_00108e6c<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_00108e6c {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_00108e6c(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_00108e6c<R, T, A> mem_fun_00108e6c(R (T::*pm)(A)) { return MemFun1_00108e6c<R, T, A>(pm); }

template <class Op> struct Binder2nd_00108e6c {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_00108e6c(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_00108e6c<Op> bind2nd_00108e6c(const Op &op, const T &x)
{
    return Binder2nd_00108e6c<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_00108e6c(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00108e6c {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00108e6c<T> begin() { return It_00108e6c<T>(data_); }
    It_00108e6c<T> end() { return It_00108e6c<T>(data_ + size_); }
};

struct Owner_00108e6c {
    int pad_[1];
    Vec_00108e6c<Elem_00108e6c *> list_;
    char pad10_[0x4c - 0x10];
    float value_;
};

extern "C" void FUN_001091c4(Owner_00108e6c *self);

extern "C" void FUN_00108e6c(Owner_00108e6c *self, float value)
{
    self->value_ = value;
    for_each_00108e6c(self->list_.begin(), self->list_.end(), bind2nd_00108e6c(mem_fun_00108e6c(&Elem_00108e6c::v6), value));
    FUN_001091c4(self);
}
