/* HSTMATCH module=EBOOT.BIN start=0x000bc72c end=0x000bc800 symbol=FUN_000bc72c lang=c++ */
/* Clone of src/sharing_main/clear_ptr_vec_000bfba0.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
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

struct V_000beaac {
    Elem **data;
    unsigned size;
    ~V_000beaac();
    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + size); }
};

struct Vec1 : V_000beaac {
    ~Vec1() {}
};

struct Vec : Vec1 {
    ~Vec() {}
};

struct Self {
    char pad[0x44];
    Vec *vec;
};

extern "C" void FUN_000bc72c(Self *self)
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
