/* HSTMATCH module=hstp_trans_main.prx start=0x0022a228 end=0x0022a3fc symbol=FUN_0022a228 lang=c++ rodata=0x002d9f14 */
/* Hand-written reconstruction (port of src/eboot/state_switch_0021acb4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern ConfigBits *DAT_003751d4;
extern int DAT_003eaad8;
extern int DAT_003ea8ec;

extern "C" {
void FUN_0022a154(SelectionState *, int);
int FUN_001204dc(int);
void FUN_00108f54(int, int);
int FUN_001205f0(int);
void FUN_001bfc3c(int *, int);

/* Dispatch on the state id: most states return to state 11, a few wait on FUN_001204dc first, and the rest read the input. */
void FUN_0022a228(SelectionState *self)
{
    switch (self->state) {
    case 1: case 2: case 3: case 4: case 5:
    case 8: case 9: case 10:
    case 14: case 15: case 16: case 17:
        FUN_0022a154(self, 11);
        break;
    case 6: case 7: case 13: case 18:
        if (FUN_001204dc(DAT_003ea8ec) != 0) {
            FUN_00108f54(DAT_003ea8ec, 1);
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                switch (self->state) {
                case 13:
                    FUN_0022a154(self, 14);
                    break;
                case 18:
                    FUN_0022a154(self, 8);
                    break;
                case 6:
                    FUN_0022a154(self, 9);
                    break;
                case 7:
                    FUN_0022a154(self, 10);
                    break;
                }
            } else {
                FUN_0022a154(self, 0);
            }
        }
        return;
    default: {
        SelectionMenu *menu = self->menu;
        if (menu->unk54 != 0 && self->state == 0) {
            FUN_0022a154(self, menu->item[menu->cursor] + 1);
            self->menu->unk54 = 0;
        }
        if (DAT_003751d4->bits0 == 0 || DAT_003751d4->bits4 == 0) {
            if (self->state == 0) {
                FUN_001bfc3c(&DAT_003eaad8, 12);
                FUN_0022a154(self, 11);
            }
        }
        ((MenuVirtuals *)self->menu)->m2();
        break;
    }
    }
}
}
