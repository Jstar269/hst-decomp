/* HSTMATCH module=EBOOT.BIN start=0x000c15e0 end=0x000c1624 symbol=FUN_000c15e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_00338acc;
extern char DAT_002d5a30[];
extern int FUN_002b7cb8();
extern void FUN_000c0b5c(char *fmt, int r);
}

extern "C" void FUN_000c15e0(void)
{
    if (DAT_00338acc != 0) {
        int r = FUN_002b7cb8();
        if (r != 0) {
            FUN_000c0b5c(DAT_002d5a30, r);
        }
    }
}
