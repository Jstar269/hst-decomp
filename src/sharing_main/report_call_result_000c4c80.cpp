/* HSTMATCH module=hstp_trans_main.prx start=0x000c4c80 end=0x000c4cc4 symbol=FUN_000c4c80 lang=c++ data=0x0037c380 */
/* Clone of src/eboot/report_call_result_000c15e0.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037c380-0x0037c3a9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003e1e0c;
extern int FUN_002c7a58();
extern void FUN_000c41fc(char *fmt, int r);
}

extern "C" void FUN_000c4c80(void)
{
    if (DAT_003e1e0c != 0) {
        int r = FUN_002c7a58();
        if (r != 0) {
            FUN_000c41fc("sceUtilitySavedataUpdate Error : 0x%08x\n", r);
        }
    }
}
