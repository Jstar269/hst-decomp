/* HSTMATCH module=hstp_trans_main.prx start=0x002b62f8 end=0x002b6568 symbol=__ct__10C_002b62f8Fv lang=c++ */
/* Clone of src/eboot/menu_ad_history_ctor_002a6b68.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

struct B_0010873c {
    B_0010873c();
    virtual void v0();
    char pad4[0x50];
};

struct C_002b62f8 : B_0010873c {
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
    C_002b62f8();
    virtual void v1();
};

extern char DAT_003aad04[];
extern char *PTR_003aa144[];
extern Lookup DAT_003aa5ac[];
extern int DAT_003aac3c[];
extern int DAT_003aacd4[];

extern "C" {
void FUN_00109a44(C_002b62f8 *m, char *path, int f);
void FUN_00108e6c(float t, C_002b62f8 *m);
Obj *FUN_00109304(C_002b62f8 *m, char *name, int f);
Item *FUN_00108124(Obj *page, char *name);
void FUN_00105470(Item *it, int on);
}

C_002b62f8::C_002b62f8()
{
    FUN_00109a44(this, DAT_003aad04, 0);
    FUN_00108e6c(1000.0f, this);
    int base = (int)this;
    {
        int i = 0;
        char **n = PTR_003aa144;
        int off = 0;
        do {
            Obj *o = FUN_00109304(this, *n, 0);
            *(Obj **)(base + off + 0x54) = o;
            (*(Obj **)(base + off + 0x54))->SetFlags(-2048);
            i++;
            n++;
            off += 4;
        } while (i < 3);
    }
    {
        int i = 0;
        Lookup *l = DAT_003aa5ac;
        int off = 0;
        do {
            Item *it = FUN_00108124(this->pages[l->page], l->name);
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
        int *t = DAT_003aac3c;
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
        int *t = DAT_003aacd4;
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
    FUN_00105470(this->items[0x83], 1);
    FUN_00105470(this->items[0x85], 1);
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

