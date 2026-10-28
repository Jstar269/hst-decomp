/* HSTMATCH module=EBOOT.BIN start=0x002548d8 end=0x00254908 symbol=FUN_002548d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { int f0; unsigned char flags[472]; int v[1]; };

int FUN_002548d8(struct S *s, int i)
{
    return s->flags[i] != 0 && s->v[i] == 0;
}
