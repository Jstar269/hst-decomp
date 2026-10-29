/* HSTMATCH module=EBOOT.BIN start=0x001d2088 end=0x001d2118 symbol=FUN_001d2088 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the copied fields as float; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
extern void FUN_000ffb3c(u32, int);

enum { COLOR_SLOTS = 6 };
#define COLOR_NEUTRAL 0x80808080

typedef struct ColorOwner {
    char pad00[0x6c];
    u32 *colors[COLOR_SLOTS]; /* 0x6c colour words, all reset to neutral */
    u32 widget84;             /* 0x84 */
    u32 widget88;             /* 0x88 */
    char pad8c[0xd4 - 0x8c];
    int cur_index;            /* 0xd4 */
    int next_index;           /* 0xd8 */
    char paddc[0x270 - 0xdc];
    float unk270;             /* 0x270 */
    float unk274;             /* 0x274 */
} ColorOwner;

/* Commits the pending values (index wrapped into 0..5), resets the six colours to neutral and calls FUN_000ffb3c on both widgets. */
void FUN_001d2088(ColorOwner *self)
{
    self->unk270 = self->unk274;
    self->cur_index = (self->next_index + COLOR_SLOTS) % COLOR_SLOTS;
    *self->colors[0] = COLOR_NEUTRAL;
    *self->colors[1] = COLOR_NEUTRAL;
    *self->colors[2] = COLOR_NEUTRAL;
    *self->colors[3] = COLOR_NEUTRAL;
    *self->colors[4] = COLOR_NEUTRAL;
    *self->colors[5] = COLOR_NEUTRAL;
    FUN_000ffb3c(self->widget84, 1);
    FUN_000ffb3c(self->widget88, 1);
}
