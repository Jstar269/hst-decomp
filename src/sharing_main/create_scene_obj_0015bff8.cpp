/* HSTMATCH module=hstp_trans_main.prx start=0x0015bff8 end=0x0015c0f0 symbol=FUN_0015bff8 lang=c++ */
/* Hand-written reconstruction from the disassembly (same code as the EBOOT sibling src/eboot/create_scene_obj_0014ffc0.cpp with this module's addresses substituted); exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003e9734;
extern int DAT_003f344c;
extern char DAT_0038387c[];
extern int DAT_003b1698;
extern int DAT_003b2264;
extern void FUN_00158b2c(int, int);
extern void FUN_0015bb68(char *, int);
extern void FUN_001da430(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_0 {
    virtual void reset(int);
    virtual int run(float, int);
};

extern "C" int *FUN_0015bff8(int param_1, int param_2, float param_3)
{
    VC_0 *piVar1;
    int iVar2;

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2, param_2);
        FUN_0015bb68(DAT_0038387c, *(int *)(param_1 + 8));
    }
    if (DAT_003e9734 != 0) {
        return 0;
    }
    FUN_001da430(DAT_003f344c, *(int *)(param_2 + 0xc), *(int *)(param_1 + 8), 0xffffffff);
    if ((piVar1 = (VC_0 *)FUN_00000bcc(4)) != 0) {
        *(int *)piVar1 = (int)&DAT_003b1698;
        *(int *)piVar1 = (int)&DAT_003b2264;
    }
    iVar2 = piVar1->run(param_3, param_2);
    if (iVar2 != 0) {
        if (piVar1 != 0 && piVar1 != 0) piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
