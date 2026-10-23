/* HSTMATCH module=EBOOT.BIN start=0x00153f54 end=0x0015405c symbol=FUN_00153f54 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc838[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, long long);
extern long long FUN_00020f5c(float);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);

int FUN_00153f54(int param_1, int param_2)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc838, *(int *)(param_1 + 8),
                     FUN_00020f5c(*(float *)(param_1 + 0xc)));
    }
    id = *(int *)(param_1 + 8);
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
            result = FUN_001c70c0(DAT_0034a114);
    }
    if (result != 0)
        *(float *)(result + 0x50) = *(float *)(param_1 + 0xc);
    return 0;
}
// near miss: 60/66 words, 39 differ -- everything through +0x6c is instruction-for-instruction
// retail. Two source facts were needed: FUN_0014d044 takes only the int (no float; the lone
// lwc1 belongs to FUN_00020f5c), and the id < 1000 arm must keep the call's return
// (`result = FUN_001c6f70(...)`) or result is forced into s1 across the call and the whole
// chain changes colour. The dead-looking `lw v0,12(s1)` in the bne delay is real: it is
// result's initial value, used by the tail when id < 0. Remaining delta is the documented
// 0x154xxx family `bgezl` guard (retail duplicates slti at,a1,100 into the likely-branch
// delay and at the target; ours emits `bltz` + a single copy) -- 6 words, same semantics.
// near miss from lane fm6 (unreviewed)
