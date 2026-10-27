/* HSTMATCH module=hstp_trans_main.prx start=0x00273138 end=0x00273290 symbol=FUN_00273138 lang=c++ data=0x003a6a24 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x003a6a24-0x003a6a30) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Constructor-style init of a scene object: base init 0x268090 (gets the second argument unchanged), vtable
   0x3b2cec, menu index 13, four menu items laid out around the current entry, "bg"/"vsfire0" lookup, then
   virtual slot 7. The two entry loads are written x then y (retail loads y first, x in the jal slot). */
struct Entry {
    short x;
    short y;
    char pad4[0xc - 0x4];
};

struct Menu {
    char pad0[0xd8];
    int fd8;
    int cur;
    char padE0[0x114 - 0xe0];
    unsigned char f114;
    char pad115[0x120 - 0x115];
    Entry *entries;
};

struct Scene {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad4[0x55 - 0x4];
    unsigned char f55;
    char pad56[0x58 - 0x56];
    Menu *menu;
    char pad5c[0x1854 - 0x5c];
    int f1854;
    char pad1858[0x1860 - 0x1858];
    void *f1860;
};

extern "C" {
extern char DAT_003b2cec[];
void FUN_00268090(Scene *self, void *arg);
void FUN_00111aa4(Menu *m, int idx, int mode);
void FUN_00111908(Menu *m);
void FUN_00111944(Menu *m, short x, short y, int a, char b, int c);
void *FUN_00109304(Scene *self, const char *name, int n);
void *FUN_00108124(void *node, const char *name);
}

extern "C" Scene *FUN_00273138(Scene *self, void *arg)
{
    FUN_00268090(self, arg);
    *(void **)self = DAT_003b2cec;
    FUN_00111aa4(self->menu, 13, 0);
    Entry *e = &self->menu->entries[self->menu->cur];
    short x = e->x;
    short y = e->y;
    FUN_00111908(self->menu);
    FUN_00111944(self->menu, x - 48, y + 12, 1, 0, 1);
    FUN_00111944(self->menu, x + 54, y + 12, 0, 0, 1);
    FUN_00111944(self->menu, x + 213, y + 12, 0, 0, 1);
    FUN_00111944(self->menu, x + 314, y + 12, 0, 0, 1);
    Menu *m = self->menu;
    m->fd8 = 0;
    m->f114 = 1;
    self->f1854 = 0;
    self->f55 = 0;
    self->f1860 = FUN_00108124(FUN_00109304(self, "bg", 0), "vsfire0");
    self->v7();
    return self;
}
