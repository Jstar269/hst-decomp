/* HSTMATCH module=EBOOT.BIN start=0x00100bb4 end=0x00100d54 symbol=FUN_00100bb4 lang=c++ data=0x002d8a9c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each over two vector<Elem *> members: vector at +0x10 with mem_fun(&Elem::f_000ffd60) (no bound arg),
   then vector at +4 with bind2nd(mem_fun(&Elem::f_00100d54), self). PTMFs {0, -1, func} at
   data=0x002d8a9c relocate against the two non-virtual member functions. */

struct Owner_00100bb4;
class Elem_00100bb4 {
public:
    void f_000ffd60();
    void f_00100d54(Owner_00100bb4 *o);
};

template <class T> struct It_00100bb4 {
    T *p_;
    It_00100bb4(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00100bb4 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00100bb4<T> &a, const It_00100bb4<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00100bb4<T> &a, const It_00100bb4<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00100bb4 {
    typedef T *argument_type;
    typedef R result_type;
    R (T::*pm_)();
    explicit MemFun_00100bb4(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00100bb4<R, T> mem_fun_00100bb4(R (T::*pm)()) { return MemFun_00100bb4<R, T>(pm); }

template <class R, class T, class A> struct MemFun1_00100bb4 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_00100bb4(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_00100bb4<R, T, A> mem_fun_00100bb4(R (T::*pm)(A)) { return MemFun1_00100bb4<R, T, A>(pm); }

template <class Op> struct Binder2nd_00100bb4 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_00100bb4(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_00100bb4<Op> bind2nd_00100bb4(const Op &op, const T &x)
{
    return Binder2nd_00100bb4<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_00100bb4(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00100bb4 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00100bb4<T> begin() { return It_00100bb4<T>(data_); }
    It_00100bb4<T> end() { return It_00100bb4<T>(data_ + size_); }
};

struct Owner_00100bb4 {
    int f0_;
    Vec_00100bb4<Elem_00100bb4 *> a_;
    Vec_00100bb4<Elem_00100bb4 *> b_;
};

extern "C" void FUN_00100bb4(Owner_00100bb4 *self)
{
    for_each_00100bb4(It_00100bb4<Elem_00100bb4 *>(self->b_.data_),
                      It_00100bb4<Elem_00100bb4 *>(self->b_.data_ + self->b_.size_),
                      mem_fun_00100bb4(&Elem_00100bb4::f_000ffd60));
    { int n = self->b_.size_; self->b_.size_ -= n; }
    for_each_00100bb4(self->a_.begin(), self->a_.end(), bind2nd_00100bb4(mem_fun_00100bb4(&Elem_00100bb4::f_00100d54), self));
    { int n = self->a_.size_; self->a_.size_ -= n; }
}
