/* HSTMATCH module=hstp_trans_main.prx start=0x000dfcb0 end=0x000e07a8 symbol=FUN_000dfcb0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rule.cpp (file name, assert texts and the m_ResultGame / GetGameResult() names come from this function's
   assert strings): point-won / event handler of the match rule object; Sharing twin of EBOOT 0xdbc90
   (asserts enabled, plus the counter bump before the game-won bookkeeping). */
struct Player {
    char pad0[0x144];
    int side;   /* 0x144 */
    int court;  /* 0x148 */
};

struct PlayerStats {
    char pad0[0x50];
    int doubleFaults; /* +0x50 */
    int aces;         /* +0x54 */
    int loveGames;    /* +0x58 */
};

struct GameResult {
    char pad0[0x18];
    PlayerStats players[2];       /* 0x18 */
    char padD0[0x208 - 0xd0];
    char m_getGame[2][0x50];      /* 0x208 */
    char m_pointPerGame[2][0x50]; /* 0x2a8 */
};

struct MatchRecord {
    char pad0[0x54];
    GameResult result;  /* 0x54 */
};

struct Game {
    char pad0[0x70];
    Player *players[12];  /* 0x70 */
    MatchRecord *record;  /* 0xa0 */
    char padA4[4];
    void *voice;          /* 0xa8 */
};

struct Rule {
    char pad0[0x44];
    unsigned char active;   /* 0x44 */
    unsigned char doubles;  /* 0x45 */
    char pad46[0x4c - 0x46];
    int dir;                /* 0x4c */
    int base;               /* 0x50 */
    int server;             /* 0x54 */
    int f58;                /* 0x58 */
    char pad5c[4];
    unsigned char f60;      /* 0x60 */
    unsigned char f61;      /* 0x61 */
    unsigned char f62;      /* 0x62 */
    char pad63[0x86 - 0x63];
    unsigned char f86;      /* 0x86 */
    unsigned char f87;      /* 0x87 */
    unsigned char f88;      /* 0x88 */
    char pad89[0x90 - 0x89];
    int f90;                /* 0x90 */
    int f94;                /* 0x94 */
    int f98;                /* 0x98 */
    int m_GetPointTeamNo;   /* 0x9c */
    int fa0;                /* 0xa0 */
    int fa4;                /* 0xa4 */
    int fa8;                /* 0xa8 */
    char padac[4];
    unsigned char fb0;      /* 0xb0 */
    char padb1[3];
    int numSets;            /* 0xb4 */
    int sets[2];            /* 0xb8 */
    int gamesPerSet;        /* 0xc0 */
    int games[2];           /* 0xc4 */
    int pointsPerGame;      /* 0xcc */
    int points[2];          /* 0xd0 */
    int m_ResultGame[2][6];  /* 0xd8 */
    unsigned char f108;     /* 0x108 */
};

extern Game *DAT_003e19f0;
extern void *DAT_003e1f60;
extern unsigned char DAT_003e1e88;
extern unsigned char DAT_003eaaf3;
extern unsigned char DAT_003eabd3;
extern unsigned char DAT_003eacf3;
extern int DAT_0037d780;
extern int DAT_0037d784;

struct Entry120 {
    char pad0[0x7c];
    unsigned char f7c;  /* 0x7c */
    char pad7d[0x120 - 0x7d];
};
extern Entry120 DAT_003eaaf0[4];

