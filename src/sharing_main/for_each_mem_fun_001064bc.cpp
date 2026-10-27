/* HSTMATCH module=hstp_trans_main.prx start=0x001064bc end=0x0010665c symbol=FUN_001064bc lang=c++ data=0x0037f83c */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/FUN_00100bb4.cpp: addresses, PTMF data and member names substituted); exact match verified; names and types await human review. */
/* for_each over two vector<Elem *> members: vector at +0x10 with mem_fun(&Elem::f_00105694) (no bound arg),
   then vector at +4 with bind2nd(mem_fun(&Elem::f_0010665c), self). PTMFs {0, -1, func} at
   data=0x0037f83c relocate against the two non-virtual member functions. */

struct Owner_001064bc;
class Elem_001064bc {
public:
    void f_00105694();
    void f_0010665c(Owner_001064bc *o);
};

template <class T> struct It_001064bc {
    T *p_;
    It_001064bc(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_001064bc &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_001064bc<T> &a, const It_001064bc<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_001064bc<T> &a, const It_001064bc<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_001064bc {
    typedef T *argument_type;
    typedef R result_type;
    R (T::*pm_)();
    explicit MemFun_001064bc(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_001064bc<R, T> mem_fun_001064bc(R (T::*pm)()) { return MemFun_001064bc<R, T>(pm); }

template <class R, class T, class A> struct MemFun1_001064bc {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_001064bc(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_001064bc<R, T, A> mem_fun_001064bc(R (T::*pm)(A)) { return MemFun1_001064bc<R, T, A>(pm); }

template <class Op> struct Binder2nd_001064bc {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_001064bc(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_001064bc<Op> bind2nd_001064bc(const Op &op, const T &x)
{
    return Binder2nd_001064bc<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_001064bc(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_001064bc {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_001064bc<T> begin() { return It_001064bc<T>(data_); }
    It_001064bc<T> end() { return It_001064bc<T>(data_ + size_); }
};

struct Owner_001064bc {
    int f0_;
    Vec_001064bc<Elem_001064bc *> a_;
    Vec_001064bc<Elem_001064bc *> b_;
};

extern "C" void FUN_001064bc(Owner_001064bc *self)
{
    for_each_001064bc(It_001064bc<Elem_001064bc *>(self->b_.data_),
                      It_001064bc<Elem_001064bc *>(self->b_.data_ + self->b_.size_),
                      mem_fun_001064bc(&Elem_001064bc::f_00105694));
    { int n = self->b_.size_; self->b_.size_ -= n; }
    for_each_001064bc(self->a_.begin(), self->a_.end(), bind2nd_001064bc(mem_fun_001064bc(&Elem_001064bc::f_0010665c), self));
    { int n = self->a_.size_; self->a_.size_ -= n; }
}
