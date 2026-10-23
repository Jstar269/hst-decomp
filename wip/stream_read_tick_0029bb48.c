/* HSTMATCH module=EBOOT.BIN start=0x0029bb48 end=0x0029bcfc symbol=FUN_0029bb48 lang=c99 */
extern char DAT_002cb984[];
extern char DAT_002cb95c[];
extern int FUN_002b77a8(int, int *);
extern int FUN_002b7748(int, char *, int);
extern int FUN_000ff5b0(int, char *);
extern void FUN_00011090(char *, char *, int);
extern void FUN_002b7958(int);
extern void FUN_0029a584(char *, ...);

void FUN_0029bb48(char *param_1)
{
    int left[2];
    int r;
    int e;

    if (*(int *)(param_1 + 0x1582c) > 0) {
        r = FUN_000ff5b0(*(int *)(param_1 + 0x1c), (char *)(*(int *)(param_1 + 0x15828)));
        *(int *)(param_1 + 0x1582c) = *(int *)(param_1 + 0x1582c) - r;
        *(int *)(param_1 + 0x15828) = *(int *)(param_1 + 0x15828) + r;
        if (*(int *)(param_1 + 0x1582c) == 0) {
            e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
            if (e != 0)
                FUN_0029a584(DAT_002cb95c);
        }
    } else {
                    r = FUN_002b77a8(*(int *)(param_1 + 0xc), left);
        if (r == 0) {
            if (left[0] < 0) {
                FUN_0029a584(DAT_002cb984, left[0]);
                FUN_002b7958(100);
                e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
                if (e != 0)
                    FUN_0029a584(DAT_002cb95c);
            } else {
                *(int *)(param_1 + 0x7420) = left[0];
                r = FUN_000ff5b0(*(int *)(param_1 + 0x1c), param_1 + 0x20);
                if (r < *(int *)(param_1 + 0x7420)) {
                    *(int *)(param_1 + 0x1582c) = *(int *)(param_1 + 0x7420) - r;
                    *(int *)(param_1 + 0x15828) = (int)(param_1 + 0xe428);
                    FUN_00011090(param_1 + 0xe428, param_1 + r + 0x20,
                                 *(int *)(param_1 + 0x1582c));
                } else {
                    e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
                    if (e != 0)
                        FUN_0029a584(DAT_002cb95c);
                }
            }
        }
    }
}
// near miss: 103/109 words (6 short). The whole read state machine is recovered: the >0x7fff
// fields via the char* parameter (`lui 0x1; addu; lw 22572/22568`), the +0xe428 midpoint
// (`addiu a0,s0,25648` + `addiu a0,a0,32760`), the poll path with the error string, the retry
// read of 0x7400 bytes and the memmove with the re-read count.
// Remaining deltas:
//  * the branch polarity: retail `blez a2,POLL` puts the poll path OUT of line, which needs the
//    source written as `if (count > 0) {consume} else {poll}` (writing `if (count < 1) {poll} else
//    {consume}` inverts the arms and puts consume out of line).
//  * retail materialises the FUN_002b7748 result as `move a1,v0; beqz a1` (a named temp), and the
//    count load lands in a2 (`lw a2,22572(v0)`) instead of our v0; ours emits `beqz v0`. Naming the
//    temp (`e = FUN(...); if (e != 0)`) did NOT reproduce it (MWCC coalesced e back into v0).
//  * `if (count == 0) { read }` written as a nested if costs the extra `b` retail has; a `&&` form
//    would be shorter than retail.
// near miss from lane fm8 (unreviewed)
