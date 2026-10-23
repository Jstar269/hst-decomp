/* HSTMATCH module=EBOOT.BIN start=0x00155834 end=0x0015592c symbol=FUN_00155834 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dcb18[];
extern char *DAT_0034a118;
extern char *DAT_0034a114;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
extern void FUN_001cd5a0(void *, int);

int FUN_00155834(int param_1, int param_2)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dcb18, *(int *)(param_1 + 8));
    }
    id = *(int *)(param_1 + 8);
    result = *(int *)(param_2 + 0xc);
    if (id == -1) {
        if (DAT_0034a118 == 0)
            result = 0;
        else
            result = (int)DAT_0034a118 + 0xe0;
    } else if (id >= 0) {
        if (id < 100)
            result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = FUN_001c6f70(DAT_0034a114, id, 0);
        else
            result = FUN_001c70c0(DAT_0034a114);
    }
    FUN_001cd5a0(DAT_0034a114, result);
    return 0;
}
// near miss: 57/62 words (41 differ), same shape as 0x154e30: retail lays the id == -1 block out first
// with a `b end` jump-over, sets the result register in the beqzl delay (`move a1,v0`), then guards the
// id >= 0 chain with `bgezl`; ours falls through and emits bltz/bnezl forms. Ruled out: if/else vs
// conditional assignment in the -1 branch, `0 <= id`.
// near miss from lane fm6 (unreviewed)
