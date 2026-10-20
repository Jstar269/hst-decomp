/* HSTMATCH module=EBOOT.BIN start=0x00115f68 end=0x0011605c symbol=FUN_00115f68 lang=c++ */
// NEAR MISS (58/59 words, 54 differ): passing an empty allocator class BY VALUE as the 4th argument of the
// out-of-line reserve call reproduces retail's 48-byte frame and the 16-byte slot below the named local, but MWCC
// adds one `move a3,a2` for the empty arg. Ruled out: Alloc() vs a named local (invisible reference), 3-arg call (32-byte frame).
#pragma opt_strength_reduction off

struct Vec4 { float x, y, z, w; };

struct Vec {
    Vec4 *data;
    unsigned int size;
    unsigned int cap;
};

struct Tag { char c; };
struct Alloc {};

extern "C" void FUN_0012cb38(Vec *v, unsigned int n, Tag tag, Alloc a);
extern "C" void FUN_00000a00(void *p);

extern "C" void FUN_00115f68(Vec *self, unsigned int n)
{
    Vec tmp;
    Vec4 *src;
    Vec4 *end;
    Vec4 *dst;
    unsigned int c;
    Vec4 *d;

    tmp.data = 0;
    tmp.size = 0;
    tmp.cap = 0;
    FUN_0012cb38(&tmp, n, Tag(), Alloc());
    src = self->data;
    end = src + self->size;
    dst = tmp.data + tmp.size;
    for (; src < end; src++) {
        if (dst)
            *dst = *src;
        tmp.size++;
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
