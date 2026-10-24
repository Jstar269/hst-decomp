/* HSTMATCH module=EBOOT.BIN start=0x0029bb48 end=0x0029bcfc symbol=FUN_0029bb48 lang=c99 */
/* Hand-written reconstruction from the disassembly (started from wip/stream_read_tick_0029bb48.c, Ghidra pseudocode); exact match verified; names and types await human review. Matching idiom: `return;` at the end of the first arm (puts MWCC's branch cleanup in the mode that keeps the dead originals of delay-slot copies); FUN_000ff5b0 takes the byte count as 3rd arg and FUN_0029a584 the error code as 2nd arg, both dropped by Ghidra. */
extern char DAT_002cb984[];
extern char DAT_002cb95c[];
extern int FUN_002b77a8(int, int *);
extern int FUN_002b7748(int, char *, int);
extern int FUN_000ff5b0(int, char *, int);
extern void FUN_00011090(char *, char *, int);
extern void FUN_002b7958(int);
extern void FUN_0029a584(char *, ...);

void FUN_0029bb48(char *param_1)
{
    int left[2];
    int r;
    int e;
    int n;

    if (*(int *)(param_1 + 0x1582c) > 0) {
        r = FUN_000ff5b0(*(int *)(param_1 + 0x1c), (char *)(*(int *)(param_1 + 0x15828)), *(int *)(param_1 + 0x1582c));
        *(int *)(param_1 + 0x1582c) = *(int *)(param_1 + 0x1582c) - r;
        *(int *)(param_1 + 0x15828) = *(int *)(param_1 + 0x15828) + r;
        if (*(int *)(param_1 + 0x1582c) == 0) {
            e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
            if (e != 0)
                FUN_0029a584(DAT_002cb95c, e);
        }
        return;
    }
    {
        r = FUN_002b77a8(*(int *)(param_1 + 0xc), left);
        if (r == 0) {
            n = left[0];
            if (n < 0) {
                FUN_0029a584(DAT_002cb984, n);
                FUN_002b7958(100);
                e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
                if (e != 0)
                    FUN_0029a584(DAT_002cb95c, e);
            } else {
                *(int *)(param_1 + 0x7420) = n;
                r = FUN_000ff5b0(*(int *)(param_1 + 0x1c), param_1 + 0x20, n);
                if (r < *(int *)(param_1 + 0x7420)) {
                    *(int *)(param_1 + 0x1582c) = *(int *)(param_1 + 0x7420) - r;
                    *(int *)(param_1 + 0x15828) = (int)(param_1 + 0xe428);
                    FUN_00011090(param_1 + 0xe428, param_1 + r + 0x20,
                                 *(int *)(param_1 + 0x1582c));
                } else {
                    e = FUN_002b7748(*(int *)(param_1 + 0xc), param_1 + 0x20, 0x7400);
                    if (e != 0)
                        FUN_0029a584(DAT_002cb95c, e);
                }
            }
        }
    }
}
