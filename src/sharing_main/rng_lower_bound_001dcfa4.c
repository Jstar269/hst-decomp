/* HSTMATCH module=hstp_trans_main.prx start=0x001dcfa4 end=0x001dd048 symbol=FUN_001dcfa4 lang=c99 */
/* Clone of src/eboot/rng_lower_bound_001ce8c8.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_003f3444;

int *FUN_001dcfa4(int *begin, int *end, int unused, int *scale)
{
    int r;
    int *p;

    DAT_003f3444 = DAT_003f3444 * 0x343fd + 0x269ec3;
    r = (int)((float)*scale *
              ((float)((DAT_003f3444 >> 16) & 0x7fff) * (1.0f / 32768.0f)));

    for (p = begin; p != end; p++) {
        r -= *p;
        if (r < 0)
            break;
    }
    return p;
}
