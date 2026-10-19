/* HSTMATCH module=hstp_trans_main.prx start=0x002ad1a0 end=0x002ad25c symbol=FUN_002ad1a0 lang=c99 */
/* Clone of src/eboot/acquire_or_log_0029e024.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002c79b8(int code);
extern int FUN_002c7a60(int code);
extern void FUN_002a9808(char *msg, int val);
extern char DAT_002db538[];
extern char DAT_002db4e8[];
extern char DAT_002db5dc[];
extern char DAT_002db588[];

int FUN_002ad1a0(void)
{
    int a;
    int b;

    a = FUN_002c79b8(256);
    if (a < 0) {
        FUN_002a9808(DAT_002db538, a);
        goto L;
    }
    a = FUN_002c79b8(257);
    if (a < 0) {
        FUN_002a9808(DAT_002db4e8, a);
        goto L;
    }
    return a;
L:
    b = FUN_002c7a60(257);
    if (b < 0)
        FUN_002a9808(DAT_002db5dc, b);
    b = FUN_002c7a60(256);
    if (b < 0)
        FUN_002a9808(DAT_002db588, b);
    return a;
}
