/* HSTMATCH module=hstp_trans_main.prx start=0x000f50cc end=0x000f523c symbol=FUN_000f50cc lang=c++ */
/* Hand-written reconstruction of the EBOOT twin (src/eboot/handle_mode_action_000efa04.cpp) ported to the Sharing module with its addresses substituted, no other change; exact match verified; names and types await human review. */
extern char *DAT_003751d4;
extern float DAT_0037dfa8;
extern unsigned char DAT_003e19f8;
extern void *DAT_003eaad8;

extern "C" {
extern void FUN_000f4c2c(void *self, int mode);
extern void FUN_000f523c(void *self);
extern void FUN_00108a2c(void *self);
extern void FUN_001bfc3c(void *obj, int val);
extern void FUN_002910e4(void *dst, void *src, int flag);
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

extern "C" void FUN_000f50cc(Self *self)
{
    self->ticks = self->ticks + 1;
    int mode = self->mode;
    switch (mode) {
    case 1:
        FUN_000f4c2c(self, 2);
        break;
    case 3: {
        int idx = (self->side != 0) ? 7 : 8;
        void *item = self->items[idx];
        FUN_002910e4(&self->unkb4, item, 1);
        unsigned char target_idx = (self->side != 0) ^ 1;
        TargetSub *target = self->targets[target_idx];
        target->action(*(int *)item);
        if (((((int)DAT_003751d4[0x8b] << 0x1c) >> 0x1e) == 0) ||
            ((float)self->ticks > DAT_0037dfa8)) {
            FUN_001bfc3c(&DAT_003eaad8, 3);
            int next_mode = (DAT_003e19f8 != 0) ? 4 : 5;
            FUN_000f4c2c(self, next_mode);
        }
        break;
    }
    case 4:
        FUN_000f4c2c(self, 5);
        break;
    }
    if (self->disabled == 0) {
        if ((unsigned)(self->mode - 1) < 2) {
            FUN_000f523c(self);
        }
        FUN_00108a2c(self);
    }
}
