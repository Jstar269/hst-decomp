/* HSTMATCH module=EBOOT.BIN start=0x00215ab8 end=0x00215af0 symbol=FUN_00215ab8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_0020b62c(void);
extern char *DAT_0034a6b4;

char *FUN_00215ab8(void)
{
    int idx = FUN_0020b62c();
    return (char *)(*(char **)DAT_0034a6b4) + idx * 72;
}
