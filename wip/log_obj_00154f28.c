/* HSTMATCH module=EBOOT.BIN start=0x00154f28 end=0x00155040 symbol=FUN_00154f28 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dca38[];
extern char *DAT_0034a118;
extern char *DAT_0034a114;
extern void FUN_0014d044(int);
extern long long FUN_00020f5c(float);
extern void FUN_0014fd94(char *, int, int, int, long long, int);
extern int FUN_001c6f70(void *);
extern int FUN_001c70c0(void *, int, int);
extern void FUN_00288470(int, int, int);

int FUN_00154f28(int param_1, int param_2, int param_3, int param_4)
{
    int id;
    int result;

    if (DAT_003402f0 != 0) {
        long long v;
        FUN_0014d044(param_2);
        v = FUN_00020f5c(*(float *)(param_1 + 0xc));
        FUN_0014fd94(DAT_002dca38, *(int *)(param_1 + 8), *(int *)(param_1 + 0x14), param_4, v,
                     *(int *)(param_1 + 0x10));
    }
    id = *(int *)(param_1 + 8);
    result = *(int *)(param_2 + 0xc);
    if (id == -1) {
        result = (int)DAT_0034a118;
        if (DAT_0034a118 != 0)
            result = (int)DAT_0034a118 + 0xe0;
    } else if (id >= 0) {
        if (id < 100)
            result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = FUN_001c6f70(DAT_0034a114);
        else
            result = FUN_001c70c0(DAT_0034a114, id, *(int *)(param_1 + 0x14));
    }
    if (result != 0)
        FUN_00288470(*(int *)(param_1 + 0xc), result, *(int *)(param_1 + 0x10));
    return 0;
}
// near miss: 69/70 words (68 differ). Shape is right (same id lookup chain as 0x154e30/0x155834,
// float arg to FUN_00020f5c, long long result passed as two words); ours saves one extra s-register
// (s2 = param_2) so the frame is 16 bytes with three saves. Ruled out: call inline in the arg list vs
// a named long long temp (same allocation).
// near miss from lane fm6 (unreviewed)
