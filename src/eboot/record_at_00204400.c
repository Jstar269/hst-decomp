/* HSTMATCH module=EBOOT.BIN start=0x00204400 end=0x0020443c symbol=FUN_00204400 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern void *DAT_0034a148;

char *FUN_00204400(int i)
{
    if (DAT_0034a148 != 0) {
        if (i >= 0 && i < 15)
            return (char *)DAT_0034a148 + i * 16;
    }
    return 0;
}
