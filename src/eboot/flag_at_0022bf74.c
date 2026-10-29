/* HSTMATCH module=EBOOT.BIN start=0x0022bf74 end=0x0022bf94 symbol=FUN_0022bf74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern unsigned char *DAT_003415a8;

int FUN_0022bf74(int a0)
{
    return *(unsigned char *)((char *)((a0 + 0x8c00) + (int)DAT_003415a8) + 0x3500) != 0;
}
