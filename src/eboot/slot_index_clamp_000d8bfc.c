/* HSTMATCH module=EBOOT.BIN start=0x000d8bfc end=0x000d8c24 symbol=FUN_000d8bfc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { int f0, f4, f8; };
struct S { struct E e[8]; };

int FUN_000d8bfc(struct S *s, int i)
{
    if (i == 4)
        i = 3;
    return s->e[i].f8;
}
