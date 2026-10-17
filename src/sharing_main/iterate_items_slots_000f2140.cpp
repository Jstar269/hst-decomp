/* HSTMATCH module=hstp_trans_main.prx start=0x000f2140 end=0x000f224c symbol=FUN_000f2140 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Item loop over 0x60-byte records with a pointer-wrapper iterator (free operator!= as !(a == b), begin() const, end() non-const), as in the other iterator loops. */
extern "C" {
    extern void FUN_00051e30(void *, int, int, int, int, int, int);
    extern void FUN_0005b540(void *, void *, void *, void *);
    extern void FUN_000522c0(void *);
    extern void *DAT_003da704;
}

struct Elem {
    char pad[0x40];
    void *f40;
    int state;
    char pad2[0x60 - 0x48];
};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    T *operator->() const { return p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

template <class T> struct Vec {
    T *data_;
    unsigned size_;
    It<T> begin() const { return It<T>(data_); }
    It<T> end() { return It<T>(data_ + size_); }
};

struct Self {
    char pad[0x40];
    void *slots[6];
    Vec<Elem> items;
};

extern "C" void FUN_000f2140(Self *self)
{
    for (It<Elem> it = self->items.begin(); it != self->items.end(); ++it) {
        if (it->state != 6) {
            void *src = it->f40;
            void *target = self->slots[it->state];
            void *g = DAT_003da704;
            if (src != 0 && target != 0) {
                FUN_00051e30(target, 0, 0, 0x1e0, 0x110, 0, 0);
                FUN_0005b540(src, target, g, &*it);
                FUN_000522c0(target);
            }
        }
    }
}
