/* HSTMATCH module=hstp_trans_main.prx start=0x001aedf4 end=0x001af93c symbol=FUN_001aedf4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Sub68 { char pad[0x20]; };
struct SubF4 { char pad[0x2a4 - 0xf4]; };
struct Ent { char pad[0x54]; int id; };
struct EntList { char pad[4]; Ent **list; };
struct Cam { char pad[0xc]; float unk0c; };
struct Snd { char pad[8]; float unk08; };
struct Game { char pad[0x178]; unsigned char unk178; };
struct Cfg { char pad[0x424]; int holdLimit; };
struct Peer { char pad[0x3ac]; int unk3ac; char pad3b0[8]; int unk3b8; };
struct Q { int a, b, c, d; Q() : a(0), b(0), c(0), d(0) {} };

/* Ids of the update function's state machine (named by number; roles not established). */
enum {
    ST_01 = 1, ST_02, ST_03, ST_04, ST_05, ST_06, ST_07, ST_08, ST_09, ST_10, ST_11, ST_12, ST_13,
    ST_14, ST_15, ST_16, ST_17, ST_18, ST_19, ST_20, ST_21, ST_22, ST_23, ST_24, ST_25, ST_26
};
enum {
    TIMEOUT_LIMIT = 600, /* timeoutCount limit in state 14 */
    DELAY_LIMIT = 45,    /* delayCount limit in state 18 */
    END_LIMIT = 60,      /* endCount limit in state 20 */
    SLOT_PARTS = 4       /* sub-object slots refreshed when the flag byte changes */
};

struct Self {
    char pad0[0x3c];
    int mode;              /* 0x3c */
    int state;            /* 0x40 */
    int next;             /* 0x44 */
    int result;              /* 0x48 */
    char pad4c;
    unsigned char unk4d;    /* 0x4d */
    char pad4e[0x60 - 0x4e];
    int unk60;              /* 0x60 */
    char pad64[4];
    Sub68 sub;            /* 0x68 */
    EntList *entries;         /* 0x88 */
    char pad8c[0xd4 - 0x8c];
    int unkd4, unkd8, unkdc, unke0;
    char pade4[0xf4 - 0xe4];
    SubF4 unkf4;          /* 0xf4 */
    unsigned char unk2a4;   /* 0x2a4 */
    char pad2a5[3];
    int unk2a8, delayCount, endCount, timeoutCount;
    char pad2b8[0x348 - 0x2b8];
    int *kinds;          /* 0x348 */
    char pad34c[8];
    int *marks;          /* 0x354 */
    unsigned slotCount;        /* 0x358 */
    char pad35c[0x39c - 0x35c];
    int holdCount;             /* 0x39c */
    unsigned char unk3a0;   /* 0x3a0 */
    unsigned char unk3a1;   /* 0x3a1 */
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
    if (DAT_003daec4->unk0c != 0.0f)
        b = false;
    if (DAT_003f3b50 && DAT_003f3b50->unk08 != 0.0f)
        b = false;
    return b;
}

