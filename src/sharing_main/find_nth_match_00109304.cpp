/* HSTMATCH module=hstp_trans_main.prx start=0x00109304 end=0x001093cc symbol=FUN_00109304 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

struct Item {
    char pad[0xc0];
    const char *key;
};

struct Finder {
    char pad[4];
    Vec<Item *> items;
};

extern "C" int FUN_00014934(const char *a, const char *b);

extern "C" Item *FUN_00109304(Finder *self, const char *key, int n)
{
    for (It<Item *> it = self->items.begin(); it != self->items.end(); ++it) {
        Item *item = *it;
        if (item->key != 0) {
            if (FUN_00014934(key, item->key) == 0 && n-- <= 0) return item;
        }
    }
    return 0;
}
