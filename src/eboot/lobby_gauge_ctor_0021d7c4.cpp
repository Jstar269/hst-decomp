/* HSTMATCH module=EBOOT.BIN start=0x0021d7c4 end=0x0021da3c symbol=__ct__10C_0021d7c4Fv lang=c++ data=0x002f0814 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002f0814-0x002f086c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/parts_pane.h"

/* Sub-layout page with a virtual Show(int) in slot 1. */
struct Obj {
    virtual void v0();
    virtual void Show(int on);
};
/* Layout item: colour word, four halfwords at 4..0xb, a value at 0x24. */
struct Item {
    int color;
    short s4;
    short s6;
    short s8;
    short sA;
    char padc[0x18];
    int unk24;
};
typedef PaneItemDef Lookup;

struct B_00102e38 {
    B_00102e38();
    virtual void v0();
    virtual void v1();
    char pad4[0x50];
};

/* Lobby gauge: two layouts (gaugelay.lay and its highlight variant), their pages and items, and the owned
   parts pane. The layout is mirrored by LobbyGauge in hst/lobby_gauge.h. */
struct C_0021d7c4 : B_00102e38 {
    Obj *pages[3];
    Item *items[19];
    Obj *pages2[3];
    Item *items2[9];
    int saved4[9];          /* copies of item halfword 4 of items2 */
    int saved8[9];          /* halfword 8 */
    int saved6[9];          /* halfword 6 */
    int savedA[9];          /* halfword 0xa */
    PartsPane *gauge;
    int unk170;
    B_00102e38 pane;
    int pad1c8[3];
    float unk1d4;
    char pad1d8[0xd];
    unsigned char unk1e5;
    char pad1e6[0x22];
    unsigned char unk208;
    char pad209[3];
    int handle;

    C_0021d7c4();
    virtual void v2();
};

extern float DAT_002eff88;
extern char *PTR_002f0644[];
extern Lookup DAT_002f0694[];
extern char *PTR_002f0778[];
extern Lookup DAT_002f07a8[];

extern "C" {
void *FUN_00000bcc(unsigned int n);
PartsPane *FUN_0021d02c(void *p);
void FUN_00104118(B_00102e38 *m, char *path, int f);
void FUN_00103540(float t, B_00102e38 *m);
Obj *FUN_001039d8(B_00102e38 *m, char *name, int f);
Item *FUN_001026b8(Obj *page, char *name);
void FUN_0021e2d4(C_0021d7c4 *self, int n);
}

/* Builds the gauge: loads both layouts, their pages and items (remembering each item's halfwords and setting its colour), creates the parts pane. */
C_0021d7c4::C_0021d7c4() : gauge(0), unk170(0), handle(-1)
{
    PartsPane *g = (PartsPane *)FUN_00000bcc(0xa4); /* sizeof(PartsPane) */
    if (g != 0)
        g = FUN_0021d02c(g);
    gauge = g;
    FUN_00104118(this, "data/menu/lobby/lobbyinpane/gaugelay.lay", 0);
    FUN_00103540(DAT_002eff88 + 10.0f, this);
    FUN_00104118(&pane, "data/menu/lobby/lobbyinpane/gaugelay_HL.lay", 0);
    FUN_00103540(DAT_002eff88 + 10.0f, &pane);
    int base = (int)this;
    {
        int i = 0;
        char **n = PTR_002f0644;
        int off = 0;
        do {
            Obj *o = FUN_001039d8(this, *n, 0);
            *(Obj **)(base + off + 0x54) = o;
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_002f0694;
        int off = 0;
        do {
            Item *it = FUN_001026b8(this->pages[l->layer], l->name);
            *(Item **)(base + off + 0x60) = it;
            if (it != 0)
                l->value = it->unk24;
            i++;
            l++;
            off += 4;
        } while (i < 19);
    }
    {
        int i = 0;
        char **n = PTR_002f0778;
        int off = 0;
        do {
            Obj *o = FUN_001039d8(&pane, *n, 0);
            *(Obj **)(base + off + 0xac) = o;
            (*(Obj **)(base + off + 0xac))->Show(1);
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_002f07a8;
        int off = 0;
        do {
            Item *it = FUN_001026b8(this->pages2[l->layer], l->name);
            *(Item **)(base + off + 0xb8) = it;
            l->value = it->unk24;
            *(int *)(base + off + 0xdc) = (*(Item **)(base + off + 0xb8))->s4;
            *(int *)(base + off + 0x100) = (*(Item **)(base + off + 0xb8))->s8;
            *(int *)(base + off + 0x124) = (*(Item **)(base + off + 0xb8))->s6;
            *(int *)(base + off + 0x148) = (*(Item **)(base + off + 0xb8))->sA;
            (*(Item **)(base + off + 0xb8))->color = 0x80ffffff;
            i++;
            l++;
            off += 4;
        } while (i < 9);
    }
    unk1d4 = 95.0f;
    unk1e5 = 0;
    unk208 = 1;
    FUN_0021e2d4(this, 2);
    v1();
}
