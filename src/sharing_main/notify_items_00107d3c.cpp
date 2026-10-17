/* HSTMATCH module=hstp_trans_main.prx start=0x00107d3c end=0x00107ddc symbol=FUN_00107d3c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

class Sub {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void v07(bool);
};

struct Item {
    char pad[0x20];
    Sub *sub;
};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

template <class T> struct Vec {
    T *data_;
    unsigned size_;
    unsigned cap_;
    It<T> begin() const { return It<T>(data_); }
    It<T> end() { return It<T>(data_ + size_); }
};

struct Container {
    char pad0[0x10];
    Vec<Item *> v;
    char pad1[8];
    bool flag;
};

extern "C" void FUN_00107d3c(Container *self, bool flag)
{
    self->flag = flag;
    for (It<Item *> it = self->v.begin(); it != self->v.end(); ++it) {
        if ((*it)->sub != 0) {
            (*it)->sub->v07(flag);
        }
    }
}
