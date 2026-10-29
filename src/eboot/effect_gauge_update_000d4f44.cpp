/* HSTMATCH module=EBOOT.BIN start=0x000d4f44 end=0x000d5060 symbol=FUN_000d4f44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_set.h"

/* Player view: only the gauge value and the model pointer are used. */
struct Model;
struct Player { char pad0[0x41c]; int unk41c; char pad420[0x5bc - 0x420]; Model *model; };
/* Global game object: array of player pointers. */
struct Game { char pad0[0x70]; Player *players[4]; };
/* Per-slot view: the effect object starts at 0x50. */
struct Entry { char pad0[0x50]; char eff[0x80]; float unkd0; char pad_d4[0x154 - 0xd4]; float unk154; char pad158[0x1b0 - 0x158]; };
extern "C" {
extern Game *DAT_003386b0;
extern float DAT_00341314;
void FUN_000550c8(void *, void *);
void FUN_00058e50(void *, int, float);
void FUN_00058f38(void *, float, int);
void FUN_00059174(void *);
void FUN_0005f0d8(void *);
void FUN_0005f110(void *, float);
void *FUN_00093838(Model *);
}
extern "C" void FUN_000d4f44(Entry *entries)
{
    int i = 0;
    int off = 0;
    Entry *p = entries;
    do {
        Player *pl = *(Player **)((char *)DAT_003386b0 + off + 0x70);
        if (pl) {
            float ratio = (float)pl->unk41c / DAT_00341314; /* gauge fraction */
            if (ratio == 0.0f) {
                FUN_00058f38(p->eff, 0.0f, -1);
                FUN_0005f110(p->eff, 0.0f);
                FUN_00058e50(p->eff, -1, 0.0f);
            } else if (ratio == 1.0f) {
                FUN_00058e50(p->eff, -1, 33.0f);
            }
            FUN_000550c8(p->eff, FUN_00093838(pl->model));
            FUN_00059174(p->eff);
            FUN_0005f0d8(p->eff);
            p->unkd0 = p->unk154;
        }
        i++; off += 4; p++;
    } while (i < EFFECT_SLOTS);
}
