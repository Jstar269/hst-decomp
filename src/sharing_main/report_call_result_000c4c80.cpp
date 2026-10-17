/* HSTMATCH module=hstp_trans_main.prx start=0x000c4c80 end=0x000c4cc4 symbol=FUN_000c4c80 lang=c++ */
/* Clone of src/eboot/report_call_result_000c15e0.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003e1e0c;
extern char DAT_0037c380[];
extern int FUN_002c7a58();
extern void FUN_000c41fc(char *fmt, int r);
}

extern "C" void FUN_000c4c80(void)
{
    if (DAT_003e1e0c != 0) {
        int r = FUN_002c7a58();
        if (r != 0) {
            FUN_000c41fc(DAT_0037c380, r);
        }
    }
}
