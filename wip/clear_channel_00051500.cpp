/* HSTMATCH module=hstp_trans_main.prx start=0x00051500 end=0x000516a0 symbol=FUN_00051500 lang=c++ */

#pragma opt_strength_reduction off

extern "C" {
extern int DAT_003d4584;
extern int DAT_003d458c;
extern int FUN_000045d8(int);
extern int FUN_000049e4(int);
extern void FUN_00004c3c(int, int, int);
extern void FUN_00004f44(void);
extern void FUN_0000511c(int);
extern void FUN_00005174(unsigned int);
extern void FUN_00005188(int);
extern void FUN_00005198(int);
extern void FUN_000051a8(int);
extern void FUN_000051d0(int, int);
extern void FUN_00005294(int, int, int, int);
extern int FUN_0003994c(void *);
extern int FUN_002c77f0(void);

struct Array {
    int *items;
    unsigned int count;
    void Clear() {
        for (unsigned int i = 0; i < count; i++) {
            FUN_000049e4(items[i]);
        }
        int n = (int)count;
        if (n != 0) {
            count -= n;
        }
    }
};

struct MyStruct {
    char pad_0[0x1a0a8];
    Array arr;
    char pad_1[4];
    unsigned char bytes[4];
};

struct Tag {};

void FUN_00051500(struct MyStruct *param_1, int param_2, int param_3, int param_4, Tag = Tag())
{
    FUN_000045d8(0);
    if (param_1->arr.count != 0) {
        param_1->arr.Clear();
    }
    {
        int iVar1 = DAT_003d4584;
        int uVar3 = DAT_003d458c;
        int iVar2 = FUN_002c77f0();
        FUN_00004c3c(uVar3, iVar1 - iVar2, 0x200);
    }
    FUN_000051d0(0x710, 0x778);
    FUN_00005294(0, 0, 0x1e0, 0x110);
    FUN_0000511c(2);
    {
        unsigned int val = *(unsigned char *)((char *)param_1 + 0x1a0b4) |
                          (*(unsigned char *)((char *)param_1 + 0x1a0b5) << 8) |
                          (*(unsigned char *)((char *)param_1 + 0x1a0b6) << 16) |
                          (*(unsigned char *)((char *)param_1 + 0x1a0b7) << 24);
        FUN_00005174(val);
    }
    FUN_00005198(0);
    FUN_00005188(0);
    if (param_4 != 0) {
        FUN_000051a8(23);
    } else {
        FUN_000051a8(22);
    }
    FUN_000049e4(FUN_0003994c(param_1));
    FUN_00004f44();
}
}
// Near miss: 13 words differ out of 104 (down from 101 differing words in mechanical draft).
// Exact match from +0x0 to +0x2c (prologue, 48B frame, saved registers ra, s3, s2, s1, s0)
// and from +0xa0 to +0x19c (entire function tail, DAT_003d4584/8c evaluation, unaligned 4-byte loads,
// calls, and epilogue).
// Differs only in 13 words around the vector cleanup loop (+0x30 to +0x9c), where retail uses v0
// rather than a0 for the loop-bound / count register.
// near miss from lane ag6 (unreviewed)
