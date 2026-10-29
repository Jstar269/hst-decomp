/* HSTMATCH module=EBOOT.BIN start=0x000f9290 end=0x000f9508 symbol=FUN_000f9290 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; outer switch default-first places case 8 at fallthrough; inner switch case 3..1 lowers to ascending beq chain; 3rd arg 1 to FUN_001ec488 hoists li a2, 1 before switch comparison; names and types await human review. */

#include "hst/root_state.h"

/* Session context: two words at +0xb8 are summed. */
struct SessionExtra {
    char pad[0xb8];
    int fb8;
    int fbc;
};

/* Flag block: a signed 2-bit field at +0x88 (bits 6..7). */
struct FlagBlock {
    char pad[0x88];
    signed char pad_bits:6;
    signed char flag:2;
};

struct Node {
    char pad[0x24];
    int val;
    int val2;
};

struct SubObj {
    virtual void d0();
    virtual void v1();
    char pad_04[0x128 - 4];
    Node *n128;
    Node *n12c;
    char pad_130[0x138 - 0x130];
    Node *n138;
    Node *n13c;
    char pad_140[0x160 - 0x140];
    Node *n160;
    Node *n164;
    Node *n168;
    Node *n16c;
    char pad_170[0x1b8 - 0x170];
    void *p1b8;
    char pad_1bc[0x1e0 - 0x1bc];
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    char pad_1f0[0x208 - 0x1f0];
    int f208;
    int f20c;
};

struct P94 {
    char pad[0x0c];
    int f0c;
};

struct BaseObj {
    virtual void d0();
    virtual void d1();
    virtual void v2();
    char pad_04[0x54 - 4];
    SubObj *sub;
    char pad_58[0x94 - 0x58];
    P94 *p94;
    char pad_98[0x14c - 0x98];
    int f14c;
    int f150;
    char pad_154;
    unsigned char f155;
};

extern "C" {
extern RootState *DAT_003386b0;
extern SessionExtra *DAT_00338b44;
extern FlagBlock *DAT_002cfc8c;
extern int FUN_000889ec();
extern int FUN_000487dc();
extern int FUN_000487c8();
extern void FUN_001ec488(...);
extern void FUN_001ecbc4(P94 *);
extern void FUN_00103480(void *);
}

extern "C" void FUN_000f9290(BaseObj *self) {
    switch (DAT_003386b0->mode) {
    default:
        if (DAT_003386b0 != 0 && FUN_000889ec()) {
            if (FUN_000487dc() && self->f155 == 0) {
                FUN_001ec488(self->p94, 0, 1);
            }
            self->f155 = FUN_000487dc();
            break;
        }
        switch (DAT_003386b0->mode) {
        case 3:
        case 2:
        case 1:
            break;
        default:
            if (self->f155 == 0) {
                if (DAT_002cfc8c->flag == 0) {
                    FUN_001ec488(self->p94, 0, 1);
                    self->f155 = 1;
                    FlagBlock *fb = DAT_002cfc8c;
                    fb->flag = -1;
                }
            } else if (self->p94->f0c == 11) {
                self->f155 = 0;
            }
            break;
        }
        break;
    case 8:
        if (self->f155 == 0) {
            FUN_001ec488(self->p94, DAT_00338b44->fb8 + DAT_00338b44->fbc, 0);
        }
        self->f155 = 1;
        break;
    }

    if (!FUN_000487c8()) {
        self->v2();
        self->f150 = 0;
    } else if (DAT_003386b0->mode != 4) {
        FUN_001ecbc4(self->p94);
    } else {
        if (self->f150 == 0) {
            FUN_00103480(self->sub);
            FUN_00103480(self->sub->p1b8);
            SubObj *sub = self->sub;
            sub->f1e0 = sub->n128->val;
            sub->f1e4 = sub->n12c->val;
            sub->f1e8 = sub->n138->val;
            sub->f1ec = sub->n13c->val;
            self->sub->v1();
            SubObj *sub2 = self->sub;
            int v = sub2->n168->val;
            Node *n160 = sub2->n160;
            n160->val = v;
            n160->val2 = v;
            sub2->f208 = sub2->n168->val;
            int v2 = sub2->n16c->val;
            Node *n164 = sub2->n164;
            n164->val = v2;
            n164->val2 = v2;
            sub2->f20c = sub2->n16c->val;
            self->f14c = 0;
        }
        self->v2();
        self->f150++;
    }
}
