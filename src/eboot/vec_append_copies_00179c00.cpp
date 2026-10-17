/* HSTMATCH module=EBOOT.BIN start=0x00179c00 end=0x00179ca4 symbol=FUN_00179c00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>> append n copies of x at the end (caller 0x179ad8): placement-new copy construction
   (null-checked) through the inner range-init 0x179eb8, ++size per element. The `lb a3,44(sp)` tag comes
   from a named empty tag local inside the inline copy constructor (never-written frame-top slot).
   Names provisional. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Tag_00179c00 {};
struct IVec_00179c00;
extern "C" void FUN_00179eb8(IVec_00179c00 *v, int *first, int *last, Tag_00179c00 t);
struct IVec_00179c00 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    IVec_00179c00(const IVec_00179c00 &x) : data_(0), size_(0), cap_(0) { Tag_00179c00 t; FUN_00179eb8(this, x.begin(), x.end(), t); }
};
struct Vec_00179c00 {
    IVec_00179c00 *data_;
    unsigned size_;
    unsigned cap_;
};
extern "C" void FUN_00179c00(Vec_00179c00 *v, unsigned n, const IVec_00179c00 &x, Tag_00179c00)
{
    IVec_00179c00 *p = v->data_ + v->size_;
    for (; n != 0; --n, ++p) {
        new (p) IVec_00179c00(x);
        ++v->size_;
    }
}
