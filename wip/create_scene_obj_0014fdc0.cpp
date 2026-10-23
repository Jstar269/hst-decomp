/* HSTMATCH module=EBOOT.BIN start=0x0014fdc0 end=0x0014febc symbol=FUN_0014fdc0 lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc380[];
extern int DAT_003083cc;
extern int DAT_00308fcc;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cb860(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_1 {
    virtual void reset(int);
    virtual int run(int, float);
};

extern "C" int *FUN_0014fdc0(int param_1, int param_2, float param_3)
{
    VC_1 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc380, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cb860(DAT_0034a114, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc), 0xffffffff);
    piVar1 = (VC_1 *)FUN_00000bcc(4);
    if (piVar1 != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308fcc;
    }
    iVar2 = piVar1->run(param_2, param_3);
    if (iVar2 != 0) {
        if (piVar1 == 0) {
            return 0;
        }
        piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
// NEAR MISS (lane fm3): 63/63 words, 22 differ -- byte-identical shape to 0014ffc0's near miss and
// the same three deltas: (a) retail emits `mov.s $f20,$f12` before `move s0,a1`; (b) retail tests
// the alloc result (`beqz v0`, `move s1,v0` in the delay) where we copy to s1 first; (c) the
// `if (piVar1 != 0) piVar1->reset(1);` arm is inline in retail (`beqz s1,<return 0>`), out of line
// with `bnezl s1` for us. Same C++ requirement as 0014ffc0 (virtual class, no virtual dtor, method
// #0 = +8 takes the flag, method #1 = +0xc takes (int,float) -> int). `if (piVar1)` instead of
// `if (piVar1 != 0)` changes nothing.
// near miss from lane fm3 (unreviewed)
