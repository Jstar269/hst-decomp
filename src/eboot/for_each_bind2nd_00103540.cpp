/* HSTMATCH module=EBOOT.BIN start=0x00103540 end=0x00103628 symbol=FUN_00103540 lang=c++ data=0x002d8c30 */
/* Clone of src/sharing_main/for_each_bind2nd_00108e6c.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Stores the float at +0x4c, then for_each(v.begin(), v.end(), bind2nd(mem_fun(&Elem::v6), value)) over the
   vector<Elem *> member at +4 {data, size, cap}, then calls FUN_00103898(self). The method is virtual slot 6
   taking a float, so the 12-byte pointer-to-member in .data is {0, 32, 0}, called through __ptmf_scall (0x100c).
   Adapted from the sibling for_each_bind2nd_001090f4.cpp (same TU shape; EBOOT twin 0x00103540). Names provisional. */
class Elem_00103540 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float val);
};

template <class T> struct It_00103540 {
    T *p_;
    It_00103540(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00103540 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00103540<T> &a, const It_00103540<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00103540<T> &a, const It_00103540<T> &b) { return !(a == b); }

template <class R, class T, class A> struct MemFun1_00103540 {
    typedef T *first_argument_type;
    typedef A second_argument_type;
    typedef R result_type;
    R (T::*pm_)(A);
    explicit MemFun1_00103540(R (T::*pm)(A)) : pm_(pm) {}
    R operator()(T *p, A a) const { return (p->*pm_)(a); }
};
template <class R, class T, class A> inline MemFun1_00103540<R, T, A> mem_fun_00103540(R (T::*pm)(A)) { return MemFun1_00103540<R, T, A>(pm); }

template <class Op> struct Binder2nd_00103540 {
    Op op_;
    typename Op::second_argument_type value_;
    Binder2nd_00103540(const Op &op, const typename Op::second_argument_type &v) : op_(op), value_(v) {}
    typename Op::result_type operator()(const typename Op::first_argument_type &x) const { return op_(x, value_); }
};
template <class Op, class T> inline Binder2nd_00103540<Op> bind2nd_00103540(const Op &op, const T &x)
{
    return Binder2nd_00103540<Op>(op, typename Op::second_argument_type(x));
}

template <class I, class F> inline F for_each_00103540(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00103540 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00103540<T> begin() { return It_00103540<T>(data_); }
    It_00103540<T> end() { return It_00103540<T>(data_ + size_); }
};

struct Owner_00103540 {
    int pad_[1];
    Vec_00103540<Elem_00103540 *> list_;
    char pad10_[0x4c - 0x10];
    float value_;
};

extern "C" void FUN_00103898(Owner_00103540 *self);

extern "C" void FUN_00103540(Owner_00103540 *self, float value)
{
    self->value_ = value;
    for_each_00103540(self->list_.begin(), self->list_.end(), bind2nd_00103540(mem_fun_00103540(&Elem_00103540::v6), value));
    FUN_00103898(self);
}
