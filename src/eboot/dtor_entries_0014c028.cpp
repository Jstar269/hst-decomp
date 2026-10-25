/* HSTMATCH module=EBOOT.BIN start=0x0014c028 end=0x0014c100 symbol=FUN_0014c028 lang=c++ */
/* Clone of src/sharing_main/dtor_entries_001579f8.cpp (hstclone.py tag ag56e): addresses substituted; exact match verified; names and types await human review. */
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
Child *FUN_0014befc(Child *, short);
void FUN_0014f11c(Container *, short);
}

extern "C" Container *FUN_0014c028(Container *p, short flag)
{
    if (p != 0) {
        It<Entry> it = p->begin();
        It<Entry> end = p->end();
        while (it != end) {
            Child *&obj = (*it).obj;
            if (obj != 0) {
                FUN_0014befc(obj, 1);
                obj = 0;
            }
            ++it;
            end = p->end();
        }
        if (p != 0 && p != 0) {
            FUN_0014f11c(p, 0);
        }
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
