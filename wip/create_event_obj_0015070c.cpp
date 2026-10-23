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
    virtual int run(int, float);
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
    piVar1 = (VC_3 *)FUN_00000bcc(4);
    if (piVar1 != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308ee0;
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
// NEAR MISS (lane fm3): 63/63 words, 22 differ -- fourth sibling of the 0x0014fdc0 family, same
// three deltas (see wip/create_scene_obj_0014fdc0.cpp). C++ virtual class needed; +8 = reset(int),
// +0xc = run(int,float); vtable DAT_00308ee0.
// near miss from lane fm3 (unreviewed)
