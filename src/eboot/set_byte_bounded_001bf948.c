/* HSTMATCH module=EBOOT.BIN start=0x00001bf948 end=0x00001bf980 symbol=FUN_00001bf948 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00001bf948(void *s, int i, int c)
{
    char *p;
    if (i >= 0 && i < 640)
        p = (char *)s + i + 2124;
    else
        p = 0;
    if (p != 0)
        *p = c;
}
