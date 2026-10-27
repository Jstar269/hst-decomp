/* HSTMATCH module=EBOOT.BIN start=0x0014fdc0 end=0x0014febc symbol=FUN_0014fdc0 lang=c++ data=0x002dc380 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: FUN_0014d044 takes a second int in a1 that it ignores; FUN_0014d044(param_2, param_2) keeps a1 live at the first call, which moves param_2's home copy into the beqz delay slot. Data: its string literals (1 strings, 0x002dc380-0x002dc391) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern int DAT_003083cc;
extern int DAT_00308fcc;
extern void FUN_0014d044(int, int);
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
        FUN_0014d044(param_2, param_2);
        FUN_0014fd94("TextNo [%d, %d]\n", *(int *)((char *)param_1 + 8), *(int *)((char *)param_1 + 0xc));
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
