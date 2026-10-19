/* HSTMATCH module=EBOOT.BIN start=0x0029e024 end=0x0029e0e0 symbol=FUN_0029e024 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002b7c18(int code);
extern int FUN_002b7cc0(int code);
extern void FUN_0029a584(char *msg, int val);
extern char DAT_002cb598[];
extern char DAT_002cb548[];
extern char DAT_002cb63c[];
extern char DAT_002cb5e8[];

int FUN_0029e024(void)
{
    int a;
    int b;

    a = FUN_002b7c18(256);
    if (a < 0) {
        FUN_0029a584(DAT_002cb598, a);
        goto L;
    }
    a = FUN_002b7c18(257);
    if (a < 0) {
        FUN_0029a584(DAT_002cb548, a);
        goto L;
    }
    return a;
L:
    b = FUN_002b7cc0(257);
    if (b < 0)
        FUN_0029a584(DAT_002cb63c, b);
    b = FUN_002b7cc0(256);
    if (b < 0)
        FUN_0029a584(DAT_002cb5e8, b);
    return a;
}
