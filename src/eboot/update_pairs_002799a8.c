/* HSTMATCH module=EBOOT.BIN start=0x002799a8 end=0x00279a2c symbol=FUN_002799a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; exact match verified; names and types await human review. */

extern void FUN_000ffb3c(void *, int);

void FUN_002799a8(char *param_1, int param_2)
{
    int i;
    char *p = param_1;
    for (i = 0; i < 16; i++, p += 0x10) {
        if (i == param_2) {
            FUN_000ffb3c(*(void **)(p + 0x4b8), 0);
            FUN_000ffb3c(*(void **)(p + 0x4bc), 0);
        } else {
            FUN_000ffb3c(*(void **)(p + 0x4b8), 1);
            FUN_000ffb3c(*(void **)(p + 0x4bc), 1);
        }
    }
}
