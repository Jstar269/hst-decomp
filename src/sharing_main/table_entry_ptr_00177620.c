/* HSTMATCH module=hstp_trans_main.prx start=0x00177620 end=0x00177684 symbol=FUN_00177620 lang=c99 */
/* Clone of src/eboot/table_entry_ptr_0016b45c.c (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bounds-checked pointer into a record table: 15 rows of 56 bytes, 4 records of 12 bytes each inside a row,
   records start at +0xd0 of DAT_003eb004. Out-of-range either index returns 0. Matching idiom: the four tests
   are nested ifs with ONE shared trailing `return 0` (early returns, a result variable and an && chain all give
   a 2-word-shorter or longer-differing layout); that shape is what produces retail's `bltzl a0,JR; move v0,zero`
   first test with the later tests branching to the separate zero block. */
extern unsigned char DAT_003eb004[];

char *FUN_00177620(int a0, int a1)
{
    if (a0 >= 0) {
        if (a0 < 15) {
            if (a1 >= 0) {
                if (a1 < 4)
                    return (char *)(DAT_003eb004 + a0 * 56 + a1 * 12 + 0xd0);
            }
        }
    }
    return 0;
}
