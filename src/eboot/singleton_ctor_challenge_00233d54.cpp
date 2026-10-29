/* HSTMATCH module=EBOOT.BIN start=0x00233d54 end=0x00233f3c symbol=FUN_00233d54 lang=c++ */
/* Hand-written reconstruction from the disassembly (structure taken from singleton_ctor_002313c8.cpp); exact match verified (matching idioms: the allocation is tested inside the condition 'DAT == 0 && (lobby = operator new(20)) != 0' so the pointer copy lands in the beqz slot, each of the first two owned objects is 'if (obj != 0) lobby->x = Init(obj); else lobby->x = obj;', and the table loop's menu pointer is declared after the counter); names and types await human review. */
#include "hst/challenge_lobby.h"
#include "hst/challenge_menu.h"
#include "hst/vtable_obj.h"

extern "C" {
extern char DAT_0030985c[];
extern VtableObj *DAT_0034a668;
extern ChallengeLobby *DAT_0034a664;
extern int DAT_0034a120;
extern char DAT_0030ebf4[];
extern char DAT_002f3e78[];
extern char DAT_002f3e94[];
extern char DAT_002f3e24[];
extern char DAT_002f3eb0[];

extern void FUN_0001f06c(void *);
extern void *FUN_00000bcc(unsigned);
extern void FUN_0001cad0(void *, int, char *);
extern void FUN_0001cb88(void *);
extern void FUN_0001ca58(void *, char *);
extern void *FUN_0023167c(void *);
extern void *FUN_002200d4(void *);
extern void *FUN_00220f00(void *);
extern int FUN_000143b0(char *, char *, ...);
extern void *FUN_00050fc0(void *);
extern void FUN_000511c4(void *, char *, int);
extern void FUN_00051398(void *, float);
extern void FUN_002afb80(int, int);
extern void FUN_002afce0(int);
extern void FUN_0023302c(ChallengeLobby *, int);
extern void FUN_00232ec4(ChallengeLobby *);
}

/* Constructor of the object that owns the challenge lobby: registers itself, and when no lobby exists yet builds one
   (menu, two helpers and ten named widgets on the menu) and enters its initial state. */
extern "C" VtableObj *FUN_00233d54(VtableObj *self)
{
    char name[256];
    FUN_0001f06c(self);
    self->vtable = DAT_0030985c;
    DAT_0034a668 = self;
    ChallengeLobby *lobby;
    if (DAT_0034a664 == 0 && (lobby = (ChallengeLobby *)::operator new(sizeof(ChallengeLobby))) != 0) {
        lobby->menu = 0;
        lobby->unk4 = 0;
        DAT_0034a664 = lobby;
        lobby->unk10 = 0;
        lobby->unk11 = 0;
        lobby->unk12 = 0;
        FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f3e78);
        void *obj = ::operator new(sizeof(ChallengeMenu));
        if (obj != 0)
            lobby->menu = (LobbyMenu *)FUN_0023167c(obj);
        else
            lobby->menu = (LobbyMenu *)obj;
        obj = ::operator new(0x78);
        if (obj != 0)
            lobby->unk4 = (LobbyHelper4 *)FUN_002200d4(obj);
        else
            lobby->unk4 = (LobbyHelper4 *)obj;
        obj = ::operator new(0xa0);
        if (obj != 0)
            obj = FUN_00220f00(obj);
        lobby->unk8 = (LobbyHelper8 *)obj;
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0001ca58(DAT_0030ebf4, DAT_002f3e94);
        int i;
        ChallengeMenu *menu;
        menu = (ChallengeMenu *)lobby->menu;
        i = 0;
        do {
            FUN_000143b0(name, DAT_002f3e24, i + 1);
            void *widget = ::operator new(0x48);
            if (widget != 0)
                widget = FUN_00050fc0(widget);
            menu->extras[i] = widget;
            FUN_000511c4(widget, name, 0);
            FUN_00051398(menu->extras[i], 1100.0f);
            i++;
        } while (i < CHALLENGE_EXTRAS);
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f3eb0);
        FUN_002afb80(DAT_0034a120, 0);
        FUN_002afce0(1);
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0023302c(lobby, LOBBY_STATE_INITIAL);
    }
    FUN_00232ec4(DAT_0034a664);
    return self;
}
