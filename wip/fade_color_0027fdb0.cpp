/* HSTMATCH module=EBOOT.BIN start=0x0027fdb0 end=0x0027fed8 symbol=FUN_0027fdb0 lang=c++ */
struct Fader {
    int pad0;
    unsigned count;
    unsigned color;
};
extern unsigned char DAT_002caa58[];
extern unsigned DAT_002fe86c;
extern unsigned DAT_002fe870;
extern unsigned DAT_002fe874;

static inline unsigned Clamp(unsigned s, unsigned lim) { return lim < s ? lim : s; }
extern "C" void FUN_0027fdb0(Fader *self, unsigned *out, unsigned char step)
{
    unsigned c = self->color;
    int d = DAT_002caa58[self->count % 30] / 3;
    *out = c;
    unsigned r = Clamp(d + (c & 0xff), DAT_002fe86c);
    unsigned g = Clamp(d + ((c >> 8) & 0xff), DAT_002fe870);
    unsigned b = Clamp(d + ((c >> 16) & 0xff), DAT_002fe874);
    c = (c & 0xffffff00) | (unsigned char)r;
    *out = c;
    c = (c & 0xffff00ff) | ((unsigned char)g << 8);
    *out = c;
    c = (c & 0xff00ffff) | ((unsigned char)b << 16);
    *out = c;
    c = (c & 0x00ffffff) | (DAT_002caa58[self->count % 30] << 24);
    *out = c;
    self->count += step;
}
// lane sn6: 32 of 74 words differ, but the STRUCTURE is retail's: ~25 of them are register colours / head scheduling (retail: c=v1, magic 0x55555556 in t2, table byte a3, d in t2,
// then t0/t3/t2 for the three clamp results; ours: d in t3, magic t1). What matched and is worth keeping:
//  - the clamp is a by-value inline `Clamp(unsigned s, unsigned lim) { return lim < s ? lim : s; }` called as Clamp(d + channel, DAT_limit): that (and only that) gives retail's
//    `sltu at,lim,sum; beqzl at,L; move lim_reg,sum` (the `s <= lim ? s : lim` and `if (s <= x) x = s;` spellings give bnezl or `bnez; nop; move` and 3 extra words);
//  - const-ref Min() puts the sums on the stack (frame appears, 90 words);
//  - d = tab[count % 30] / 3 as a signed int, the table re-read after the stores (retail reloads count: *out is unsigned *, may alias), the four `c = (c & mask) | field; *out = c;` inserts
//    and the final `self->count += step` (void return) are word-for-word retail.
// Tried for the head (all 32 or worse): d before c, c before d, *out = c before/after d, d via local `unsigned char t`/`idx`/`d /= 3`, Third() inline, channel+d vs d+channel, Clamp(lim, s) order.
// near miss from lane sn6 (unreviewed)
