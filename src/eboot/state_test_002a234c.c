/* HSTMATCH module=EBOOT.BIN start=0x002a234c end=0x002a2378 symbol=FUN_002a234c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int f0; };
struct S { char pad[432]; int f1b0; char pad2[28]; struct P *f1d0; };

int FUN_002a234c(struct S *s)
{
    return s->f1b0 == 5 && s->f1d0->f0 == 2;
}
