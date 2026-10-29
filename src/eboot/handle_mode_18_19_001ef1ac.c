/* HSTMATCH module=EBOOT.BIN start=0x001ef1ac end=0x001ef2d8 symbol=FUN_001ef1ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: two-case switch on mode (cases 18 and 19), restored 3rd argument 1 to FUN_001fb928 and self argument to FUN_001f2f08, and typed DAT_003386b0; readability pass; exact match verified; names and types await human review. */
#include "hst/prize_screen.h"

/* Global game object: table of four entries and a pointer to another object. */
typedef struct Game_001ef1ac {
    char pad0[0x70];
    void *players[PRIZE_PLAYER_COUNT]; /* 0x70 */
    char pad1[0x88 - 0x80];
    char *ball;                        /* 0x88 */
} Game_001ef1ac;

extern Game_001ef1ac *DAT_003386b0;
extern void FUN_0001f20c(void *, int, int);
extern void FUN_001f2f08(PrizeScreen *);
extern void FUN_001fb928(PrizeSub *, int, int);

/* Mode handler: entering turns the screen on; leaving turns it off and calls the helper three times (with
   0, 1 and 2) on each existing table entry and on the object at 0x1e0 of the other pointer. */
int FUN_001ef1ac(PrizeScreen *self, int mode)
{
    switch (mode) {
    case PRIZE_MODE_ENTER:
        self->active = 1;
        FUN_001fb928(&self->sub, 0, 1);
        break;
    case PRIZE_MODE_LEAVE:
        self->active = 0;
        FUN_001f2f08(self);
        for (int i = 0; i < PRIZE_PLAYER_COUNT; i++) {
            if (DAT_003386b0->players[i] != 0) {
                FUN_0001f20c(DAT_003386b0->players[i], 0, 1);
                FUN_0001f20c(DAT_003386b0->players[i], 1, 1);
                FUN_0001f20c(DAT_003386b0->players[i], 2, 1);
            }
        }
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 0, 1);
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 1, 1);
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 2, 1);
        break;
    }
    return 0;
}
