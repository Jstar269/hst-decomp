/* HSTMATCH module=hstp_trans_main.prx start=0x001579f8 end=0x00157ad0 symbol=FUN_001579f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Child;

struct Entry {
    int key;
    Child *obj;
};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

struct Container {
    Entry *items;
    int count;
    It<Entry> begin() { return It<Entry>(items); }
    It<Entry> end() { return It<Entry>(items + count); }
};

extern "C" {
void FUN_00000a00(void *);
Child *FUN_001578cc(Child *, short);
void FUN_0015b11c(Container *, short);
}

extern "C" Container *FUN_001579f8(Container *p, short flag)
{
    if (p != 0) {
        It<Entry> it = p->begin();
        It<Entry> end = p->end();
        while (it != end) {
            Child *&obj = (*it).obj;
            if (obj != 0) {
                FUN_001578cc(obj, 1);
                obj = 0;
            }
            ++it;
            end = p->end();
        }
        if (p != 0 && p != 0) {
            FUN_0015b11c(p, 0);
        }
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
