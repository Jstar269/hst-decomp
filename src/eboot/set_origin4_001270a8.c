/* HSTMATCH module=EBOOT.BIN start=0x001270a8 end=0x001270d4 symbol=FUN_001270a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[464]; float f1d0, f1d4, f1d8, f1dc; unsigned char f1e0; };

void FUN_001270a8(struct S *s, float *src)
{
    s->f1d0 = src[0];
    s->f1d4 = src[1];
    s->f1d8 = src[2];
    s->f1dc = src[3];
    s->f1e0 = 1;
}
