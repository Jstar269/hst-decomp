/* HSTMATCH module=EBOOT.BIN start=0x002a5680 end=0x002a57ec symbol=FUN_002a5680 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: readability pass, switch structure for mode dispatch, loop predicate variable, matching idiom (loop counter declared as parameter to steer s-register allocation); exact match verified; names and types await human review. */
#include "hst/types.h"

enum { CHOICE_COUNT = 4 };

typedef struct ChoiceScreen {
    char pad00[0x78];
    u32 off_item[CHOICE_COUNT];     /* 0x78 shown while the choice is not selected */
    u32 on_item[CHOICE_COUNT];      /* 0x88 shown while the choice is selected */
    char pad98[0xd4 - 0x98];
    u32 unkd4;                      /* 0xd4 */
} ChoiceScreen;

extern u32 DAT_0034b354;
extern void FUN_000ffb3c(u32, int);
extern void FUN_0010b8cc(u32, int, int);
extern void FUN_00110a78(u32, u32, int);
extern void * FUN_001fea10(int, int, int);
extern void FUN_002a57ec(ChoiceScreen *, int, int);

/* Shows the selected choice's item (hides the others), refreshes the screen and sets the matching text. */
void FUN_002a5680(ChoiceScreen *self, int selected, int i)
{
    int eq;

    i = 0;
    for (; i < CHOICE_COUNT; i++) {
        eq = i == selected;
        FUN_000ffb3c(self->off_item[i], !eq);
        FUN_000ffb3c(self->on_item[i], eq);
    }
    FUN_002a57ec(self, selected, 0);
    FUN_0010b8cc(self->unkd4, selected, 0);
    switch (selected) {
    case 0:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 13), 0);
        break;
    case 1:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 14), 0);
        break;
    case 2:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 17), 0);
        break;
    case 3:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 18), 0);
        break;
    }
}