/* Per-frame update of the state machine: apply a pending state change, then run the current state. */
extern "C" void FUN_001aedf4(Self *self)
{
    if (self->next) {
        self->state = self->next;
        self->next = 0;
        self->unkd4 = 0;
        self->unkd8 = 0;
        self->unkdc = 0;
        self->unke0 = 0;
    }
    switch (self->state) {
    case ST_01: {
        if (self->unk2a4)
            FUN_0020d6d4(self->state, self->unk2a8, self->unk60);
        FUN_001ad6e8(self);
        self->next = ST_21;
        FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, Q(), Q(), 10, 0, 0);
        if (DAT_003f3b50 && FUN_002a4a08(DAT_003f3b50))
            FUN_002a47a0(65535.0f, DAT_003f3b50);
        self->mode = 1;
        FUN_001bc544(&self->sub);
        FUN_001b15ac(self);
        break;
    }
    case ST_02:
        if (self->unk2a4) {
            if (DAT_003e1e04->unk178) {
                Peer *p = FUN_0020d694();
                if (p->unk3ac == DAT_003f39a8 && p->unk3b8 == 2) {
                    for (unsigned i = 0; i < self->slotCount; i++) {
                        switch (self->kinds[i]) {
                        case 1:
                        case 3:
                            self->marks[i] = 1;
                            break;
                        }
                    }
                } else {
                    for (unsigned i = 0; i < self->slotCount; i++) {
                        switch (self->kinds[i]) {
                        case 1:
                        case 3:
                            self->marks[i] = 0;
                            break;
                        }
                    }
                }
                FUN_001bcdcc(&self->sub);
            } else {
                if (FUN_0020dbac(1)) {
                    self->next = ST_17;
                } else if (FUN_0020dbac(2)) {
                    self->next = ST_18;
                    self->delayCount = 0;
                    FUN_0011e940(DAT_003ea8ec, 0, FUN_0020d1e0(17, 11, 2), 0, 0);
                }
            }
        }
        break;
    case ST_05:
        break;
    case ST_14: {
        bool done = false;
        if (self->unk2a4 && ++self->timeoutCount > TIMEOUT_LIMIT) {
            self->timeoutCount = 0;
            done = true;
            FUN_00108f54(DAT_003ea8ec, 1);
            FUN_001bfc3c(DAT_003eaad8, 4);
            self->next = ST_02;
            FUN_001bc52c(&self->sub, 0);
        }
        if (!done && FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                if (self->unk2a4) {
                    self->next = ST_17;
                } else {
                    self->next = ST_13;
                    self->holdCount = 0;
                    FUN_001c0ce8(DAT_003eaad8, self->entries->list[0]->id + 0x41);
                    FUN_001c8a7c(self->entries);
                    self->unk3a1 = 0;
                    FUN_001bd0f0(&self->sub);
                }
            } else {
                self->next = ST_02;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    }
    case ST_13:
        if (++self->holdCount > DAT_003eaac0->holdLimit) {
            self->next = ST_23;
            FUN_001aafa4(23);
            FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case ST_12:
        if (FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            self->next = ST_03;
        }
        break;
    case ST_15:
        if (FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                self->next = ST_24;
                FUN_001aafa4(24);
                if (DAT_003f39a8 == 4)
                    FUN_001c2130(DAT_003eaad8, 0.33333334f);
                FUN_0020c8c4(1);
            } else {
                self->next = ST_02;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    case ST_16:
        if (self->unk2a4 && FUN_0020dc70())
            self->next = ST_17;
        break;
    case ST_17:
        self->unk2a8 = 1;
        if (FUN_0020dbac(1)) {
            self->next = ST_13;
            self->holdCount = 0;
            if (self->unk2a4) {
                if (DAT_003e1e04->unk178)
                    FUN_001c0ce8(DAT_003eaad8, self->entries->list[0]->id + 0x41);
                else
                    FUN_001c0ce8(DAT_003eaad8, self->entries->list[1]->id + 0x41);
            } else {
                FUN_001c0ce8(DAT_003eaad8, self->entries->list[0]->id + 0x41);
            }
            FUN_001c8a7c(self->entries);
            self->unk3a1 = 0;
            FUN_001bd0f0(&self->sub);
        }
        break;
    case ST_18:
        if (++self->delayCount > DELAY_LIMIT) {
            FUN_00108f54(DAT_003ea8ec, 1);
            self->next = ST_24;
            FUN_001aafa4(24);
            if (DAT_003f39a8 == 4)
                FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case ST_19: {
        bool done = false;
        if (self->unk2a4 && !DAT_003e1e04->unk178 && FUN_0020dbac(2)) {
            self->next = ST_18;
            self->delayCount = 0;
            FUN_00108f54(DAT_003ea8ec, 1);
            FUN_0011e940(DAT_003ea8ec, 0, FUN_0020d1e0(17, 11, 2), 0, 0);
            done = true;
        }
        if (!done && self->unk2a4 && !self->unk4d && !DAT_003e1e04->unk178) {
            Peer *p = FUN_0020d694();
            if (p->unk3ac == DAT_003f39a8) {
                switch (p->unk3b8) {
                case 14:
                case 23:
                    FUN_00108f54(DAT_003ea8ec, 1);
                    self->next = ST_02;
                    FUN_001bc52c(&self->sub, 0);
                    done = true;
                    break;
                }
            }
        }
        if (!done && FUN_001204dc(DAT_003ea8ec)) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                self->next = ST_20;
                self->endCount = 0;
                if (DAT_003e1e04)
                    FUN_000be4b4(DAT_003e1e04);
            } else {
                self->next = ST_02;
                FUN_001bc52c(&self->sub, 0);
            }
        }
        break;
    }
    case ST_20:
        if (++self->endCount > END_LIMIT) {
            self->next = ST_25;
            FUN_001aafa4(25);
            if (DAT_003f39a8 == 4)
                FUN_001c2130(DAT_003eaad8, 0.33333334f);
            FUN_0020c8c4(1);
        }
        break;
    case ST_21:
        if (IsQuiet()) {
            self->mode = 2;
            self->next = ST_02;
            if (self->unk2a4 && !DAT_003e1e04->unk178)
                self->unk2a8 = 1;
        }
        break;
    case ST_22:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 3;
            FUN_001aac18(3, &self->unkf4, self->unk2a4);
        }
        break;
    case ST_23:
        self->next = ST_26;
        self->mode = 1;
        self->result = 1;
        FUN_001aac18(1, &self->unkf4, self->unk2a4);
        break;
    case ST_24:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 2;
            FUN_001aac18(2, &self->unkf4, self->unk2a4);
        }
        break;
    case ST_25:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 4;
            FUN_001aac18(4, &self->unkf4, self->unk2a4);
        }
        break;
    }
    if (self->unk3a0 != FUN_001bc520(&self->sub)) {
        for (int i = 0; i < SLOT_PARTS; i++)
            FUN_001bd158(&self->sub, i);
    }
}
