/* HSTMATCH module=hstp_trans_main.prx start=0x00107824 end=0x001078e4 symbol=FUN_00107824 lang=c++ data=0x0037f8dc */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::f_00105510)) over a vector<Elem *> member at +0x10.
   PTMF {0, -1, 0x00105510} at data=0x0037f8dc relocates against f_00105510__13Elem_00107824Fv. */

class Elem_00107824 {
public:
    void f_00105510();
};

template <class T> struct It_00107824 {
    T *p_;
    It_00107824(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00107824 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00107824<T> &a, const It_00107824<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00107824<T> &a, const It_00107824<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00107824 {
    typedef T *argument_type;
    typedef R result_type;
    R (T::*pm_)();
    explicit MemFun_00107824(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00107824<R, T> mem_fun_00107824(R (T::*pm)()) { return MemFun_00107824<R, T>(pm); }

template <class I, class F> inline F for_each_00107824(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00107824 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00107824<T> begin() { return It_00107824<T>(data_); }
    It_00107824<T> end() { return It_00107824<T>(data_ + size_); }
};

struct Owner_00107824 {
    int pad_[4];
    Vec_00107824<Elem_00107824 *> list_;
};

extern "C" void FUN_00107824(Owner_00107824 *self)
{
    for_each_00107824(self->list_.begin(), self->list_.end(), mem_fun_00107824(&Elem_00107824::f_00105510));
}
