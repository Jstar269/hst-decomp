/* HSTMATCH module=EBOOT.BIN start=0x0011caa0 end=0x0011cc1c symbol=FUN_0011caa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block, same container as 0x11be88): push_back(const T&).
   FUN_0011e790 adds a block at the back; max_size() is the inline guarded static local. Names provisional. */
extern "C" {
struct Reent_0011caa0 { int pad[3]; void *err; };
Reent_0011caa0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002da140[]; /* "deque::push_back length error" */
extern char DAT_0033b490;       /* max_size() static-local guard */
extern unsigned DAT_002c1328;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_0011caa0 {
    int a; int b; float c;
    Elem_0011caa0(const Elem_0011caa0 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_0011caa0 *Block_0011caa0;

struct Buf_0011caa0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011caa0 *data_;
    unsigned size() const { return size_; }
    Block_0011caa0 &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};

struct Alloc_0011caa0 {
    void construct(Elem_0011caa0 *p, const Elem_0011caa0 &v) { new (p) Elem_0011caa0(v); }
};

struct Deque_0011caa0 {
    Buf_0011caa0 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_0033b490) {
            DAT_002c1328 = 0xffffffd2;
            DAT_0033b490 = 1;
        }
        return DAT_002c1328;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" void FUN_0011e790(Deque_0011caa0 *self, unsigned n); /* grow at back */

extern "C" void FUN_0011caa0(Deque_0011caa0 *self, const Elem_0011caa0 &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da140);
            FUN_0000d518();
        }
        FUN_0011e790(self, 1);
        if (self->size_ == 0)
            self->start_ = 21;
        i = self->start_ + self->size_;
    }
    Alloc_0011caa0 a;
    a.construct(&self->buf_[i / 42][i % 42], x);
    ++self->size_;
}
