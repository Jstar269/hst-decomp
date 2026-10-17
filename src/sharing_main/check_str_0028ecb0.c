/* HSTMATCH module=hstp_trans_main.prx start=0x0028ecb0 end=0x0028ed24 symbol=FUN_0028ecb0 lang=c99 */
/* Clone of src/eboot/check_str_0027d940.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: single-case switch on call result, shared return join; exact match verified; names and types await human review. */

extern char DAT_003a74b0[];
extern char DAT_003a74bc[];

extern int FUN_00014934(const char *str, const char *pat);
extern int FUN_00014d64(const char *str, const char *pat);

int FUN_0028ecb0(void *unused, const char *str)
{
    int res = 0;

    if (str == 0) {
        res = 0;
    } else {
        switch (FUN_00014d64(str, DAT_003a74b0)) {
        case 0:
            if (FUN_00014934(str, DAT_003a74bc) == 0) {
                res = 1;
            }
            break;
        }
    }
    return res;
}
