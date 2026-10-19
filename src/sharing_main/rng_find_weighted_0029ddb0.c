/* HSTMATCH module=hstp_trans_main.prx start=0x0029ddb0 end=0x0029de6c symbol=FUN_0029ddb0 lang=c99 */
/* Clone of src/eboot/rng_find_weighted_0028c5e8.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Entry {
    int f0;
    int f4;
} Entry;

extern unsigned int DAT_003f3b24;

void FUN_0029ddb0(Entry **out, Entry *begin, Entry *end, int unused, int *scale)
{
    int r;
    Entry *p;
    int more;

    DAT_003f3b24 = DAT_003f3b24 * 0x343fd + 0x269ec3;
    r = (int)((float)*scale *
              ((float)((DAT_003f3b24 >> 16) & 0x7fff) * (1.0f / 32768.0f)));

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
