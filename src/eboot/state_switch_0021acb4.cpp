/* HSTMATCH module=EBOOT.BIN start=0x0021acb4 end=0x0021ae88 symbol=FUN_0021acb4 lang=c++ rodata=0x002c9954 */
/* Hand-written reconstruction from the disassembly (continued from lane sn1 near-miss wip/state_switch_0021acb4.cpp); exact match verified; matching idiom: `return;` after the inner if/else of cases 6/7/13/18 (keeps retail's unthreaded branch cleanup); names and types await human review. */
#include "hst/selection_menu.h"

/* Virtual interface of the selection menu. */
class MenuVirtuals {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

/* Config byte at 0x8b holding three 2-bit fields. */
struct ConfigBits {
    char pad[0x8b];
    signed char bits0 : 2;
    signed char bits2 : 2;
    signed char bits4 : 2;
};

extern ConfigBits *DAT_002cfc8c;
extern int DAT_0034179c;
extern int DAT_003415ac;

extern "C" {
void FUN_0021abe0(SelectionState *, int);
int FUN_001155c0(int);
void FUN_00103628(int, int);
int FUN_001156d4(int);
void FUN_001b1c44(int *, int);

/* Dispatch on the state id: most states return to state 11, a few wait on FUN_001155c0 first, and the rest read the input. */
void FUN_0021acb4(SelectionState *self)
{
    switch (self->state) {
    case 1: case 2: case 3: case 4: case 5:
    case 8: case 9: case 10:
    case 14: case 15: case 16: case 17:
        FUN_0021abe0(self, 11);
        break;
    case 6: case 7: case 13: case 18:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_00103628(DAT_003415ac, 1);
            if (FUN_001156d4(DAT_003415ac) == 0) {
                switch (self->state) {
                case 13:
                    FUN_0021abe0(self, 14);
                    break;
                case 18:
                    FUN_0021abe0(self, 8);
                    break;
                case 6:
                    FUN_0021abe0(self, 9);
                    break;
                case 7:
                    FUN_0021abe0(self, 10);
                    break;
                }
            } else {
                FUN_0021abe0(self, 0);
            }
        }
        return;
    default: {
        SelectionMenu *menu = self->menu;
        if (menu->unk54 != 0 && self->state == 0) {
            FUN_0021abe0(self, menu->item[menu->cursor] + 1);
            self->menu->unk54 = 0;
        }
        if (DAT_002cfc8c->bits0 == 0 || DAT_002cfc8c->bits4 == 0) {
            if (self->state == 0) {
                FUN_001b1c44(&DAT_0034179c, 12);
                FUN_0021abe0(self, 11);
            }
        }
        ((MenuVirtuals *)self->menu)->m2();
        break;
    }
    }
}
}
