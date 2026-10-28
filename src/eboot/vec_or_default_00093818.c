/* HSTMATCH module=EBOOT.BIN start=0x00093818 end=0x00093838 symbol=FUN_00093818 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[88]; int f58; };
extern char DAT_002bc410;

char *FUN_00093818(struct S *s)
{
    char *r;
    if (s->f58 != 0)
        r = (char *)s->f58 + 48;
    else
        r = &DAT_002bc410;
    return r;
}
