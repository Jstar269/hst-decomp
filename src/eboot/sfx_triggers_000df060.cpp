/* HSTMATCH module=EBOOT.BIN start=0x000df060 end=0x000df444 symbol=FUN_000df060 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the other-player flag is `if (unk61 != 0 && player_index >= 0 && side != players[player_index]->side) b = true; else b = false;` (one && chain with both arms assigned: retail's shared false label), kinds 8/9/10 and 11/12 are switch statements, the A arm is the else of `if (F(..) != 0)`, the 4-float copy is four field assignments; names and types await human review. */
#include "hst/ball.h"

struct Vec4 {
    float x, y, z, w;
};
struct Player {
    char pad0[0x144];
    unsigned side;
    char pad1[0x440 - 0x148];
    int unk440;
    char pad2[0x494 - 0x444];
    float unk494;
    char pad3[0x4cc - 0x498];
    unsigned char unk4cc;
    unsigned char unk4cd;
};
struct Rec {
    char pad[0x10];
    Vec4 pos;
};
/* Game singleton: the player table, the ball and the receiver of the trigger ids. */
struct Game {
    char pad0[0x70];
    Player *players[6];
    Ball *ball;
    char pad1[0xa8 - 0x8c];
    void *sfx;
};
/* Event object: flags and ids that select which trigger ids are sent. */
struct Self {
    char pad0[0x61];
    unsigned char unk61;
    unsigned char unk62;
    char pad1[0x67 - 0x63];
    unsigned char unk67;
    char pad2[0x6c - 0x68];
    int kind;
    char pad3[0x71 - 0x70];
    unsigned char unk71;
    unsigned char unk72;
    unsigned char unk73;
    unsigned char unk74;
    char pad4[0x7c - 0x75];
    int unk7c;
    char pad5[0x84 - 0x80];
    unsigned char unk84;
    unsigned char unk85;
    char pad6[0x90 - 0x86];
    int unk90;
    unsigned unk94;
    int player_index;
    unsigned side;
};
extern Game *DAT_003386b0;
extern "C" {
Player *FUN_0008882c(Game *);
int FUN_00088880(Game *, int);
void FUN_001b5640(void *, int);
int FUN_000a8c18(Player *, Vec4 *);
}

/* Sends the trigger ids (190..207) that match the event flags, the player's side and the ball state. */
extern "C" void FUN_000df060(Self *self)
{
    Player *pl = FUN_0008882c(DAT_003386b0);
    if (self->side == pl->side) {
        if (FUN_00088880(DAT_003386b0, self->player_index) != 0) {
            if (self->unk71 != 0) {
                FUN_001b5640(DAT_003386b0->sfx, 199);
            }
        } else {
            if (self->unk72 != 0) {
                FUN_001b5640(DAT_003386b0->sfx, 200);
            }
        }
        return;
    }
    if (FUN_00088880(DAT_003386b0, self->player_index) != 0) {
        Ball *ball = DAT_003386b0->ball;
        void **pp = &ball->vecA.data;
        int off = 0;
        if (ball->vecA.size == 0) {
            off = ball->vecA.size - 1;
        }
        Rec *rec = (Rec *)*pp + off;
        Vec4 v;
        v.x = rec->pos.x;
        v.y = rec->pos.y;
        v.z = rec->pos.z;
        v.w = rec->pos.w;
        if (self->unk85 != 0) {
            FUN_001b5640(DAT_003386b0->sfx, 202);
        }
        bool b;
        if (self->unk61 != 0 && self->player_index >= 0 && self->side != DAT_003386b0->players[self->player_index]->side) {
            b = true;
        } else {
            b = false;
        }
        if (b) {
            switch (self->kind) {
            case 8:
            case 9:
            case 10:
                FUN_001b5640(DAT_003386b0->sfx, 193);
                break;
            default:
                if (FUN_000a8c18(pl, &v) != 0) {
                    FUN_001b5640(DAT_003386b0->sfx, 192);
                }
            }
        } else {
            if (self->unk84 != 0) {
                switch (self->kind) {
                case 11:
                    FUN_001b5640(DAT_003386b0->sfx, 194);
                    break;
                case 12:
                    FUN_001b5640(DAT_003386b0->sfx, 195);
                    if (self->unk7c > 0) {
                        FUN_001b5640(DAT_003386b0->sfx, 190);
                    } else if (self->unk7c < 0) {
                        FUN_001b5640(DAT_003386b0->sfx, 191);
                    }
                    break;
                }
            }
        }
        if (self->unk67 != 0) {
            FUN_001b5640(DAT_003386b0->sfx, 196);
        }
    } else {
        if (self->unk94 == (pl->side ^ 1)) {
            if (self->unk90 >= 3) {
                if (pl->unk494 == 0.0f) {
                    FUN_001b5640(DAT_003386b0->sfx, 203);
                }
            }
            if (pl->unk4cc != 0) {
                if (pl->unk4cd == 0) {
                    FUN_001b5640(DAT_003386b0->sfx, 197);
                }
            }
            if (pl->unk4cd != 0) {
                FUN_001b5640(DAT_003386b0->sfx, 198);
            }
            if (self->unk73 != 0) {
                FUN_001b5640(DAT_003386b0->sfx, 205);
            }
            if (self->unk74 != 0) {
                FUN_001b5640(DAT_003386b0->sfx, 206);
            }
        }
    }
    if (pl->unk440 >= 2) {
        FUN_001b5640(DAT_003386b0->sfx, 204);
    }
    if (self->unk62 != 0) {
        FUN_001b5640(DAT_003386b0->sfx, 207);
    }
}
