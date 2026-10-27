/* HSTMATCH module=hstp_trans_main.prx start=0x0015c744 end=0x0015c840 symbol=FUN_0015c744 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT sibling src/eboot/create_select_obj_001501bc.cpp, same instruction shape: addresses substituted, the two command fields passed in the order +0xc, +8); exact match verified; names and types await human review. Matching idiom: FUN_00158b2c takes a second int in a1 that it ignores; FUN_00158b2c(param_2, param_2) keeps a1 live at the first call, which moves param_2's home copy into the beqz delay slot. */
extern "C" {
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003e9734;
extern int DAT_003f344c;
extern char DAT_003838e0[];   /* "EventText [%d, %s]\n" */
extern int DAT_003b1698;
extern int DAT_003b21ac;
extern void FUN_00158b2c(int, int);
extern void FUN_0015bb68(char *, int, int);
extern void FUN_001da640(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_2 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_0015c744(int param_1, int param_2, float param_3)
{
    VC_2 *piVar1;
    int iVar2;

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2, param_2);
        FUN_0015bb68(DAT_003838e0, *(int *)(param_1 + 0xc), *(int *)(param_1 + 8));
    }
    if (DAT_003e9734 != 0) {
        return 0;
    }
    FUN_001da640(DAT_003f344c, *(int *)(param_2 + 0xc), *(int *)(param_1 + 0xc), *(int *)(param_1 + 8));
    if ((piVar1 = (VC_2 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003b1698;
        *(int *)piVar1 = (int)&DAT_003b21ac;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
