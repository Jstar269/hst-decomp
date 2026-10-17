/* HSTMATCH module=hstp_trans_main.prx start=0x0010d488 end=0x0010d510 symbol=FUN_0010d488 lang=c++ */
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
extern "C" void FUN_0010d488(It first, It last)
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
