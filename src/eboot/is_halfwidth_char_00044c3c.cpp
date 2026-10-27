/* HSTMATCH module=EBOOT.BIN start=0x00044c3c end=0x00044c88 symbol=FUN_00044c3c lang=c++ */
/* Clone of src/sharing_main/is_halfwidth_char_00044de0.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

/* UTF-16 code unit test: true for U+0000..U+00FF and for U+FF60..U+FF9F (half-width punctuation and katakana). */
extern "C" unsigned char FUN_00044c3c(void *self, unsigned short c)
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
