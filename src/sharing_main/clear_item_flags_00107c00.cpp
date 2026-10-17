/* HSTMATCH module=hstp_trans_main.prx start=0x00107c00 end=0x00107c9c symbol=FUN_00107c00 lang=c++ */
/* Clone of src/eboot/clear_item_flags_00102194.cpp (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class Sub {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
};

struct Item {
    char pad[0x0e];
    unsigned short flags;
    char pad2[0x10];
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
    char pad[0x10];
    Vec<Item *> items;
};

extern "C" void FUN_00107c00(Container *self)
{
    for (It<Item *> it = self->items.begin(); it != self->items.end(); ++it) {
        Item *item = *it;
        item->flags &= 0xf9ff;
        if (item->sub != 0) item->sub->v09();
    }
}
