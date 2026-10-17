/* HSTMATCH module=EBOOT.BIN start=0x00201228 end=0x002014d8 symbol=FUN_00201228 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a5/v18c/FUN_00201228.cpp (tag: a5) */
struct VC {
    virtual void d0();
    virtual void m(int);
};

struct Pair3 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
};

struct Param2Obj {
    short s[6];
    char pad12[0x20 - 12];
    unsigned short s10;
    char pad22[0x68 - 0x22];
    short s34;
    char pad6a[0x7e - 0x6a];
    Pair3 pairs[4];
};

extern "C" {
extern char DAT_002ef198;
extern char *DAT_0034a13c;
extern int FUN_00014d64(void *, void *);
extern void FUN_000d7d80(void *);
extern void FUN_000d7e30(void *, int);
extern void FUN_000ffb3c(int, int);
extern void FUN_0010d4a8(void *);
extern Param2Obj *FUN_00193474(int);
extern int FUN_001fea10(int, int, int);
extern void FUN_002045e8(void *, int, int, int, int, int, int, int, int);
extern int FUN_002181a4(unsigned int, int, void *, int, void *);
extern void FUN_002182a0(int *, unsigned int, int, void *);

void FUN_00201228(int param_1, Param2Obj *param_2, int param_3, int param_4, int param_5)
{
    int bVar1;
    unsigned int uVar8;
    void *s2_ptr;
    int iVar5;
    int iVar4;
    int *piVar7;
    int *piVar6;
    int iVar2;
    char auStack_c8[200];
    int local_d8[4];

    iVar4 = *(int *)(DAT_0034a13c + 0x4c);
    FUN_000d7d80(auStack_c8);
    FUN_002045e8(auStack_c8, param_2->s[0], param_2->s[1], param_2->s[2], param_2->s[3],
                 param_2->s[4], param_2->s[5], param_2->pairs[iVar4].a,
                 param_2->pairs[iVar4].b);
    uVar8 = param_2->s[0];
    bVar1 = 0;
    if (FUN_00014d64(&param_2->s34, &DAT_002ef198) != 0) {
        bVar1 = 1;
        uVar8 = param_2->s10;
        s2_ptr = &param_2->s34;
    } else {
        s2_ptr = &FUN_00193474(param_2->s[0])->s34;
    }
    iVar5 = 0;
    iVar4 = param_1 + param_3 * 0x14;
    do {
        iVar2 = FUN_002181a4(uVar8, bVar1, s2_ptr, iVar5, auStack_c8);
        piVar7 = (int *)(iVar4 + 0x30);
        iVar5++;
        iVar4 += 0x14;
        *(int *)(*piVar7 + 0x24) = *(int *)(*piVar7 + 0x28) + iVar2;
    } while (iVar5 < 5);
    FUN_002182a0(local_d8, uVar8, bVar1, s2_ptr);
    uVar8 = 0;
    piVar7 = local_d8;
    do {
        piVar6 = (int *)(param_1 + (param_4 + (int)uVar8) * 0x14 + 0x30);
        iVar4 = param_1 + (param_5 + (int)uVar8) * 0xc + 0x648;
        iVar2 = *piVar7;
        if (iVar2 >= 0 && iVar2 < 0xd) {
            FUN_000ffb3c(*piVar6, 0);
            *(int *)(*piVar6 + 0x24) = *(int *)(*piVar6 + 0x28);
            ((VC *)*(int *)(iVar4 + 4))->m(0);
            int uVar3 = FUN_001fea10(0xb, 3, *piVar7);
            int obj = *(int *)(iVar4 + 4);
            *(int *)(obj + 0xf8) = uVar3;
            *(int *)(obj + 0x138) = 1;
            FUN_0010d4a8((void *)obj);
        } else if (iVar2 >= 0xe && iVar2 < 0x1b) {
            FUN_000ffb3c(*piVar6, 0);
            *(int *)(*piVar6 + 0x24) = *(int *)(*piVar6 + 0x28) + 1;
            ((VC *)*(int *)(iVar4 + 4))->m(0);
            int uVar3 = FUN_001fea10(0xb, 3, *piVar7 - 0xe);
            int obj = *(int *)(iVar4 + 4);
            *(int *)(obj + 0xf8) = uVar3;
            *(int *)(obj + 0x138) = 1;
            FUN_0010d4a8((void *)obj);
        } else {
            FUN_000ffb3c(*piVar6, 1);
            ((VC *)*(int *)(iVar4 + 4))->m(1);
        }
        uVar8++;
        piVar7++;
    } while ((int)uVar8 < 4);
    FUN_000d7e30(auStack_c8, -1);
}
}
