/* HSTMATCH module=EBOOT.BIN start=0x001e2c84 end=0x001e2da8 symbol=FUN_001e2c84 lang=c++ */
/* Hand-written reconstruction (external matching lane). Notes: a virtual call to retail's slot 0xc
   must be written as the SECOND declared virtual (mwcc puts declared virtual #0 at vtable offset 8
   and #1 at 0xc in this build), and the C++ TU needs every extern inside `extern "C" { }` or hstmatch
   reports MISSING_SYMBOLS with the mangled names. FUN_001e4b4c's second argument is a float 0.0f
   (mtc1 zero,$f12), not an int. The score pair repeats init_score_pair_001e29e0 with DAT read first
   in both arms. Exact match verified; names and types await human review. */
extern "C" {
extern int DAT_002eb9a0;
extern unsigned char DAT_003417b8;
extern void FUN_000ffb3c(int, int);
extern void FUN_001e09dc(int, int);
extern void FUN_001e2694();
extern void FUN_001e30a8(int, int);
extern void FUN_001e4b4c(int, float);
}

struct Obj_001e2c84 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Sub_001e2c84 {
    virtual void w0();
    virtual void w1(int);
    virtual void w2();
    virtual void w3();
};

extern "C" void FUN_001e2c84(int param_1)
{
    int iVar1;
    int iVar2;
    Sub_001e2c84 *piVar3;

    FUN_001e2694();
    FUN_001e09dc(param_1, 1);
    ((Obj_001e2c84 *)*(int *)(param_1 + 0x3c))->v1();
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x60), 0);
    if (DAT_003417b8 == 1) {
        iVar2 = DAT_002eb9a0 + 1;
        iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar1 + 0x24) = iVar2;
        *(int *)(iVar1 + 0x28) = iVar2;
    } else {
        iVar2 = DAT_002eb9a0;
        iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x60);
        *(int *)(iVar1 + 0x24) = iVar2;
        *(int *)(iVar1 + 0x28) = iVar2;
    }
    piVar3 = *(Sub_001e2c84 **)(*(int *)(param_1 + 0x3c) + 0x58);
    piVar3->w1(1);
    piVar3 = *(Sub_001e2c84 **)(*(int *)(param_1 + 0x3c) + 0x5c);
    piVar3->w1(0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x7c), 0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x84), 0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x80), 0);
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x3c) + 0x88), 0);
    FUN_001e30a8(param_1, 1);
    FUN_001e4b4c(param_1, 0.0f);
}
