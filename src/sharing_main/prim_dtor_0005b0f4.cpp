/* HSTMATCH module=hstp_trans_main.prx start=0x0005b0f4 end=0x0005b224 symbol=FUN_0005b0f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* primitive.cpp (assert strings): deleting destructor; when the object owns its two buffers, return each to the global free pool (push_back, out-of-line grow 0x5bc3c with an empty tag), asserting that the pool has room. Shape notes: the room check reads the pool size/capacity through separate extern words (DAT_003da6a8/ac, as in vec_reset_elements_0005b024.cpp) so push_back re-reads them; the tag is passed straight to the out-of-line grow. Names provisional. */
extern const char DAT_00376c9c[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00376d10[];   /* "false" */
extern const char DAT_00376cd8[];   /* "primitive.cpp" */
extern char DAT_003b0308[];         /* vtable */
extern "C" void FUN_0005aff8(...);
extern "C" void FUN_00000a00(void *);
#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_0005aff8(DAT_00376c9c, text, DAT_00376cd8, line); for (;;) {} } } while (0)

struct Tag {};

struct Pool;
extern "C" void FUN_0005bc3c(Pool *, void *const *, Tag);
struct Pool {
    void **data;
    unsigned int size;
    unsigned int cap;
    void push_back(void *const &x)
    {
        if (size < cap) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_0005bc3c(this, &x, Tag());
        }
    }
};
extern Pool DAT_003da6a4;
extern "C" { extern unsigned int DAT_003da6a8; extern unsigned int DAT_003da6ac; }

struct Prim {
    void *vtbl;
    char pad04[0x50 - 0x04];
    int owns;           /* 0x50 */
    char pad54[0x64 - 0x54];
    void *buf[2];       /* 0x64 */
};

extern "C" Prim *FUN_0005b0f4(Prim *self, short flag)
{
    if (self != 0) {
        self->vtbl = DAT_003b0308;
        if (self->owns != 0) {
            unsigned int i = 0;
            do {
                if (self->buf[i] != 0) {
                    if (DAT_003da6ac <= DAT_003da6a8) HST_ASSERT(false, DAT_00376d10, 0x118);
                    DAT_003da6a4.push_back(self->buf[i]);
                    self->buf[i] = 0;
                }
            } while (++i < 2);
        }
        if (flag > 0) FUN_00000a00(self);
    }
    return self;
}
