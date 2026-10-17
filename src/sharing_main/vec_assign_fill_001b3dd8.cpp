/* HSTMATCH module=hstp_trans_main.prx start=0x001b3dd8 end=0x001b3f00 symbol=FUN_001b3dd8 lang=c++ */
/* Clone of src/eboot/vec_assign_fill_00179ad8.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend 0x17a548, reallocate 0x17a62c, append n copies
   0x179c00); otherwise copy-assign min(n, size) elements (inner assign 0x179fb0), then erase the tail (0x17a4b4)
   or append n - size copies. The grow path is written as the fall-through after an if/else whose else-part
   returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_001b3dd8(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_001b3dd8 {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_001b3dd8 {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_001b3dd8;
struct Vec_001b3dd8;
extern "C" {
void FUN_001b43c8(IVec_001b3dd8 *v, int *first, int *last, Tag_001b3dd8 t);
unsigned FUN_001b5724(Vec_001b3dd8 *v, unsigned n);
void FUN_001b5808(Vec_001b3dd8 *v, unsigned n, unsigned cap);
void FUN_001b3f00(Vec_001b3dd8 *v, unsigned n, const IVec_001b3dd8 &x, Tag_001b3dd8 t);
void FUN_001b537c(Vec_001b3dd8 *v, unsigned n, Tag_001b3dd8 t);
}

struct IVec_001b3dd8 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_001b3dd8) { FUN_001b43c8(this, first, last, Tag_001b3dd8()); }
    IVec_001b3dd8 &operator=(const IVec_001b3dd8 &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_001b3dd8());
        return *this;
    }
};

struct Vec_001b3dd8 {
    IVec_001b3dd8 *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_001b3dd8(IVec_001b3dd8 *p, unsigned m, const IVec_001b3dd8 &x, Tag2_001b3dd8)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_001b3dd8(Vec_001b3dd8 *v, unsigned n, const IVec_001b3dd8 &x)
{
    unsigned c;
    if (v->cap_ < n) {
        c = FUN_001b5724(v, n - v->cap_);
    } else {
        Fill_001b3dd8(v->data_, Min_001b3dd8(n, v->size_), x, Tag2_001b3dd8());
        if (n < v->size_) {
            FUN_001b537c(v, v->size_ - n, Tag_001b3dd8());
            return;
        }
        FUN_001b3f00(v, n - v->size_, x, Tag_001b3dd8());
        return;
    }
    FUN_001b5808(v, n, c);
    FUN_001b3f00(v, n, x, Tag_001b3dd8());
}
