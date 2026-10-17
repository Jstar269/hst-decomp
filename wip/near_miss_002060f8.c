/* HSTMATCH module=EBOOT.BIN start=0x002060f8 end=0x00206290 symbol=FUN_002060f8 lang=c99 */
/* Near miss: 100/102 words matched retail. Util player assert blocks, DAT_002c93b0 loop, volatile count loop, subu zero clear, and trailing copy/call matched. */

typedef unsigned int uint;

extern const int DAT_002c93b0[6];
extern const char DAT_002ef6d4[];
extern const char DAT_002ef700[];
extern const char DAT_002ef724[];
extern const char DAT_002ef734[];

extern void *FUN_00011090(void *dest, const void *src, int n);
extern void FUN_00048fc8(void *fn, void *obj);
extern int FUN_00049094(int);
extern void FUN_00055e48(int, int);
extern void FUN_00092c38(int, int);
extern void FUN_002059ec(const char *, ...);
extern void FUN_00204f18(void);

typedef struct PlayerObj PlayerObj;
struct PlayerObj {
    int f_0;
    char pad4[8];
    int *f_c;
    volatile int f_10;
    char pad14[0x54 - 0x14];
    char f_54[24];
    char flag_6c;
    char pad6d[0x74 - 0x6d];
    unsigned char flag_74;
    char f_75;
    char f_76;
    char f_77;
    char f_78;
};

void FUN_002060f8(PlayerObj *self, int unused, const void *src, char p4, char p5, char p6, char p7)
{
    char stack_pad[16];

    self->flag_74 = 0;

    if (FUN_00049094(0) == 0) {
        FUN_002059ec(DAT_002ef6d4);
        FUN_002059ec(DAT_002ef700, DAT_002ef724, 1113);
        FUN_002059ec(DAT_002ef734);
    }
    FUN_00049094(1);

    if (self->flag_74 == 0) {
        const int *p = DAT_002c93b0;
        int i = 0;
        do {
            int val = 0;
            if (i >= 0 && i < 6) {
                val = *p;
            }
            FUN_00092c38(self->f_0, val);
            i++;
            p++;
        } while (i < 6);
    }

    uint u = 0;
    if (self->f_10 != 0) {
        int off = 0;
        do {
            int item = *(int *)((char *)self->f_c + off);
            if (item != 0) {
                FUN_00055e48(item, 1);
                *(int *)((char *)self->f_c + off) = 0;
            }
            u++;
            off += 4;
        } while (u < (uint)self->f_10);
    }

    self->f_10 -= self->f_10;
    self->flag_6c = 0;
    FUN_00011090(self->f_54, src, 24);
    self->f_75 = p4;
    self->f_76 = p5;
    self->f_77 = p6;
    self->f_78 = p7;
    FUN_00048fc8(FUN_00204f18, self);
}
// near miss from lane u6fr1-0 (unreviewed)
