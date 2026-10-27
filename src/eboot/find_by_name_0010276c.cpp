/* HSTMATCH module=EBOOT.BIN start=0x0010276c end=0x00102824 symbol=FUN_0010276c lang=c++ data=0x002d8b80 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8b80-0x002d8bb5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

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

extern "C" int FUN_0010276c(Container *self, const char *name)
{
    int i = 0;
    for (It<Elem *> it = self->v1.begin(); it != self->v1.end(); ++it, ++i) {
        if (FUN_00014934((*it)->name, name) == 0) {
            return i;
        }
    }
    FUN_001006b0("ERROR: SpriteGroup::GetSpriteIndex(\"%s\") not found.\n", name);
    return -1;
}
