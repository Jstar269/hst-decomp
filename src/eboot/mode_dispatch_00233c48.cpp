/* HSTMATCH module=EBOOT.BIN start=0x00233c48 end=0x00233d54 symbol=FUN_00233c48 lang=c++ rodata=0x002c9cc4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/challenge_lobby.h"

extern void *DAT_0034a120;
extern "C" void *FUN_001d9cc4(void *);
extern "C" int FUN_002a17e0(void *);

/* The lobby's owned objects, seen through the virtual calls this function makes. */
struct LobbyMenu {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct LobbyHelper4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct LobbyHelper8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

/* Per-state dispatch on the lobby: states 0, 7 and 9 do nothing; states 2 and 3 run slot 3 of the helper at 0x08 and
   the menu; all others run slot 3 of the menu, preceded for states 4 and 5 by slots 2 and 3 of the helper at 0x04
   (skipped when both checks on the global object succeed). */
extern "C" void FUN_00233c48(ChallengeLobby *lobby)
{
    switch (lobby->state) {
    case 0:
    case 7:
    case LOBBY_STATE_INITIAL:
        return;
    case 2:
    case 3:
        lobby->unk8->v3();
        lobby->menu->v3();
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 8:
    default:
        if (DAT_0034a120 != 0 && FUN_001d9cc4(DAT_0034a120) != 0 && FUN_002a17e0(FUN_001d9cc4(DAT_0034a120)) != 0) {
        } else {
            if ((unsigned)(lobby->state - 4) < 2) {
                lobby->unk4->v2();
                lobby->unk4->v3();
            }
        }
        lobby->menu->v3();
        break;
    }
}
