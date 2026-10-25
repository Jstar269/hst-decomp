/* HSTMATCH module=EBOOT.BIN start=0x0014ffc0 end=0x001500b8 symbol=FUN_0014ffc0 lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc394[];
extern int DAT_003083cc;
extern int DAT_00308f98;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int);
extern void FUN_001cbccc(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_0 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_0014ffc0(int param_1, int param_2, float param_3)
{
    VC_0 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc394, *(int *)(param_1 + 8));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cbccc(DAT_0034a114, *(int *)(param_2 + 0xc), *(int *)(param_1 + 8), 0xffffffff);
    if ((piVar1 = (VC_0 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308f98;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        piVar1 = piVar1 == 0 ? 0 : (piVar1->reset(1), (VC_0 *)0);
    }
    return (int *)piVar1;
}
// NEAR (62/62 words, 12 differ). Using run(float, int) and calling it with
// (param_3, param_2) matches the virtual-call argument setup. Remaining: retail
// saves $f20 before s0; the candidate reverses them. The return/reset tail still
// has different branch layout. Virtual calls remain necessary; a virtual
// destructor shifts the method slots. FUN_0014d044's second argument is float.
// Earlier if/else and shared-return tail variants did not improve the wip.
// improved by lane lnm1 (unreviewed): 22 -> 12 differing words
