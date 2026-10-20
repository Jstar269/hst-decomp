/* HSTMATCH module=EBOOT.BIN start=0x001ee0f8 end=0x001ee200 symbol=FUN_001ee0f8 lang=c++ */
// NEAR MISS (66/66 words, 12 differ, first at +0x84): the whole first loop over arr[10] is exact. Retail re-uses
// the SAME cursor (self+0x6c) for the second group and addresses it with +0x78/+0x7c/+0x80 displacements, i.e.
// one contiguous 20-record block; giving the second loop its own cursor makes MWCC move the base pointer instead
// (s2+=0x6c, s2+=0x78) -- 12 words. `r[10]` spellings fix the displacements but swap the s0/s1 colours (15 words).

struct VB { int pad; };
struct VC : VB { virtual ~VC(); };

struct Rec {
    void *a;
    void *b;
    VC *c;
};

struct X {
    Rec arr[10];
    Rec arr2[10];
};

extern "C" void FUN_0005d818(void *p, int flag);
extern "C" void FUN_00055e48(void *p, int flag);

extern "C" void FUN_001ee0f8(X *self)
{
    int i;

    for (i = 9; i >= 0; i--) {
        Rec *r = &self->arr[i];
        if (r->c) {
            delete r->c;
            r->c = 0;
        }
        if (r->b) {
            FUN_0005d818(r->b, 1);
            r->b = 0;
        }
        if (r->a) {
            FUN_00055e48(r->a, 1);
            r->a = 0;
        }
    }
    for (i = 9; i >= 0; i--) {
        Rec *r = &self->arr2[i];
        if (r->c) {
            delete r->c;
            r->c = 0;
        }
        if (r->b) {
            FUN_0005d818(r->b, 1);
            r->b = 0;
        }
        if (r->a) {
            FUN_00055e48(r->a, 1);
            r->a = 0;
        }
    }
}
// near miss from lane ds1 (unreviewed)
