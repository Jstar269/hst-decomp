/* HSTMATCH module=hstp_trans_main.prx start=0x000e2c0c end=0x000e30f8 symbol=FUN_000e2c0c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rule.cpp (struct layout as in src/eboot/rule_on_event_000dbc90.cpp): match-point test for a team (-1 = either);
   FUN_000e2708 is the set-point test of the same shape, FUN_000e30f8 the tie-break test. */
struct Player { char pad0[0x144]; int side; };
struct Game { char pad0[0x70]; Player *players[12]; };
struct Rule {
    char pad0[0x50];
    int base;          /* 0x50 */
    char pad54[0xb4 - 0x54];
    int numSets;       /* 0xb4 */
    int sets[2];       /* 0xb8 */
    int gamesPerSet;   /* 0xc0 */
    int games[2];      /* 0xc4 */
    int pointsPerGame; /* 0xcc */
    int points[2];     /* 0xd0 */
};

extern Game *DAT_003e19f0;
extern unsigned char DAT_003e1e88;
extern unsigned char DAT_003eaaf3;

extern "C" {
int FUN_000e30f8(Rule *self);
bool FUN_000e2708(Rule *self, int team);
bool FUN_000e2c0c(Rule *self, int team);
}

static inline int Server(Rule *self) { return DAT_003e19f0->players[self->base]->side; }

/* true when winning the next point would win the current game for side w */
static inline bool NextPointWinsGame(Rule *self, int w)
{
    bool won;
    if (FUN_000e30f8(self))
        won = self->points[w] + 1 > 8 || (self->points[w] + 1 >= 7 && self->points[w] + 1 - self->points[w ^ 1] >= 2);
    else
        won = self->points[w] + 1 >= self->pointsPerGame && (self->points[w] + 1 - self->points[w ^ 1] >= 2 || DAT_003eaaf3 == 1);
    return won;
}

extern "C" bool FUN_000e2c0c(Rule *self, int team)
{
    if (DAT_003e1e88)
        return false;
    if (FUN_000e2708(self, team)) {
        int side = Server(self);
        if (NextPointWinsGame(self, side) && NextPointWinsGame(self, Server(self) ^ 1)) {
            if (team == -1)
                return FUN_000e2c0c(self, 0) || FUN_000e2c0c(self, 1);
            side = team;
        } else if (!NextPointWinsGame(self, Server(self))) {
            if (NextPointWinsGame(self, Server(self) ^ 1))
                side ^= 1;
            else
                side = -1;
        }
        if (side >= 0 && (team < 0 || team == side))
            return self->sets[side] + 1 >= (self->numSets + 1) / 2;
    }
    return false;
}
