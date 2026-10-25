/* HSTMATCH module=EBOOT.BIN start=0x0012ca4c end=0x0012cb38 symbol=FUN_0012ca4c lang=c++ */
// NEAR (57/59 words, 34 differ): the inline reserve helper with an unused empty Tag2
// preserves the 48-byte frame without the extra fourth argument move. The residual is
// the symmetric loop source/destination register pair: retail uses a3/a2; this form a2/a0.
// Prior notes record no gain from five declaration permutations or inline_depth(8); revisit
// in the near-miss pass without repeating those variants.
#pragma opt_strength_reduction off

struct Vec4 { float x, y, z, w; };

struct Vec {
    Vec4 *data;
    unsigned int size;
    unsigned int cap;
};

struct Tag { char c; };
struct Tag2 {};

extern "C" void FUN_0012cb38(Vec *v, unsigned int n, Tag tag);
extern "C" void FUN_00000a00(void *p);
static inline void Reserve(Vec *v, unsigned int n, Tag2 tag)
{
    FUN_0012cb38(v, n, Tag());
}

extern "C" void FUN_0012ca4c(Vec *self, unsigned int n)
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
    Reserve(&tmp, n, Tag2());
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
// improved by lane lnm1 (unreviewed): 54 -> 34 differing words
