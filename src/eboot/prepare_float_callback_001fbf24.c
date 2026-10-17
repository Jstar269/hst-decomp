/* HSTMATCH module=EBOOT.BIN start=0x001fbf24 end=0x001fbfa8 symbol=FUN_001fbf24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the callback argument order across the integer and floating register banks and corrected the byte and short accesses; exact match verified; names and types await human review. */
typedef unsigned int uint;
extern void FUN_000ffb3c(int, int);
extern void FUN_000edec0(float, float, float, void *, uint *, int, int,
                         float, float);
extern void FUN_001031e8(void *);

void FUN_001fbf24(char *self)
{
    FUN_000ffb3c(*(int *)(self + 0x74),
                 ((*(unsigned char *)(self + 0x7c) != 0) ^ 1));
    if (*(int *)(self + 0x78) != 0 &&
        ((*(unsigned short *)((char *)*(uint **)(self + 0x70) + 0xe) & 3) == 0)) {
        FUN_000edec0(0.0f, 0.0f, 1.0f,
                     *(void **)(self + 0x78), *(uint **)(self + 0x70), 0, 0,
                     1.0f, 1.0f);
    }
    FUN_001031e8(self);
}
