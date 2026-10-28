/* HSTMATCH module=EBOOT.BIN start=0x00045ac8 end=0x00045af4 symbol=FUN_00045ac8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_000032ac(void *, int, int, int);
struct B { unsigned char b0 : 1; unsigned char b1 : 7; };
struct S { int f0; int f4; };

void FUN_00045ac8(struct S *s, int a1)
{
    int v;
    if (s->f0 & 1)
        v = s->f4;
    else
        v = ((struct B *)s)->b1;
    FUN_000032ac(s, v, 0, a1);
}
