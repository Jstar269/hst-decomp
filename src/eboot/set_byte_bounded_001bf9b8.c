/* HSTMATCH module=EBOOT.BIN start=0x00001bf9b8 end=0x00001bf9f0 symbol=FUN_00001bf9b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00001bf9b8(void *s, int i, int c)
{
    char *p;
    if (i >= 0 && i < 640)
        p = (char *)s + i + 3404;
    else
        p = 0;
    if (p != 0)
        *p = c;
}
