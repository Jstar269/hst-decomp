/* HSTMATCH module=EBOOT.BIN start=0x0001e23c end=0x0001e268 symbol=FUN_0001e23c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[132]; int f84; };

void FUN_0001e23c(struct S *s, int a1, int a2)
{
    if (a2)
        s->f84 = s->f84 | a1;
    else
        s->f84 = s->f84 & ~a1;
}
