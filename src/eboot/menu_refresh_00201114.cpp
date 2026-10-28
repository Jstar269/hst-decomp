/* HSTMATCH module=EBOOT.BIN start=0x00201114 end=0x00201228 symbol=FUN_00201114 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/game.h"

struct Widget_00201114 {
    virtual void Vfn0();
    virtual void Vfn1(int on);
};
struct RefreshMenu {
    void *source;          /* 0x00, passed to the lookup */
    char pad04[0xc];
    Widget_00201114 *left;  /* 0x10 */
    Widget_00201114 *right; /* 0x14 */
};
extern "C" {
void FUN_0019335c(int *a, int *b, void *arg);
void FUN_00200f48(void *self, void *entry, int mode, int idx);
extern Game *DAT_0034a13c;
}

/* Shows both widgets, then hides and fills those whose lookup result is non-zero. */
extern "C" void FUN_00201114(RefreshMenu *self)
{
    int leftEntry = 0;
    int rightEntry = 0;
    FUN_0019335c(&leftEntry, &rightEntry, self->source);
    self->left->Vfn1(1);
    self->right->Vfn1(1);
    if (DAT_0034a13c->unkc4 == 0) {
        if (leftEntry == 0)
            return;
        self->left->Vfn1(0);
        FUN_00200f48(self, (void *)leftEntry, 3, 0);
    } else {
        if (leftEntry != 0) {
            self->left->Vfn1(0);
            FUN_00200f48(self, (void *)leftEntry, 3, 0);
        }
        if (rightEntry != 0) {
            self->right->Vfn1(0);
            FUN_00200f48(self, (void *)rightEntry, 8, 1);
        }
    }
}
