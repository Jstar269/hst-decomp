/* HSTMATCH module=EBOOT.BIN start=0x001d2088 end=0x001d2118 symbol=FUN_001d2088 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the copied fields as float; exact match verified; names and types await human review. */
typedef unsigned int uint;
extern void FUN_000ffb3c(uint, int);

void FUN_001d2088(char *self)
{
    *(float *)(self + 0x270) = *(float *)(self + 0x274);
    *(int *)(self + 0xd4) = (*(int *)(self + 0xd8) + 6) % 6;
    **(uint **)(self + 0x6c) = 0x80808080;
    **(uint **)(self + 0x70) = 0x80808080;
    **(uint **)(self + 0x74) = 0x80808080;
    **(uint **)(self + 0x78) = 0x80808080;
    **(uint **)(self + 0x7c) = 0x80808080;
    **(uint **)(self + 0x80) = 0x80808080;
    FUN_000ffb3c(*(uint *)(self + 0x84), 1);
    FUN_000ffb3c(*(uint *)(self + 0x88), 1);
}
