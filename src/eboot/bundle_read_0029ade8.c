/* HSTMATCH module=EBOOT.BIN start=0x0029ade8 end=0x0029b014 symbol=FUN_0029ade8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00060224(int, int);
extern void FUN_0001b880(void);
extern void FUN_0029a584(char *, ...);
extern void FUN_002b7958(int);
extern int FUN_002b7790(char *, int, int);
extern long long FUN_002b77a0(int, long long, int);
extern int FUN_002b7720(int, int, int);
extern int FUN_002b7738(int);
extern unsigned int FUN_002b7cf8(void);
extern int DAT_00311000;
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];

void FUN_0029ade8(int *self, int mode)
{
    int fd;
    int n;

    self[2] = mode;
    switch (mode) {
    case 0:
        return;
    case 3:
        self[1] = 0;
        return;
    case 4:
        FUN_00060224(DAT_00311000, 1);
        FUN_0001b880();
        FUN_0029a584(DAT_002cb714, DAT_002cb6dc);
        while ((fd = FUN_002b7790(DAT_002cb6a4, 1, 0)) < 0) {
            FUN_0001b880();
        }
        self[8] = (int)FUN_002b77a0(fd, 0LL, 2);
        while (self[8] < 0) {
            FUN_0001b880();
            self[8] = (int)FUN_002b77a0(fd, 0LL, 2);
        }
        while (FUN_002b77a0(fd, 0LL, 0) < 0) {
            FUN_0001b880();
        }
        for (;;) {
            while ((FUN_002b7cf8() & 0x20) == 0) {
                FUN_0029a584(DAT_002cb68c);
                FUN_002b7958(1000000);
            }
            n = self[8];
            if (FUN_002b7720(fd, self[7], n) == n)
                break;
            FUN_002b7958(1000000);
        }
        n = FUN_002b7738(fd);
        while (n < 0) {
            FUN_002b7958(1000000);
            n = FUN_002b7738(fd);
        }
        FUN_00060224(DAT_00311000, 0);
        return;
    }
}
