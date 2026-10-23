/* HSTMATCH module=EBOOT.BIN start=0x000ffa60 end=0x000ffb3c symbol=FUN_000ffa60 lang=c99 */
extern int DAT_0033b45c;
extern char DAT_0033a6e0[];
extern char DAT_0033b394[];
extern char DAT_002d8a28[];
extern int FUN_00014a40();
extern void FUN_000149a8(char *, int);
extern void FUN_00014788(char *, char *);
extern int FUN_00014934(char *, char *);

void FUN_000ffa60(int param)
{
    char buf[256];
    int i;
    char *p;

    if (DAT_0033b45c != 0 && FUN_00014a40() != 0) {
        FUN_000149a8(buf, param);
        FUN_00014788(buf, DAT_002d8a28);
        i = 0;
        p = DAT_0033a6e0;
        do {
            if (FUN_00014934(buf, p) == 0) {
                DAT_0033a6e0[i * 0x41] = 0;
                *(int *)(DAT_0033b394 + i * 4) = 0;
                DAT_0033b45c = DAT_0033b45c - 1;
                return;
            }
            i++;
            p += 0x41;
        } while (i < 50);
    }
}

// 3 words short of retail's 55 (52/55). Retail keeps the body OUT OF LINE: `beqz v1,EPI1` for the
// global test, then `bnezl v0,BODY` (positive) with `move a1,s0` in the delay, then `b EPI2; lw ra`,
// then the body. Ours merges both failures into one block (`beqzl v0,EPI2`) and inlines the body.
// Ruled out: `&&` vs nested if, `if (DAT==0) return;` pairs, if/else with the return in the then and
// the body in the else, and passing param to FUN_00014a40 vs declaring it void.
// near miss from lane fm6 (unreviewed)
