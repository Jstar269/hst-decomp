/* HSTMATCH module=EBOOT.BIN start=0x0012b72c end=0x0012b760 symbol=FUN_0012b72c lang=c99 */
struct S { char pad[868]; unsigned char f364, pad2[1]; unsigned char f366, f367; };
int FUN_0012b72c(struct S *s, int a1, int mode)
{
    int r = 0;
    if (mode == 5)
        r = s->f367;
    if (mode == 4)
        r = s->f366;
    if (mode == 0)
        r = s->f364;
    return r;
}
// improved by lane dsn3 (unreviewed): 11 -> 8 differing words
