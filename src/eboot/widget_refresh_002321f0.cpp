/* HSTMATCH module=EBOOT.BIN start=0x002321f0 end=0x002323e0 symbol=FUN_002321f0 lang=c++ rodata=0x002c9c68 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: the tests read `int m = self->mode;` back after the store (the parameter itself then stays in a1 for the store). */
#include "hst/challenge_menu.h"

/* Pane object with an enable switch. */
struct PaneCtl {
    virtual void v0();
    virtual void SetEnabled(bool on);
};

/* Menu part with two values that are always written together. */
struct Part {
    char pad[0x24];
    int unk24;
    int unk28;
};

/* Record returned by the shared getter. */
struct Shared {
    char pad0[0x138];
    int unk138;
    unsigned char unk13c;
};

struct LobbyMenu {
    char pad0[0x5c];
    PaneCtl *pane2;
    PaneCtl *pane3;
    Part *parts[CHALLENGE_PARTS];
    char pad1[0x1dc - 0x64 - CHALLENGE_PARTS * 4];
    int mode;
    int selected;
    char pad2[0x200 - 0x1e4];
    int status[POINT_COUNT];
};

extern "C" {
Shared *FUN_0022cd60(void);
void FUN_000ffb3c(Part *, bool);
void FUN_00232558(LobbyMenu *, int);
extern int DAT_002f3af4;
extern int DAT_002f39f0[];
}

/* Switches the menu to a new mode and updates which panes and parts are enabled and what values they show. */
extern "C" void FUN_002321f0(LobbyMenu *self, int new_mode)
{
    self->mode = new_mode;
    int m = self->mode;
    bool notOne = !(m == 1);
    Shared *shared = FUN_0022cd60();
    bool no_unk138 = shared->unk138 == 0;
    unsigned char flag13c = shared->unk13c;
    self->pane2->SetEnabled(!(m == 0));
    self->pane3->SetEnabled(notOne);
    for (int i = 25; i <= 34; i++) {
        FUN_000ffb3c(self->parts[i], 1);
    }
    FUN_000ffb3c(self->parts[22], notOne);
    FUN_000ffb3c(self->parts[23], notOne);
    FUN_000ffb3c(self->parts[19], !no_unk138);
    bool b = !flag13c;
    FUN_000ffb3c(self->parts[20], b);
    FUN_000ffb3c(self->parts[21], b);
    int v = DAT_002f3af4 + no_unk138;
    Part *it = self->parts[21];
    it->unk24 = v;
    it->unk28 = v;
    switch (self->mode) {
    case 0:
        for (int i = 0; i < POINT_COUNT; i++) {
            int m = self->status[i];
            switch (m) {
            case 0:
            case 1:
                FUN_000ffb3c(self->parts[CHALLENGE_FIRST_POINT_PART + i], 1);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                m = (m == 4) ? 2 : m;
                FUN_000ffb3c(self->parts[CHALLENGE_FIRST_POINT_PART + i], 0);
                int val = m - 2 + DAT_002f39f0[i * 3 + 0x89];
                Part *p = self->parts[CHALLENGE_FIRST_POINT_PART + i];
                p->unk24 = val;
                p->unk28 = val;
            }
        }
        break;
    case 1:
        FUN_00232558(self, self->selected);
        break;
    }
}
