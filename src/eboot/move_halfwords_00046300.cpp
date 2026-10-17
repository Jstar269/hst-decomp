/* HSTMATCH module=EBOOT.BIN start=0x00046300 end=0x000463e4 symbol=FUN_00046300 lang=c++ */
/* Clone of src/sharing_main/move_halfwords_00046400.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (MSL char_traits::move shape for 16-bit characters); exact match verified; names and types await human review. */
/* matching idiom: the copies go through an inline assign(char_type &, const char_type &) so the 8x-unrolled forward loop keeps its extra destination address register. */

typedef unsigned short wc;

static inline void assign(wc &c1, const wc &c2)
{
    c1 = c2;
}

extern "C" wc *FUN_00046300(wc *s1, const wc *s2, unsigned int n);

wc *FUN_00046300(wc *s1, const wc *s2, unsigned int n)
{
    wc *r = s1;
    if (s1 < s2) {
        for (unsigned int i = 0; i < n; ++i)
            assign(*s1++, *s2++);
    } else if (s2 < s1) {
        s1 += n;
        s2 += n;
        for (; n != 0; --n)
            assign(*--s1, *--s2);
    }
    return r;
}
