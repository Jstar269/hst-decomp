/* HSTMATCH module=EBOOT.BIN start=0x0014ffc0 end=0x001500b8 symbol=FUN_0014ffc0 lang=c++ */
extern "C" {
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern char DAT_002dc394[];
extern int DAT_003083cc;
extern int DAT_00308f98;
extern void FUN_0014d044(int, float);
extern void FUN_0014fd94(char *, int);
extern void FUN_001cbccc(int, int, int, int);
extern int FUN_00000bcc(int);
}

struct VC_0 {
    virtual void reset(int);
    virtual int run(int, float);
};

extern "C" int *FUN_0014ffc0(int param_1, int param_2, float param_3)
{
    VC_0 *piVar1;
    int iVar2;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2, param_3);
        FUN_0014fd94(DAT_002dc394, *(int *)(param_1 + 8));
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cbccc(DAT_0034a114, *(int *)(param_2 + 0xc), *(int *)(param_1 + 8), 0xffffffff);
    piVar1 = (VC_0 *)FUN_00000bcc(4);
    if (piVar1 != 0) {
        *(int *)piVar1 = (int)&DAT_003083cc;
        *(int *)piVar1 = (int)&DAT_00308f98;
    }
    iVar2 = piVar1->run(param_2, param_3);
    if (iVar2 != 0) {
        if (piVar1 == 0) {
            return 0;
        }
        piVar1->reset(1);
        return 0;
    }
    return (int *)piVar1;
}
// NEAR MISS (lane fm3): 62/62 words, 22 differ. Shape is right; the three remaining gaps are
//   (a) prologue order: retail emits `mov.s $f20,$f12` BEFORE `move s0,a1`;
//   (b) retail tests the alloc result (`beqz v0` with `move s1,v0` in the delay) where we get
//       `move s1,v0; beqzl s1` plus a hoisted `lw t9,0(s1)`;
//   (c) the `if (piVar1 != 0) piVar1->reset(1);` arm: retail lays the call inline with
//       `beqz s1,<return 0>` while we get the inverted `bnezl s1` + out-of-line call.
// Findings worth keeping: this is a C++ TU -- the two indirect calls MUST be written as virtual
// method calls on a class (they come out as `lw t9,0(s1); lw t9,0xc(t9); jalr t9`, which the C
// function-pointer spelling cannot produce, it gives v0), the class must have NO virtual destructor
// (declaring one shifts the methods to +0x10/+0x14), method #0 (+8) takes the int flag 1 and
// method #1 (+0xc) takes (int, float) and returns int. FUN_0014d044's second argument is a float
// (the caller's param_3 is in $f12, saved to $f20). Tried and rejected for the tail: if/else forms,
// duplicated `return 0`, `piVar1 = 0` + single return (63 words).
// near miss from lane fm3 (unreviewed)
