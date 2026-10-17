/* HSTMATCH module=EBOOT.BIN start=0x001f9390 end=0x001f93dc symbol=FUN_001f9390 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: used an early null return and reloaded the owner pointer for the final helper call; exact match verified; names and types await human review. */
extern void FUN_00219a50(void *, int);

void FUN_001f9390(char *self)
{
    char *target = *(char **)(self + 0x564);
    if (target == 0) return;
    *(float *)(target + 0x10) = *(float *)(self + 0x570);
    *(float *)(target + 0x14) = *(float *)(self + 0x574);
    *(float *)(target + 0x18) = *(float *)(self + 0x578);
    *(float *)(target + 0x1c) = *(float *)(self + 0x57c);
    FUN_00219a50(*(void **)(self + 0x564), 3);
}
