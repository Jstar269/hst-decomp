/* HSTMATCH module=EBOOT.BIN start=0x00232084 end=0x002321f0 symbol=FUN_00232084 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/challenge_menu.h"

struct LobbyMenu {
    char pad0[0x64];
    void *parts[CHALLENGE_PARTS];
    char pad1[0x1da - 0x64 - CHALLENGE_PARTS * 4];
    unsigned char unk1da;
    char pad2;
    int mode;
};

extern "C" void FUN_000ffb3c(void *, int);

static inline bool Ne(int a, int b)
{
    return !(a == b);
}

/* Applies the flag to parts 2..13 through FUN_000ffb3c: all set when show_all is nonzero, otherwise one of two groups chosen by unk1da. */
extern "C" void FUN_00232084(LobbyMenu *menu, int show_all)
{
    int st = menu->mode;
    int not0 = Ne(st, 0);
    int not1 = Ne(st, 1);
    if (show_all != 0) {
        for (int i = 2; i <= 13; i++) FUN_000ffb3c(menu->parts[i], 1);
    } else if (menu->unk1da != 0) {
        FUN_000ffb3c(menu->parts[12], not0);
        FUN_000ffb3c(menu->parts[13], not1);
        FUN_000ffb3c(menu->parts[7], not0);
        FUN_000ffb3c(menu->parts[8], not0);
        FUN_000ffb3c(menu->parts[9], not0);
        FUN_000ffb3c(menu->parts[10], not0);
        FUN_000ffb3c(menu->parts[11], 0);
        for (int i = 2; i <= 6; i++) FUN_000ffb3c(menu->parts[i], 1);
    } else {
        FUN_000ffb3c(menu->parts[5], not0);
        FUN_000ffb3c(menu->parts[6], not1);
        FUN_000ffb3c(menu->parts[2], not0);
        FUN_000ffb3c(menu->parts[3], not0);
        FUN_000ffb3c(menu->parts[4], 0);
        for (int i = 7; i <= 13; i++) FUN_000ffb3c(menu->parts[i], 1);
    }
}
