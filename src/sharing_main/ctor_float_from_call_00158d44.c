/* HSTMATCH module=hstp_trans_main.prx start=0x00158d44 end=0x00158db8 symbol=FUN_00158d44 lang=c99 */
/* Clone of src/eboot/ctor_float_from_call_0014d25c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: prototyped extern with unsigned result so the (float)unsigned conversion matches; exact match verified; names and types await human review. */
extern char DAT_003b16d8;
extern char DAT_003b1660;
extern unsigned FUN_0015b050(int arg);

int *FUN_00158d44(int *self, int arg)
{
    unsigned v;
    *self = (int)&DAT_003b16d8;
    *(char *)(self + 1) = 0;
    *self = (int)&DAT_003b1660;
    v = FUN_0015b050(arg);
    *(float *)(self + 2) = (float)v;
    return self;
}
