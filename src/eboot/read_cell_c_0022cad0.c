/* HSTMATCH module=EBOOT.BIN start=0x0022cad0 end=0x0022cb04 symbol=FUN_0022cad0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415a8;

unsigned char FUN_0022cad0(int a, int b, int c)
{
    unsigned char *p = (unsigned char *)((c + 0x8D10) + (int)DAT_003415a8);
    return p[a * 96 + b * 16 + 0x3500];
}
