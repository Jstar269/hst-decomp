/* HSTMATCH module=EBOOT.BIN start=0x00088128 end=0x0008822c symbol=FUN_00088128 lang=c99 */
extern char DAT_002d21f0[];
extern char DAT_002d2218[];
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

    FUN_0008822c(DAT_002d21f0);
    if ((FUN_002b7cf8() & 0x20) == 0) {
        do {
            FUN_002b7958(1000000);
        } while ((FUN_002b7cf8() & 0x20) == 0);
    }
    while ((s1 = FUN_002b7790(h, 1, 0)) < 0) {
        if ((FUN_002b7cf8() & 0x20) == 0) {
            do {
                FUN_002b7958(1000000);
            } while ((FUN_002b7cf8() & 0x20) == 0);
        }
        FUN_002b7958(100);
    }
    while (FUN_002b7738(s1) < 0)
        FUN_002b7958(1000000);
    FUN_0008822c(DAT_002d2218);
}
// near miss: 69/65 words; the retry loop is identical in content but not rotated. Retail emits
// the inverted form (j head; body; head: s1 = open; bltz v0 -> body) while MWCC keeps ours
// top-tested (head; bgez exit; body; b head). Single call site in retail rules out the
// explicit re-call spelling (that compiles to a duplicate jal). Ruled out: while(s1<0) with the
// call in the body (duplicate call), for(;;)+if(s1>=0)break, for(;;)+if(open()>=0)break.
// near miss from lane fm6 (unreviewed)
