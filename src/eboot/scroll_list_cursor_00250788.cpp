/* HSTMATCH module=EBOOT.BIN start=0x00250788 end=0x002508ac symbol=FUN_00250788 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/scroll_list_cursor_00260adc.cpp, identical masked code: addresses substituted); exact match verified (matching idiom: the clamp is an inline taking its value and bounds by const reference, which reloads the global lower bound like retail); names and types await human review. */
/* Moves a 16-row list cursor by delta: inside the window only the row (+0x35c) changes; past the top or bottom
   edge the row is pinned (0 / 15) and the first visible index (+0x364) is taken from +0x300 or +0x2fc (chosen by
   FUN_00250cc4) and clamped between the global minimum DAT_002fcbc0 / DAT_002fcbc4 and count (+0x308) - 16.
   FUN_002508b4 then refreshes the list. Names provisional. */
#include "hst/scroll_list_obj.h"
extern "C" {
extern int DAT_002fcbc0;
extern int DAT_002fcbc4;
int FUN_00250cc4(ScrollListObj *self);
void FUN_002508b4(ScrollListObj *self);
}
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00250788(ScrollListObj *self, int delta)
{
    int max;
    if (self->count < SCROLL_LIST_ROWS) {
        max = 0;
    } else {
        max = self->count - SCROLL_LIST_ROWS;
    }
    if (delta < 0) {
        int row = self->row + delta;
        if (row < 0) {
            self->row = 0;
            self->top = FUN_00250cc4(self) != 0 ? self->unk300 : self->unk2fc;
            self->top = Clamp(self->top, DAT_002fcbc0, max);
        } else {
            self->row = row;
        }
    } else {
        int row = self->row + delta;
        if (row > SCROLL_LIST_ROWS - 1) {
            self->row = SCROLL_LIST_ROWS - 1;
            self->top = (FUN_00250cc4(self) != 0 ? self->unk300 : self->unk2fc) - (SCROLL_LIST_ROWS - 1);
            self->top = Clamp(self->top, DAT_002fcbc4, max);
        } else {
            self->row = row;
        }
    }
    FUN_002508b4(self);
}
