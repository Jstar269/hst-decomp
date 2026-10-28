/* HSTMATCH module=EBOOT.BIN start=0x0022ca9c end=0x0022cad0 symbol=FUN_0022ca9c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415a8;

void FUN_0022ca9c(int a, int b, int c, signed char v)
{
    unsigned char *p = (unsigned char *)((c + 0x8D10) + (int)DAT_003415a8);
    p[a * 96 + b * 16 + 0x3500] = v;
}
