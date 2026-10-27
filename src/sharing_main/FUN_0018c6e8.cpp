/* HSTMATCH module=hstp_trans_main.prx start=0x0018c6e8 end=0x0018c9a8 symbol=FUN_0018c6e8 lang=c++ data=0x00387e74 */
/* Hand-written reconstruction (port of src/eboot/FUN_0017fff4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x00387e74-0x00387eda) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* ChrSelect_LoadLayoutAndUnitList: data/menu/chrselect/chrsel_unitlist.txt; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode (character-select screen init, sibling of 0x1802b4); the two globals tested first are the arguments of FUN_0008f170 / FUN_001dbee0 (Ghidra dropped them), the layout is a struct so accesses are displacements off s0; exact match verified; names and types await human review. */
struct Rect {
    char pad0[4];
    short a, b, c, d;
};

struct Panel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    virtual void v6(float);
    char pad1[0xd8 - 4];
    int f_d8;
    char pad2[0x114 - 0xd8 - 4];
    unsigned char f114;
};

struct Obj28 {
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
    float f60;
};

struct Screen {
    char pad00[0x4];
    void * f4;
    void * f8;
    char pad01[0x4];
    void * layout;
    void * h14;
    char pad02[0x8];
    void * f20;
    void * f24;
    Obj28 * f28;
    void * f2c;
    void * f30;
    void * f34;
    void * f38;
    char pad03[0x8];
    char sub2[0x8c];
    int fd0;
    char pad04[0x90c];
    Rect * r9e0;
    char pad05[0x10];
    Rect * r9f4;
    char pad06[0x178];
    Rect * rb70;
    char pad07[0x40c];
    Rect * rf80;
    char pad08[0x178];
    char sub3[0x84];
    Panel * panel;
    int v1184;
    char pad09[0xb0];
    int v1238;
    int v123c;
    char pad10[0x14];
    char s1254[0x8c];
    char s12e0[0x8c];
    char s136c[0x8c];
    char s13f8[0x8c];
    char s1484[0x8c];
    char s1510[0x8c];
    char s159c[0x8c];
    char s1628[0x8c];
    char s16b4[0x8c];
};

extern char DAT_003b7ebc[];
extern char DAT_00387dd0[];
extern char DAT_002d2580[];
extern char DAT_002d26ec[];
extern "C" int DAT_003e1a08;
extern "C" int DAT_003f344c;
extern "C" int DAT_003ea85c;

extern "C" {
void FUN_0001c684(char *, int, char *);
void FUN_002262f8(int *, char *, int);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_0001c73c(char *);
void *FUN_0008f170(int);
void *FUN_001dbee0(int);
void FUN_00108f54(void *, int);
void FUN_0018dcb0(Screen *);
void FUN_00225e94(void *, void *, char *, int);
void FUN_00225f18(void *, void *, int, int);
void FUN_00225fb4(void *, void *, char *, int);
void FUN_0022618c(void *, void *, char *);
void FUN_000587ac(float, void *, int, int);
void FUN_00059ac0(void *, int, int);
void FUN_00059d68(void *, int);
char *FUN_00177ea4(void);
void FUN_00055c0c(float, void *);
void FUN_00055be8(void *, float *);
void FUN_002267ac(void *, void *);
void FUN_002266bc(void *, int);
}

extern "C" void FUN_0018c6e8(Screen *self)
{
    FUN_0001c684(DAT_003b7ebc, 1, "menu/chrsel_030_chrsel.xb");
    FUN_002262f8(&DAT_003ea85c, "data/menu/chrselect/chrsel_unitlist.txt", 0xd6);
    FUN_00109a44(self->layout, "data/menu/chrselect/chrselect.lay", 0);
    FUN_00108e6c(0.0f, self->layout);
    FUN_001090f4(self->layout, 0x10);
    FUN_0001c73c(DAT_003b7ebc);
    if (DAT_003e1a08 != 0) {
        self->f4 = FUN_0008f170(DAT_003e1a08);
    } else if (DAT_003f344c != 0) {
        self->f4 = FUN_001dbee0(DAT_003f344c);
    }
    if (self->f4 != 0) {
        FUN_00108f54(self->f4, 0);
    }
    FUN_0018dcb0(self);
    FUN_00225e94(&self->h14, self->layout, DAT_00387dd0, 12);
    FUN_00225f18(self->sub2, &self->h14, DAT_003ea85c, 0xd6);
    FUN_00225fb4(self->sub3, &self->h14, DAT_002d2580, 11);
    FUN_0022618c(&self->panel, &self->h14, DAT_002d26ec);
    Panel *pn = self->panel;
    pn->f_d8 = 0;
    pn->f114 = 1;
    self->panel->v5(-256);
    self->panel->v6(2300.0f);
    self->v1184 = (short)(self->rf80->c - self->rf80->a);
    if (self->f8 != 0) {
        float v[4];
        FUN_000587ac(0.0f, self->f8, 0, 0);
        FUN_00059ac0(self->f8, 1, -1);
        FUN_00059d68(self->f8, -1);
        FUN_00055c0c(*(float *)(FUN_00177ea4() + 0x6c), self->f8);
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        FUN_00055be8(self->f8, v);
    }
    FUN_002267ac(self->s1254, self->h14);
    FUN_002266bc(self->s12e0, self->fd0);
    FUN_002267ac(self->s136c, self->f20);
    FUN_002267ac(self->s13f8, self->f2c);
    FUN_002267ac(self->s1484, self->f28);
    FUN_002267ac(self->s1510, self->f24);
    FUN_002267ac(self->s159c, self->f30);
    FUN_002267ac(self->s1628, self->f34);
    FUN_002267ac(self->s16b4, self->f38);
    self->v1238 = (int)self->f28->f60;
    self->v123c = self->r9f4->a - self->r9e0->a;
    Rect *rr = self->rb70;
    self->f28->v8(1, rr->a, rr->b, rr->c, rr->d);
}
