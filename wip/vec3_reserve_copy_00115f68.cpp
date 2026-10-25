/* HSTMATCH module=EBOOT.BIN start=0x00115f68 end=0x0011605c symbol=FUN_00115f68 lang=c++ */
// NEAR (59/61 words, 14 differ): a Vec3 array member, inline reserve wrapper, and
// src/size/dst increments in the for-update make the 12-byte element-copy loop exact.
// Remaining differences start after the loop in the cap/data/size swap and cleanup.
// The 4-argument Alloc form adds a3,a2; this 3-argument helper with an unused
// empty Tag2 preserves the 48-byte frame without it.
#pragma opt_strength_reduction off

struct Vec3 { float axis[3]; };

struct Vec {
    Vec3 *data;
    unsigned int size;
    unsigned int cap;
};

struct Tag { char c; };
struct Tag2 {};

extern "C" void FUN_0011676c(Vec *v, unsigned int n, Tag tag);
extern "C" void FUN_00000a00(void *p);
static inline void Reserve(Vec *v, unsigned int n, Tag2 tag)
{
    FUN_0011676c(v, n, Tag());
}

extern "C" void FUN_00115f68(Vec *self, unsigned int n)
{
    Vec tmp;
    Vec3 *src;
    Vec3 *end;
    Vec3 *dst;
    unsigned int c;
    Vec3 *d;

    tmp.data = 0;
    tmp.size = 0;
    tmp.cap = 0;
    Reserve(&tmp, n, Tag2());
    src = self->data;
    end = src + self->size;
    dst = tmp.data + tmp.size;
    for (; src < end; src++, tmp.size++, dst++) {
        if (dst) {
            *dst = *src;
        }
    }
    c = self->cap;
    self->cap = tmp.cap;
    tmp.cap = c;
    d = self->data;
    self->data = tmp.data;
    tmp.data = d;
    c = self->size;
    self->size = tmp.size;
    tmp.size = c - c;
    if (tmp.data)
        FUN_00000a00(tmp.data);
}
// Best current result; hstmatch reverified after the helper, element type, and
// loop-update changes. The remaining tail mismatch is not yet solved.
// improved by lane lnm1 (unreviewed): 55 -> 14 differing words
