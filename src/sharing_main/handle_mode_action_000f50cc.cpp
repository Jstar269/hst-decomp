/* HSTMATCH module=hstp_trans_main.prx start=0x000f50cc end=0x000f523c symbol=FUN_000f50cc lang=c++ */
/* Hand-written reconstruction of the EBOOT twin (src/eboot/handle_mode_action_000efa04.cpp) ported to the Sharing module with its addresses substituted, no other change; exact match verified; names and types await human review. */

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uchar;

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

extern "C" void FUN_000f50cc(unsigned char *self)
{
    *(int *)(self + 0xbc) = *(int *)(self + 0xbc) + 1;
    int mode = *(int *)(self + 0xb8);
    switch (mode) {
    case 1:
        FUN_000f4c2c(self, 2);
        break;
    case 3: {
        int idx = (self[0xb0] != 0) ? 7 : 8;
        void *puVar5 = ((void **)(self + 0x5c))[idx];
        FUN_002910e4(self + 0xb4, puVar5, 1);
        unsigned char target_idx = (self[0xb0] != 0) ^ 1;
        TargetSub *piVar2 = ((TargetSub **)(self + 0x88))[target_idx];
        piVar2->action(*(int *)puVar5);
        if (((((int)DAT_003751d4[0x8b] << 0x1c) >> 0x1e) == 0) ||
            ((float)*(int *)(self + 0xbc) > DAT_0037dfa8)) {
            FUN_001bfc3c(&DAT_003eaad8, 3);
            int m = (DAT_003e19f8 != 0) ? 4 : 5;
            FUN_000f4c2c(self, m);
        }
        break;
    }
    case 4:
        FUN_000f4c2c(self, 5);
        break;
    }
    if (self[0x54] == 0) {
        if ((unsigned)(*(int *)(self + 0xb8) - 1) < 2) {
            FUN_000f523c(self);
        }
        FUN_00108a2c(self);
    }
}
