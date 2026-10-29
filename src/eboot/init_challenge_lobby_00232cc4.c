/* HSTMATCH module=EBOOT.BIN start=0x00232cc4 end=0x00232e2c symbol=FUN_00232cc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured lobby and menu types, unified alloc/ctor idiom, loop typing; readability pass; exact match verified; names and types await human review. */
#include "hst/challenge_menu.h"
#include "hst/challenge_lobby.h"

extern char DAT_0030ebf4;
extern char DAT_002f3e24[];
extern char DAT_002f3e78[];
extern char DAT_002f3e94[];
extern char DAT_002f3eb0[];
extern void *DAT_0034a120;

extern void *FUN_00000bcc(unsigned int);
extern void FUN_000143b0(char *, const char *, ...);
extern void FUN_0001ca58(void *, const char *);
extern void FUN_0001cad0(void *, int, const char *);
extern void FUN_0001cb88(void *);
extern void *FUN_00050fc0(void *);
extern void FUN_000511c4(void *, const char *, int);
extern void FUN_00051398(void *, float);
extern void *FUN_002200d4(void *);
extern void *FUN_00220f00(void *);
extern void *FUN_0023167c(void *);
extern void FUN_002afb80(void *, int);
extern void FUN_002afce0(int);

/* Builds the lobby's three owned objects (menu and two helpers), then ten named widgets on the menu. */
void FUN_00232cc4(ChallengeLobby *lobby)
{
    char name[256];
    void *menu_obj;
    void *obj4;
    void *obj8;
    ChallengeMenu *menu;
    int i;
    void *widget;

    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002f3e78);

    menu_obj = FUN_00000bcc(sizeof(ChallengeMenu));
    if (menu_obj)
        menu_obj = FUN_0023167c(menu_obj);
    lobby->menu = menu_obj;

    obj4 = FUN_00000bcc(120);
    if (obj4)
        obj4 = FUN_002200d4(obj4);
    lobby->unk4 = obj4;

    obj8 = FUN_00000bcc(160);
    if (obj8)
        obj8 = FUN_00220f00(obj8);
    lobby->unk8 = obj8;

    FUN_0001cb88(&DAT_0030ebf4);
    FUN_0001ca58(&DAT_0030ebf4, DAT_002f3e94);

    menu = (ChallengeMenu *)lobby->menu;
    for (i = 0; i < CHALLENGE_EXTRAS; i++) {
        FUN_000143b0(name, DAT_002f3e24, i + 1);
        widget = FUN_00000bcc(72);
        if (widget)
            widget = FUN_00050fc0(widget);
        menu->extras[i] = widget;
        FUN_000511c4(widget, name, 0);
        FUN_00051398(menu->extras[i], 1100.0f);
    }

    FUN_0001cb88(&DAT_0030ebf4);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002f3eb0);
    FUN_002afb80(DAT_0034a120, 0);
    FUN_002afce0(1);
    FUN_0001cb88(&DAT_0030ebf4);
}
