/* HSTMATCH module=hstp_trans_main.prx start=0x001081d8 end=0x00108290 symbol=FUN_001081d8 lang=c++ data=0x0037f94c */
/* Clone of src/eboot/find_by_name_0010276c.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037f94c-0x0037f981) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
    extern int FUN_00014934(const char *, const char *);
    extern void FUN_0010532c(const void *, const char *);
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

extern "C" int FUN_001081d8(Container *self, const char *name)
{
    int i = 0;
    for (It<Elem *> it = self->v1.begin(); it != self->v1.end(); ++it, ++i) {
        if (FUN_00014934((*it)->name, name) == 0) {
            return i;
        }
    }
    FUN_0010532c("ERROR: SpriteGroup::GetSpriteIndex(\"%s\") not found.\n", name);
    return -1;
}
