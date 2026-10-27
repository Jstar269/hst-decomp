/* HSTMATCH module=hstp_trans_main.prx start=0x0026a9f8 end=0x0026ab28 symbol=FUN_0026a9f8 lang=c++ data=0x003a63c8 */
/* Clone of src/eboot/deque_push_back_001909ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a63c8-0x003a63e6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block, block pointers held in a cdeque with a
   trailing spare slot): push_back. When the back block is full: length check against max_size() (inline
   function with a guarded static local: guard 0x3f3af0, value 0x2dad70), grow the block map by one
   (0x191194), centre an empty deque at 64. The end index is kept in a local and recomputed after growing
   (writing it once after the if loses retail's CSE on the fast path). Names provisional. */
extern "C" {
struct Reent_0026a9f8 { int pad[3]; void *err; };
Reent_0026a9f8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_003f3af0;        /* max_size() static-local guard */
extern unsigned DAT_002dad70;    /* max_size() static local */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef void *Elem_0026a9f8;
typedef Elem_0026a9f8 *Block_0026a9f8;
struct Buf_0026a9f8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0026a9f8 *data_;
    unsigned size() const { return size_; }
    Block_0026a9f8 &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};
struct Deque_0026a9f8 {
    Buf_0026a9f8 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_003f3af0) {
            DAT_002dad70 = 0xffffff00;
            DAT_003f3af0 = 1;
        }
        return DAT_002dad70;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 128;
    }
};
extern "C" void FUN_0026aff0(Deque_0026a9f8 *self, unsigned n); /* grow the block map at the back */
extern "C" void FUN_0026a9f8(Deque_0026a9f8 *self, const Elem_0026a9f8 &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, "deque::push_back length error");
            FUN_0000d530();
        }
        FUN_0026aff0(self, 1);
        if (self->size_ == 0)
            self->start_ = 64;
        i = self->start_ + self->size_;
    }
    Elem_0026a9f8 *p = self->buf_[i >> 7] + (i & 0x7f);
    new (p) Elem_0026a9f8(x);
    ++self->size_;
}
