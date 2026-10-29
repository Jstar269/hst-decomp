/* HSTMATCH module=hstp_trans_main.prx start=0x00212c68 end=0x00212ca4 symbol=FUN_00212c68 lang=c99 */
/* Clone of src/eboot/record_at_00204400.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern void *DAT_003f3480;

char *FUN_00212c68(int i)
{
    if (DAT_003f3480 != 0) {
        if (i >= 0 && i < 15)
            return (char *)DAT_003f3480 + i * 16;
    }
    return 0;
}
