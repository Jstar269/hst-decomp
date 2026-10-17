/* HSTMATCH module=hstp_trans_main.prx start=0x00107a84 end=0x00107c00 symbol=FUN_00107a84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* For every item of the vector at +0x10: clamp the carried mode to [DAT_0037f900, 1] (inline clamp taking the
   lower bound by const reference gives retail's doubled global load), set the 0x200/0x400 flag in item+0xe,
   store four shorts into the second clamp's record (DAT_0037f758 bound) and forward everything to the item's
   child through virtual slot 8. The iterator has a user-level !(a == b) operator!= and end() is re-read every
   pass. Names provisional. */
class Sub {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(int a, int b, int c, int d, int e);
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

struct Rec {
    short a, b, c, d;
};
struct Tab {
    char pad[0x4c];
    Rec rec[2];
};
extern int DAT_0037f900;
extern int DAT_0037f758;
extern Tab DAT_003e39c0;

inline int Clamp(int v, const int &lo, int hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_00107a84(Container *self, int mode, int a, int b, int c, int d)
{
    for (It<Item *> it = self->items.begin(); it != self->items.end(); ++it) {
        Item *item = *it;
        mode = Clamp(mode, DAT_0037f900, 1);
        unsigned short flag;
        if (mode == 0)
            flag = 0x200;
        else
            flag = 0x400;
        item->flags |= flag;
        int idx = Clamp(mode, DAT_0037f758, 1);
        DAT_003e39c0.rec[idx].a = a;
        DAT_003e39c0.rec[idx].b = b;
        DAT_003e39c0.rec[idx].c = c;
        DAT_003e39c0.rec[idx].d = d;
        if (item->sub != 0)
            item->sub->v08(mode, a, b, c, d);
    }
}
