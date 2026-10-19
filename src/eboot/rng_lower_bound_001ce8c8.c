/* HSTMATCH module=EBOOT.BIN start=0x001ce8c8 end=0x001ce96c symbol=FUN_001ce8c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned int DAT_0034a10c;

int *FUN_001ce8c8(int *begin, int *end, int unused, int *scale)
{
    int r;
    int *p;

    DAT_0034a10c = DAT_0034a10c * 0x343fd + 0x269ec3;
    r = (int)((float)*scale *
              ((float)((DAT_0034a10c >> 16) & 0x7fff) * (1.0f / 32768.0f)));

    for (p = begin; p != end; p++) {
        r -= *p;
        if (r < 0)
            break;
    }
    return p;
}
