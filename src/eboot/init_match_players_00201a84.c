/* HSTMATCH module=EBOOT.BIN start=0x00201a84 end=0x00201cf4 symbol=FUN_00201a84 lang=c99 data=0x002ef19c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ef19c-0x002ef1af) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Matching idioms: the radians conversion must be one direct multiply expression assigned to the member (a local factor puts the constant in the multiply destination FPR); the two player statements use distinct p1/p2 locals (retail reuses s1) and access the member directly for the two later stat reads. */
#include "hst/match_players.h"
#include "hst/game.h"

extern void *FUN_001fd170(void);
extern float FUN_00093898(Player *);
extern float FUN_000657e4(void *, char *, int);
extern float FUN_00195a18(float, float, int);
extern void FUN_00093484(Player *, float);
extern void FUN_00091c48(Player *, int);
extern void FUN_0012b2b0(float, Player *, int, int);
extern void FUN_0019335c(void *, void *, void *);
extern Game *DAT_0034a13c;

/* Sets up the two-player object: records the players and their current values, then applies the
   stat-derived value (BaseTall / Rating lookups) to each. */
void FUN_00201a84(MatchPlayers *self, unsigned char kind, Player *a, Player *b)
{
    Player *p1;
    Player *p2;
    void *stats;
    int x;
    int y;

    self->kind = kind;
    self->count = 0;
    void *r = FUN_001fd170();
    float angle = *(float *)((char *)r + 0x10) * 0.017453292f;
    self->unk10 = 0;
    self->angleRad = angle;
    self->unk18 = 0;
    self->unk1c = 0;
    self->p1 = a;
    self->p2 = b;
    if (self->p1 != 0) {
        self->count++;
    }
    if (self->p2 != 0) {
        self->count++;
    }
    x = 0;
    y = 0;
    FUN_0019335c(&x, &y, DAT_0034a13c->unk58);
    p1 = self->p1;
    stats = DAT_0034a13c->unk12c4;
    if (p1 != 0) {
        self->saved20[0] = p1->sub ? p1->sub->unkf0 : -1;
        self->saved28[0] = self->p1->sub ? self->p1->sub->unkf8 : 0;
        self->saved2c[0] = FUN_00093898(self->p1);
        self->saved34[0] = self->p1->sub ? self->p1->sub->unk104 : 0.0f;
        self->saved3c[0] = p1->unk32d;
        FUN_0012b2b0(-1.0f, p1, 0, 1);
        FUN_00093484(self->p1, FUN_00195a18(FUN_000657e4(stats, "BaseTall", 1),
                                  FUN_000657e4(stats, "Rating", 1), x));
        FUN_00091c48(p1, -1);
    }
    p2 = self->p2;
    if (p2 != 0) {
        self->saved20[1] = p2->sub ? p2->sub->unkf0 : -1;
        self->saved28[1] = self->p2->sub ? self->p2->sub->unkf8 : 0;
        self->saved2c[1] = FUN_00093898(self->p2);
        self->saved34[1] = self->p2->sub ? self->p2->sub->unk104 : 0.0f;
        self->saved3c[1] = p2->unk32d;
        FUN_0012b2b0(-1.0f, p2, 0, 1);
        FUN_00093484(self->p2, FUN_00195a18(FUN_000657e4(stats, "BaseTall", 1),
                                  FUN_000657e4(stats, "Rating", 1), y));
        FUN_00091c48(p2, -1);
    }
}
