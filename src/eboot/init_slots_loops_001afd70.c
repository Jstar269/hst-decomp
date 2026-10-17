/* HSTMATCH module=EBOOT.BIN start=0x001afd70 end=0x001afe0c symbol=FUN_001afd70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop bounds written inclusive (i <= 0x31 etc.) to get slti at; exact match verified; names and types await human review. */
extern void FUN_001b04d0(char *self, int idx);

void FUN_001afd70(char *self)
{
    int i;
    i = 0x28;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0x31);
    i = 0x84;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0x97);
    i = 0x98;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0xab);
    *(int *)(self + 0x7a4) = -1;
    *(int *)(self + 0x7c4) = -1;
    *(int *)(self + 0x7c8) = 0x1da;
}
