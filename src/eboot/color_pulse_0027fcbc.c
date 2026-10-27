/* HSTMATCH module=EBOOT.BIN start=0x0027fcbc end=0x0027fdb0 symbol=FUN_0027fcbc lang=c99 */
/* Hand-written reconstruction from the disassembly (lanes ds8/lnm1 near miss, finished by lane wf20261026-e01-03: each clamped channel is narrowed with (unsigned char) before it is packed); exact match verified; names and types await human review. */
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
    color = (color & 0xffffff00) | (unsigned char)r;
    *out = color;
    color = (color & 0xffff00ff) | ((unsigned char)g << 8);
    *out = color;
    color = (color & 0xff00ffff) | ((unsigned char)b << 16);
    *out = color;
    self[1] += step & 0xff;
}
