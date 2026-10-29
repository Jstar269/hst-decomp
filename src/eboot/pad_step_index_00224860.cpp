/* HSTMATCH module=EBOOT.BIN start=0x00224860 end=0x002249dc symbol=FUN_00224860 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: pad flags as signed 2-bit fields, the two clamps as an inline Clamp(v, const lo&, const hi&), virtual hook call; matching idiom: hi = count-1 is computed into a local before v = cursor+-1; readability pass; exact match verified; names and types await human review. */
#include "hst/page_menu.h"
#include "hst/pad_state.h"

/* Optional helper object of the menu; only virtual slot 2 is called. */
struct Hook {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
extern PadState *DAT_002cfc8c;
extern int DAT_002f1208;
extern int DAT_002f120c;
extern char DAT_0034179c;
extern "C" void FUN_00103128(PageMenu *menu);
extern "C" void FUN_0010b980(void *p, int v, int z);
extern "C" void FUN_001b1c44(void *p, int v);
extern "C" void FUN_00224738(PageMenu *menu, int v);
inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}
/* Per-frame update: two pad edges step the cursor within [limit, count - 1]; a confirm edge arms the menu. */
extern "C" void FUN_00224860(PageMenu *menu)
{
    if (menu->unk54 == 0 && menu->unk118 == 0) {
        int old = menu->cursor;
        if (DAT_002cfc8c->byte89.st3 == 0) {
            int hi = menu->count - 1;
            int v = old - 1;
            menu->cursor = Clamp(v, DAT_002f1208, hi);
        } else if (DAT_002cfc8c->byte89.st1 == 0) {
            int hi = menu->count - 1;
            int v = old + 1;
            menu->cursor = Clamp(v, DAT_002f120c, hi);
        } else if (DAT_002cfc8c->byte8b.st1 == 0) {
            FUN_001b1c44(&DAT_0034179c, 3);
            menu->unk118 = 1;
        }
        if (old != menu->cursor) {
            FUN_0010b980(menu->unk8c, menu->cursor, 0);
            FUN_00224738(menu, menu->cursor);
            FUN_001b1c44(&DAT_0034179c, 1);
        }
    }
    FUN_00103128(menu);
    if (menu->hook != 0) {
        ((Hook *)menu->hook)->v2();
    }
}
