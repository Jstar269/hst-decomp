/* HSTMATCH module=EBOOT.BIN start=0x001f92ec end=0x001f9354 symbol=FUN_001f92ec lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

uchar FUN_001f92ec(void *self)
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
