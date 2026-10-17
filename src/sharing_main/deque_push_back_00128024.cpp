/* HSTMATCH module=hstp_trans_main.prx start=0x00128024 end=0x001281a0 symbol=FUN_00128024 lang=c++ */
/* Clone of src/eboot/deque_push_back_0011caa0.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block, same container as 0x11be88): push_back(const T&).
   FUN_00129fbc adds a block at the back; max_size() is the inline guarded static local. Names provisional. */
extern "C" {
struct Reent_00128024 { int pad[3]; void *err; };
Reent_00128024 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
extern char DAT_00381120[]; /* "deque::push_back length error" */
extern char DAT_003e47d1;       /* max_size() static-local guard */
extern unsigned DAT_002d170c;    /* max_size() static local */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Elem_00128024 {
    int a; int b; float c;
    Elem_00128024(const Elem_00128024 &o) : a(o.a), b(o.b), c(o.c) {}
};
typedef Elem_00128024 *Block_00128024;

struct Buf_00128024 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00128024 *data_;
    unsigned size() const { return size_; }
    Block_00128024 &operator[](unsigned i) { return data_[(start_ + i) % cap_]; }
};

struct Alloc_00128024 {
    void construct(Elem_00128024 *p, const Elem_00128024 &v) { new (p) Elem_00128024(v); }
};

struct Deque_00128024 {
    Buf_00128024 buf_;
    unsigned start_;
    unsigned size_;
    unsigned max_size() const
    {
        if (!DAT_003e47d1) {
            DAT_002d170c = 0xffffffd2;
            DAT_003e47d1 = 1;
        }
        return DAT_002d170c;
    }
    unsigned capacity() const
    {
        unsigned s = buf_.size();
        return s == 0 ? 0 : (s - 1) * 42;
    }
};
extern "C" void FUN_00129fbc(Deque_00128024 *self, unsigned n); /* grow at back */

extern "C" void FUN_00128024(Deque_00128024 *self, const Elem_00128024 &x)
{
    unsigned i = self->start_ + self->size_;
    if (i == self->capacity()) {
        if (self->size_ == self->max_size()) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00381120);
            FUN_0000d530();
        }
        FUN_00129fbc(self, 1);
        if (self->size_ == 0)
            self->start_ = 21;
        i = self->start_ + self->size_;
    }
    Alloc_00128024 a;
    a.construct(&self->buf_[i / 42][i % 42], x);
    ++self->size_;
}
