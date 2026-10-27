/* HSTMATCH module=hstp_trans_main.prx start=0x00291130 end=0x00291224 symbol=FUN_00291130 lang=c99 */
/* Clone of src/eboot/color_pulse_0027fcbc.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lanes ds8/lnm1 near miss, finished by lane wf20261026-e01-03: each clamped channel is narrowed with (unsigned char) before it is packed); exact match verified; names and types await human review. */
extern unsigned char DAT_002db018[];
extern unsigned int DAT_003a76c0;
extern unsigned int DAT_003a76c4;
extern unsigned int DAT_003a76c8;

void FUN_00291130(int *self, unsigned int *out, unsigned int step)
{
    unsigned int packed = (unsigned int)self[2];
    *out = packed;
    unsigned int k = DAT_002db018[(unsigned int)self[1] % 30] / 3;
    unsigned int r, g, b, value;

    value = k + (packed & 0xff);
    r = DAT_003a76c0;
    r = (r < value) ? r : value;
    value = k + ((packed >> 8) & 0xff);
    g = DAT_003a76c4;
    g = (g < value) ? g : value;
    value = k + ((packed >> 16) & 0xff);
    b = DAT_003a76c8;
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
