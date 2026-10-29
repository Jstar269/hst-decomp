/* HSTMATCH module=EBOOT.BIN start=0x0017fff4 end=0x001802b4 symbol=FUN_0017fff4 lang=c++ data=0x002e083c */
/* ChrSelect_LoadLayoutAndUnitList: data/menu/chrselect/chrsel_unitlist.txt; see docs/DATA-TABLES.md Data: its string literals (3 strings, 0x002e083c-0x002e08a2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode (character-select screen init, sibling of 0x1802b4); the two globals tested first are the arguments of FUN_0008d994 / FUN_001cd804 (Ghidra dropped them), the layout is a struct so accesses are displacements off s0; exact match verified; names and types await human review. */
#include "hst/chrsel_screen.h"

struct ChrSelPanel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    virtual void v6(float);
    char pad1[0xd8 - 4];
    int unkD8;
    char pad2[0x114 - 0xd8 - 4];
    unsigned char unk114;
};

struct ChrSelPart {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int, int, int, int);
    char pad[0x60 - 4];
    float unk60;
};

extern char DAT_0030ebf4[];
extern char DAT_002e0798[];
extern char DAT_002c2080[];
extern char DAT_002c21ec[];
extern "C" int DAT_003386c8;
extern "C" int DAT_0034a114;
extern "C" int DAT_0034151c;

extern "C" {
void FUN_0001cad0(char *, int, char *);
void FUN_002172f4(int *, char *, int);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_0001cb88(char *);
void *FUN_0008d994(int);
void *FUN_001cd804(int);
void FUN_00103628(void *, int);
void FUN_001815bc(ChrSelScreen *);
void FUN_00216e90(void *, void *, char *, int);
void FUN_00216f14(void *, void *, int, int);
void FUN_00216fb0(void *, void *, char *, int);
void FUN_00217188(void *, void *, char *);
void FUN_00057b58(float, void *, int, int);
void FUN_00058ddc(void *, int, int);
void FUN_00059084(void *, int);
char *FUN_0016bc7c(void);
void FUN_000550ec(float, void *);
void FUN_000550c8(void *, float *);
void FUN_00217704(void *, void *);
void FUN_00217614(void *, int);
}

/* Character-select screen init: loads the layout and unit list, binds the sub-objects, positions the panel. */
extern "C" void FUN_0017fff4(ChrSelScreen *self)
{
    FUN_0001cad0(DAT_0030ebf4, 1, "menu/chrsel_030_chrsel.xb");
    FUN_002172f4(&DAT_0034151c, "data/menu/chrselect/chrsel_unitlist.txt", 0xd6);
    FUN_00104118(self->layout, "data/menu/chrselect/chrselect.lay", 0);
    FUN_00103540(0.0f, self->layout);
    FUN_001037c8(self->layout, 0x10);
    FUN_0001cb88(DAT_0030ebf4);
    if (DAT_003386c8 != 0) {
        self->unk04 = FUN_0008d994(DAT_003386c8);
    } else if (DAT_0034a114 != 0) {
        self->unk04 = FUN_001cd804(DAT_0034a114);
    }
    if (self->unk04 != 0) {
        FUN_00103628(self->unk04, 0);
    }
    FUN_001815bc(self);
    FUN_00216e90(&self->group14, self->layout, DAT_002e0798, 12);
    FUN_00216f14(self->sub44, &self->group14, DAT_0034151c, 0xd6);
    FUN_00216fb0(self->sub10fc, &self->group14, DAT_002c2080, 11);
    FUN_00217188(&self->panel, &self->group14, DAT_002c21ec);
    ChrSelPanel *panel = self->panel;
    panel->unkD8 = 0;
    panel->unk114 = 1;
    self->panel->v5(-256);
    self->panel->v6(2300.0f);
    self->unk1184 = (short)(self->rectf80->c - self->rectf80->a);
    if (self->unk08 != 0) {
        float v[4];
        FUN_00057b58(0.0f, self->unk08, 0, 0);
        FUN_00058ddc(self->unk08, 1, -1);
        FUN_00059084(self->unk08, -1);
        FUN_000550ec(*(float *)(FUN_0016bc7c() + 0x6c), self->unk08);
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        FUN_000550c8(self->unk08, v);
    }
    FUN_00217704(self->s1254, self->group14);
    FUN_00217614(self->s12e0, self->unkd0);
    FUN_00217704(self->s136c, self->unk20);
    FUN_00217704(self->s13f8, self->unk2c);
    FUN_00217704(self->s1484, self->part28);
    FUN_00217704(self->s1510, self->unk24);
    FUN_00217704(self->s159c, self->unk30);
    FUN_00217704(self->s1628, self->unk34);
    FUN_00217704(self->s16b4, self->unk38);
    self->unk1238 = (int)self->part28->unk60;
    self->unk123c = self->rect9f4->a - self->rect9e0->a;
    ChrSelRect *rect = self->rectb70;
    self->part28->v8(1, rect->a, rect->b, rect->c, rect->d);
}
