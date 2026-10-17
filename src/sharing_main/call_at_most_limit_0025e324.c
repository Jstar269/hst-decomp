/* HSTMATCH module=hstp_trans_main.prx start=0x0025e324 end=0x0025e390 symbol=FUN_0025e324 lang=c99 */
/* Clone of src/eboot/call_at_most_limit_0024e0ec.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and receiver argument, then expressed the guard as early returns; exact match verified; names and types await human review. */
extern unsigned char DAT_003a490d;
extern unsigned char DAT_003a490c;
extern int DAT_003f3ab0;
extern int FUN_0025e3ac(void *);
extern void FUN_0025e430(void *, unsigned char, int, int, int);

void FUN_0025e324(void *object, int limit)
{
    if (DAT_003a490d != 0) return;
    if (FUN_0025e3ac(object) > limit) return;
    FUN_0025e430(object, DAT_003a490c, DAT_003f3ab0, 4, limit + 1);
}
