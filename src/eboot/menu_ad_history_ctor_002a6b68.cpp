/* HSTMATCH module=EBOOT.BIN start=0x002a6b68 end=0x002a6dd8 symbol=__ct__10C_002a6b68Fv lang=c++ data=0x00301c68 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00301c68-0x00301c8f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Obj {
    virtual void v0();
    virtual void Show(int on);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetFlags(int f);
    char pad[0xd4];
    int fd8;
    int fdc;
    int fe0;
    char padE4[0x30];
    unsigned char f114;
};
struct Item {
    char pad[0x20];
    Obj *obj;
    int f24;
};
struct Shape {
    char pad[4];
    short h;
};
struct Lookup {
    int page;
    char *name;
    int out;
};

struct B_00102e38 {
    B_00102e38();
    virtual void v0();
    char pad4[0x50];
};

struct C_002a6b68 : B_00102e38 {
    Obj *pages[3];
    Item *items[140];
    Obj *a[38];
    Obj *b[12];
    Obj *cursor;
    Obj *frame;
    unsigned char f360;
    char pad361[0x1303];
    int f1664;
    int f1668;
    int f166c;
    int f1670;
    int f1674;
    int f1678;
    int f167c;
    int f1680;
    int f1684;
    int f1688;
    int f168c;
    int f1690;
    C_002a6b68();
    virtual void v1();
};

extern char *PTR_003010a8[];
extern Lookup DAT_00301510[];
extern int DAT_00301ba0[];
extern int DAT_00301c38[];

extern "C" {
void FUN_00104118(C_002a6b68 *m, char *path, int f);
void FUN_00103540(float t, C_002a6b68 *m);
Obj *FUN_001039d8(C_002a6b68 *m, char *name, int f);
Item *FUN_001026b8(Obj *page, char *name);
void FUN_000ffb3c(Item *it, int on);
}

C_002a6b68::C_002a6b68()
{
    FUN_00104118(this, "data/menu/ad_history/ad_history_02.lay", 0);
    FUN_00103540(1000.0f, this);
    int base = (int)this;
    {
        int i = 0;
        char **n = PTR_003010a8;
        int off = 0;
        do {
            Obj *o = FUN_001039d8(this, *n, 0);
            *(Obj **)(base + off + 0x54) = o;
            (*(Obj **)(base + off + 0x54))->SetFlags(-2048);
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_00301510;
        int off = 0;
        do {
            Item *it = FUN_001026b8(this->pages[l->page], l->name);
            *(Item **)(base + off + 0x60) = it;
            if (it != 0)
                l->out = it->f24;
            i++;
            l++;
            off += 4;
        } while (i < 140);
    }
    {
        int i = 0;
        int *t = DAT_00301ba0;
        int off = 0;
        do {
            Obj **d = (Obj **)(base + off + 0x290);
            *d = this->items[*t]->obj;
            (*d)->SetFlags(-1808);
            i++;
            t++;
            off += 4;
        } while (i < 38);
    }
    {
        int i = 0;
        int *t = DAT_00301c38;
        int off = 0;
        do {
            Obj **d = (Obj **)(base + off + 0x328);
            *d = this->items[*t]->obj;
            (*d)->SetFlags(-1808);
            i++;
            t++;
            off += 4;
        } while (i < 12);
    }
    FUN_000ffb3c(this->items[0x83], 1);
    FUN_000ffb3c(this->items[0x85], 1);
    Obj *c = this->items[0]->obj;
    this->cursor = c;
    c->fd8 = 0;
    c->f114 = 1;
    this->cursor->SetFlags(-16);
    this->cursor->Show(1);
    this->f360 = 0;
    Obj *f = this->items[0x55]->obj;
    this->frame = f;
    f->fd8 = 12;
    f->fdc = 12;
    this->frame->fe0 = 0;
    this->f1674 = 18;
    this->f1678 = 0;
    this->f167c = 0;
    this->f1680 = 0;
    this->f1684 = 0;
    this->f1664 = 0;
    this->f1668 = 0;
    this->f166c = 0;
    this->f1670 = 12;
    this->f168c = ((Shape *)this->items[0x5c])->h;
    this->f1690 = ((Shape *)this->items[0x5d])->h;
    this->f1688 = 0;
    
}

