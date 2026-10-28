/* HSTMATCH module=EBOOT.BIN start=0x0022c8b4 end=0x0022c8d8 symbol=FUN_0022c8b4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char *DAT_003415a8;

int FUN_0022c8b4(int i)
{
    unsigned char *p = (unsigned char *)((i + 0x8D00) + (int)DAT_003415a8);
    return (p[0x3500] & 1) != 0;
}
