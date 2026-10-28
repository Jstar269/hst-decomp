/* HSTMATCH module=EBOOT.BIN start=0x00001bf980 end=0x00001bf9b8 symbol=FUN_00001bf980 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00001bf980(void *s, int i, int c)
{
    char *p;
    if (i >= 0 && i < 640)
        p = (char *)s + i + 2764;
    else
        p = 0;
    if (p != 0)
        *p = c;
}
