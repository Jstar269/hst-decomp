/* HSTMATCH module=hstp_trans_main.prx start=0x0025e2b4 end=0x0025e324 symbol=FUN_0025e2b4 lang=c99 */
/* Clone of src/eboot/call_below_limit_0024e07c.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and receiver argument, then expressed the guard as early returns; exact match verified; names and types await human review. */
extern unsigned char DAT_003a490d;
extern unsigned char DAT_003a490c;
extern unsigned int DAT_003a4908;
extern int DAT_003f3ab0;
extern int FUN_0025e390(void *);
extern void FUN_0025e430(void *, unsigned char, int, unsigned int, int);

void FUN_0025e2b4(void *object, int limit)
{
    if (DAT_003a490d != 0) return;
    if (FUN_0025e390(object) >= limit) return;
    FUN_0025e430(object, DAT_003a490c, DAT_003f3ab0, DAT_003a4908, limit);
}
