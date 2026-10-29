/* HSTMATCH module=EBOOT.BIN start=0x0022c05c end=0x0022c07c symbol=FUN_0022c05c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char *DAT_003415a8;

short FUN_0022c05c(int idx)
{
    return ((short *)((char *)DAT_003415a8 + 0xd4e6))[idx];
}
