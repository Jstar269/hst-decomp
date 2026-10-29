/* HSTMATCH module=EBOOT.BIN start=0x001a1828 end=0x001a2370 symbol=FUN_001a1828 lang=c++ */
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
extern Cam *DAT_00331b84;
extern Snd *DAT_0034a820;
extern Game *DAT_00338ac4;
extern int DAT_0034a678;
extern void *DAT_003415ac;
extern char DAT_0034179c[];
extern Cfg *DAT_00341784;

void FUN_0019d6e0(int, SubF4 *, unsigned char);
void FUN_0019da6c(int);
void FUN_001b3ea4(void *, float);
void FUN_001fe0f4(int);
int FUN_001ff3dc(int);
void FUN_00103628(void *, int);
int FUN_001fea10(int, int, int);
void FUN_00114168(void *, int, int, int, int);
Peer *FUN_001feec4(void);
void FUN_001aee54(Sub68 *, int);
int FUN_001155c0(void *);
int FUN_001156d4(void *);
void FUN_000bb06c(Game *);
void FUN_001b2bb8(void *, int);
void FUN_001bad34(EntList *);
void FUN_001afa18(Sub68 *);
int FUN_001ff4a0(void);
void FUN_001b1c44(void *, int);
void FUN_001fef04(int, int, int);
void FUN_001a0148(Self *);
void FUN_00063830(float, float, Cam *, const Q &, const Q &, int, int, int);
int FUN_002933fc(Snd *);
void FUN_00293194(float, Snd *);
void FUN_001aee6c(Sub68 *);
void FUN_001a3fe0(Self *);
unsigned char FUN_001aee48(Sub68 *);
void FUN_001afa80(Sub68 *, int);
void FUN_001af6f4(Sub68 *);
}

static inline bool IsQuiet()
{
    bool b = true;
    if (DAT_00331b84->unk0c != 0.0f)
        b = false;
    if (DAT_0034a820 && DAT_0034a820->unk08 != 0.0f)
        b = false;
    return b;
}

