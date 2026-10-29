/* HSTMATCH module=EBOOT.BIN start=0x000dbc90 end=0x000dc6a4 symbol=FUN_000dbc90 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rule.cpp (file name and the m_ResultGame / m_GetPointTeamNo / GetGameResult() names come from the
   hstp_trans_main.prx twin's assert strings): point-won / event handler of the match rule object. */
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
    int unk58;                /* 0x58 */
    char pad5c[4];
    unsigned char unk60;      /* 0x60 */
    unsigned char unk61;      /* 0x61 */
    unsigned char unk62;      /* 0x62 */
    char pad63[0x86 - 0x63];
    unsigned char unk86;      /* 0x86 */
    unsigned char doubleFault;      /* 0x87 */
    unsigned char ace;      /* 0x88 */
    char pad89[0x90 - 0x89];
    int unk90;                /* 0x90 */
    int unk94;                /* 0x94 */
    int unk98;                /* 0x98 */
    int m_GetPointTeamNo;   /* 0x9c */
    int unka0;                /* 0xa0 */
    int unka4;                /* 0xa4 */
    int unka8;                /* 0xa8 */
    char padac[4];
    unsigned char unkb0;      /* 0xb0 */
    char padb1[3];
    int numSets;            /* 0xb4 */
    int sets[2];            /* 0xb8 */
    int gamesPerSet;        /* 0xc0 */
    int games[2];           /* 0xc4 */
    int pointsPerGame;      /* 0xcc */
    int points[2];          /* 0xd0 */
    int m_ResultGame[2][6];  /* 0xd8 */
    unsigned char unk108;     /* 0x108 */
};

extern Game *DAT_003386b0;
extern void *DAT_00338c20;
extern unsigned char DAT_00338b48;
extern unsigned char DAT_003417bb;
extern unsigned char DAT_0034189b;
extern unsigned char DAT_003419bb;
extern int DAT_002d6b04;
extern int DAT_002d6b08;

extern "C" {
Player *FUN_0008882c(Game *g);
int FUN_000fb528(void *p);
void FUN_000dc6a4(Rule *s, int k);
void FUN_000dd524(Rule *s, int k);
void FUN_000dd994(Rule *s);
void FUN_000df060(Rule *s);
int FUN_000def0c(Rule *s);
void FUN_000de100(Rule *s, int *pts, bool *deuce, int *adv);
void FUN_000ddbb0(Rule *s, int w, int side);
void FUN_000ddc6c(Rule *s);
void FUN_000ddca8(Rule *s);
void FUN_001b5c70(void *voice, int id, int ch);
}

/* event ids handled below; 20 is the result of a rally (the point winner is in m_GetPointTeamNo) */
enum { RULE_EV_POINT_RESULT = 20 };

template <class T> static inline const T &min_(const T &a, const T &b) { return b < a ? b : a; }

/* True when side w has won the current game; the win test differs when FUN_000def0c returns nonzero. */
static inline bool GameWon(Rule *self, int w)
{
    bool won;
    if (FUN_000def0c(self))
        won = self->points[w] > 8 || (self->points[w] >= 7 && self->points[w] - self->points[w ^ 1] >= 2);
    else
        won = self->points[w] >= self->pointsPerGame && (self->points[w] - self->points[w ^ 1] >= 2 || DAT_003417bb == 1);
    return won;
}

static inline GameResult &GetGameResult() { return DAT_003386b0->record->result; }

