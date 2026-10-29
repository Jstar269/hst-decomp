/* HSTMATCH module=EBOOT.BIN start=0x00092078 end=0x00092258 symbol=FUN_00092078 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: restored the float types, split the table index into two statements and reordered the float/int call parameters; readability pass; exact match verified; names and types await human review. */
#include "hst/char_model.h"

extern float DAT_002d2900; /* lower bound of the blend value for item 2 */
extern float DAT_002d2904; /* lower bound of the blend value for item 0 */
extern void FUN_00058f38(ModelItem *, float, int);
extern void FUN_0005f030(float, ModelItem *, int);
extern void FUN_0005f110(ModelItem *, float);
extern void FUN_00093750(float, CharModel *, int, int);
extern void FUN_00093778(CharModel *, int, int);
extern void FUN_00093be0(CharModel *, int);
extern void FUN_00093c08(CharModel *, int);

/* Applies state to one channel of a character: switches item 2's channel when its state differs
   (state < 0 clears it), mirrors the state onto item 0 for channel 0, and when blend and state are
   non-negative updates the items with the blend value. */
void FUN_00092078(float blend_in, CharModel *self, int state, int flag, int channel)
{
    float blend;
    float blend_copy;
    float *clamped;
    int cur_state;
    int changed;
    ModelItem *item;

    blend = blend_in;
    changed = 0;
    if (self->item[2] != 0) {
        cur_state = self->item[2]->chan[channel].state;
    } else
        cur_state = -1;
    if (state != cur_state) {
        changed = 1;
        FUN_00093778(self, flag, channel);
        if (DAT_002d2900 < blend)
            clamped = &blend;
        else
            clamped = &DAT_002d2900;
        FUN_00093750(*clamped, self, channel, state);
        if (state >= 0)
            FUN_00093be0(self, channel);
        else
            FUN_00093c08(self, channel);
    }
    if (((channel == 0) && (item = self->item[0], item != 0)) &&
        (state != item->unka0) && (item != 0)) {
        if (DAT_002d2904 < blend)
            clamped = &blend;
        else
            clamped = &DAT_002d2904;
        FUN_0005f030(*clamped, item, state);
        self->item[0]->unkc0 = (char)flag;
        self->item[0]->unkd0 = self->item[0]->unkc4;
    }
    blend_copy = blend;
    if ((blend >= 0.0f) && (state >= 0)) {
        item = self->item[2];
        if ((item != 0) && (!changed)) {
            FUN_00058f38(item, blend_copy, channel);
            FUN_0005f110(item, blend_copy);
        }
        if ((channel == 0) && (self->item[0] != 0))
            FUN_0005f110(self->item[0], blend);
    }
}
