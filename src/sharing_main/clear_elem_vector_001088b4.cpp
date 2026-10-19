/* HSTMATCH module=hstp_trans_main.prx start=0x001088b4 end=0x0010896c symbol=FUN_001088b4 lang=c++ */
/* Clone of src/eboot/clear_elem_vector_00102fb0.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

class Elem_00103068 {
public:
    virtual ~Elem_00103068();
};

template <class T> struct It_00103068 {
    T *p_;
    It_00103068(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It_00103068 &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It_00103068<T> &a, const It_00103068<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It_00103068<T> &a, const It_00103068<T> &b) { return !(a == b); }

struct Alloc_00103068 {};

template <class T> struct Vec_00103068 {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It_00103068<T> begin() { return It_00103068<T>(data_); }
    It_00103068<T> end() { return It_00103068<T>(data_ + size_); }
    void shrink(int n, Alloc_00103068) { size_ -= n; }
};

struct Owner_00103068 {
    int head_;
    Vec_00103068<Elem_00103068 *> list_;
};

template <class I> inline void DeleteAll(I first, I last)
{
    for (; first != last; ++first) {
        if (*first != 0) {
            delete *first;
        }
    }
}

extern "C" void FUN_001088b4(Owner_00103068 *self)
{
    DeleteAll(self->list_.begin(), self->list_.end());
    int n = self->list_.size_;
    self->list_.shrink(n, Alloc_00103068());
}
