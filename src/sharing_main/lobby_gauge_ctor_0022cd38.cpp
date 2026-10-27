/* HSTMATCH module=hstp_trans_main.prx start=0x0022cd38 end=0x0022cfb0 symbol=__ct__10C_0022cd38Fv lang=c++ data=0x00398be0 */
/* Clone of src/eboot/lobby_gauge_ctor_0021d7c4.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00398be0-0x00398c38) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    virtual void v0();
    virtual void Show(int on);
};
struct Item {
    int color;
    short f4;
    short f6;
    short f8;
    short fa;
    char padc[0x18];
    int f24;
};
struct Lookup {
    int page;
    char *name;
    int out;
};

struct B_0010873c {
    B_0010873c();
    virtual void v0();
    virtual void v1();
    char pad4[0x50];
};

struct Gauge;

struct C_0022cd38 : B_0010873c {
    Obj *pages[3];
    Item *items[19];
    Obj *pages2[3];
    Item *items2[9];
    int x[9];
    int y[9];
    int w[9];
    int h[9];
    Gauge *gauge;
    int f170;
    B_0010873c pane;
    int pad1c8[3];
    float f1d4;
    char pad1d8[0xd];
    unsigned char f1e5;
    char pad1e6[0x22];
    unsigned char f208;
    char pad209[3];
    int f20c;

    C_0022cd38();
    virtual void v2();
};

extern float DAT_00398354;
extern char *PTR_00398a10[];
extern Lookup DAT_00398a60[];
extern char *PTR_00398b44[];
extern Lookup DAT_00398b74[];

extern "C" {
void *FUN_00000bcc(unsigned int n);
Gauge *FUN_0022c5a0(void *p);
void FUN_00109a44(B_0010873c *m, char *path, int f);
void FUN_00108e6c(float t, B_0010873c *m);
Obj *FUN_00109304(B_0010873c *m, char *name, int f);
Item *FUN_00108124(Obj *page, char *name);
void FUN_0022d848(C_0022cd38 *self, int n);
}

C_0022cd38::C_0022cd38() : gauge(0), f170(0), f20c(-1)
{
    Gauge *g = (Gauge *)FUN_00000bcc(0xa4);
    if (g != 0)
        g = FUN_0022c5a0(g);
    gauge = g;
    FUN_00109a44(this, "data/menu/lobby/lobbyinpane/gaugelay.lay", 0);
    FUN_00108e6c(DAT_00398354 + 10.0f, this);
    FUN_00109a44(&pane, "data/menu/lobby/lobbyinpane/gaugelay_HL.lay", 0);
    FUN_00108e6c(DAT_00398354 + 10.0f, &pane);
    int base = (int)this;
    {
        int i = 0;
        char **n = PTR_00398a10;
        int off = 0;
        do {
            Obj *o = FUN_00109304(this, *n, 0);
            *(Obj **)(base + off + 0x54) = o;
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_00398a60;
        int off = 0;
        do {
            Item *it = FUN_00108124(this->pages[l->page], l->name);
            *(Item **)(base + off + 0x60) = it;
            if (it != 0)
                l->out = it->f24;
            i++;
            l++;
            off += 4;
        } while (i < 19);
    }
    {
        int i = 0;
        char **n = PTR_00398b44;
        int off = 0;
        do {
            Obj *o = FUN_00109304(&pane, *n, 0);
            *(Obj **)(base + off + 0xac) = o;
            (*(Obj **)(base + off + 0xac))->Show(1);
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_00398b74;
        int off = 0;
        do {
            Item *it = FUN_00108124(this->pages2[l->page], l->name);
            *(Item **)(base + off + 0xb8) = it;
            l->out = it->f24;
            *(int *)(base + off + 0xdc) = (*(Item **)(base + off + 0xb8))->f4;
            *(int *)(base + off + 0x100) = (*(Item **)(base + off + 0xb8))->f8;
            *(int *)(base + off + 0x124) = (*(Item **)(base + off + 0xb8))->f6;
            *(int *)(base + off + 0x148) = (*(Item **)(base + off + 0xb8))->fa;
            (*(Item **)(base + off + 0xb8))->color = 0x80ffffff;
            i++;
            l++;
            off += 4;
        } while (i < 9);
    }
    f1d4 = 95.0f;
    f1e5 = 0;
    f208 = 1;
    FUN_0022d848(this, 2);
    v1();
}
