/* HSTMATCH module=EBOOT.BIN start=0x0029398c end=0x00293a20 symbol=FUN_0029398c lang=c++ */
// NEAR MISS 40/37 words (35 differ): structure now matches retail exactly - `bool done = !(o != 0)` materialises
// as sltu/xori/andi (the only spelling that does), the range-guard `if (f15c < i) return ok;` returns through the
// masked tail, and the loop flag is `ok` (true, set false + break on the first violating element).
// Left: (a) retail returns `(bool)ok` through `andi v0,v0,0xff` while `bool ok` gives no mask, `int ok`/`char ok`
// give `sltu`, and `unsigned char` return type gives `andi v0,a1,0xff` with the flag in a1 (retail keeps it in v0);
// (b) the null test is `bnez v0,<jr ra>; nop` (unlikely form, separate return) vs our `beqzl` + tail-merge;
// (c) ours keeps i in a2/end in v1 where retail has i in a1/end in v0. Ruled out: `if (!o)`, `if (!(o != 0))`,
// inline bool helper (all fold to one bnezl), bool/int/char/unsigned-char `ok`, bool/unsigned-char/void return types,
// do-while vs while, break-to-tail vs return-false.


struct Obj {
    char pad[0x158];
    int f158;
    int f15c;
};

struct Self {
    char pad[0x78];
    Obj *f78;
};

extern "C" bool FUN_0029398c(Self *self)
{
    Obj *o = self->f78;
    bool done = !(o != 0);
    if (done) {
        return done;
    }
    int i = o->f158;
    bool ok;
    if (o->f15c < i) {
        ok = true;
    } else {
        char *r = (char *)o + i * 52;
        ok = true;
        while (i <= o->f15c) {
            void **pp = *(void ***)(r + 0xf4);
            float f2 = 0.0f;
            if (pp) f2 = *(float *)((char *)*pp + 8);
            float f0 = *(float *)(r + 0x104);
            if (!(f0 < f2)) {
                ok = false;
                break;
            }
            i++;
            r += 52;
        }
    }
    return ok;
}
// near miss from lane ds4 (unreviewed)
