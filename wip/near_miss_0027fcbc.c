/* HSTMATCH module=EBOOT.BIN start=0x0027fcbc end=0x0027fdb0 symbol=FUN_0027fcbc lang=c99 */
extern unsigned char DAT_002daa58[];
extern unsigned int DAT_0030e860;
extern unsigned int DAT_0030e864;
extern unsigned int DAT_0030e868;

void FUN_0027fcbc(int *self, volatile unsigned int *out, unsigned int step)
{
    unsigned int packed = (unsigned int)self[2];
    unsigned int k = DAT_002daa58[self[1] % 30] / 3;
    unsigned int r, g, b;

    *out = packed;
    r = k + (packed & 0xff);
    if (r < DAT_0030e860)
        r = DAT_0030e860;
    g = k + ((packed >> 8) & 0xff);
    if (g < DAT_0030e864)
        g = DAT_0030e864;
    b = k + ((packed >> 16) & 0xff);
    if (b < DAT_0030e868)
        b = DAT_0030e868;
    *out = (*out & 0xffffff00) | r;
    *out = (*out & 0xffff00ff) | (g << 8);
    *out = (*out & 0xff00ffff) | (b << 16);
    self[1] += step & 0xff;
}
// Near miss: the three read-modify-write stores to *out only survive if *out is volatile, and the
// clamp direction (max against the DAT_0030e86x floors) still needs checking against the disassembly.
// near miss from lane ds8 (unreviewed)