extern const char DAT_0037d738[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_0037d774[]; /* "Rule.cpp" */
extern const char DAT_0037d788[]; /* "setNo < BULK_OF(m_ResultGame[0])" */
extern const char DAT_0037d7ac[]; /* "gameNo < BULK_OF(GetGameResult().m_getGame[0])" */
extern const char DAT_0037d7dc[]; /* "gameNo < BULK_OF(GetGameResult().m_pointPerGame[0])" */

extern "C" {
Player *FUN_00089f84(Game *g);
int FUN_00100c64(void *p);
void FUN_000e07a8(Rule *s, int k);
void FUN_000e166c(Rule *s, int k);
void FUN_000e1b54(Rule *s);
void FUN_000e324c(Rule *s);
int FUN_000e30f8(Rule *s);
void FUN_000e22ec(Rule *s, int *pts, bool *deuce, int *adv);
void FUN_000e1d9c(Rule *s, int w, int side);
void FUN_000e1e58(Rule *s);
void FUN_000e1e94(Rule *s);
void FUN_001c3930(void *voice, int id, int ch);
void FUN_00100768(void *p);
void FUN_000df718(...);
}

#define BULK_OF(a) (sizeof(a) / sizeof((a)[0]))
#define RULE_ASSERT(c, text, line) \
    if (!(c)) { FUN_000df718(DAT_0037d738, text, DAT_0037d774, line); while (1) {} }

template <class T> static inline const T &min_(const T &a, const T &b) { return b < a ? b : a; }

static inline bool GameWon(Rule *self, int w)
{
    bool won;
    if (FUN_000e30f8(self))
        won = self->points[w] > 8 || (self->points[w] >= 7 && self->points[w] - self->points[w ^ 1] >= 2);
    else
        won = self->points[w] >= self->pointsPerGame && (self->points[w] - self->points[w ^ 1] >= 2 || DAT_003eaaf3 == 1);
    return won;
}

static inline GameResult &GetGameResult() { return DAT_003e19f0->record->result; }

extern "C" int FUN_000dfcb0(Rule *self, int ev)
{
    switch (ev) {
    case 0:
        FUN_000e07a8(self, 0);
        break;
    case 1:
        break;
    case 7: {
        int court = FUN_00089f84(DAT_003e19f0)->court & 1;
        if (FUN_00100c64(DAT_003e1f60))
            self->server = court;
        else
            self->server = (court + 1) % 2;
        self->dir = (self->server & 1) ? -1 : 1;
        self->base = self->server;
        break;
    }
    case 8:
        FUN_000e07a8(self, 1);
        break;
    case 9:
        break;
    case 20: {
        if (self->m_GetPointTeamNo < 0 || !self->active)
            break;
        FUN_000e166c(self, self->f98);
        FUN_000e1b54(self);
        self->active = 0;
        self->fb0 = 0;
        int w = self->m_GetPointTeamNo;
        void *voice = DAT_003e19f0->voice;
        int side = DAT_003e19f0->players[self->base]->side;
        bool mine = w == side;
        FUN_00089f84(DAT_003e19f0);
        self->points[w]++;
        if (w == self->f94 && !self->f61 && !self->f62) {
            self->f86 = self->f90 == 1;
            self->f87 = self->f90 == 2;
            self->f88 = self->f60;
            if (self->f87)
                DAT_003e19f0->record->result.players[self->f98].doubleFaults++;
            if (self->f88)
                DAT_003e19f0->record->result.players[self->f98].aces++;
        }
        FUN_000e324c(self);
        self->f58 = -self->f58;
        if (FUN_000e30f8(self) || DAT_003e1e88) {
            if ((self->points[0] + self->points[1]) % 2 == 1) {
                int n = self->doubles ? 2 : 4;
                self->server = (n + (self->base + self->dir)) % n;
            }
        }
        if (FUN_000e30f8(self) && (self->points[0] + self->points[1]) % 6 == 0)
            self->fb0 = 1;
        if (GameWon(self, w)) {
            if (DAT_003e1e88) {
                for (int i = 1; i < 4; i += 2) {
                    int v = DAT_003eaaf0[i].f7c + 1;
                    v = (v >= 16) ? 16 : v;
                    DAT_003eaaf0[i].f7c = v;
                }
                FUN_00100768(DAT_003e1f60);
            }
            FUN_000e1d9c(self, w, side);
            if (!DAT_003eabd3 && !DAT_003eacf3 && self->points[w ^ 1] == 0)
                DAT_003e19f0->record->result.players[w].loveGames++;
            int setNo = self->sets[0] + self->sets[1];
            RULE_ASSERT(setNo < BULK_OF(self->m_ResultGame[0]), DAT_0037d788, 439);
            int gameNo = 0;
            for (int i = 0; i <= setNo; i++) {
                gameNo += self->m_ResultGame[0][i];
                gameNo += self->m_ResultGame[1][i];
            }
            RULE_ASSERT(gameNo < BULK_OF(GetGameResult().m_getGame[0]), DAT_0037d7ac, 450);
            GetGameResult().m_getGame[w][gameNo] = 1;
            RULE_ASSERT(gameNo < BULK_OF(GetGameResult().m_pointPerGame[0]), DAT_0037d7dc, 454);
            GetGameResult().m_pointPerGame[0][gameNo] = min_(DAT_0037d780, self->points[0]);
            GetGameResult().m_pointPerGame[1][gameNo] = min_(DAT_0037d784, self->points[1]);
            self->games[w]++;
            self->fa0 = w;
            self->f108 = 0;
            self->m_ResultGame[w][setNo] = self->games[w];
            if ((self->games[0] + self->games[1]) & 1)
                self->fb0 = 1;
            int n = self->doubles ? 2 : 4;
            self->server = (n + (self->base + self->dir)) % n;
            self->f58 = 1;
            bool setWon = false;
            if (self->games[w] >= self->gamesPerSet + 1)
                setWon = true;
            if (self->games[w] >= self->gamesPerSet && self->games[w] - self->games[w ^ 1] >= 2)
                setWon = true;
            if (setWon && !DAT_003e1e88) {
                FUN_000e1e58(self);
                self->games[0] = 0;
                self->games[1] = 0;
                self->sets[w]++;
                self->fa4 = w;
                if (self->sets[w] >= (self->numSets + 1) / 2) {
                    FUN_000e1e94(self);
                    self->fa8 = w;
                    self->fb0 = 0;
                } else {
                    FUN_001c3930(voice, 0x98, 0);
                    FUN_001c3930(voice, mine ? 0x8f : 0x90, 3);
                }
            } else {
                FUN_001c3930(voice, 0x97, 0);
                FUN_001c3930(voice, mine ? 0x8f : 0x90, 3);
            }
            if (FUN_000e30f8(self)) {
                self->points[0] = 0;
                self->points[1] = 0;
            } else {
                self->points[0] = DAT_003eabd3;
                self->points[1] = DAT_003eacf3;
            }
        } else {
            bool deuce;
            int pts[2];
            int adv;
            FUN_000e22ec(self, pts, &deuce, &adv);
            if (!FUN_000e30f8(self)) {
                if (deuce && DAT_003eaaf3 != 1) {
                    if (!self->f108) {
                        FUN_001c3930(voice, 0x8c, 0);
                        self->f108 = 1;
                    } else {
                        FUN_001c3930(voice, 0x8d, 0);
                    }
                } else if (adv >= 0) {
                    FUN_001c3930(voice, 0x8e, 0);
                    FUN_001c3930(voice, mine ? 0x8f : 0x90, 3);
                } else {
                    FUN_001c3930(voice, self->points[side] + 0x83, 0);
                    if (self->points[0] != self->points[1])
                        FUN_001c3930(voice, self->points[side ^ 1] + 0x87, 3);
                    else
                        FUN_001c3930(voice, 0x8b, 3);
                }
            } else {
                int a, b;
                if (self->points[0] > self->points[1]) {
                    a = self->points[0] + 0x9c;
                    b = self->points[1] + 0xa6;
                } else if (self->points[0] < self->points[1]) {
                    a = self->points[1] + 0x9c;
                    b = self->points[0] + 0xa6;
                } else {
                    a = self->points[0] + 0x9c;
                    b = 0x8b;
                }
                FUN_001c3930(voice, a, 0);
                FUN_001c3930(voice, b, 3);
            }
        }
        break;
    }
    case 10:
        FUN_000e07a8(self, 2);
        break;
    case 11:
        break;
    case 14:
        FUN_000e07a8(self, 3);
        break;
    case 15:
        break;
    case 18:
        FUN_000e07a8(self, 4);
        break;
    }
    return 0;
}
