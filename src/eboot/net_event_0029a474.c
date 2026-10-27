/* HSTMATCH module=EBOOT.BIN start=0x0029a474 end=0x0029a584 symbol=FUN_0029a474 lang=c99 */
/* Clone of src/sharing_main/net_event_002a96f8.c (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_0029a584(const char *fmt, ...);
extern char DAT_002ffd1c[];
extern char DAT_002ffccc[][16];
extern unsigned int DAT_0034b320;
extern int DAT_0034b324;

void FUN_0029a474(int kind, int code)
{
    FUN_0029a584(DAT_002ffd1c, DAT_002ffccc[kind], code);
    if (kind == 0) {
        DAT_0034b324 = code;
        DAT_0034b320 |= 1;
    } else if (kind == 1) {
        DAT_0034b324 = 0;
        DAT_0034b320 |= 2;
    } else if (kind == 2) {
        DAT_0034b324 = 0;
        DAT_0034b320 |= 4;
    } else if (kind == 3) {
        DAT_0034b324 = 0;
        DAT_0034b320 |= 8;
    } else if (kind == 4) {
        DAT_0034b324 = 0;
        DAT_0034b320 |= 0x10;
    }
}
