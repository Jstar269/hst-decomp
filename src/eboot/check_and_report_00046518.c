/* HSTMATCH module=EBOOT.BIN start=0x00046518 end=0x00046564 symbol=FUN_00046518 lang=c99 data=0x002d0228 */
/* Clone of src/sharing_main/check_and_report_00046618.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d0228-0x002d026e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00310fcc;
extern void FUN_00046564(char *fmt, void *arg);
extern int FUN_002b77e0(void);
extern void *FUN_002b7998(int id);

void FUN_00046518(void)
{
    void *p;
    int id = FUN_002b77e0();
    if (DAT_00310fcc != id) {
        p = FUN_002b7998(DAT_00310fcc);
        if (p != 0) {
            FUN_00046564("ERROR: SuspendMainThread(): sceKernelSuspendThread(): failed. 0x%08x\n", p);
        }
    }
}
