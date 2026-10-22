/* HSTMATCH module=EBOOT.BIN start=0x0016b45c end=0x0016b4c0 symbol=FUN_0016b45c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bounds-checked pointer into a record table: 15 rows of 56 bytes, 4 records of 12 bytes each inside a row,
   records start at +0xd0 of DAT_00341ccc. Out-of-range either index returns 0. Matching idiom: the four tests
   are nested ifs with ONE shared trailing `return 0` (early returns, a result variable and an && chain all give
   a 2-word-shorter or longer-differing layout); that shape is what produces retail's `bltzl a0,JR; move v0,zero`
   first test with the later tests branching to the separate zero block. */
extern unsigned char DAT_00341ccc[];

char *FUN_0016b45c(int a0, int a1)
{
    if (a0 >= 0) {
        if (a0 < 15) {
            if (a1 >= 0) {
                if (a1 < 4)
                    return (char *)(DAT_00341ccc + a0 * 56 + a1 * 12 + 0xd0);
            }
        }
    }
    return 0;
}
