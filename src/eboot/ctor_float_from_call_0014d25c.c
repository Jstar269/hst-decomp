/* HSTMATCH module=EBOOT.BIN start=0x0014d25c end=0x0014d2d0 symbol=FUN_0014d25c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: prototyped extern with unsigned result so the (float)unsigned conversion matches; exact match verified; names and types await human review. */
extern char DAT_0030840c;
extern char DAT_00308394;
extern unsigned FUN_0014f050(int arg);

int *FUN_0014d25c(int *self, int arg)
{
    unsigned v;
    *self = (int)&DAT_0030840c;
    *(char *)(self + 1) = 0;
    *self = (int)&DAT_00308394;
    v = FUN_0014f050(arg);
    *(float *)(self + 2) = (float)v;
    return self;
}
