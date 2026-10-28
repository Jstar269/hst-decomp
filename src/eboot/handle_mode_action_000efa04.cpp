/* HSTMATCH module=EBOOT.BIN start=0x000efa04 end=0x000efb74 symbol=FUN_000efa04 lang=c++ */
/* Hand-written reconstruction from Ghidra decompilation; matching idiom: class virtual action dispatch, offset array indexing, and switch mode handling; exact match verified; names and types await human review. */

extern char *DAT_002cfc8c;
extern float DAT_002d71d0;
extern unsigned char DAT_003386b8;
extern void *DAT_0034179c;

extern "C" {
extern void FUN_000ef564(void *self, int mode);
extern void FUN_000efb74(void *self);
extern void FUN_00103128(void *self);
extern void FUN_001b1c44(void *obj, int val);
extern void FUN_0027fc70(void *dst, void *src, int flag);
}

struct TargetSub {
    virtual ~TargetSub();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void action(int arg); /* slot at +24 */
};

extern "C" void FUN_000efa04(unsigned char *self)
{
    *(int *)(self + 0xbc) = *(int *)(self + 0xbc) + 1;
    int mode = *(int *)(self + 0xb8);
    switch (mode) {
    case 1:
        FUN_000ef564(self, 2);
        break;
    case 3: {
        int idx = (self[0xb0] != 0) ? 7 : 8;
        void *puVar5 = ((void **)(self + 0x5c))[idx];
        FUN_0027fc70(self + 0xb4, puVar5, 1);
        unsigned char target_idx = (self[0xb0] != 0) ^ 1;
        TargetSub *piVar2 = ((TargetSub **)(self + 0x88))[target_idx];
        piVar2->action(*(int *)puVar5);
        if (((((int)DAT_002cfc8c[0x8b] << 0x1c) >> 0x1e) == 0) ||
            ((float)*(int *)(self + 0xbc) > DAT_002d71d0)) {
            FUN_001b1c44(&DAT_0034179c, 3);
            int m = (DAT_003386b8 != 0) ? 4 : 5;
            FUN_000ef564(self, m);
        }
        break;
    }
    case 4:
        FUN_000ef564(self, 5);
        break;
    }
    if (self[0x54] == 0) {
        if ((unsigned)(*(int *)(self + 0xb8) - 1) < 2) {
            FUN_000efb74(self);
        }
        FUN_00103128(self);
    }
}
