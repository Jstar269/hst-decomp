/* HSTMATCH module=hstp_trans_main.prx start=0x00044de0 end=0x00044e2c symbol=FUN_00044de0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

/* UTF-16 code unit test: true for U+0000..U+00FF and for U+FF60..U+FF9F (half-width punctuation and katakana). */
extern "C" unsigned char FUN_00044de0(void *self, unsigned short c)
{
    int r;

    switch (c & 0xff00) {
    case 0:
        return 1;
    case 0xff00:
        r = 0;
        if ((c & 0xff) >= 0x60 && (c & 0xff) <= 0x9f) r = 1;
        return r;
    }
    return 0;
}
