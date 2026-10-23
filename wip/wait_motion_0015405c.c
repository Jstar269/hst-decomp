/* HSTMATCH module=EBOOT.BIN start=0x0015405c end=0x001541b0 symbol=FUN_0015405c lang=c++ */
/* near miss: 80/85 words, 69 differ. Eighth member of the 0x154xxx look-up family, whose
   `bgezl a1` guard is the known 6-word loss, plus one colouring difference: retail keeps
   param_1 in s1 and coalesces param_2 with the resolved pointer in s0, ours puts param_1 in
   s0. Tail decoded: slot 0x34 (the 11th virtual after a 2-entry dtor prefix) is called twice,
   tested `!= 2` and `!= 3` as `xori/sltiu`, then the object is backed up by 0xe0 and its
   +0x334 field stored. A one-case-plus-default `switch (id)` is wrong here -- it makes the
   -1 arm the fall-through and turns the guard into a plain `bltz`; the two independent `if`s
   are what give retail's `bne` + out-of-line guard. */
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc850[];
extern char *DAT_0034a114;
extern char *DAT_0034a118;
extern void FUN_0014d044(int);
extern void FUN_0014fd94(char *, int, int);
extern int FUN_001c6f70(void *, int, int);
extern int FUN_001c70c0(void *);
}

struct VC {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int m6();
    virtual int m7();
    virtual int m8();
    virtual int m9();
    virtual int m10();
    virtual int m11(int);
};

extern "C" int FUN_0015405c(int param_1, int param_2)
{
    int id;
    VC *result;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94(DAT_002dc850, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
    }
    id = *(int *)(param_1 + 8);
    result = *(VC **)(param_2 + 0xc);
    if (id == -1) {
        result = (VC *)DAT_0034a118;
        if (DAT_0034a118 != 0)
            result = (VC *)(DAT_0034a118 + 0xe0);
    }
    if (id >= 0) {
        if (id < 100)
            result = *(VC **)(*(int *)(DAT_0034a114 + 0x4c) + id * 4);
        else if (id < 1000)
            result = (VC *)FUN_001c6f70(DAT_0034a114, id, 0);
        else
            result = (VC *)FUN_001c70c0(DAT_0034a114);
    }
    if (result == 0)
        return 0;
    if (result->m11(0) != 2 && result->m11(0) != 3)
        return 0;
    if (result != 0)
        result = (VC *)((char *)result - 0xe0);
    *(int *)((char *)result + 0x334) = *(int *)(param_1 + 0xc);
    return 0;
}
// near miss from lane fm6 (unreviewed)
