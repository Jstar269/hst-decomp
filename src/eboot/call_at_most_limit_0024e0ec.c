/* HSTMATCH module=EBOOT.BIN start=0x0024e0ec end=0x0024e158 symbol=FUN_0024e0ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and receiver argument, then expressed the guard as early returns; readability pass; exact match verified; names and types await human review. */
extern unsigned char DAT_002fbef9;
extern unsigned char DAT_002fbef8;
extern int DAT_0034a780;
extern int FUN_0024e174(void *);
extern void FUN_0024e1f8(void *, unsigned char, int, int, int);

/* Calls the worker with limit + 1 unless the guard byte is set or the object's current value is above the limit. */
void FUN_0024e0ec(void *object, int limit)
{
    if (DAT_002fbef9 != 0) return;
    if (FUN_0024e174(object) > limit) return;
    FUN_0024e1f8(object, DAT_002fbef8, DAT_0034a780, 4, limit + 1);
}
