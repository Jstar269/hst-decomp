/* HSTMATCH module=EBOOT.BIN start=0x0011a57c end=0x0011a7d8 symbol=FUN_0011a57c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; earlier declaration order int other_side, side_now assigns other_side=$17 and side_now=$16; int index_bytes=cur_player*4, players_base=(int)DAT_003386b0 gives addu v1, a0, v1; names and types await human review. */

#include "hst/action_pair_obj.h"

struct Player {
    char pad[0x144];
    int side;
};

struct Game {
    char pad[0x70];
    Player *players[1];
};

struct GlobB {
    char pad[0x50];
    int cur_player;
};

/* Priority levels: a side only takes over when it outranks the stored level. */
enum { PRIO_LOW = 100, PRIO_MID = 110, PRIO_HIGH = 200, PRIO_HIGHER = 210, PRIO_TOP = 300, PRIO_TOP_ALT = 310 };

extern "C" {
extern Game *DAT_003386b0;
extern GlobB *DAT_00338b44;

extern int FUN_000de2c8(GlobB *, int);
extern int FUN_000de3f0(GlobB *, int);
extern int FUN_000de51c(GlobB *, int);
extern int FUN_000dea20(GlobB *, int);

void FUN_0011a57c(ActionPairObj *self);
}

void FUN_0011a57c(ActionPairObj *self) {
    self->action[0] = 27;
    self->action[1] = 27;

    int other_side;
    int side_now = self->side;
    int claimed = self->claimed_side;
    other_side = !side_now;

    if (claimed != side_now) {
        if (FUN_000dea20(DAT_00338b44, side_now) && self->priority < PRIO_TOP_ALT) {
            self->claimed_side = side_now;
            self->priority = PRIO_TOP_ALT;
            self->action[0] = 11;
            self->action[1] = 23;
            return;
        }
        if (FUN_000de51c(DAT_00338b44, side_now) && self->priority < PRIO_HIGHER) {
            self->claimed_side = side_now;
            self->priority = PRIO_HIGHER;
            self->action[0] = 17;
            self->action[1] = 22;
            return;
        }
        if ((FUN_000de2c8(DAT_00338b44, side_now) || FUN_000de3f0(DAT_00338b44, side_now)) && self->priority < PRIO_MID) {
            self->claimed_side = side_now;
            self->priority = PRIO_MID;
            self->action[0] = 5;
            int index_bytes = DAT_00338b44->cur_player * 4;
            int players_base = (int)DAT_003386b0;
            Player *cur = *(Player **)(index_bytes + players_base + 0x70);
            self->action[1] = (self->side == cur->side) ? 21 : 24;
            return;
        }
    }

    if (self->claimed_side != other_side) {
        if (FUN_000dea20(DAT_00338b44, other_side) && self->priority < PRIO_TOP) {
            self->claimed_side = other_side;
            self->priority = PRIO_TOP;
            self->action[0] = 11;
            self->action[1] = 25;
            return;
        }
        if (FUN_000de51c(DAT_00338b44, other_side) && self->priority < PRIO_HIGH) {
            self->claimed_side = other_side;
            self->priority = PRIO_HIGH;
            self->action[0] = 17;
            return;
        }
        if ((FUN_000de2c8(DAT_00338b44, other_side) || FUN_000de3f0(DAT_00338b44, other_side)) && self->priority < PRIO_LOW) {
            self->claimed_side = other_side;
            self->priority = PRIO_LOW;
            self->action[0] = 5;
            return;
        }
    }
}
