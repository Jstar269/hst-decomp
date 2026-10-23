/* HSTMATCH module=EBOOT.BIN start=0x0015371c end=0x00153818 symbol=FUN_0015371c lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc7ac[];
extern int DAT_003083cc;
extern int DAT_00308a20;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cc190(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_4 {
    virtual void reset(int);
    virtual int run(int, float);
};

extern "C" int *FUN_0015371c(int param_1, int param_2, float param_3)
{
    VC_4 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc7ac, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cc190(DAT_0034a114, *(int *)(param_2 + 0xc), *(int *)(param_1 + 0xc), *(int *)(param_1 + 8));
    piVar1 = (VC_4 *)FUN_00000bcc(4);
    if (piVar1 != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308a20;
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
// NEAR MISS (lane fm3): 63/63 words, 22 differ -- fifth sibling of the 0x0014fdc0 family, same
// three deltas. C++ virtual class; +8 = reset(int), +0xc = run(int,float); vtable DAT_00308a20.
// near miss from lane fm3 (unreviewed)
