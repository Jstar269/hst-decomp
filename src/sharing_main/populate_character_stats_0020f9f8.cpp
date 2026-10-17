/* HSTMATCH module=hstp_trans_main.prx start=0x0020f9f8 end=0x0020fca8 symbol=FUN_0020f9f8 lang=c++ */
/* Clone of src/eboot/populate_character_stats_00201228.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a5/v18c/FUN_0020f9f8.cpp (tag: a5) */
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
extern char DAT_00397220;
extern char *DAT_003f3474;
extern int FUN_00014d64(void *, void *);
extern void FUN_000dba70(void *);
extern void FUN_000dbb20(void *, int);
extern void FUN_00105470(int, int);
extern void FUN_00113a50(void *);
extern Param2Obj *FUN_0019fc84(int);
extern int FUN_0020d1e0(int, int, int);
extern void FUN_00212e50(void *, int, int, int, int, int, int, int, int);
extern int FUN_00227284(unsigned int, int, void *, int, void *);
extern void FUN_002273b8(int *, unsigned int, int, void *);

void FUN_0020f9f8(int param_1, Param2Obj *param_2, int param_3, int param_4, int param_5)
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

    iVar4 = *(int *)(DAT_003f3474 + 0x4c);
    FUN_000dba70(auStack_c8);
    FUN_00212e50(auStack_c8, param_2->s[0], param_2->s[1], param_2->s[2], param_2->s[3],
                 param_2->s[4], param_2->s[5], param_2->pairs[iVar4].a,
                 param_2->pairs[iVar4].b);
    uVar8 = param_2->s[0];
    bVar1 = 0;
    if (FUN_00014d64(&param_2->s34, &DAT_00397220) != 0) {
        bVar1 = 1;
        uVar8 = param_2->s10;
        s2_ptr = &param_2->s34;
    } else {
        s2_ptr = &FUN_0019fc84(param_2->s[0])->s34;
    }
    iVar5 = 0;
    iVar4 = param_1 + param_3 * 0x14;
    do {
        iVar2 = FUN_00227284(uVar8, bVar1, s2_ptr, iVar5, auStack_c8);
        piVar7 = (int *)(iVar4 + 0x30);
        iVar5++;
        iVar4 += 0x14;
        *(int *)(*piVar7 + 0x24) = *(int *)(*piVar7 + 0x28) + iVar2;
    } while (iVar5 < 5);
    FUN_002273b8(local_d8, uVar8, bVar1, s2_ptr);
    uVar8 = 0;
    piVar7 = local_d8;
    do {
        piVar6 = (int *)(param_1 + (param_4 + (int)uVar8) * 0x14 + 0x30);
        iVar4 = param_1 + (param_5 + (int)uVar8) * 0xc + 0x648;
        iVar2 = *piVar7;
        if (iVar2 >= 0 && iVar2 < 0xd) {
            FUN_00105470(*piVar6, 0);
            *(int *)(*piVar6 + 0x24) = *(int *)(*piVar6 + 0x28);
            ((VC *)*(int *)(iVar4 + 4))->m(0);
            int uVar3 = FUN_0020d1e0(0xb, 3, *piVar7);
            int obj = *(int *)(iVar4 + 4);
            *(int *)(obj + 0xf8) = uVar3;
            *(int *)(obj + 0x138) = 1;
            FUN_00113a50((void *)obj);
        } else if (iVar2 >= 0xe && iVar2 < 0x1b) {
            FUN_00105470(*piVar6, 0);
            *(int *)(*piVar6 + 0x24) = *(int *)(*piVar6 + 0x28) + 1;
            ((VC *)*(int *)(iVar4 + 4))->m(0);
            int uVar3 = FUN_0020d1e0(0xb, 3, *piVar7 - 0xe);
            int obj = *(int *)(iVar4 + 4);
            *(int *)(obj + 0xf8) = uVar3;
            *(int *)(obj + 0x138) = 1;
            FUN_00113a50((void *)obj);
        } else {
            FUN_00105470(*piVar6, 1);
            ((VC *)*(int *)(iVar4 + 4))->m(1);
        }
        uVar8++;
        piVar7++;
    } while ((int)uVar8 < 4);
    FUN_000dbb20(auStack_c8, -1);
}
}
