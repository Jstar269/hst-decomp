/* HSTMATCH module=EBOOT.BIN start=0x0027d940 end=0x0027d9b4 symbol=FUN_0027d940 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: single-case switch on call result, shared return join; exact match verified; names and types await human review. */

extern char DAT_002fe730[];
extern char DAT_002fe73c[];

extern int FUN_00014934(const char *str, const char *pat);
extern int FUN_00014d64(const char *str, const char *pat);

int FUN_0027d940(void *unused, const char *str)
{
    int res = 0;

    if (str == 0) {
        res = 0;
    } else {
        switch (FUN_00014d64(str, DAT_002fe730)) {
        case 0:
            if (FUN_00014934(str, DAT_002fe73c) == 0) {
                res = 1;
            }
            break;
        }
    }
    return res;
}
