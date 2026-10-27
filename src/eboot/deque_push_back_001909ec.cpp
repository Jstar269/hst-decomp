/* HSTMATCH module=EBOOT.BIN start=0x001909ec end=0x00190b1c symbol=FUN_001909ec lang=c++ data=0x002e136c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e136c-0x002e138a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block, block pointers held in a cdeque with a
   trailing spare slot): push_back. When the back block is full: length check against max_size() (inline
   function with a guarded static local: guard 0x3415d8, value 0x2c2780), grow the block map by one
   (0x191194), centre an empty deque at 64. The end index is kept in a local and recomputed after growing
   (writing it once after the if loses retail's CSE on the fast path). Names provisional. */
extern "C" {
struct Reent_001909ec { int pad[3]; void *err; };
Reent_001909ec *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_003415d8;        /* max_size() static-local guard */
extern unsigned DAT_002c2780;    /* max_size() static local */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef void *Elem_001909ec;
typedef Elem_001909ec *Block_001909ec;
struct Buf_001909ec {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_001909ec *data_;
    unsigned size() const { return size_; }
    Block_001909ec &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};
struct Deque_001909ec {
    Buf_001909ec buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_003415d8) {
            DAT_002c2780 = 0xffffff00;
            DAT_003415d8 = 1;
        }
        return DAT_002c2780;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 128;
    }
};
extern "C" void FUN_00191194(Deque_001909ec *self, unsigned n); /* grow the block map at the back */
extern "C" void FUN_001909ec(Deque_001909ec *self, const Elem_001909ec &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, "deque::push_back length error");
            FUN_0000d518();
        }
        FUN_00191194(self, 1);
        if (self->size_ == 0)
            self->start_ = 64;
        i = self->start_ + self->size_;
    }
    Elem_001909ec *p = self->buf_[i >> 7] + (i & 0x7f);
    new (p) Elem_001909ec(x);
    ++self->size_;
}
