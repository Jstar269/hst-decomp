/* HSTMATCH module=EBOOT.BIN start=0x0021d164 end=0x0021d340 symbol=FUN_0021d164 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/parts_pane.h"

/* 8-byte entry of the table at DAT_0034b5d4; the low nibble (signed) picks the variant. */
struct PartsEntry { signed char lo : 4; signed char hi : 4; char pad[7]; };

#define PARTS_ENTRY_COUNT 0x1e
#define PARTS_VARIANT_NONE 5 /* variant value outside 0..4 */

extern "C" {
extern int DAT_002eff90;
extern int DAT_002f0590;
extern int DAT_002f05b4;
extern int DAT_002f05d8;
extern float DAT_002f05ec[];
extern float DAT_002f0618;
extern float DAT_002f061c;
extern float DAT_0034a1a0;
extern float DAT_0034a1a4;
extern float DAT_0034a1b0;
extern PartsEntry *DAT_0034b5d4;
extern char DAT_0034179c;
void FUN_00103480(PartsPane *);
int FUN_001b2af0(char *, int);
void FUN_0021d3f8(PartsPane *);
}
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (!(v > hi) ? v : hi); }

/* Sets the pane mode: derives the variant from the mode's table entry, restarts the animation timer, offsets the
   three item ranges by the variant, places the layers and starts a sound. */
extern "C" void FUN_0021d164(PartsPane *self, int mode)
{
    self->mode = mode;
    self->variant = 0;
    int k = self->mode;
    PartsEntry *tab = DAT_0034b5d4;
    int v;
    if (k >= 0 && k < PARTS_ENTRY_COUNT) {
        v = tab[k].lo;
    } else {
        v = PARTS_VARIANT_NONE;
    }
    switch (v) {
    case 0:
        self->variant = 0;
        break;
    case 1:
        self->variant = 1;
        break;
    case 2:
        self->variant = 2;
        break;
    case 3:
        self->variant = 3;
        break;
    case 4:
        self->variant = 0;
        break;
    }
    self->timer = DAT_002eff90;
    self->active = 1;
    FUN_0021d3f8(self);
    int a = DAT_002f0590 + self->variant;
    PaneItem *it = self->item[1];
    it->unk24 = a;
    it->unk28 = a;
    int b = DAT_002f05b4 + self->variant;
    PaneItem *it2 = self->item[4];
    it2->unk24 = b;
    it2->unk28 = b;
    int c = DAT_002f05d8 + self->variant;
    PaneItem *it3 = self->item[7];
    it3->unk24 = c;
    it3->unk28 = c;
    int i = 0;
    do {
        self->layer[i]->unk60 = DAT_0034a1a0;
        self->layer[i]->unk64 = DAT_0034a1a4 + DAT_002f05ec[self->selected];
        self->layer[i]->unk78 = Clamp(DAT_0034a1b0, DAT_002f0618, DAT_002f061c);
        i++;
    } while (i < PARTS_LAYER_COUNT);
    FUN_00103480(self);
    self->sound = FUN_001b2af0(&DAT_0034179c, 0xd);
}
