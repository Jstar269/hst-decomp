/* HSTMATCH module=EBOOT.BIN start=0x00046820 end=0x00046880 symbol=FUN_00046820 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_00311028; extern unsigned char DAT_0030ab8c; extern char DAT_002d041c[]; extern void FUN_00046564(char *s); extern void FUN_002b7888(int us); extern void FUN_002b77f0(void);
int FUN_00046820(void) { DAT_00311028 = 1; while (DAT_0030ab8c) { FUN_00046564(DAT_002d041c); FUN_002b7888(1000); } FUN_002b77f0(); return 0; }
