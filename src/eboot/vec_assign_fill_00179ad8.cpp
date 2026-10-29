/* HSTMATCH module=EBOOT.BIN start=0x00179ad8 end=0x00179c00 symbol=FUN_00179ad8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend FUN_0017a548, reallocate FUN_0017a62c, append n copies
   FUN_00179c00); otherwise copy-assign min(n, size) elements (inner assign FUN_00179fb0), then erase the tail
   (FUN_0017a4b4) or append n - size copies. The grow path is written as the fall-through after an if/else whose
   else-part returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_00179ad8(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_00179ad8 {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_00179ad8 {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_00179ad8;
struct Vec_00179ad8;
extern "C" {
void FUN_00179fb0(IVec_00179ad8 *v, int *first, int *last, Tag_00179ad8 t);
unsigned FUN_0017a548(Vec_00179ad8 *v, unsigned n);
void FUN_0017a62c(Vec_00179ad8 *v, unsigned n, unsigned cap);
void FUN_00179c00(Vec_00179ad8 *v, unsigned n, const IVec_00179ad8 &x, Tag_00179ad8 t);
void FUN_0017a4b4(Vec_00179ad8 *v, unsigned n, Tag_00179ad8 t);
}

struct IVec_00179ad8 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_00179ad8) { FUN_00179fb0(this, first, last, Tag_00179ad8()); }
    IVec_00179ad8 &operator=(const IVec_00179ad8 &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_00179ad8());
        return *this;
    }
};

struct Vec_00179ad8 {
    IVec_00179ad8 *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_00179ad8(IVec_00179ad8 *p, unsigned m, const IVec_00179ad8 &x, Tag2_00179ad8)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_00179ad8(Vec_00179ad8 *v, unsigned n, const IVec_00179ad8 &x)
{
    unsigned newCap;
    if (v->cap_ < n) {
        newCap = FUN_0017a548(v, n - v->cap_);
    } else {
        Fill_00179ad8(v->data_, Min_00179ad8(n, v->size_), x, Tag2_00179ad8());
        if (n < v->size_) {
            FUN_0017a4b4(v, v->size_ - n, Tag_00179ad8());
            return;
        }
        FUN_00179c00(v, n - v->size_, x, Tag_00179ad8());
        return;
    }
    FUN_0017a62c(v, n, newCap);
    FUN_00179c00(v, n, x, Tag_00179ad8());
}
