/* HSTMATCH module=EBOOT.BIN start=0x000bbba4 end=0x000bbc1c symbol=FUN_000bbba4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop counter declared before walking pointer, for loop with strncmp check; exact match verified; names and types await human review. */

extern "C" int FUN_0001100c(const void *s1, const void *s2, unsigned int n);

extern "C" int FUN_000bbba4(char *param_1, const void *target)
{
    int i;
    char *p = param_1;
    for (i = 0; i < 16; i++) {
        if (*(unsigned char *)(p + 0x5e) != 0) {
            if (FUN_0001100c(p + 0x58, target, 6) == 0) {
                return i;
            }
        }
        p += 7;
    }
    return -1;
}
