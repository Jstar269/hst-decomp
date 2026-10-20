/* HSTMATCH module=EBOOT.BIN start=0x00237330 end=0x00237444 symbol=FUN_00237330 lang=c++ */
// NEAR MISS (67/69 words, 36 differ, first at +0x60 = first 24 words exact): the inline-forwarding-helper variant of
// the empty-allocator recipe. 7-int element copied with lwc1/swc1 batches here (retail uses 7 lw/sw pairs and then the
// prologue colours change: first diff moves to +0x2c), so the element copy form and the loop colouring interact.
#pragma opt_strength_reduction off

struct Elem { int f[7]; };

struct Vec {
    Elem *data;
    unsigned int size;
    unsigned int cap;
};

struct Tag { char c; };
struct Alloc {};

extern "C" void FUN_00238608(Vec *v, unsigned int n, Tag tag);
extern "C" void FUN_00000a00(void *p);
static inline void Wrap(Vec *v, unsigned int n, Alloc a) { FUN_00238608(v, n, Tag()); }

extern "C" void FUN_00237330(Vec *self, unsigned int n)
{
    Vec tmp;
    Elem *src;
    Elem *end;
    Elem *dst;
    unsigned int c;
    Elem *d;

    tmp.data = 0;
    tmp.size = 0;
    tmp.cap = 0;
    Wrap(&tmp, n, Alloc());
    src = self->data;
    end = src + self->size;
    dst = tmp.data + tmp.size;
    while (src < end) {
        if (dst)
            *dst = *src;
        tmp.size++;
        src++;
        dst++;
    }
    c = self->cap;
    self->cap = tmp.cap;
    tmp.cap = c;
    d = self->data;
    self->data = tmp.data;
    tmp.data = d;
    self->size = tmp.size;
    tmp.size = 0;
    if (tmp.data)
        FUN_00000a00(tmp.data);
}
// near miss from lane ds1 (unreviewed)
