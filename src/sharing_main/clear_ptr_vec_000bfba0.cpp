/* HSTMATCH module=hstp_trans_main.prx start=0x000bfba0 end=0x000bfc74 symbol=FUN_000bfba0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ iterator loop with !(a == b) and two-level vector destructor hierarchy calling __dt__10V_000c214cFv; exact match verified; names and types await human review. */
struct Elem {
    int x;
};

struct Iter {
    Elem **p;
    Iter(Elem **q) : p(q) {}
    Iter &operator++() { ++p; return *this; }
    Elem *&operator*() const { return *p; }
};

inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }

struct V_000c214c {
    Elem **data;
    unsigned size;
    ~V_000c214c();
    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + size); }
};

struct Vec1 : V_000c214c {
    ~Vec1() {}
};

struct Vec : Vec1 {
    ~Vec() {}
};

struct Self {
    char pad[0x44];
    Vec *vec;
};

extern "C" void FUN_000bfba0(Self *self)
{
    Vec *v = self->vec;
    if (v != 0) {
        for (Iter it = v->begin(); it != self->vec->end(); ++it) {
            if (*it != 0) {
                delete *it;
                *it = 0;
            }
        }
        if (self->vec != 0) {
            delete self->vec;
            self->vec = 0;
        }
    }
}
