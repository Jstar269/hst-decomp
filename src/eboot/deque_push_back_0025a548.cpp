/* HSTMATCH module=EBOOT.BIN start=0x0025a548 end=0x0025a678 symbol=FUN_0025a548 lang=c++ */
/* Clone of src/eboot/deque_push_back_001909ec.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block, block pointers held in a cdeque with a
   trailing spare slot): push_back. When the back block is full: length check against max_size() (inline
   function with a guarded static local: guard 0x34a7c0, value 0x2ca7b0), grow the block map by one
   (0x191194), centre an empty deque at 64. The end index is kept in a local and recomputed after growing
   (writing it once after the if loses retail's CSE on the fast path). Names provisional. */
extern "C" {
struct Reent_0025a548 { int pad[3]; void *err; };
Reent_0025a548 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002fd820[];      /* push_back length error message */
extern char DAT_0034a7c0;        /* max_size() static-local guard */
extern unsigned DAT_002ca7b0;    /* max_size() static local */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef void *Elem_0025a548;
typedef Elem_0025a548 *Block_0025a548;
struct Buf_0025a548 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0025a548 *data_;
    unsigned size() const { return size_; }
    Block_0025a548 &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};
struct Deque_0025a548 {
    Buf_0025a548 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_0034a7c0) {
            DAT_002ca7b0 = 0xffffff00;
            DAT_0034a7c0 = 1;
        }
        return DAT_002ca7b0;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 128;
    }
};
extern "C" void FUN_0025ab40(Deque_0025a548 *self, unsigned n); /* grow the block map at the back */
extern "C" void FUN_0025a548(Deque_0025a548 *self, const Elem_0025a548 &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002fd820);
            FUN_0000d518();
        }
        FUN_0025ab40(self, 1);
        if (self->size_ == 0)
            self->start_ = 64;
        i = self->start_ + self->size_;
    }
    Elem_0025a548 *p = self->buf_[i >> 7] + (i & 0x7f);
    new (p) Elem_0025a548(x);
    ++self->size_;
}
