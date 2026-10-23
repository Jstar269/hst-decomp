/* HSTMATCH module=EBOOT.BIN start=0x001549e4 end=0x00154b44 symbol=FUN_001549e4 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc978[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int, int, int, int, long long);
extern long long FUN_00020f5c(float);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
extern void FUN_00287b30(int, int, int, int, float);
extern void FUN_00287c60(int, int, int, int, float);

int FUN_001549e4(int param_1, int param_2)
{
    int id;
    int result;
    int v;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc978, *(int *)(param_1 + 8),
                     *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x1c),
                     *(int *)(param_1 + 0x10), *(int *)(param_1 + 0x18),
                     FUN_00020f5c(*(float *)(param_1 + 0x14)));
    }
    id = *(int *)(param_1 + 8);
    if (id == 1) {
        v = *(int *)(param_1 + 0xc);
        result = *(int *)(param_2 + 0xc);
        if (v == -1) {
            result = (int)DAT_0034a118;
            if (DAT_0034a118 != 0)
                result = (int)DAT_0034a118 + 0xe0;
        }
        if (v >= 0) {
            if (v < 100)
                result = *(int *)(*(int *)(DAT_0034a114 + 0x4c) + v * 4);
            else if (v < 1000)
                result = FUN_001c6f70(DAT_0034a114, v, 0);
            else
                result = FUN_001c70c0(DAT_0034a114);
        }
        FUN_00287c60(result, *(int *)(param_1 + 0x10), *(int *)(param_1 + 0x1c),
                     *(int *)(param_1 + 0x18), *(float *)(param_1 + 0x14));
        return 0;
    }
    if (id == 0) {
        FUN_00287b30(*(int *)(param_2 + 0xc), *(int *)(param_1 + 0x10),
                     *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x18),
                     *(float *)(param_1 + 0x14));
    }
    return 0;
}
// near miss: 80/88 words. Body recovered but MWCC orders the two id blocks differently: retail
// emits `beql id,1,block1; beqzl id,0,block0` with BOTH blocks out of line (id0 first, id1
// second), ours falls through into the id==1 block. The lookup chain also carries the family's
// known `bgezl a1` duplicated-guard loss (ours `bltzl`). Facts pinned: the debug tail calls
// FUN_0014fd94 with (str, +8, +0xc, +0x1c, +0x10, +0x18, FUN_00020f5c(+0x14)) -- note +0x1c is
// the FOURTH argument, ahead of +0x10/+0x18; FUN_00287b30(p2+0xc, +0x10, +0xc, +0x18, f+0x14)
// for id 0 and FUN_00287c60(result, +0x10, +0x1c, +0x18, f+0x14) for id 1; string 0x2dc978.
// near miss from lane fm6 (unreviewed)
