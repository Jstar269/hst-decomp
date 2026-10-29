/* HSTMATCH module=EBOOT.BIN start=0x001f14a4 end=0x001f15d0 symbol=FUN_001f14a4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed high-offset struct access, single-case switch dispatch, and helper call arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/prize_screen.h"

typedef struct Inner Inner;
typedef struct Node Node;

/* Object with a position pair. */
struct Inner {
    char pad0[0x60];
    float x;                /* 0x60 */
    float y;                /* 0x64 */
};

struct Node {
    char pad0[4];
    Inner **inner;          /* 0x04 */
    char pad8[0x74 - 8];
    float unk74;            /* 0x74 */
    float unk78;            /* 0x78 */
};

#define PHASE_WAIT 1        /* value of unk816c while waiting for the helper to finish */

extern Node *DAT_003415ac;
extern void *DAT_003415d4;

extern void FUN_001905b8(void *, int);
extern int FUN_00190724(void *);
extern void FUN_001e1614(void *);
extern void FUN_001f3770(PrizeScreen *);
extern void FUN_001f474c(PrizeScreen *, int);
extern void FUN_001f47a4(PrizeScreen *);
extern void FUN_001f4bfc(PrizeScreen *);
extern void FUN_001ff668(void);

/* Per-frame update: on the first frame starts the helper and moves the position to its start; once the
   helper reports done, sets the position and continues with the next step. */
void FUN_001f14a4(PrizeScreen *self)
{
    Node *node;
    Node *node2;

    if (self->unk44 == 0) {
        self->unk816c = PHASE_WAIT;
        FUN_001f474c(self, 0);
        FUN_001ff668();
        FUN_001e1614(self->unk510);
        node = DAT_003415ac;
        if (node != 0) {
            (*node->inner)->x = 304.0f;
            (*node->inner)->y = 136.0f;
        }
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001ff668();
    }

    switch (self->unk816c) {
    case PHASE_WAIT:
        if (FUN_00190724(DAT_003415d4) != 0) {
            node = DAT_003415ac;
            if (node != 0) {
                node->unk74 = 1.0f;
                node->unk78 = 1.0f;
                node2 = DAT_003415ac;
                (*node2->inner)->x = 240.0f;
                (*node2->inner)->y = 136.0f;
            }
            FUN_001f3770(self);
        }
        break;
    }

    FUN_001f4bfc(self);
    FUN_001f47a4(self);
}
