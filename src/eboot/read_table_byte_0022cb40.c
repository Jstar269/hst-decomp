/* HSTMATCH module=EBOOT.BIN start=0x0022cb40 end=0x0022cb7c symbol=FUN_0022cb40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: `(char *)0 +` seeds the offset sum so the a*384 term is added to the base first. */
extern unsigned char *DAT_003415a8;

unsigned char FUN_0022cb40(int a, int b, int c, int d)
{
    return *(unsigned char *)((char *)0 + (a * 384 + ((d + 0x90D0) + (int)DAT_003415a8)) + b * 64 + c * 8 + 0x3500);
}
