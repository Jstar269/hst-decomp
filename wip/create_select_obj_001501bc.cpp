/* HSTMATCH module=EBOOT.BIN start=0x001501bc end=0x001502b8 symbol=FUN_001501bc lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc3a4[];
extern int DAT_003083cc;
extern int DAT_00308f64;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cb980(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_2 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_001501bc(int param_1, int param_2, float param_3)
{
    VC_2 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc3a4, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cb980(DAT_0034a114, *(int *)(param_2 + 0xc), *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    if ((piVar1 = (VC_2 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308f64;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
// NEAR (63 words, 2 differ): body, allocation, virtual call, and reset/return tail match. The only
// differences are the mixed-parameter prologue pair: retail saves f20 before the zero-test and
// moves a1 to s0 in its delay slot; this source moves a1 first and puts mov.s in that slot. Using
// run(float,int) and passing (param_3,param_2) matches the virtual-call setup. The allocation-result
// assignment and duplicate nonnull test are needed for the retail allocation and reset branches.
// improved by lane lnm1 (unreviewed): 22 -> 2 differing words
