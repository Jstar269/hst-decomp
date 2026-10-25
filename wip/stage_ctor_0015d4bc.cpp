/* HSTMATCH module=EBOOT.BIN start=0x0015d4bc end=0x0015d8b8 symbol=FUN_0015d4bc lang=c++ */
struct Track {
    char pad0[8];
    int speed;
    char pad1[0x14 - 0xc];
    int state;
};

struct Snd {
    char pad0[0xc];
    int vol;
    char pad1[0x52 - 0x10];
    unsigned char on;
};

struct Save {
    char pad0[0xe020];
    int base;
};

struct Self {
    void *vptr;
    char pad0[0x3c - 4];
    int mode;
    int failed;
    void *menu;
    unsigned char flag;
};

extern "C" {
extern char DAT_00309054;
extern Self *DAT_003403fc;
extern Track *DAT_003403f8;
extern Snd *DAT_00331b84;
extern void *DAT_003415d4;
extern void *DAT_003386c8;
extern char DAT_0034179c;
extern Save *DAT_003415a8;
extern unsigned char *DAT_00340400;
extern unsigned short DAT_003418f0;
extern signed char DAT_0034100c[];
extern int DAT_002dcc20;
extern float DAT_002de69c;
void FUN_0001f06c(Self *);
void *FUN_00000bcc(int);
void FUN_00159f08(void *, int);
void FUN_0015a2b0(Track *, int);
int FUN_0015a844(Track *);
void *FUN_0018ff74(void *);
void FUN_0001f21c(void *, void *);
void FUN_00063a30(Snd *, int, float);
void FUN_001b3ce8(void *, int);
void FUN_001b413c(void *, float, float);
int FUN_0015aa1c(Track *);
void FUN_0015b6a4(Track *, int, int, int);
int FUN_0024e2f4(void);
}

struct Rand {
    unsigned seed;
    int pad[3];
    Rand(unsigned s) { seed = s; }
    int Next()
    {
        seed = seed * 0x343fd + 0x269ec3;
        return (seed >> 16) & 0x7fff;
    }
};

extern "C" Self *FUN_0015d4bc(Self *self, int kind)
{
    FUN_0001f06c(self);
    self->vptr = &DAT_00309054;
    self->menu = 0;
    DAT_003403fc = self;
    self->flag = 0;
    self->failed = 0;
    if (DAT_003403f8 == 0) {
        void *p = FUN_00000bcc(0x470);
        if (p != 0)
            FUN_00159f08(p, 0);
    }
    FUN_0015a2b0(DAT_003403f8, 1);
    switch (kind) {
    default:
        self->mode = 0;
        break;
    case 0x2a:
        self->mode = 2;
        break;
    case 0x31:
        self->mode = 1;
        break;
    case 0x35:
    case 0x44:
    case 0x57:
        self->mode = 0;
        break;
    case 10:
        self->mode = 0;
        break;
    case 0x4b:
    case 0xb:
    case 0x58:
        self->mode = 4;
        break;
    case 0x4c:
        self->mode = 3;
        break;
    }
    if (self->mode != 4) {
        Snd *snd = DAT_00331b84;
        snd->vol = 0;
        snd->on = 0;
    }
    switch (self->mode) {
    case 0:
        FUN_0015b6a4(DAT_003403f8, FUN_0015aa1c(DAT_003403f8), 0, 1);
        DAT_003403f8->speed = DAT_002dcc20;
        break;
    case 1: {
        unsigned seed = self->mode;
        int n = (short)DAT_003418f0 + 0x80;
        if (FUN_0024e2f4() != 0 || (DAT_0034100c[n] != 0 && Rand(seed).Next() % 100 >= 50))
            n = FUN_0015aa1c(DAT_003403f8);
        FUN_0015b6a4(DAT_003403f8, n, 0, 1);
        DAT_003403f8->speed = DAT_002dcc20;
        break;
    }
    case 2:
        FUN_0015b6a4(DAT_003403f8, DAT_003418f0 < 100 ? DAT_003418f0 + 0x80 : FUN_0015aa1c(DAT_003403f8), 0, 1);
        DAT_003403f8->speed = DAT_002dcc20;
        break;
    case 3: {
        int b = DAT_003415a8->base;
        FUN_0015b6a4(DAT_003403f8, DAT_00340400[b + 0x51] != 0 ? b + 0x51 : b + 0x41, 0, 1);
        DAT_003403f8->speed = (int)((float)DAT_002dcc20 / DAT_002de69c);
        break;
    }
    case 4:
        if (FUN_0015a844(DAT_003403f8) >= 0) {
            if (DAT_003415d4 == 0) {
                void *p = FUN_00000bcc(0x40);
                self->menu = p != 0 ? FUN_0018ff74(p) : 0;
                FUN_0001f21c(DAT_003386c8, DAT_003415d4);
            }
            FUN_00063a30(DAT_00331b84, 15, 65535.0f);
            FUN_001b3ce8(&DAT_0034179c, 0);
            FUN_001b413c(&DAT_0034179c, 0.7f, 0.5f);
        } else {
            DAT_003403f8->state = 5;
            self->failed = 1;
        }
        break;
    }
    return self;
}
// NEAR: 255/255 words, 122 differ (mostly register shift).
// Retail frame is 32 bytes (ours 16) and the LCG seed is the literal 1 held in s0 (mult s0) without
// constant folding; every seed=1 form tried (local, struct, ref, padded struct) folds the multiply.
// Seeding from self->mode keeps the mult but puts mode in s0 instead of v1.
// Also case 0x57 merges into the case-10 store (retail branches to the 0x35/0x44 group body).
// near miss from lane ol2 (unreviewed)
