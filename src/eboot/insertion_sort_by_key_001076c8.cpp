/* HSTMATCH module=EBOOT.BIN start=0x001076c8 end=0x00107750 symbol=FUN_001076c8 lang=c++ */
/* Clone of src/sharing_main/insertion_sort_by_key_0010d488.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Insertion sort of a range of object pointers by the float at +0x20, larger keys first (the std-style loop
   `for (k = i; first < j && comp(val, *--k); --j) *j = *k;` with a stateless comparator functor and a one-pointer
   iterator class whose operator!= is written as !(a == b)). The comparator functor is what keeps the shift load
   from being CSE'd with the comparison's load. Names provisional. */
struct Obj {
    char pad[0x20];
    float key;
};
struct It {
    Obj **p;
    It() {}
    It(Obj **q) : p(q) {}
    Obj *&operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
    It &operator--() { --p; return *this; }
    It operator+(int n) const { return It(p + n); }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }
inline bool operator<(const It &a, const It &b) { return a.p < b.p; }
struct Greater {
    bool operator()(Obj *a, Obj *b) const { return a->key > b->key; }
};
extern "C" void FUN_001076c8(It first, It last)
{
    if (first != last) {
        for (It i = first + 1; i < last; ++i) {
            Obj *val = *i;
            It k = i;
            It j = i;
            for (; first < j && Greater()(val, *--k); --j)
                *j = *k;
            *j = val;
        }
    }
}
