/* HSTMATCH module=EBOOT.BIN start=0x0028c5e8 end=0x0028c6a4 symbol=FUN_0028c5e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Entry {
    int f0;
    int f4;
} Entry;

extern unsigned int DAT_0034a7f4;

void FUN_0028c5e8(Entry **out, Entry *begin, Entry *end, int unused, int *scale)
{
    int r;
    Entry *p;
    int more;

    DAT_0034a7f4 = DAT_0034a7f4 * 0x343fd + 0x269ec3;
    r = (int)((float)*scale *
              ((float)((DAT_0034a7f4 >> 16) & 0x7fff) * (1.0f / 32768.0f)));

    p = begin;
    more = !(p == end);
    while (more) {
        r -= p->f4;
        if (r < 0)
            break;
        p++;
        more = !(p == end);
    }
    *out = p;
}
