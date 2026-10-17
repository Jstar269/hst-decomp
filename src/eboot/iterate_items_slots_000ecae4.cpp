/* HSTMATCH module=EBOOT.BIN start=0x000ecae4 end=0x000ecbf0 symbol=FUN_000ecae4 lang=c++ */
/* Clone of src/sharing_main/iterate_items_slots_000f2140.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Item loop over 0x60-byte records with a pointer-wrapper iterator (free operator!= as !(a == b), begin() const, end() non-const), as in the other iterator loops. */
extern "C" {
    extern void FUN_00051490(void *, int, int, int, int, int, int);
    extern void FUN_0005a770(void *, void *, void *, void *);
    extern void FUN_0005185c(void *);
    extern void *DAT_003313c4;
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

extern "C" void FUN_000ecae4(Self *self)
{
    for (It<Elem> it = self->items.begin(); it != self->items.end(); ++it) {
        if (it->state != 6) {
            void *src = it->f40;
            void *target = self->slots[it->state];
            void *g = DAT_003313c4;
            if (src != 0 && target != 0) {
                FUN_00051490(target, 0, 0, 0x1e0, 0x110, 0, 0);
                FUN_0005a770(src, target, g, &*it);
                FUN_0005185c(target);
            }
        }
    }
}
