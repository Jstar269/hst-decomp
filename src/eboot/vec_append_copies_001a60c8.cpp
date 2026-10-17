/* HSTMATCH module=EBOOT.BIN start=0x001a60c8 end=0x001a616c symbol=FUN_001a60c8 lang=c++ */
/* Clone of src/eboot/vec_append_copies_00179c00.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<vector<int>> append n copies of x at the end (caller 0x179ad8): placement-new copy construction
   (null-checked) through the inner range-init 0x179eb8, ++size per element. The `lb a3,44(sp)` tag comes
   from a named empty tag local inside the inline copy constructor (never-written frame-top slot).
   Names provisional. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Tag_001a60c8 {};
struct IVec_001a60c8;
extern "C" void FUN_000d5304(IVec_001a60c8 *v, int *first, int *last, Tag_001a60c8 t);
struct IVec_001a60c8 {
    int *data_;
    unsigned size_;
    unsigned cap_;
    int *begin() const { return data_; }
    int *end() const { return data_ + size_; }
    IVec_001a60c8(const IVec_001a60c8 &x) : data_(0), size_(0), cap_(0) { Tag_001a60c8 t; FUN_000d5304(this, x.begin(), x.end(), t); }
};
struct Vec_001a60c8 {
    IVec_001a60c8 *data_;
    unsigned size_;
    unsigned cap_;
};
extern "C" void FUN_001a60c8(Vec_001a60c8 *v, unsigned n, const IVec_001a60c8 &x, Tag_001a60c8)
{
    IVec_001a60c8 *p = v->data_ + v->size_;
    for (; n != 0; --n, ++p) {
        new (p) IVec_001a60c8(x);
        ++v->size_;
    }
}
