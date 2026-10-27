/* HSTMATCH module=hstp_trans_main.prx start=0x002a96f8 end=0x002a9808 symbol=FUN_002a96f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_002a9808(const char *fmt, ...);
extern char DAT_003a8bf0[];
extern char DAT_003a8ba0[][16];
extern unsigned int DAT_003f4660;
extern int DAT_003f4664;

void FUN_002a96f8(int kind, int code)
{
    FUN_002a9808(DAT_003a8bf0, DAT_003a8ba0[kind], code);
    if (kind == 0) {
        DAT_003f4664 = code;
        DAT_003f4660 |= 1;
    } else if (kind == 1) {
        DAT_003f4664 = 0;
        DAT_003f4660 |= 2;
    } else if (kind == 2) {
        DAT_003f4664 = 0;
        DAT_003f4660 |= 4;
    } else if (kind == 3) {
        DAT_003f4664 = 0;
        DAT_003f4660 |= 8;
    } else if (kind == 4) {
        DAT_003f4664 = 0;
        DAT_003f4660 |= 0x10;
    }
}
