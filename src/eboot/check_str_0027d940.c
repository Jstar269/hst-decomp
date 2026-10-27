/* HSTMATCH module=EBOOT.BIN start=0x0027d940 end=0x0027d9b4 symbol=FUN_0027d940 lang=c99 data=0x002fe730 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: single-case switch on call result, shared return join; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002fe730-0x002fe740) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */


extern int FUN_00014934(const char *str, const char *pat);
extern int FUN_00014d64(const char *str, const char *pat);

int FUN_0027d940(void *unused, const char *str)
{
    int res = 0;

    if (str == 0) {
        res = 0;
    } else {
        switch (FUN_00014d64(str, "CENTERLOBBY")) {
        case 0:
            if (FUN_00014934(str, "NPC") == 0) {
                res = 1;
            }
            break;
        }
    }
    return res;
}
