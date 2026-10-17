/* HSTMATCH module=EBOOT.BIN start=0x0011ce50 end=0x0011cfcc symbol=FUN_0011ce50 lang=c++ */
/* Clone of src/eboot/deque_push_back_0011caa0.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block, same container as 0x11be88): push_back(const T&).
   FUN_0011ede8 adds a block at the back; max_size() is the inline guarded static local. Names provisional. */
extern "C" {
struct Reent_0011ce50 { int pad[3]; void *err; };
Reent_0011ce50 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
extern char DAT_002da140[]; /* "deque::push_back length error" */
extern char DAT_0033b491;       /* max_size() static-local guard */
extern unsigned DAT_002c132c;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_0011ce50 {
    int a; int b; float c;
    Elem_0011ce50(const Elem_0011ce50 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_0011ce50 *Block_0011ce50;

struct Buf_0011ce50 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0011ce50 *data_;
    unsigned size() const { return size_; }
    Block_0011ce50 &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};

struct Alloc_0011ce50 {
    void construct(Elem_0011ce50 *p, const Elem_0011ce50 &v) { new (p) Elem_0011ce50(v); }
};

struct Deque_0011ce50 {
    Buf_0011ce50 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_0033b491) {
            DAT_002c132c = 0xffffffd2;
            DAT_0033b491 = 1;
        }
        return DAT_002c132c;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" void FUN_0011ede8(Deque_0011ce50 *self, unsigned n); /* grow at back */

extern "C" void FUN_0011ce50(Deque_0011ce50 *self, const Elem_0011ce50 &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da140);
            FUN_0000d518();
        }
        FUN_0011ede8(self, 1);
        if (self->size_ == 0)
            self->start_ = 21;
        i = self->start_ + self->size_;
    }
    Alloc_0011ce50 a;
    a.construct(&self->buf_[i / 42][i % 42], x);
    ++self->size_;
}
