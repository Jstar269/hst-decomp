/* HSTMATCH module=hstp_trans_main.prx start=0x001b3694 end=0x001b3738 symbol=FUN_001b3694 lang=c++ */
/* Clone of src/eboot/vec_append_copies_00179c00.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>> append n copies of x at the end (caller 0x179ad8): placement-new copy construction
   (null-checked) through the inner range-init 0x179eb8, ++size per element. The `lb a3,44(sp)` tag comes
   from a named empty tag local inside the inline copy constructor (never-written frame-top slot).
   Names provisional. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Tag_001b3694 {};
struct IVec_001b3694;
extern "C" void FUN_000d8ff4(IVec_001b3694 *v, int *first, int *last, Tag_001b3694 t);
struct IVec_001b3694 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    IVec_001b3694(const IVec_001b3694 &x) : data_(0), size_(0), cap_(0) { Tag_001b3694 t; FUN_000d8ff4(this, x.begin(), x.end(), t); }
};
struct Vec_001b3694 {
    IVec_001b3694 *data_;
    unsigned size_;
    unsigned cap_;
};
extern "C" void FUN_001b3694(Vec_001b3694 *v, unsigned n, const IVec_001b3694 &x, Tag_001b3694)
{
    IVec_001b3694 *p = v->data_ + v->size_;
    for (; n != 0; --n, ++p) {
        new (p) IVec_001b3694(x);
        ++v->size_;
    }
}
