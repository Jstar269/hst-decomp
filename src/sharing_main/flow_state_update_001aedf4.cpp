/* HSTMATCH module=hstp_trans_main.prx start=0x001aedf4 end=0x001af93c symbol=FUN_001aedf4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Sub68 { char pad[0x20]; };
struct SubF4 { char pad[0x2a4 - 0xf4]; };
struct Ent { char pad[0x54]; int x54; };
struct EntList { char pad[4]; Ent **list; };
struct Cam { char pad[0xc]; float f0c; };
struct Snd { char pad[8]; float f08; };
struct Game { char pad[0x178]; unsigned char x178; };
struct Cfg { char pad[0x424]; int x424; };
struct Peer { char pad[0x3ac]; int x3ac; char pad3b0[8]; int x3b8; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} };

struct Self {
    char pad0[0x3c];
    int x3c;              /* 0x3c */
    int state;            /* 0x40 */
    int next;             /* 0x44 */
    int x48;              /* 0x48 */
    char pad4c;
    unsigned char x4d;    /* 0x4d */
    char pad4e[0x60 - 0x4e];
    int x60;              /* 0x60 */
    char pad64[4];
    Sub68 sub;            /* 0x68 */
    EntList *x88;         /* 0x88 */
    char pad8c[0xd4 - 0x8c];
    int xd4, xd8, xdc, xe0;
    char pade4[0xf4 - 0xe4];
    SubF4 f4;             /* 0xf4 */
    unsigned char x2a4;   /* 0x2a4 */
    char pad2a5[3];
    int x2a8, x2ac, x2b0, x2b4;
    char pad2b8[0x348 - 0x2b8];
    int *arr348;          /* 0x348 */
    char pad34c[8];
    int *arr354;          /* 0x354 */
    unsigned n358;        /* 0x358 */
    char pad35c[0x39c - 0x35c];
    int x39c;             /* 0x39c */
    unsigned char x3a0;   /* 0x3a0 */
    unsigned char x3a1;   /* 0x3a1 */
};

extern "C" {
extern Cam *DAT_003daec4;
extern Snd *DAT_003f3b50;
extern Game *DAT_003e1e04;
extern int DAT_003f39a8;
extern void *DAT_003ea8ec;
extern char DAT_003eaad8[];
extern Cfg *DAT_003eaac0;

void FUN_001aac18(int, SubF4 *, unsigned char);
void FUN_001aafa4(int);
void FUN_001c2130(void *, float);
void FUN_0020c8c4(int);
int FUN_0020dbac(int);
void FUN_00108f54(void *, int);
int FUN_0020d1e0(int, int, int);
void FUN_0011e940(void *, int, int, int, int);
Peer *FUN_0020d694(void);
void FUN_001bc52c(Sub68 *, int);
int FUN_001204dc(void *);
int FUN_001205f0(void *);
void FUN_000be4b4(Game *);
void FUN_001c0ce8(void *, int);
void FUN_001c8a7c(EntList *);
void FUN_001bd0f0(Sub68 *);
int FUN_0020dc70(void);
void FUN_001bfc3c(void *, int);
void FUN_0020d6d4(int, int, int);
void FUN_001ad6e8(Self *);
void FUN_000646f4(float, float, Cam *, const Q &, const Q &, int, int, int);
int FUN_002a4a08(Snd *);
void FUN_002a47a0(float, Snd *);
void FUN_001bc544(Sub68 *);
void FUN_001b15ac(Self *);
unsigned char FUN_001bc520(Sub68 *);
void FUN_001bd158(Sub68 *, int);
void FUN_001bcdcc(Sub68 *);
}

static inline bool IsQuiet()
{
    bool b = true;
    if (DAT_003daec4->f0c != 0.0f)
        b = false;
    if (DAT_003f3b50 && DAT_003f3b50->f08 != 0.0f)
        b = false;
    return b;
}

