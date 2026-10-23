/* HSTMATCH module=EBOOT.BIN start=0x00199ca0 end=0x00199e0c symbol=FUN_00199ca0 lang=c++ */
extern "C" {
extern char DAT_002e1a20[];
extern char DAT_002e1a40[];
extern char DAT_002e1a4c[];
extern float DAT_002bc410, DAT_002bc414, DAT_002bc418, DAT_002bc41c, DAT_002bc420, DAT_002bc424, DAT_002bc428, DAT_002bc42c, DAT_002bc430, DAT_002bc434, DAT_002bc438, DAT_002bc43c, DAT_002bc440, DAT_002bc444, DAT_002bc448, DAT_002bc44c;
extern void FUN_00104118(int, char *, int);
extern void FUN_00103540(float, int);
extern int FUN_001039d8(int, char *, int);
extern int FUN_001026b8(int, char *);
extern void FUN_00103628(int, int);
}

struct VC_00199ca0 { virtual void v0(); virtual void v1(); virtual void v2();
                     virtual void v3(); virtual void v4(); virtual void v5();
                     virtual void v6(float); };

extern "C" void FUN_00199ca0(int param_1)
{
    int iVar4;
    int *piVar5;
    float uVar1, uVar2, uVar3;

    FUN_00104118(param_1, DAT_002e1a20, 0);
    FUN_00103540(3000.0f, param_1);
    iVar4 = FUN_001039d8(param_1, DAT_002e1a40, 0);
    *(int *)(param_1 + 0x58) = iVar4;
    iVar4 = FUN_001026b8(iVar4, DAT_002e1a4c);
    piVar5 = *(int **)(iVar4 + 0x20);
    *(int **)(param_1 + 0x54) = piVar5;
    ((VC_00199ca0 *)piVar5)->v6(3001.0f);
    struct Row4_00199ca0 { float v[4]; };
    *(Row4_00199ca0 *)(param_1 + 0x60) = *(Row4_00199ca0 *)(((float *)&DAT_002bc410) + 0);
    *(Row4_00199ca0 *)(param_1 + 0x70) = *(Row4_00199ca0 *)(((float *)&DAT_002bc410) + 4);
    *(Row4_00199ca0 *)(param_1 + 0x80) = *(Row4_00199ca0 *)(((float *)&DAT_002bc410) + 8);
    *(Row4_00199ca0 *)(param_1 + 0x90) = *(Row4_00199ca0 *)(((float *)&DAT_002bc410) + 12);
    *(int *)(param_1 + 0x90) = 0xc3700000;
    *(int *)(param_1 + 0x94) = 0xc3080000;
    *(int *)(param_1 + 0x5c) = 0;
    FUN_00103628(param_1, 1);
}
// NEAR MISS (lane fm3): 54 of 91 words. Block-by-block the code is right: FUN_00104118(p, "…lay…",
// 0), FUN_00103540(3000.0f, p) (retail's 0x453b8000 IS 3000.0f - passing the integer 0x453b8000
// silently becomes 3000.0f only if written as a float literal), FUN_001039d8 -> +0x58,
// FUN_001026b8 -> +0x20 -> +0x54, the virtual call at vtable slot 0x20 with 3001.0f (0x453b9000!)
// in $f12, then four 4-float copies from 0x2bc410..0x2bc44c into +0x60..+0x9c, then
// `*(int*)(p+0x90) = 0xc3700000; *(int*)(p+0x94) = 0xc3080000; *(int*)(p+0x5c) = 0;
// FUN_00103628(p,1);`. What still differs is the copy: retail issues all four loads of a group
// (f3=first, f2, f1, f0=last, i.e. ascending) and then the four swc1, each load with its OWN
// `lui 0x2c` + negative displacement. Plain per-field float assignments give load/store pairs;
// three C float temps give the batching but in temp-assignment order; a 16-byte struct copy batches
// ascending but reuses one base register (`lwc1 8(v1)`), which retail does not.
// near miss from lane fm3 (unreviewed)
