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
    virtual int run(int, float);
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
    piVar1 = (VC_2 *)FUN_00000bcc(4);
    if (piVar1 != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308f64;
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
// NEAR MISS (lane fm3): 63/63 words, 22 differ -- third sibling of the same family; the deltas are
// exactly the ones noted in wip/create_scene_obj_0014fdc0.cpp ((a) mov.s/$f20 before the int param
// copy, (b) test the alloc result vs our copy to s1, (c) inline vs out-of-line `reset(1)` arm).
// C++ virtual class required (no virtual dtor; +8 = reset(int), +0xc = run(int,float)).
// near miss from lane fm3 (unreviewed)
