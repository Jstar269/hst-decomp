/* HSTMATCH module=hstp_trans_main.prx start=0x00178160 end=0x001781f0 symbol=FUN_00178160 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003f39a8;
extern int DAT_003f39ac;

int FUN_00178160(void)
{
    int r;

    if (DAT_003f39a8 == 3) {
        r = 1;
    } else if (DAT_003f39a8 == 0x55) {
        if (DAT_003f39ac == 0x54 || DAT_003f39ac == 0x1d) {
            r = 1;
        } else {
            r = 0;
        }
    } else if (DAT_003f39a8 == 0x24) {
        r = 0;
    } else {
        if (DAT_003f39ac != 0x30 && DAT_003f39ac != 0x29) {
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}
