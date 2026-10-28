/* HSTMATCH module=EBOOT.BIN start=0x00266b78 end=0x00266ba4 symbol=FUN_00266b78 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[336]; float f150, f154, f158, f15c; unsigned char f160; };

void FUN_00266b78(struct S *s, float *src)
{
    s->f150 = src[0];
    s->f154 = src[1];
    s->f158 = src[2];
    s->f15c = src[3];
    s->f160 = 1;
}
