/* HSTMATCH module=EBOOT.BIN start=0x000c15e0 end=0x000c1624 symbol=FUN_000c15e0 lang=c++ data=0x002d5a30 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d5a30-0x002d5a59) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern unsigned char DAT_00338acc;
extern int FUN_002b7cb8();
extern void FUN_000c0b5c(char *fmt, int r);
}

extern "C" void FUN_000c15e0(void)
{
    if (DAT_00338acc != 0) {
        int r = FUN_002b7cb8();
        if (r != 0) {
            FUN_000c0b5c("sceUtilitySavedataUpdate Error : 0x%08x\n", r);
        }
    }
}
