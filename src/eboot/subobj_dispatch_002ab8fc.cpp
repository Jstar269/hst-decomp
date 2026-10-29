/* HSTMATCH module=EBOOT.BIN start=0x002ab8fc end=0x002abb70 symbol=FUN_002ab8fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/vshistory.h"

struct Widget {
    virtual void d0();
    virtual void m(int);
};

struct Menu : Widget {
    char pad4[0xdc - 4];
    int choice; /* 0xdc index into the sound table */
};

struct CommonPanel {
    char pad00[0x60];
    Widget *w60; /* 0x60 */
    Widget *w64; /* 0x64 */
    Widget *w68; /* 0x68 */
    Widget *w6c; /* 0x6c */
    char pad70[0xd4 - 0x70];
    Widget *wd4; /* 0xd4 */
    char padd8[0xe0 - 0xd8];
    bool disabled_e0; /* 0xe0 */
};

struct Page1 {
    char pad00[0x178];
    Menu *menu;         /* 0x178 */
    bool menu_disabled; /* 0x17c */
};

struct Page2 {
    char pad00[0x358];
    Widget *list;       /* 0x358 */
    int pad35c;
    bool list_disabled; /* 0x360 */
};

struct Page3 {
    char pad00[0x1034];
    Widget *selector;    /* 0x1034 */
    int pad1038;
    bool selector_disabled; /* 0x103c */
    char pad103d[0x30c8 - 0x103d];
    int unk30c8;         /* 0x30c8 */
};

extern "C" {
extern int DAT_00300af4[];
extern char *DAT_003415a8;
extern void *DAT_0034b354;
extern void FUN_0010b8cc(Widget *, int, int);
extern void FUN_00110a78(void *, const char *, int);
extern const char *FUN_001fea10(int, int, int);
extern void FUN_002a5680(CommonPanel *, int);
extern int FUN_002af274(char *);
}

/* Set the focus state (`val` nonzero = top bar has focus) and enable or disable the widgets of each part. */
extern "C" void FUN_002ab8fc(HistoryScreen *self, unsigned char val) {
    self->top_focus = val;
    bool b = !self->top_focus;
    CommonPanel *common = self->common;
    common->wd4->m(b);
    common->disabled_e0 = !b;
    if (!b) {
        common->w60->m(0);
        common->w64->m(1);
        common->w68->m(1);
        common->w6c->m(1);
    } else {
        common->w60->m(1);
    }
    FUN_002a5680(self->common, self->tab);

    b = (self->top_focus != 0) || (self->tab != 0);
    Page1 *page1 = self->page1;
    page1->menu->m(b);
    page1->menu_disabled = !b;
    if (!b) {
        Menu *menu = page1->menu;
        int v = menu->choice;
        FUN_0010b8cc(menu, v, 0);
        if (DAT_0034b354 != 0) {
            const char *u = FUN_001fea10(18, 49, DAT_00300af4[v]);
            FUN_00110a78(DAT_0034b354, u, 0);
        }
    }

    b = (self->top_focus != 0) || (self->tab != 1);
    Page2 *page2 = self->page2;
    int list_enabled = 1;
    if (!b) {
        bool ok = 0 < FUN_002af274(DAT_003415a8 + HISTORY_LIST_OFFSET);
        bool not_ok = !ok;
        if (not_ok) {
        } else {
            list_enabled = 0;
        }
    }
    page2->list->m(list_enabled);
    page2->list_disabled = !b;

    int selector_enabled = 1;
    if (self->top_focus == 0) {
        int a0 = 0;
        if (self->tab != 2 && self->tab != 3) {
            a0 = selector_enabled;
        }
        if (!a0) {
            selector_enabled = 0;
        }
    }
    Page3 *page3 = self->page3;
    page3->selector->m(selector_enabled);
    page3->selector_disabled = !selector_enabled;
    if (!selector_enabled) {
        FUN_0010b8cc(page3->selector, page3->unk30c8, 0);
    }
}