/* Per-frame update of the state machine: apply a pending state change, then run the current state. */
extern "C" void FUN_001a1828(Self *self)
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
            FUN_001fef04(self->state, self->unk2a8, self->unk60);
        FUN_001a0148(self);
        self->next = ST_21;
        FUN_00063830(65535.0f, -1.0f, DAT_00331b84, Q(), Q(), 10, 0, 0);
        if (DAT_0034a820 && FUN_002933fc(DAT_0034a820))
            FUN_00293194(65535.0f, DAT_0034a820);
        self->mode = 1;
        FUN_001aee6c(&self->sub);
        FUN_001a3fe0(self);
        break;
    }
    case ST_02:
        if (self->unk2a4) {
            if (DAT_00338ac4->unk178) {
                Peer *p = FUN_001feec4();
                if (p->unk3ac == DAT_0034a678 && p->unk3b8 == 2) {
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
                FUN_001af6f4(&self->sub);
            } else {
                if (FUN_001ff3dc(1)) {
                    self->next = ST_17;
                } else if (FUN_001ff3dc(2)) {
                    self->next = ST_18;
                    self->delayCount = 0;
                    FUN_00114168(DAT_003415ac, 0, FUN_001fea10(17, 11, 2), 0, 0);
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
            FUN_00103628(DAT_003415ac, 1);
            FUN_001b1c44(DAT_0034179c, 4);
            self->next = ST_02;
            FUN_001aee54(&self->sub, 0);
        }
        if (!done && FUN_001155c0(DAT_003415ac)) {
            FUN_00103628(DAT_003415ac, 1);
            if (FUN_001156d4(DAT_003415ac) == 0) {
                if (self->unk2a4) {
                    self->next = ST_17;
                } else {
                    self->next = ST_13;
                    self->holdCount = 0;
                    FUN_001b2bb8(DAT_0034179c, self->entries->list[0]->id + 0x41);
                    FUN_001bad34(self->entries);
                    self->unk3a1 = 0;
                    FUN_001afa18(&self->sub);
                }
            } else {
                self->next = ST_02;
                FUN_001aee54(&self->sub, 0);
            }
        }
        break;
    }
    case ST_13:
        if (++self->holdCount > DAT_00341784->holdLimit) {
            self->next = ST_23;
            FUN_0019da6c(23);
            FUN_001b3ea4(DAT_0034179c, 0.33333334f);
            FUN_001fe0f4(1);
        }
        break;
    case ST_12:
        if (FUN_001155c0(DAT_003415ac)) {
            FUN_00103628(DAT_003415ac, 1);
            self->next = ST_03;
        }
        break;
    case ST_15:
        if (FUN_001155c0(DAT_003415ac)) {
            FUN_00103628(DAT_003415ac, 1);
            if (FUN_001156d4(DAT_003415ac) == 0) {
                self->next = ST_24;
                FUN_0019da6c(24);
                if (DAT_0034a678 == 4)
                    FUN_001b3ea4(DAT_0034179c, 0.33333334f);
                FUN_001fe0f4(1);
            } else {
                self->next = ST_02;
                FUN_001aee54(&self->sub, 0);
            }
        }
        break;
    case ST_16:
        if (self->unk2a4 && FUN_001ff4a0())
            self->next = ST_17;
        break;
    case ST_17:
        self->unk2a8 = 1;
        if (FUN_001ff3dc(1)) {
            self->next = ST_13;
            self->holdCount = 0;
            if (self->unk2a4) {
                if (DAT_00338ac4->unk178)
                    FUN_001b2bb8(DAT_0034179c, self->entries->list[0]->id + 0x41);
                else
                    FUN_001b2bb8(DAT_0034179c, self->entries->list[1]->id + 0x41);
            } else {
                FUN_001b2bb8(DAT_0034179c, self->entries->list[0]->id + 0x41);
            }
            FUN_001bad34(self->entries);
            self->unk3a1 = 0;
            FUN_001afa18(&self->sub);
        }
        break;
    case ST_18:
        if (++self->delayCount > DELAY_LIMIT) {
            FUN_00103628(DAT_003415ac, 1);
            self->next = ST_24;
            FUN_0019da6c(24);
            if (DAT_0034a678 == 4)
                FUN_001b3ea4(DAT_0034179c, 0.33333334f);
            FUN_001fe0f4(1);
        }
        break;
    case ST_19: {
        bool done = false;
        if (self->unk2a4 && !DAT_00338ac4->unk178 && FUN_001ff3dc(2)) {
            self->next = ST_18;
            self->delayCount = 0;
            FUN_00103628(DAT_003415ac, 1);
            FUN_00114168(DAT_003415ac, 0, FUN_001fea10(17, 11, 2), 0, 0);
            done = true;
        }
        if (!done && self->unk2a4 && !self->unk4d && !DAT_00338ac4->unk178) {
            Peer *p = FUN_001feec4();
            if (p->unk3ac == DAT_0034a678) {
                switch (p->unk3b8) {
                case 14:
                case 23:
                    FUN_00103628(DAT_003415ac, 1);
                    self->next = ST_02;
                    FUN_001aee54(&self->sub, 0);
                    done = true;
                    break;
                }
            }
        }
        if (!done && FUN_001155c0(DAT_003415ac)) {
            FUN_00103628(DAT_003415ac, 1);
            if (FUN_001156d4(DAT_003415ac) == 0) {
                self->next = ST_20;
                self->endCount = 0;
                if (DAT_00338ac4)
                    FUN_000bb06c(DAT_00338ac4);
            } else {
                self->next = ST_02;
                FUN_001aee54(&self->sub, 0);
            }
        }
        break;
    }
    case ST_20:
        if (++self->endCount > END_LIMIT) {
            self->next = ST_25;
            FUN_0019da6c(25);
            if (DAT_0034a678 == 4)
                FUN_001b3ea4(DAT_0034179c, 0.33333334f);
            FUN_001fe0f4(1);
        }
        break;
    case ST_21:
        if (IsQuiet()) {
            self->mode = 2;
            self->next = ST_02;
            if (self->unk2a4 && !DAT_00338ac4->unk178)
                self->unk2a8 = 1;
        }
        break;
    case ST_22:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 3;
            FUN_0019d6e0(3, &self->unkf4, self->unk2a4);
        }
        break;
    case ST_23:
        self->next = ST_26;
        self->mode = 1;
        self->result = 1;
        FUN_0019d6e0(1, &self->unkf4, self->unk2a4);
        break;
    case ST_24:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 2;
            FUN_0019d6e0(2, &self->unkf4, self->unk2a4);
        }
        break;
    case ST_25:
        if (IsQuiet()) {
            self->next = ST_26;
            self->mode = 1;
            self->result = 4;
            FUN_0019d6e0(4, &self->unkf4, self->unk2a4);
        }
        break;
    }
    if (self->unk3a0 != FUN_001aee48(&self->sub)) {
        for (int i = 0; i < SLOT_PARTS; i++)
            FUN_001afa80(&self->sub, i);
    }
}
