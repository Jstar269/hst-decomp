/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d90 end=0x000c3dd8 symbol=FUN_000c3d90 lang=c++ */
/* Clone of src/eboot/report_call_result_reset_000c06f0.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_0037bf14;
extern char DAT_0037c15c[];
extern int FUN_002c7b88(int, int);
extern void FUN_000c394c(char *fmt, int r);
}

extern "C" void FUN_000c3d90(void)
{
    int r = FUN_002c7b88(DAT_0037bf14, 0);
    if (r != 0) {
        FUN_000c394c(DAT_0037c15c, r);
    }
    DAT_0037bf14 = -1;
}
