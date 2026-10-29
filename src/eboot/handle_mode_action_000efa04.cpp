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

struct Self {
    char pad00[0x54];
    unsigned char disabled;     /* 0x54 */
    char pad55[0x5c - 0x55];
    void *items[9];             /* 0x5c: items[7] and items[8] are used here */
    char pad80[0x88 - 0x80];
    TargetSub *targets[2];      /* 0x88 */
    char pad90[0xb0 - 0x90];
    unsigned char side;         /* 0xb0 selects which item and which target are used */
    char padb1[3];
    int unkb4;                  /* 0xb4 */
    int mode;                   /* 0xb8 */
    int ticks;                  /* 0xbc frames spent in the current mode */
};

extern "C" void FUN_000efa04(Self *self)
{
    self->ticks = self->ticks + 1;
    int mode = self->mode;
    switch (mode) {
    case 1:
        FUN_000ef564(self, 2);
        break;
    case 3: {
        int idx = (self->side != 0) ? 7 : 8;
        void *item = self->items[idx];
        FUN_0027fc70(&self->unkb4, item, 1);
        unsigned char target_idx = (self->side != 0) ^ 1;
        TargetSub *target = self->targets[target_idx];
        target->action(*(int *)item);
        if (((((int)DAT_002cfc8c[0x8b] << 0x1c) >> 0x1e) == 0) ||
            ((float)self->ticks > DAT_002d71d0)) {
            FUN_001b1c44(&DAT_0034179c, 3);
            int next_mode = (DAT_003386b8 != 0) ? 4 : 5;
            FUN_000ef564(self, next_mode);
        }
        break;
    }
    case 4:
        FUN_000ef564(self, 5);
        break;
    }
    if (self->disabled == 0) {
        if ((unsigned)(self->mode - 1) < 2) {
            FUN_000efb74(self);
        }
        FUN_00103128(self);
    }
}
