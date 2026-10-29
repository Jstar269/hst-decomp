/* HSTMATCH module=hstp_trans_main.prx start=0x001eedc4 end=0x001ef2a8 symbol=FUN_001eedc4 lang=c++ data=0x00393a40 */
/* Hand-written reconstruction (port of src/eboot/screen_update_001e0ba0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Per-frame update of a screen object: each optional part (a virtual-call object at +0x3c.. and the 0x8c-byte sub-objects updated by 0x217940 beside it) is updated when present; two pulse counters (+0x28b4/+0x28b8) and one (+0x2354) step a 5-entry grey table (0x80,0xc0,0xff,0xc0,0x80; anonymous .data at 0x393a40, local copy loop) into colour words; the countdown at +0x2528 calls 0x1e7cf0 when it runs out. Matching idioms: the first guard is a one-case `switch (s->mode) { case 0: ... }` (an `if (s->mode == 0)` lays the block out with bnezl and without retail's `beqzl ...; b` pair and its unfilled inner slot); the table is a local `const unsigned char tab[5]` initialiser; `Gray(c)` = (c << 24) | (c << 16) | (c << 8) | c; the third counter block re-reads tab[0] when the decremented value is 0. Names provisional. */
#include "hst/result_scene.h"

/* Part object: only the update call (vtable slot 2) is used here. */
struct ResultPart {
    virtual void V0();
    virtual void V1();
    virtual void Update();
};
extern "C" {
void FUN_002269e8(Animator *);
void FUN_0022697c(Animator *);
void FUN_00105470(void *, int);
void FUN_001055a4(ResultColor *, unsigned);
void FUN_001f5f08(ResultScene *);
}
static inline unsigned Gray(unsigned c)
{
    return (c << 24) | (c << 16) | (c << 8) | c;
}
/* Per-frame update of the result scene. */
extern "C" void FUN_001eedc4(ResultScene *s)
{
    const unsigned char tab[5] = { 0x80, 0xc0, 0xff, 0xc0, 0x80 };
    switch (s->mode) {
    case 0:
        FUN_002269e8(&s->anim48);
        s->part40->Update();
        if (s->partd4 != 0) {
            FUN_002269e8(&s->anim168);
            s->partd4->Update();
        }
        break;
    }
    if (s->part3c != 0)
        s->part3c->Update();
    if (s->part25b8 != 0) {
        FUN_002269e8(&s->anim279c);
        FUN_002269e8(&s->anim2828);
        s->part25b8->Update();
        if (s->pulseA > 0) {
            unsigned u = --s->pulseA;
            FUN_001055a4(s->color25f8, Gray(tab[u % 5]));
        }
        if (s->pulseB > 0) {
            unsigned u = --s->pulseB;
            FUN_001055a4(s->color25e4, Gray(tab[u % 5]));
        }
    }
    if (s->part1f4 != 0) {
        FUN_002269e8(&s->anim3ac);
        FUN_002269e8(&s->anim43c);
        FUN_002269e8(&s->anim4c8);
        FUN_002269e8(&s->anim554);
        FUN_002269e8(&s->anim5e0);
        FUN_002269e8(&s->anim66c);
        if (s->anim66c.block3c.done != 0) {
            FUN_0022697c(&s->anim66c);
            FUN_00105470(s->unk270, 1);
        }
        FUN_002269e8(&s->anim6f8);
        FUN_002269e8(&s->anim784);
        s->part1f4->Update();
    }
    if (s->part9b4 != 0)
        s->part9b4->Update();
    if (s->part810 != 0) {
        FUN_002269e8(&s->anim89c);
        FUN_002269e8(&s->anim928);
        s->part810->Update();
    }
    if (s->part175c != 0) {
        FUN_002269e8(&s->anim183c);
        FUN_002269e8(&s->anim18c8);
        s->part175c->Update();
    }
    if (s->part1954 != 0)
        s->part1954->Update();
    if (s->part1d68 != 0) {
        FUN_002269e8(&s->anim1f28);
        FUN_002269e8(&s->anim1fb4);
        FUN_002269e8(&s->anim2040);
        FUN_002269e8(&s->anim20cc);
        FUN_002269e8(&s->anim2158);
        s->part1d68->Update();
    }
    if (s->part1958 != 0) {
        FUN_002269e8(&s->anim1b34);
        FUN_002269e8(&s->anim1c4c);
        FUN_002269e8(&s->anim1bc0);
        FUN_002269e8(&s->anim1cd8);
        s->part1958->Update();
        if (s->part1d64 != 0)
            s->part1d64->Update();
    }
    bool b = false;
    if (s->part21e4 != 0) {
        FUN_002269e8(&s->anim22c4);
        s->part21e4->Update();
        if (s->pulseC > 0) {
            unsigned u = --s->pulseC;
            unsigned char c = tab[u % 5];
            if (u == 0)
                c = tab[0];
            FUN_001055a4(s->slotsA[s->slotIndex].color, Gray(c));
        }
        b = true;
    }
    if (s->part235c != 0) {
        FUN_002269e8(&s->anim22c4);
        s->part235c->Update();
        if (s->pulseC > 0 && !b) {
            unsigned u = --s->pulseC;
            unsigned char c = tab[u % 5];
            if (u == 0)
                c = tab[0];
            FUN_001055a4(s->slotsB[s->slotIndex].color, Gray(c));
        }
    }
    if (s->part2464 != 0) {
        FUN_002269e8(&s->anim2480);
        s->part2464->Update();
    }
    if (s->part250c != 0) {
        FUN_002269e8(&s->anim252c);
        s->part250c->Update();
        if (s->countdown > 0 && --s->countdown < 1) {
            s->countdown = 0;
            FUN_001f5f08(s);
        }
    }
}
