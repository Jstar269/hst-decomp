/* HSTMATCH module=hstp_trans_main.prx start=0x001862f4 end=0x00186398 symbol=FUN_001862f4 lang=c++ */
/* Clone of src/eboot/vec_append_copies_00179c00.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>> append n copies of x at the end (caller 0x179ad8): placement-new copy construction
   (null-checked) through the inner range-init 0x179eb8, ++size per element. The `lb a3,44(sp)` tag comes
   from a named empty tag local inside the inline copy constructor (never-written frame-top slot).
   Names provisional. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Tag_001862f4 {};
struct IVec_001862f4;
extern "C" void FUN_001865ac(IVec_001862f4 *v, int *first, int *last, Tag_001862f4 t);
struct IVec_001862f4 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    IVec_001862f4(const IVec_001862f4 &x) : data_(0), size_(0), cap_(0) { Tag_001862f4 t; FUN_001865ac(this, x.begin(), x.end(), t); }
};
struct Vec_001862f4 {
    IVec_001862f4 *data_;
    unsigned size_;
    unsigned cap_;
};
extern "C" void FUN_001862f4(Vec_001862f4 *v, unsigned n, const IVec_001862f4 &x, Tag_001862f4)
{
    IVec_001862f4 *p = v->data_ + v->size_;
    for (; n != 0; --n, ++p) {
        new (p) IVec_001862f4(x);
        ++v->size_;
    }
}
