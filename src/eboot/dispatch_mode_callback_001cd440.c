/* HSTMATCH module=EBOOT.BIN start=0x001cd440 end=0x001cd490 symbol=FUN_001cd440 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered the threshold arms as mode greater than one; exact match verified; names and types await human review. */
extern unsigned int DAT_0033b580;
extern void FUN_0012de6c(unsigned int, int, unsigned int, int);

void FUN_001cd440(int *object, unsigned int value, int mode)
{
    *(unsigned char *)(*(int *)((char *)object + 0x15c) + 0x60) = 1;
    if (DAT_0033b580 != 0) {
        int code;
        if (mode > 1) {
            code = 3;
        } else {
            code = 2;
        }
        FUN_0012de6c(DAT_0033b580, code, value, 0);
    }
}
