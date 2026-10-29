/* HSTMATCH module=EBOOT.BIN start=0x000f0db8 end=0x000f0e94 symbol=FUN_000f0db8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

/* Global object (selected by DAT_00338b44): two values the boxes are offset by. */
struct Glob_000f0db8 {
    char pad0[0xb4];
    int fb4;
    char padb8[8];
    int fc0;
    int GetB4() const { return fb4; }
};
extern "C" {
extern int DAT_002d7554;
extern int DAT_002d756c;
extern Glob_000f0db8 *DAT_00338b44;
extern void FUN_00102c54(FadeNode *);
}

/* Reset the three layers' position (dropped 14 pixels unless the flag is set) and offset the two boxes. */
extern "C" void FUN_000f0db8(PointPane *self)
{
    for (int i = 0; i < POINT_LAYER_COUNT; i++) {
        FadeNode *layer = self->layer[i];
        float drop;
        if (self->unka0 != 0) {
            drop = 0.0f;
        } else {
            drop = -14.0f;
        }
        if (layer != 0) {
            layer->x = 0.0f;
            layer->y = drop + -32.0f;
            layer->alpha = 0.0f;
            FUN_00102c54(layer);
            self->scale = layer->alpha;
        }
    }
    int c0 = DAT_00338b44->fc0;
    int x = DAT_002d7554 + DAT_00338b44->GetB4();
    PaneQuad *box = self->item[7];
    box->value = x;
    box->base = x;
    int y = DAT_002d756c + c0;
    PaneQuad *box2 = self->item[9];
    box2->value = y;
    box2->base = y;
}
