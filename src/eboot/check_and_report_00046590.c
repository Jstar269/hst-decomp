/* HSTMATCH module=EBOOT.BIN start=0x00046590 end=0x000465dc symbol=FUN_00046590 lang=c99 data=0x002d0270 */
/* Clone of src/sharing_main/check_and_report_00046618.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d0270-0x002d02b5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00310fcc;
extern void FUN_00046564(char *fmt, void *arg);
extern int FUN_002b77e0(void);
extern void *FUN_002b7968(int id);

void FUN_00046590(void)
{
    void *p;
    int id = FUN_002b77e0();
    if (DAT_00310fcc != id) {
        p = FUN_002b7968(DAT_00310fcc);
        if (p != 0) {
            FUN_00046564("ERROR: ResumeMainThread(): sceKernelSuspendThread(): failed. 0x%08x\n", p);
        }
    }
}
