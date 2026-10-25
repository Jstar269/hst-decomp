/* HSTMATCH module=EBOOT.BIN start=0x0027fcbc end=0x0027fdb0 symbol=FUN_0027fcbc lang=c99 */
extern unsigned char DAT_002caa58[];
extern unsigned int DAT_002fe860;
extern unsigned int DAT_002fe864;
extern unsigned int DAT_002fe868;

void FUN_0027fcbc(int *self, unsigned int *out, unsigned int step)
{
    unsigned int packed = (unsigned int)self[2];
    *out = packed;
    unsigned int k = DAT_002caa58[(unsigned int)self[1] % 30] / 3;
    unsigned int r, g, b, value;

    value = k + (packed & 0xff);
    r = DAT_002fe860;
    r = (r < value) ? r : value;
    value = k + ((packed >> 8) & 0xff);
    g = DAT_002fe864;
    g = (g < value) ? g : value;
    value = k + ((packed >> 16) & 0xff);
    b = DAT_002fe868;
    b = (b < value) ? b : value;
    unsigned int color = packed;
    color = (color & 0xffffff00) | r;
    *out = color;
    color = (color & 0xffff00ff) | (g << 8);
    *out = color;
    color = (color & 0xff00ffff) | (b << 16);
    *out = color;
    self[1] += step & 0xff;
}
// NEAR (58/61 words, 42 differ). Retail uses the sign-extended addresses
// DAT_002caa58 and DAT_002fe860/64/68, and clamps each channel with min(value,floor).
// Remaining: register allocation for the modulo/divide intermediates and the channel
// temporaries, plus the three packed-color stores. The initial packed word is stored
// before the table lookup; out is nonvolatile so subsequent merges use the saved color.
// Tried signed/unsigned index forms, explicit index locals, int/unsigned k, inline
// Div3/GetK/Min helpers, volatile input/floors, struct fields, byte channel locals,
// color locals, and direct read-modify-write stores. Best remains this source.
// improved by lane lnm1 (unreviewed): 45 -> 42 differing words
