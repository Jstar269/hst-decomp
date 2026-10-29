/* HSTMATCH module=EBOOT.BIN start=0x0023302c end=0x00233378 symbol=FUN_0023302c lang=c++ rodata=0x002c9c80 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: flag-table address as an int offset accumulated onto the global (`off = idx; off += (int)G;`) for retail's index-first addu; names and types await human review. */
#include "hst/challenge_lobby.h"
#include "hst/game_record.h"

/* The challenge menu, seen through the fields and virtual calls used here. */
struct LobbyMenu {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    char pad[0x1da - 4];
    unsigned char unk1da;
    char pad1db;
    int mode;
    int selected;
    int unk1e4;
};

extern "C" {
extern int DAT_002f3668;
extern int DAT_002f3664;
extern int DAT_002f3ed4;
extern GameRecord *DAT_003415a8;
extern void *DAT_003415ac;
extern int DAT_0034a120;
extern char DAT_0034a678[];
extern char DAT_0034179c[];
char *FUN_001fea10(int a, int b, int c);
void FUN_000143b0(char *buf, char *a, char *b, char *c);
void FUN_00114168(void *a, int b, char *s, int c, int d);
int FUN_0022c988(int n);
int FUN_0022c9ac(void);
void FUN_00233384(ChallengeLobby *s, int a, int b);
void FUN_0022101c(LobbyHelper8 *a, int b);
void FUN_001b1c44(void *p, int n);
void FUN_00232558(LobbyMenu *m, int n);
void FUN_002323e0(LobbyMenu *m);
void FUN_002321f0(LobbyMenu *m, int n);
void FUN_00220238(LobbyHelper4 *a, unsigned char b);
void FUN_0022115c(LobbyHelper8 *a);
void FUN_0022c4ac(int a, int b);
int FUN_00233378(void);
void FUN_00234158(void *p, int n);
void FUN_001d9c78(int n);
void FUN_00232084(LobbyMenu *m, int n);
void FUN_0023302c(ChallengeLobby *s, int n);
}

/* Enters lobby state n and runs that state's entry action. */
extern "C" void FUN_0023302c(ChallengeLobby *lobby, int n)
{
    lobby->state = n;
    switch (n) {
    case 4:
        FUN_002321f0(lobby->menu, 0);
        if (FUN_0022c9ac())
            lobby->unk11 = 1;
        else
            lobby->unk11 = 0;
        {
            LobbyMenu *m = lobby->menu;
            m->unk1da = lobby->unk11;
            FUN_002321f0(m, m->mode);
        }
        lobby->unk12 = 0;
        break;
    case 5:
        FUN_002321f0(lobby->menu, 1);
        goto tail;
    case 6:
    case 7: {
        int off = lobby->menu->selected;
        off += (int)DAT_003415a8;
        ((GameRecord *)off)->slots.slot_flags[0] |= SLOT_FLAG_BIT7;
        FUN_0022c4ac(lobby->menu->selected, lobby->menu->unk1e4);
        break;
    }
    case 0: {
        int idx = lobby->menu->selected;
        char *text_a = FUN_001fea10(0x11, 0x11, 0);
        char *text_b = FUN_001fea10(6, 0, idx + 1);
        char *text_c = FUN_001fea10(6, idx + 1, DAT_003415a8->slots.unkab24 + 1);
        char buf[512];
        FUN_000143b0(buf, text_a, text_b, text_c);
        FUN_00114168(DAT_003415ac, 2, buf, 0, 0);
        bool ok = FUN_0022c988(7) != 0 && !FUN_0022c988(8);
        if (ok)
            FUN_00233384(lobby, 0xf0, 0x88);
        else
            FUN_00233384(lobby, DAT_002f3ed4, 0x88);
        break;
    }
    case 2: {
        int requested = DAT_002f3668;
        if (requested >= 0) {
            FUN_0022101c(lobby->unk8, requested);
            LobbyMenu *m = lobby->menu;
            if (m->selected != requested - 1)
                FUN_001b1c44(DAT_0034179c, 1);
            m->selected = requested - 1;
            switch (m->mode) {
            case 0:
                break;
            case 1:
                FUN_00232558(m, m->selected);
                break;
            }
            DAT_002f3664 = requested - 1;
            DAT_002f3668 = -1;
            FUN_002323e0(lobby->menu);
            FUN_002321f0(lobby->menu, 0);
            lobby->menu->m1();
            lobby->menu->m2();
            DAT_002f3664 = requested - 1;
        } else {
            FUN_0023302c(lobby, 4);
            lobby->menu->m1();
            FUN_00220238(lobby->unk4, lobby->unk10);
        }
        break;
    }
    case 3:
        FUN_0022115c(lobby->unk8);
        break;
    case 8:
        DAT_002f3664 = FUN_00233378();
        if (DAT_0034a120 != 0)
            FUN_001d9c78(DAT_0034a120);
        else
            FUN_00234158(DAT_0034a678, 0x47);
        break;
    }
tail:
    if (lobby->state != 4 && lobby->state != 5)
        FUN_00232084(lobby->menu, 1);
}
