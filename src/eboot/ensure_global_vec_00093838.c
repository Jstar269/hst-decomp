/* HSTMATCH module=EBOOT.BIN start=0x00093838 end=0x00093898 symbol=FUN_00093838 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[88]; int f58; };
extern char DAT_00338710;
extern int DAT_002beb40, DAT_002beb44, DAT_002beb48, DAT_002beb4c;

void *FUN_00093838(struct S *s)
{
    if (s->f58 != 0)
        return (char *)s->f58 + 96;
    if (DAT_00338710 == 0) {
        DAT_002beb40 = 0;
        DAT_002beb44 = 0;
        DAT_002beb48 = 0;
        DAT_002beb4c = 0x3F800000;
        DAT_00338710 = 1;
    }
    return &DAT_002beb40;
}
