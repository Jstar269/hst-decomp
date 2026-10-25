/* HSTMATCH module=hstp_trans_main.prx start=0x00061e34 end=0x00061f00 symbol=FUN_00061e34 lang=c++ */
/* WIP near miss: 35/51 words, 47 differ (frame size 48 vs retail 80).
   Retail copies 4-float vectors at param_1 + 0x40 and param_1 + 0x60 into stack
   temporaries at sp+64 and sp+48 before calling FUN_00022440(&ret, &arg, param_2),
   then copies the 4-float results from sp+32 and sp+16 back into param_1.
   Under MWCC -O4,p, the compiler copy-propagates the contiguous struct fields
   directly into a1 (addiu a1, s1, 0x40 / 0x60) eliminating the two stack copies.
   Tried: by-value struct parameters, volatile qualifiers, inline helper with by-value
   arguments, aggregate initializers, and field-by-field getters.
*/

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad0[64];
    Vec4 v64;
    char pad1[16];
    Vec4 v96;
};

extern "C" Vec4 *FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);

static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022440(&r, &a, &b);
    return r;
}

extern "C" void FUN_00061e34(Obj *self, const Vec4 *b)
{
    self->v64 = Add(self->v64, *b);
    self->v96 = Add(self->v96, *b);
}
// near miss from lane ag6 (unreviewed)
