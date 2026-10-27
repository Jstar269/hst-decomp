/* HSTMATCH module=hstp_trans_main.prx start=0x000e1b54 end=0x000e1d9c symbol=FUN_000e1b54 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rule.cpp (assert text "m_GetPointTeamNo >= 0", line 0x4e1): per-point statistics counters of the match rule object. */
struct Player {
    char pad0[0x144];
    int side;   /* 0x144 */
};

struct PlayerStats {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    char pad18[0x4c - 0x18];
    int f4c;
    char pad50[0x5c - 0x50];
};

struct MatchRecord {
    char pad0[0x64];
    int teamPoints[2];          /* 0x64 */
    PlayerStats players[2];     /* 0x6c */
    char pad124[0x1fc - 0x124];
    int f1fc;                   /* 0x1fc */
};

struct Game {
    char pad0[0xa0];
    MatchRecord *record;  /* 0xa0 */
};

struct Rule {
    char pad0[0x5f];
    unsigned char f5f;      /* 0x5f */
    char pad60[2];
    unsigned char f62;      /* 0x62 */
    unsigned char f63;      /* 0x63 */
    char pad64[0x78 - 0x64];
    int f78;                /* 0x78 */
    char pad7c[0x90 - 0x7c];
    int f90;                /* 0x90 */
    int f94;                /* 0x94 */
    int f98;                /* 0x98 */
    int m_GetPointTeamNo;   /* 0x9c */
};

extern Game *DAT_003e19f0;

extern const char DAT_0037d738[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_0037d774[]; /* "Rule.cpp" */
extern const char DAT_0037d854[]; /* "m_GetPointTeamNo >= 0" */

extern "C" {
Player *FUN_00089f84(Game *g);
int FUN_000e25dc(Rule *s, int side);
void FUN_000df718(...);
}

#define RULE_ASSERT(c, text, line) \
    if (!(c)) { FUN_000df718(DAT_0037d738, text, DAT_0037d774, line); while (1) {} }

extern "C" void FUN_000e1b54(Rule *self)
{
    if (FUN_000e25dc(self, FUN_00089f84(DAT_003e19f0)->side))
        DAT_003e19f0->record->f1fc++;
    if (self->f78 >= 0)
        DAT_003e19f0->record->players[self->f78].f4++;
    RULE_ASSERT(self->m_GetPointTeamNo >= 0, DAT_0037d854, 0x4e1);
    DAT_003e19f0->record->teamPoints[self->m_GetPointTeamNo]++;
    if (self->f94 == self->m_GetPointTeamNo) {
        if (self->f90 == 1) {
            if (!self->f62)
                DAT_003e19f0->record->players[self->f98].fc++;
        } else {
            if (!self->f62)
                DAT_003e19f0->record->players[self->f98].f8++;
            if (self->f63)
                DAT_003e19f0->record->players[self->f98].f4c++;
        }
    } else {
        if (self->f90 >= 2)
            DAT_003e19f0->record->players[self->f98].f10++;
        if (self->f5f)
            DAT_003e19f0->record->players[self->f98].f14++;
    }
}