extern "C" void FUN_001aedf4(Self *self)
{
    if (self->next) {
        self->state = self->next;
        self->next = 0;
        self->xd4 = 0;
        self->xd8 = 0;
        self->xdc = 0;
        self->xe0 = 0;
    }
    switch (self->state) {
    case 1: {
        if (self->x2a4)
            FUN_0020d6d4(self->state, self->x2a8, self->x60);
        FUN_001ad6e8(self);
        self->next = 21;
        FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, Q(), Q(), 10, 0, 0);
        if (DAT_003f3b50 && FUN_002a4a08(DAT_003f3b50))
            FUN_002a47a0(65535.0f, DAT_003f3b50);
        self->x3c = 1;
        FUN_001bc544(&self->sub);
        FUN_001b15ac(self);
        break;
    }
    case 2:
        if (self->x2a4) {
            if (DAT_003e1e04->x178) {
                Peer *p = FUN_0020d694();
                if (p->x3ac == DAT_003f39a8 && p->x3b8 == 2) {
                    for (unsigned i = 0; i < self->n358; i++) {
                        switch (self->arr348[i]) {
                        case 1:
                        case 3:
                            self->arr354[i] = 1;
                            break;
                        }
                    }
                } else {
                    for (unsigned i = 0; i < self->n358; i++) {
                        switch (self->arr348[i]) {
                        case 1:
                        case 3:
                            self->arr354[i] = 0;
                            break;
                        }
                    }
                }
                FUN_001bcdcc(&self->sub);
            } else {
                if (FUN_0020dbac(1)) {
                    self->next = 17;
                } else if (FUN_0020dbac(2)) {
                    self->next = 18;
                    self->x2ac = 0;
                    FUN_0011e940(DAT_003ea8ec, 0, FUN_0020d1e0(17, 11, 2), 0, 0);
                }
            }
        }
        break;
    case 5:
        break;
    case 14: {
        bool done = false;
        if (self->x2a4 && ++self->x2b4 > 600) {
            self->x2b4 = 0;
            done = true;
            FUN_00108f54(DAT_003ea8ec, 1);
            FUN_001bfc3c(DAT_003eaad8, 4);
            self->next = 2;
            FUN_001bc52c(&self->sub, 0);
        }
        if (!done && FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                if (self->x2a4) {
                    self->next = 17;
                } else {
                    self->next = 13;
                    self->x39c = 0;
                    FUN_001c0ce8(DAT_003eaad8, self->x88->list[0]->x54 + 0x41);
                    FUN_001c8a7c(self->x88);
                    self->x3a1 = 0;
                    FUN_001bd0f0(&self->sub);
                }
            } else {
                self->next = 2;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    }
    case 13:
        if (++self->x39c > DAT_003eaac0->x424) {
            self->next = 23;
            FUN_001aafa4(23);
            FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case 12:
        if (FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            self->next = 3;
        }
        break;
    case 15:
        if (FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                self->next = 24;
                FUN_001aafa4(24);
                if (DAT_003f39a8 == 4)
                    FUN_001c2130(DAT_003eaad8, 0.33333334f);
                FUN_0020c8c4(1);
            } else {
                self->next = 2;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    case 16:
        if (self->x2a4 && FUN_0020dc70())
            self->next = 17;
        break;
    case 17:
        self->x2a8 = 1;
        if (FUN_0020dbac(1)) {
            self->next = 13;
            self->x39c = 0;
            if (self->x2a4) {
                if (DAT_003e1e04->x178)
                    FUN_001c0ce8(DAT_003eaad8, self->x88->list[0]->x54 + 0x41);
                else
                    FUN_001c0ce8(DAT_003eaad8, self->x88->list[1]->x54 + 0x41);
            } else {
                FUN_001c0ce8(DAT_003eaad8, self->x88->list[0]->x54 + 0x41);
            }
            FUN_001c8a7c(self->x88);
            self->x3a1 = 0;
            FUN_001bd0f0(&self->sub);
        }
        break;
    case 18:
        if (++self->x2ac > 45) {
            FUN_00108f54(DAT_003ea8ec, 1);
            self->next = 24;
            FUN_001aafa4(24);
            if (DAT_003f39a8 == 4)
                FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case 19: {
        bool done = false;
        if (self->x2a4 && !DAT_003e1e04->x178 && FUN_0020dbac(2)) {
            self->next = 18;
            self->x2ac = 0;
            FUN_00108f54(DAT_003ea8ec, 1);
            FUN_0011e940(DAT_003ea8ec, 0, FUN_0020d1e0(17, 11, 2), 0, 0);
            done = true;
        }
        if (!done && self->x2a4 && !self->x4d && !DAT_003e1e04->x178) {
            Peer *p = FUN_0020d694();
            if (p->x3ac == DAT_003f39a8) {
                switch (p->x3b8) {
                case 14:
                case 23:
                    FUN_00108f54(DAT_003ea8ec, 1);
                    self->next = 2;
                    FUN_001bc52c(&self->sub, 0);
                    done = true;
                    break;
                }
            }
        }
        if (!done && FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                self->next = 20;
                self->x2b0 = 0;
                if (DAT_003e1e04)
                    FUN_000be4b4(DAT_003e1e04);
            } else {
                self->next = 2;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    }
    case 20:
        if (++self->x2b0 > 60) {
            self->next = 25;
            FUN_001aafa4(25);
            if (DAT_003f39a8 == 4)
                FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case 21:
        if (IsQuiet()) {
            self->x3c = 2;
            self->next = 2;
            if (self->x2a4 && !DAT_003e1e04->x178)
                self->x2a8 = 1;
        }
        break;
    case 22:
        if (IsQuiet()) {
            self->next = 26;
            self->x3c = 1;
            self->x48 = 3;
            FUN_001aac18(3, &self->f4, self->x2a4);
        }
        break;
    case 23:
        self->next = 26;
        self->x3c = 1;
        self->x48 = 1;
        FUN_001aac18(1, &self->f4, self->x2a4);
        break;
    case 24:
        if (IsQuiet()) {
            self->next = 26;
            self->x3c = 1;
            self->x48 = 2;
            FUN_001aac18(2, &self->f4, self->x2a4);
        }
        break;
    case 25:
        if (IsQuiet()) {
            self->next = 26;
            self->x3c = 1;
            self->x48 = 4;
            FUN_001aac18(4, &self->f4, self->x2a4);
        }
        break;
    }
    if (self->x3a0 != FUN_001bc520(&self->sub)) {
        for (int i = 0; i < 4; i++)
            FUN_001bd158(&self->sub, i);
    }
}
