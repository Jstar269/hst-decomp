/* HSTMATCH module=hstp_trans_main.prx start=0x0015c1f4 end=0x0015c2f0 symbol=FUN_0015c1f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Same source as the EBOOT function src/eboot/create_select_obj_001501bc.cpp with the Sharing addresses substituted (DAT_003402f0->DAT_003e9630, DAT_002dc3a4->DAT_0038388c, DAT_003403f4->DAT_003e9734, DAT_0034a114->DAT_003f344c, DAT_003083cc->DAT_003b1698, DAT_00308f64->DAT_003b2230, FUN_0014d044->FUN_00158b2c, FUN_0014fd94->FUN_0015bb68, FUN_001cb980->FUN_001da150). Matching idiom: FUN_00158b2c takes a second int in a1 that it ignores; FUN_00158b2c(param_2, param_2) keeps a1 live at the first call, which moves param_2's home copy into the beqz delay slot. */
extern "C" {
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003e9734;
extern int DAT_003f344c;
extern char DAT_0038388c[];
extern int DAT_003b1698;
extern int DAT_003b2230;
extern void FUN_00158b2c(int, int);
extern void FUN_0015bb68(char *, int, int);
extern void FUN_001da150(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_2 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_0015c1f4(int param_1, int param_2, float param_3)
{
    VC_2 *piVar1;
    int iVar2;

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2, param_2);
        FUN_0015bb68(DAT_0038388c, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    if (DAT_003e9734 != 0) {
        return 0;
    }
    FUN_001da150(DAT_003f344c, *(int *)(param_2 + 0xc), *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    if ((piVar1 = (VC_2 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003b1698;
        *(int *)piVar1 = (int)&DAT_003b2230;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
