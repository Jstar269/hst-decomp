/* HSTMATCH module=EBOOT.BIN start=0x00088128 end=0x0008822c symbol=FUN_00088128 lang=c99 data=0x002d21f0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d21f0-0x002d223b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int FUN_0029a468(void);
extern void FUN_0008822c(char *, ...);
extern int FUN_002b7cf8(void);
extern void FUN_002b7958(int);
extern int FUN_002b7790(int, int, int);
extern int FUN_002b7738(int);

void FUN_00088128(void)
{
    int h = FUN_0029a468();
    int s1;

    FUN_0008822c("***** CheckDiskFile(): start. *****\n");
    while ((FUN_002b7cf8() & 0x20) == 0)
        FUN_002b7958(1000000);
    while ((s1 = FUN_002b7790(h, 1, 0)) < 0) {
        while ((FUN_002b7cf8() & 0x20) == 0)
            FUN_002b7958(1000000);
        FUN_002b7958(100);
    }
    while (FUN_002b7738(s1) < 0)
        FUN_002b7958(1000000);
    FUN_0008822c("***** CheckDiskFile(): end. *****\n");
}
