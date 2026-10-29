/* HSTMATCH module=EBOOT.BIN start=0x00216e00 end=0x00216e70 symbol=FUN_00216e00 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: RGB local declaration order and nested packing ORs; readability pass; exact match verified; names and types await human review. */

#include "hst/color_words.h"

/* Halve each channel (rounding up) and pack them as red | green << 8 | blue << 16 with the alpha bit pattern on top. */
u32 FUN_00216e00(ColorWords *color)
{
    int r;
    int b;
    int g;

    r = (int)color->r >> 1;
    if (color->r & 1) {
        r++;
    }

    b = (int)color->b >> 1;
    if (color->b & 1) {
        b++;
    }

    g = (int)color->g >> 1;
    if (color->g & 1) {
        g++;
    }

    return (((PACKED_ALPHA | ((b & 0xff) << 16)) | ((g & 0xff) << 8)) | (r & 0xff));
}
