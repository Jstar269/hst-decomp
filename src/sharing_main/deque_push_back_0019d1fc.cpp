/* HSTMATCH module=hstp_trans_main.prx start=0x0019d1fc end=0x0019d32c symbol=FUN_0019d1fc lang=c++ data=0x00388a48 */
/* Clone of src/eboot/deque_push_back_001909ec.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388a48-0x00388a66) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block, block pointers held in a cdeque with a
   trailing spare slot): push_back. When the back block is full: length check against max_size() (inline
   function with a guarded static local: guard 0x3ea918, value 0x2d2c80), grow the block map by one
   (0x191194), centre an empty deque at 64. The end index is kept in a local and recomputed after growing
   (writing it once after the if loses retail's CSE on the fast path). Names provisional. */
extern "C" {
struct Reent_0019d1fc { int pad[3]; void *err; };
Reent_0019d1fc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_003ea918;        /* max_size() static-local guard */
extern unsigned DAT_002d2c80;    /* max_size() static local */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef void *Elem_0019d1fc;
typedef Elem_0019d1fc *Block_0019d1fc;
struct Buf_0019d1fc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0019d1fc *data_;
    unsigned size() const { return size_; }
    Block_0019d1fc &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};
struct Deque_0019d1fc {
    Buf_0019d1fc buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_003ea918) {
            DAT_002d2c80 = 0xffffff00;
            DAT_003ea918 = 1;
        }
        return DAT_002d2c80;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 128;
    }
};
extern "C" void FUN_0019d9a4(Deque_0019d1fc *self, unsigned n); /* grow the block map at the back */
extern "C" void FUN_0019d1fc(Deque_0019d1fc *self, const Elem_0019d1fc &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, "deque::push_back length error");
            FUN_0000d530();
        }
        FUN_0019d9a4(self, 1);
        if (self->size_ == 0)
            self->start_ = 64;
        i = self->start_ + self->size_;
    }
    Elem_0019d1fc *p = self->buf_[i >> 7] + (i & 0x7f);
    new (p) Elem_0019d1fc(x);
    ++self->size_;
}
