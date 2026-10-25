/* HSTMATCH module=EBOOT.BIN start=0x0015070c end=0x00150808 symbol=FUN_0015070c lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc3f8[];
extern int DAT_003083cc;
extern int DAT_00308ee0;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cbedc(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_3 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_0015070c(int param_1, int param_2, float param_3)
{
    VC_3 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc3f8, *(int *)(param_1 + 0xc), *(int *)(param_1 + 8));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cbedc(DAT_0034a114, *(int *)(param_2 + 0xc), *(int *)(param_1 + 0xc), *(int *)(param_1 + 8));
    if ((piVar1 = (VC_3 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308ee0;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
// NEAR (63 words, 2 differ): the allocation, virtual call, and return/reset tail match. Remaining
// differences are the mixed-parameter prologue order at 0x0015072c/0x00150734: retail saves f20
// before the zero-test and moves a1 to s0 in its delay slot; this source saves s0 first and puts
// mov.s in that slot. `run(float,int)` and `(param_3,param_2)` give the retail virtual-call setup.
// The allocation-result assignment and duplicate nonnull test preserve retail's branches.
// improved by lane lnm1 (unreviewed): 22 -> 2 differing words
