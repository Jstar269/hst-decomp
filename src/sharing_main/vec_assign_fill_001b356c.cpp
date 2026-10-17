/* HSTMATCH module=hstp_trans_main.prx start=0x001b356c end=0x001b3694 symbol=FUN_001b356c lang=c++ */
/* Clone of src/eboot/vec_assign_fill_00179ad8.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend 0x17a548, reallocate 0x17a62c, append n copies
   0x179c00); otherwise copy-assign min(n, size) elements (inner assign 0x179fb0), then erase the tail (0x17a4b4)
   or append n - size copies. The grow path is written as the fall-through after an if/else whose else-part
   returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_001b356c(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_001b356c {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_001b356c {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_001b356c;
struct Vec_001b356c;
extern "C" {
void FUN_001b41e0(IVec_001b356c *v, int *first, int *last, Tag_001b356c t);
unsigned FUN_001b47d4(Vec_001b356c *v, unsigned n);
void FUN_001b48b8(Vec_001b356c *v, unsigned n, unsigned cap);
void FUN_001b3694(Vec_001b356c *v, unsigned n, const IVec_001b356c &x, Tag_001b356c t);
void FUN_001b4740(Vec_001b356c *v, unsigned n, Tag_001b356c t);
}

struct IVec_001b356c {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_001b356c) { FUN_001b41e0(this, first, last, Tag_001b356c()); }
    IVec_001b356c &operator=(const IVec_001b356c &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_001b356c());
        return *this;
    }
};

struct Vec_001b356c {
    IVec_001b356c *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_001b356c(IVec_001b356c *p, unsigned m, const IVec_001b356c &x, Tag2_001b356c)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_001b356c(Vec_001b356c *v, unsigned n, const IVec_001b356c &x)
{
    unsigned c;
    if (v->cap_ < n) {
        c = FUN_001b47d4(v, n - v->cap_);
    } else {
        Fill_001b356c(v->data_, Min_001b356c(n, v->size_), x, Tag2_001b356c());
        if (n < v->size_) {
            FUN_001b4740(v, v->size_ - n, Tag_001b356c());
            return;
        }
        FUN_001b3694(v, n - v->size_, x, Tag_001b356c());
        return;
    }
    FUN_001b48b8(v, n, c);
    FUN_001b3694(v, n, x, Tag_001b356c());
}
