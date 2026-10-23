/* NEAR 71/71 words, 60 differ (first +0x8, the saved-register list). Best source for
   0x001dd0a4. Same size as retail and the same instruction sequence throughout; what
   differs is one allocator choice that cascades: retail keeps the object pointer in s3
   and runs a separate byte-offset counter in s0 (`move s0,zero` ... `addu v1,s3,s0;
   sw v0,84(v1)`), ours folds base+offset into one pointer held in s4/s0 (`move s0,s4;
   sw v0,84(s0)`) and spends one more saved register. The vtable store must be written
   as `*(int *)param_1 = (int)DAT_00309460` (a symbol) so MWCC emits lui+addiu rather
   than lui+ori. Loop 2 must re-read the slot after the call (`param_1[0x18+i]` three
   times) to get retail's reload before `lw v1,36(v0)`.
   Ruled out: explicit `int off` counter with off += 4, `*(param_1 + 0x15 + i)`,
   `param_1[i + 0x15]`, unsigned index (72 words), int* slot local, and
   block-scoping the two loop counters (`for (int i ...)` in each loop) - all leave
   the five-saved-register allocation unchanged. */
/* HSTMATCH module=EBOOT.BIN start=0x001dd0a4 end=0x001dd1c0 symbol=FUN_001dd0a4 lang=c++ */
struct Entry {
    int idx;
    int arg;
    int out;
};
extern "C" char DAT_002eba1c[];
extern "C" char DAT_00309460[];
extern "C" float DAT_002eb90c;
extern "C" int DAT_002eb930[3];
extern "C" struct Entry DAT_002eb998[11];
extern "C" int DAT_00338c20;
extern "C" void FUN_00102e38(void);
extern "C" void FUN_00104118(int *, char *, int);
extern "C" void FUN_00103540(float, void *);
extern "C" int FUN_001039d8(int *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000ffc3c(int, int);
extern "C" int FUN_000fb874(int);

extern "C" int *FUN_001dd0a4(int *param_1)
{
    int i;

    FUN_00102e38();
    *param_1 = (int)DAT_00309460;
    FUN_00104118(param_1, DAT_002eba1c, 0);
    FUN_00103540(DAT_002eb90c, param_1);
    for (i = 0; i < 3; i++)
        param_1[0x15 + i] = FUN_001039d8(param_1, DAT_002eb930[i], 0);
    for (i = 0; i < 11; i++) {
        param_1[0x18 + i] = FUN_001026b8(((int *)((char *)param_1 + 0x54))[DAT_002eb998[i].idx],
                                        DAT_002eb998[i].arg);
        FUN_000ffc3c(param_1[0x18 + i], 0xffffff00);
        DAT_002eb998[i].out = *(int *)(param_1[0x18 + i] + 0x24);
    }
    param_1[0x23] = FUN_000fb874(DAT_00338c20);
    return param_1;
}
// near miss from lane fm6 (unreviewed)
