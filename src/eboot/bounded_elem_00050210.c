/* HSTMATCH module=EBOOT.BIN start=0x00050210 end=0x00050240 symbol=FUN_00050210 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { int a, b, c, d; };
struct S { char pad[520]; struct E e[576]; };

int FUN_00050210(struct S *s, int i)
{
    if (i >= 0) {
        if (i < 576)
            return s->e[i].a;
    }
    return 0;
}
