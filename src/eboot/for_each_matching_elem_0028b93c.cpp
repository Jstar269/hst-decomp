/* HSTMATCH module=EBOOT.BIN start=0x0028b93c end=0x0028ba54 symbol=FUN_0028b93c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Elem {
    int id;
    int unk4;
    int unk8;
    int unkc;
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
    int unk18;
    It<Elem> begin() const { return It<Elem>(data_); }
    It<Elem> end() { return It<Elem>(data_ + size_); }
};

extern "C" {
extern int DAT_0033b574;
extern int DAT_0034a114;
int FUN_001cd0e4(int, int);
void FUN_001c6aa0(int, int, int, int);
void FUN_0028a9b8(int, Elem *, int *);
void FUN_0028ba54(Vec *);
}

/* When enabled, visits every element whose id and unk4 match, hands matching ones with a non-zero lookup to the helpers, then calls the finish helper. */
extern "C" void FUN_0028b93c(Vec *v, int want_id, int want_unk4)
{
    if (DAT_0033b574 != 0) {
        for (It<Elem> it = v->begin(); it != v->end(); ++it) {
            Elem *e = &*it;
            if (e->id == want_id && e->unk4 == want_unk4) {
                int h = FUN_001cd0e4(DAT_0034a114, e->unkc);
                if (h != 0) {
                    FUN_001c6aa0(DAT_0034a114, e->unk8, e->unkc, h);
                    FUN_0028a9b8(h, e, &v->unk18);
                }
            }
        }
        FUN_0028ba54(v);
    }
}
