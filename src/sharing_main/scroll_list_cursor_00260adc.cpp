/* HSTMATCH module=hstp_trans_main.prx start=0x00260adc end=0x00260c00 symbol=FUN_00260adc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the clamp is an inline taking its value and bounds by const reference, which reloads the global lower bound like retail); names and types await human review. */
/* Moves a 16-row list cursor by delta: inside the window only the row (+0x35c) changes; past the top or bottom
   edge the row is pinned (0 / 15) and the first visible index (+0x364) is taken from +0x300 or +0x2fc (chosen by
   FUN_00261018) and clamped between the global minimum DAT_003a56b4 / DAT_003a56b8 and count (+0x308) - 16.
   FUN_00260c08 then refreshes the list. Names provisional. */
struct List_00260adc {
    char pad0[0x2fc];
    int f2fc;
    int f300;
    int f304;
    int count;
    char pad1[0x35c - 0x30c];
    int row;
    int f360;
    int top;
};
extern "C" {
extern int DAT_003a56b4;
extern int DAT_003a56b8;
int FUN_00261018(List_00260adc *self);
void FUN_00260c08(List_00260adc *self);
}
static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00260adc(List_00260adc *self, int delta)
{
    int max;
    if (self->count < 16) {
        max = 0;
    } else {
        max = self->count - 16;
    }
    if (delta < 0) {
        int row = self->row + delta;
        if (row < 0) {
            self->row = 0;
            self->top = FUN_00261018(self) != 0 ? self->f300 : self->f2fc;
            self->top = Clamp(self->top, DAT_003a56b4, max);
        } else {
            self->row = row;
        }
    } else {
        int row = self->row + delta;
        if (row > 15) {
            self->row = 15;
            self->top = (FUN_00261018(self) != 0 ? self->f300 : self->f2fc) - 15;
            self->top = Clamp(self->top, DAT_003a56b8, max);
        } else {
            self->row = row;
        }
    }
    FUN_00260c08(self);
}
