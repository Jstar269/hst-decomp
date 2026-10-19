/* HSTMATCH module=hstp_trans_main.prx start=0x002079a4 end=0x00207a0c symbol=FUN_002079a4 lang=c99 */
/* Clone of src/eboot/mode_result_select_001f92ec.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

uchar FUN_002079a4(void *self)
{
    uchar r = 0;

    switch (*(int *)((char *)self + 0x40)) {
    case 1:
    case 2:
    case 4:
    case 16:
        if (*(int *)((char *)self + 0x524) == 5)
            r = 1;
        break;
    default:
        if (*(uchar *)((char *)self + 0x568) != 0)
            r = 1;
        break;
    }
    return r;
}
