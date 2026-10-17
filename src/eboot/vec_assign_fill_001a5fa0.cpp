/* HSTMATCH module=EBOOT.BIN start=0x001a5fa0 end=0x001a60c8 symbol=FUN_001a5fa0 lang=c++ */
/* Clone of src/eboot/vec_assign_fill_00179ad8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend 0x17a548, reallocate 0x17a62c, append n copies
   0x179c00); otherwise copy-assign min(n, size) elements (inner assign 0x179fb0), then erase the tail (0x17a4b4)
   or append n - size copies. The grow path is written as the fall-through after an if/else whose else-part
   returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_001a5fa0(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_001a5fa0 {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_001a5fa0 {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_001a5fa0;
struct Vec_001a5fa0;
extern "C" {
void FUN_001a6c14(IVec_001a5fa0 *v, int *first, int *last, Tag_001a5fa0 t);
unsigned FUN_001a7208(Vec_001a5fa0 *v, unsigned n);
void FUN_001a72ec(Vec_001a5fa0 *v, unsigned n, unsigned cap);
void FUN_001a60c8(Vec_001a5fa0 *v, unsigned n, const IVec_001a5fa0 &x, Tag_001a5fa0 t);
void FUN_001a7174(Vec_001a5fa0 *v, unsigned n, Tag_001a5fa0 t);
}

struct IVec_001a5fa0 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_001a5fa0) { FUN_001a6c14(this, first, last, Tag_001a5fa0()); }
    IVec_001a5fa0 &operator=(const IVec_001a5fa0 &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_001a5fa0());
        return *this;
    }
};

struct Vec_001a5fa0 {
    IVec_001a5fa0 *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_001a5fa0(IVec_001a5fa0 *p, unsigned m, const IVec_001a5fa0 &x, Tag2_001a5fa0)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_001a5fa0(Vec_001a5fa0 *v, unsigned n, const IVec_001a5fa0 &x)
{
    unsigned c;
    if (v->cap_ < n) {
        c = FUN_001a7208(v, n - v->cap_);
    } else {
        Fill_001a5fa0(v->data_, Min_001a5fa0(n, v->size_), x, Tag2_001a5fa0());
        if (n < v->size_) {
            FUN_001a7174(v, v->size_ - n, Tag_001a5fa0());
            return;
        }
        FUN_001a60c8(v, n - v->size_, x, Tag_001a5fa0());
        return;
    }
    FUN_001a72ec(v, n, c);
    FUN_001a60c8(v, n, x, Tag_001a5fa0());
}
