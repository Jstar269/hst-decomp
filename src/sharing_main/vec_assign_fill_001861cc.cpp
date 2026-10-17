/* HSTMATCH module=hstp_trans_main.prx start=0x001861cc end=0x001862f4 symbol=FUN_001861cc lang=c++ */
/* Clone of src/eboot/vec_assign_fill_00179ad8.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend 0x17a548, reallocate 0x17a62c, append n copies
   0x179c00); otherwise copy-assign min(n, size) elements (inner assign 0x179fb0), then erase the tail (0x17a4b4)
   or append n - size copies. The grow path is written as the fall-through after an if/else whose else-part
   returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_001861cc(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_001861cc {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_001861cc {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_001861cc;
struct Vec_001861cc;
extern "C" {
void FUN_001866a4(IVec_001861cc *v, int *first, int *last, Tag_001861cc t);
unsigned FUN_00186c3c(Vec_001861cc *v, unsigned n);
void FUN_00186d20(Vec_001861cc *v, unsigned n, unsigned cap);
void FUN_001862f4(Vec_001861cc *v, unsigned n, const IVec_001861cc &x, Tag_001861cc t);
void FUN_00186ba8(Vec_001861cc *v, unsigned n, Tag_001861cc t);
}

struct IVec_001861cc {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_001861cc) { FUN_001866a4(this, first, last, Tag_001861cc()); }
    IVec_001861cc &operator=(const IVec_001861cc &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_001861cc());
        return *this;
    }
};

struct Vec_001861cc {
    IVec_001861cc *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_001861cc(IVec_001861cc *p, unsigned m, const IVec_001861cc &x, Tag2_001861cc)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_001861cc(Vec_001861cc *v, unsigned n, const IVec_001861cc &x)
{
    unsigned c;
    if (v->cap_ < n) {
        c = FUN_00186c3c(v, n - v->cap_);
    } else {
        Fill_001861cc(v->data_, Min_001861cc(n, v->size_), x, Tag2_001861cc());
        if (n < v->size_) {
            FUN_00186ba8(v, v->size_ - n, Tag_001861cc());
            return;
        }
        FUN_001862f4(v, n - v->size_, x, Tag_001861cc());
        return;
    }
    FUN_00186d20(v, n, c);
    FUN_001862f4(v, n, x, Tag_001861cc());
}
