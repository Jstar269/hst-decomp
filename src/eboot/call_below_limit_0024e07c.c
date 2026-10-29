/* HSTMATCH module=EBOOT.BIN start=0x0024e07c end=0x0024e0ec symbol=FUN_0024e07c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and receiver argument, then expressed the guard as early returns; readability pass; exact match verified; names and types await human review. */
extern unsigned char DAT_002fbef9;
extern unsigned char DAT_002fbef8;
extern unsigned int DAT_002fbef4;
extern int DAT_0034a780;
extern int FUN_0024e158(void *);
extern void FUN_0024e1f8(void *, unsigned char, int, unsigned int, int);

/* Calls the worker with the limit unless the guard byte is set or the object's current value already reaches the limit. */
void FUN_0024e07c(void *object, int limit)
{
    if (DAT_002fbef9 != 0) return;
    if (FUN_0024e158(object) >= limit) return;
    FUN_0024e1f8(object, DAT_002fbef8, DAT_0034a780, DAT_002fbef4, limit);
}
