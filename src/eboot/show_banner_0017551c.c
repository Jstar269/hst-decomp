/* HSTMATCH module=EBOOT.BIN start=0x0017551c end=0x001755b8 symbol=FUN_0017551c lang=c99 */
/* Hand-written reconstruction (external matching lane): FUN_0016bf78 must be prototyped to return
   unsigned char (a `char` return makes the caller emit `seb` where retail has `andi 0xff`), and the
   two calls must be written as `if (c != 0) {call} else if (DAT_0034a678 == 3) {call}` so that the
   zero case is the out-of-line block (`beqzl v0,L` with the 0x35 lui in the delay). The first
   argument is float 0x3eaaaaab (0.33333334f) in $f12, the second a pointer in a0.
   Exact match verified; names and types await human review. */
extern int DAT_0034a678;
extern char DAT_0034179c[];
extern int DAT_003415ac;
extern unsigned char FUN_0016bf78(int);
extern void FUN_001b3ea4(float, char *);
extern void FUN_001fe0f4(int);
extern void FUN_00103628(int, int);
extern void FUN_0016bdc4(int);

void FUN_0017551c(int param_1)
{
    unsigned char cVar1;

    *(int *)(param_1 + 0x74) = 0x24;
    cVar1 = FUN_0016bf78(1);
    if (cVar1 != 0) {
        FUN_001b3ea4(0.33333334f, DAT_0034179c);
    } else if (DAT_0034a678 == 3) {
        FUN_001b3ea4(0.33333334f, DAT_0034179c);
    }
    FUN_001fe0f4(1);
    FUN_00103628(DAT_003415ac, 1);
    FUN_0016bdc4(0x24);
}