extern "C" int FUN_000dbc90(Rule *self, int ev)
{
    switch (ev) {
    case 0:
        FUN_000dc6a4(self, 0);
        break;
    case 1:
        break;
    case 7: {
        int court = FUN_0008882c(DAT_003386b0)->court & 1;
        if (FUN_000fb528(DAT_00338c20))
            self->server = court;
        else
            self->server = (court + 1) % 2;
        self->dir = (self->server & 1) ? -1 : 1;
        self->base = self->server;
        break;
    }
    case 8:
        FUN_000dc6a4(self, 1);
        break;
    case 9:
        break;
    case RULE_EV_POINT_RESULT: {
        if (self->m_GetPointTeamNo < 0 || !self->active)
            break;
        FUN_000dd524(self, self->unk98);
        FUN_000dd994(self);
        self->active = 0;
        self->unkb0 = 0;
        int w = self->m_GetPointTeamNo;
        void *voice = DAT_003386b0->voice;
        int side = DAT_003386b0->players[self->base]->side;
        bool mine = w == side;
        FUN_0008882c(DAT_003386b0);
        self->points[w]++;
        if (w == self->unk94 && !self->unk61 && !self->unk62) {
            self->unk86 = self->unk90 == 1;
            self->doubleFault = self->unk90 == 2;
            self->ace = self->unk60;
            if (self->doubleFault)
                DAT_003386b0->record->result.players[self->unk98].doubleFaults++;
            if (self->ace)
                DAT_003386b0->record->result.players[self->unk98].aces++;
        }
        FUN_000df060(self);
        self->unk58 = -self->unk58;
        if (FUN_000def0c(self) || DAT_00338b48) {
            if ((self->points[0] + self->points[1]) % 2 == 1) {
                int n = self->doubles ? 2 : 4;
                self->server = (n + (self->base + self->dir)) % n;
            }
        }
        if (FUN_000def0c(self) && (self->points[0] + self->points[1]) % 6 == 0)
            self->unkb0 = 1;
        if (GameWon(self, w)) {
            FUN_000ddbb0(self, w, side);
            if (!DAT_0034189b && !DAT_003419bb && self->points[w ^ 1] == 0)
                DAT_003386b0->record->result.players[w].loveGames++;
            int setNo = self->sets[0] + self->sets[1];
            int gameNo = 0;
            for (int i = 0; i <= setNo; i++) {
                gameNo += self->m_ResultGame[0][i];
                gameNo += self->m_ResultGame[1][i];
            }
            GetGameResult().m_getGame[w][gameNo] = 1;
            GetGameResult().m_pointPerGame[0][gameNo] = min_(DAT_002d6b04, self->points[0]);
            GetGameResult().m_pointPerGame[1][gameNo] = min_(DAT_002d6b08, self->points[1]);
            self->games[w]++;
            self->unka0 = w;
            self->unk108 = 0;
            self->m_ResultGame[w][setNo] = self->games[w];
            if ((self->games[0] + self->games[1]) & 1)
                self->unkb0 = 1;
            int n = self->doubles ? 2 : 4;
            self->server = (n + (self->base + self->dir)) % n;
            self->unk58 = 1;
            bool setWon = false;
            if (self->games[w] >= self->gamesPerSet + 1)
                setWon = true;
            if (self->games[w] >= self->gamesPerSet && self->games[w] - self->games[w ^ 1] >= 2)
                setWon = true;
            if (setWon && !DAT_00338b48) {
                FUN_000ddc6c(self);
                self->games[0] = 0;
                self->games[1] = 0;
                self->sets[w]++;
                self->unka4 = w;
                if (self->sets[w] >= (self->numSets + 1) / 2) {
                    FUN_000ddca8(self);
                    self->unka8 = w;
                    self->unkb0 = 0;
                } else {
                    FUN_001b5c70(voice, 0x98, 0);
                    FUN_001b5c70(voice, mine ? 0x8f : 0x90, 3);
                }
            } else {
                FUN_001b5c70(voice, 0x97, 0);
                FUN_001b5c70(voice, mine ? 0x8f : 0x90, 3);
            }
            if (FUN_000def0c(self)) {
                self->points[0] = 0;
                self->points[1] = 0;
            } else {
                self->points[0] = DAT_0034189b;
                self->points[1] = DAT_003419bb;
            }
        } else {
            bool deuce;
            int pts[2];
            int adv;
            FUN_000de100(self, pts, &deuce, &adv);
            if (!FUN_000def0c(self)) {
                if (deuce && DAT_003417bb != 1) {
                    if (!self->unk108) {
                        FUN_001b5c70(voice, 0x8c, 0);
                        self->unk108 = 1;
                    } else {
                        FUN_001b5c70(voice, 0x8d, 0);
                    }
                } else if (adv >= 0) {
                    FUN_001b5c70(voice, 0x8e, 0);
                    FUN_001b5c70(voice, mine ? 0x8f : 0x90, 3);
                } else {
                    FUN_001b5c70(voice, self->points[side] + 0x83, 0);
                    if (self->points[0] != self->points[1])
                        FUN_001b5c70(voice, self->points[side ^ 1] + 0x87, 3);
                    else
                        FUN_001b5c70(voice, 0x8b, 3);
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
                FUN_001b5c70(voice, a, 0);
                FUN_001b5c70(voice, b, 3);
            }
        }
        break;
    }
    case 10:
        FUN_000dc6a4(self, 2);
        break;
    case 11:
        break;
    case 14:
        FUN_000dc6a4(self, 3);
        break;
    case 15:
        break;
    case 18:
        FUN_000dc6a4(self, 4);
        break;
    }
    return 0;
}
