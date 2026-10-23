/* HSTMATCH module=EBOOT.BIN start=0x001543d0 end=0x001544ec symbol=FUN_001543d0 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc8c4[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *, int);
extern void FUN_00293764(int, int);

int FUN_001543d0(int param_1, int param_2)
{
    int id;
    int result;
    int cur;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc8c4, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    id = *(int *)(param_1 + 0xc);
    result = *(int *)(param_2 + 0xc);
    if (id == -1) {
        result = (int)DAT_0034a118;
        if (DAT_0034a118 != 0)
            result = (int)DAT_0034a118 + 0xe0;
    }
    if (id >= 0) {
        if (id < 100)
            result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = FUN_001c6f70(DAT_0034a114, id, 0);
        else
            result = FUN_001c70c0(DAT_0034a114, id);
    }
    cur = FUN_001c70c0(DAT_0034a114, *(int *)(param_1 + 8));
    if (cur != 0 && result != 0)
        FUN_00293764(cur, result);
    return 0;
}
// near miss: 65/71 words -- the sixth member of the family with the same six-word delta, and this
// one pins the delta down completely: from the tail join onwards ours and retail are
// instruction-for-instruction identical (beqzl v0 -> epilogue, `lw ra` in its delay, beqz result,
// FUN_00293764(cur, result)). The only difference is retail's `bgezl a1` guard. Source facts:
// the id lives at +0xc here (not +8), FUN_001c70c0 takes (manager, x) -- the arm passes id, the
// join passes param_1[2] -- and the keep-the-return rule applies to the id < 1000 arm.
// near miss from lane fm6 (unreviewed)
