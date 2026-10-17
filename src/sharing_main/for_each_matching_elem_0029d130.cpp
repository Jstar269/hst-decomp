/* HSTMATCH module=hstp_trans_main.prx start=0x0029d130 end=0x0029d248 symbol=FUN_0029d130 lang=c++ */
/* Clone of src/eboot/for_each_matching_elem_0028b93c.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Elem {
    int id;
    int f4;
    int f8;
    int fc;
    char pad10[0x50];
};

template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

struct Vec {
    Elem *data_;
    unsigned size_;
    char pad8[0x10];
    int f18;
    It<Elem> begin() const { return It<Elem>(data_); }
    It<Elem> end() { return It<Elem>(data_ + size_); }
};

extern "C" {
extern int DAT_003e48b4;
extern int DAT_003f344c;
int FUN_001db84c(int, int);
void FUN_001d4e98(int, int, int, int);
void FUN_0029c1ac(int, Elem *, int *);
void FUN_0029d248(Vec *);
}

extern "C" void FUN_0029d130(Vec *v, int a, int b)
{
    if (DAT_003e48b4 != 0) {
        for (It<Elem> it = v->begin(); it != v->end(); ++it) {
            Elem *e = &*it;
            if (e->id == a && e->f4 == b) {
                int h = FUN_001db84c(DAT_003f344c, e->fc);
                if (h != 0) {
                    FUN_001d4e98(DAT_003f344c, e->f8, e->fc, h);
                    FUN_0029c1ac(h, e, &v->f18);
                }
            }
        }
        FUN_0029d248(v);
    }
}
