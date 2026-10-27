/* HSTMATCH module=hstp_trans_main.prx start=0x00046618 end=0x00046664 symbol=FUN_00046618 lang=c99 data=0x00375970 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00375970-0x003759b6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int DAT_003ba2cc;
extern void FUN_00046664(char *fmt, void *arg);
extern int FUN_002c75b8(void);
extern void *FUN_002c7738(int id);

void FUN_00046618(void)
{
    void *p;
    int id = FUN_002c75b8();
    if (DAT_003ba2cc != id) {
        p = FUN_002c7738(DAT_003ba2cc);
        if (p != 0) {
            FUN_00046664("ERROR: SuspendMainThread(): sceKernelSuspendThread(): failed. 0x%08x\n", p);
        }
    }
}
