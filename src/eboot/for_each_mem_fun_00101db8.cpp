/* HSTMATCH module=EBOOT.BIN start=0x00101db8 end=0x00101e78 symbol=FUN_00101db8 lang=c++ data=0x002d8b10 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* for_each(v.begin(), v.end(), mem_fun(&Elem::f_000ffbdc)) over a vector<Elem *> member at +0x10.
   PTMF {0, -1, 0x000ffbdc} at data=0x002d8b10 relocates against f_000ffbdc__13Elem_00101c18Fv. */

class Elem_00101c18 {
public:
    void f_000ffbdc();
};

template <class T> struct It_00101c18 {
    T *p_;
    It_00101c18(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00101c18 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00101c18<T> &a, const It_00101c18<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00101c18<T> &a, const It_00101c18<T> &b) { return !(a == b); }

template <class R, class T> struct MemFun_00101c18 {
    typedef T *argument_type;
    typedef R result_type;
    R (T::*pm_)();
    explicit MemFun_00101c18(R (T::*pm)()) : pm_(pm) {}
    R operator()(T *p) const { return (p->*pm_)(); }
};
template <class R, class T> inline MemFun_00101c18<R, T> mem_fun_00101c18(R (T::*pm)()) { return MemFun_00101c18<R, T>(pm); }

template <class I, class F> inline F for_each_00101c18(I first, I last, F f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

template <class T> struct Vec_00101c18 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00101c18<T> begin() { return It_00101c18<T>(data_); }
    It_00101c18<T> end() { return It_00101c18<T>(data_ + size_); }
};

struct Owner_00101c18 {
    int pad_[4];
    Vec_00101c18<Elem_00101c18 *> list_;
};

extern "C" void FUN_00101db8(Owner_00101c18 *self)
{
    for_each_00101c18(self->list_.begin(), self->list_.end(), mem_fun_00101c18(&Elem_00101c18::f_000ffbdc));
}
