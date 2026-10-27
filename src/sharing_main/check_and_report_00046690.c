/* HSTMATCH module=hstp_trans_main.prx start=0x00046690 end=0x000466dc symbol=FUN_00046690 lang=c99 data=0x003759b8 */
/* Clone of src/eboot/check_and_report_00046518.c (hstclone.py tag a0db26hsEB): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003759b8-0x003759fd) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003ba2cc;
extern void FUN_00046664(char *fmt, void *arg);
extern int FUN_002c75b8(void);
extern void *FUN_002c7708(int id);

void FUN_00046690(void)
{
    void *p;
    int id = FUN_002c75b8();
    if (DAT_003ba2cc != id) {
        p = FUN_002c7708(DAT_003ba2cc);
        if (p != 0) {
            FUN_00046664("ERROR: ResumeMainThread(): sceKernelSuspendThread(): failed. 0x%08x\n", p);
        }
    }
}
