/* HSTMATCH module=EBOOT.BIN start=0x000c06f0 end=0x000c0738 symbol=FUN_000c06f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_002d55c4;
extern char DAT_002d580c[];
extern int FUN_002b7e00(int, int);
extern void FUN_000c02ac(char *fmt, int r);
}

/* Releases the global handle (logging a nonzero result) and marks it unset. */
extern "C" void FUN_000c06f0(void)
{
    int result = FUN_002b7e00(DAT_002d55c4, 0);
    if (result != 0) {
        FUN_000c02ac(DAT_002d580c, result);
    }
    DAT_002d55c4 = -1;
}
