/* HSTMATCH module=EBOOT.BIN start=0x001a680c end=0x001a6934 symbol=FUN_001a680c lang=c++ */
/* Clone of src/eboot/vec_assign_fill_00179ad8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>>::assign(n, x)-style: grow path (recommend 0x17a548, reallocate 0x17a62c, append n copies
   0x179c00); otherwise copy-assign min(n, size) elements (inner assign 0x179fb0), then erase the tail (0x17a4b4)
   or append n - size copies. The grow path is written as the fall-through after an if/else whose else-part
   returns, which reproduces retail's block order. Names provisional. */
template <class T> inline const T &Min_001a680c(const T &a, const T &b) { return b < a ? b : a; }
struct Tag_001a680c {};  /* empty tag passed by value to the out-of-line helpers (callee sees seb of 0) */
struct Tag2_001a680c {}; /* empty dispatch tag consumed by an inline function (one 4-byte frame slot each) */

struct IVec_001a680c;
struct Vec_001a680c;
extern "C" {
void FUN_001a6dfc(IVec_001a680c *v, int *first, int *last, Tag_001a680c t);
unsigned FUN_001a8158(Vec_001a680c *v, unsigned n);
void FUN_001a823c(Vec_001a680c *v, unsigned n, unsigned cap);
void FUN_001a6934(Vec_001a680c *v, unsigned n, const IVec_001a680c &x, Tag_001a680c t);
void FUN_001a7db0(Vec_001a680c *v, unsigned n, Tag_001a680c t);
}

struct IVec_001a680c {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    void assign(int *first, int *last, Tag2_001a680c) { FUN_001a6dfc(this, first, last, Tag_001a680c()); }
    IVec_001a680c &operator=(const IVec_001a680c &x)
    {
        if (this != &x)
            assign(x.begin(), x.end(), Tag2_001a680c());
        return *this;
    }
};

struct Vec_001a680c {
    IVec_001a680c *data_;
    unsigned size_;
    unsigned cap_;
};

inline void Fill_001a680c(IVec_001a680c *p, unsigned m, const IVec_001a680c &x, Tag2_001a680c)
{
    for (; m != 0; --m, ++p)
        *p = x;
}

extern "C" void FUN_001a680c(Vec_001a680c *v, unsigned n, const IVec_001a680c &x)
{
    unsigned c;
    if (v->cap_ < n) {
        c = FUN_001a8158(v, n - v->cap_);
    } else {
        Fill_001a680c(v->data_, Min_001a680c(n, v->size_), x, Tag2_001a680c());
        if (n < v->size_) {
            FUN_001a7db0(v, v->size_ - n, Tag_001a680c());
            return;
        }
        FUN_001a6934(v, n - v->size_, x, Tag_001a680c());
        return;
    }
    FUN_001a823c(v, n, c);
    FUN_001a6934(v, n, x, Tag_001a680c());
}
