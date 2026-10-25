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
    virtual int run(float, int);
};

extern "C" int *FUN_0014fdc0(void *param_1, int param_2, float param_3)
{
    VC_1 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc380, *(int *)((char *)param_1 + 8), *(int *)((char *)param_1 + 0xc));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cb860(DAT_0034a114, *(int *)((char *)param_1 + 8), *(int *)((char *)param_1 + 0xc), 0xffffffff);
    if ((piVar1 = (VC_1 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308fcc;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
// NEAR (63 words, 2 differ): hstmatch shows the entire body and return/reset tail equal to retail;
// only the prologue pair at 0x0014fde0/0x0014fde8 is reversed. Retail saves the float first, then
// puts move s0,a1 in the beqz delay slot; this source saves s0 first and puts mov.s in that slot.
// Tried the alternate virtual-method parameter order, return type VC_1*, register and local copies,
// pointer/number parameter types, helper parameter order, and declaration-order changes; none moved
// the prologue pair. The duplicate nonnull condition is required for the retail null-check/reset tail.
// Final revisit: an inline C++ member wrapper around the body regressed to 14 differences; preserve this 2-word free-function form.
// improved by lane lnm1 (unreviewed): 22 -> 2 differing words
