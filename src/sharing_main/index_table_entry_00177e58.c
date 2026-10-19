/* HSTMATCH module=hstp_trans_main.prx start=0x00177e58 end=0x00177e98 symbol=FUN_00177e58 lang=c99 */
/* Clone of src/eboot/index_table_entry_0016bc30.c (hstclone.py tag ds1018ar2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003ea8e8;

void *FUN_00177e58(int idx)
{
    char *base = DAT_003ea8e8 + 128;

    if (idx >= 0 && idx < 40) {
        return base + idx * 20 + 0x1058;
    }
    return 0;
}
