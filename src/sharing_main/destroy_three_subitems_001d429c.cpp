/* HSTMATCH module=hstp_trans_main.prx start=0x001d429c end=0x001d4320 symbol=FUN_001d429c lang=c++ */
/* Clone of src/eboot/destroy_three_subitems_001c5ed0.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001d429c.c (tag: a1, hand-written C++ reconstruction) */
struct Item {
    virtual void d0();
    virtual void d1();
    virtual void m();
};

template <class T>
struct It {
    T *p;
    It(T *x) : p(x) {}
    T &operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
};

template <class T>
inline bool operator==(const It<T> &a, const It<T> &b) {
    return a.p == b.p;
}

template <class T>
inline bool operator!=(const It<T> &a, const It<T> &b) {
    return !(a == b);
}

struct Vec {
    Item **data;
    int size;
    It<Item *> begin() const { return It<Item *>(data); }
    It<Item *> end() { return It<Item *>(data + size); }
};

struct Obj {
    char pad[0x40];
    Vec vec;
};

extern "C" void FUN_001d429c(Obj *self)
{
    for (It<Item *> it = self->vec.begin(); it != self->vec.end(); ++it) {
        (*it)->m();
    }
}
