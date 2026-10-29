/* HSTMATCH module=EBOOT.BIN start=0x00232ec4 end=0x0023302c symbol=FUN_00232ec4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-decompiled: virtual member calls on subobject, &DAT_0034179c symbol reference, switch case ordering; exact match verified. */
#include "hst/challenge_lobby.h"

extern "C" {
    extern char DAT_0034179c;
    int FUN_001b1c44(void *dat, int arg2);
    void FUN_00220238(LobbyHelper4 *helper, unsigned char arg2);
    int FUN_0022c194(void);
    int FUN_0022c1c4(void);
    int FUN_0022c1dc(void);
    unsigned char FUN_0022c928(int arg1);
    void FUN_002323e0(LobbyMenu *menu);
    void FUN_00232558(LobbyMenu *menu, int selected);
    void FUN_0023302c(ChallengeLobby *lobby, int state);
    unsigned char FUN_0026ef04(void);
}

/* The challenge menu, seen through the fields and virtual calls used here. */
struct LobbyMenu {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[0x1dc - 4];
    int mode;
    int selected;
};

/* Per-frame state update of the lobby: refreshes the menu, then picks the next lobby state from the input queries. */
extern "C" void FUN_00232ec4(ChallengeLobby *self)
{
    FUN_002323e0(self->menu);
    FUN_0023302c(self, 4);
    self->menu->v1();
    self->menu->v2();
    self->unk10 = FUN_0026ef04();
    int flag_slot7 = FUN_0022c928(7);
    int flag_cur = 0;
    int cur_slot = FUN_0022c194();
    if (cur_slot >= 0 && cur_slot < 10) {
        flag_cur = FUN_0022c928(cur_slot);
    }
    if (FUN_0022c1dc()) {
        int new_selected = FUN_0022c1c4();
        LobbyMenu *menu = self->menu;
        if (menu->selected != new_selected) {
            FUN_001b1c44(&DAT_0034179c, 1);
            menu->selected = new_selected;
        } else {
            menu->selected = new_selected;
        }
        switch (menu->mode) {
        case 0:
            break;
        case 1:
            FUN_00232558(menu, menu->selected);
            break;
        }
        FUN_0023302c(self, 0);
    } else {
        if (flag_slot7 != 0) {
            FUN_0023302c(self, 3);
        } else if (flag_cur != 0) {
            FUN_0023302c(self, 1);
        } else {
            FUN_00220238(self->unk4, self->unk10);
        }
    }
}
