/* HSTMATCH module=EBOOT.BIN start=0x001026b8 end=0x0010276c symbol=FUN_001026b8 lang=c++ data=0x002d8b50 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
    extern int FUN_00014934(const char *, const char *);
    extern void FUN_001006b0(const void *, const char *);
}

struct Elem {
    char pad[0x10];
    const char *name;
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
    int pad0;
    Vec<void *> v0;
    Vec<Elem *> v1;
};

extern "C" Elem *FUN_001026b8(Container *self, const char *name)
{
    for (It<Elem *> it = self->v1.begin(); it != self->v1.end(); ++it) {
        Elem *e = *it;
        if (FUN_00014934(e->name, name) == 0) {
            return e;
        }
    }
    FUN_001006b0("ERROR: SpriteGroup::GetSprite(\"%s\") not found.\n", name);
    return 0;
}
