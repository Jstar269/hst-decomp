/* HSTMATCH module=hstp_trans_main.prx start=0x0018dcf4 end=0x0018e070 symbol=FUN_0018dcf4 lang=c++ */
/* Clone of src/eboot/FUN_00181600.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
extern "C" {
extern void FUN_00108e6c(void *, float);
extern void FUN_001090f4(void *, int);
extern void FUN_00108f54(void *, int);
extern void FUN_00105470(void *, int);
extern void FUN_0018dbb0(void *);
extern void FUN_0018d978(void *);
extern void *FUN_00177e98();
extern int FUN_00185780(void *);
extern void FUN_00108558(void *);
extern void FUN_001118ac(void *, int, int);
extern void FUN_001900a0(void *, void *, int, int, void *, void *);
extern void FUN_0019078c(void *, void *, int, int, int, int);
}

enum { LIST_ROW_COUNT = 12, LIST_ROW_STRIDE = 20, REQUEST_TYPE_NO_INDENT = 4 };

struct Widget {
    virtual void m0();
    virtual void SetVisible(int);
};

struct SlotItem {
    char pad[4];
    short y;
    char pad6[2];
    short h;
};

struct Slot {
    SlotItem *item;
    char pad[16];
};

struct Param2 {
    char pad[0x1c];
    int type;
};

struct SubObj {
    char pad[68];
    Slot slots[LIST_ROW_COUNT];
    void *fcb0;
};

struct Obj {
    char pad[4];
    void *f4;
    char pad8[4];
    unsigned char f0c;
    unsigned char f0d;
    char pade[2];
    void *f10;
    Widget *w14;
    Widget *w18;
    Widget *w1c;
    Widget *w20;
    Widget *w24;
    char pad28[4];
    Widget *w2c;
    Widget *w30;
    Widget *w34;
    Widget *w38;
    Widget *w3c;
    Widget *w40;
    char pad44[0xd0 - 0x44];
    void *fd0;
    char padb7c[0xb7c - 0xd4];
    SubObj sub;
    char pad1180[0x1180 - 0xcb4];
    void *f1180;
    char pad1f45[0x1f45 - 0x1184];
    unsigned char f1f45;
    char pad1f48[2];
    void *f1f48;
    char pad2864[0x2864 - 0x1f4c];
    void *f2864;
};

struct Widget20 {
    char pad[100];
    float f64;
};

extern "C" void FUN_0018dcf4(Obj *self, Param2 *request, void *ctx_a, void *ctx_b, int show_first)
{
    int i; /* row index */
    int offset;
    int count;
    int y_first;
    Slot *slot;
    void *list_item;
    float step;

    if (self->f4 != 0) {
        FUN_00108e6c(self->f4, 2000.0f);
        FUN_001090f4(self->f4, 16);
    }

    FUN_00108f54(self->f10, 0);

    if (self->f1f48 != 0) {
        FUN_00108f54(self->f1f48, 1);
        FUN_00108f54(self->f2864, 1);
    }

    self->f0c = 1;
    self->f0d = 0;
    self->f1f45 = 0;

    self->w14->SetVisible(0);
    self->w18->SetVisible(0);
    self->w20->SetVisible(0);
    self->w2c->SetVisible(0);
    FUN_00105470(self->sub.fcb0, 1);
    self->w30->SetVisible(0);
    self->w38->SetVisible(0);
    self->w40->SetVisible(0);
    self->w34->SetVisible(0);
    self->w3c->SetVisible(1);
    self->w24->SetVisible(1);
    self->w1c->SetVisible(1);

    void **p_panel_ref = &self->fd0;
    if (show_first != 0) {
        self->w14->SetVisible(1);
        FUN_00105470(*p_panel_ref, 0);
    } else {
        self->w14->SetVisible(0);
        FUN_00105470(*p_panel_ref, 1);
    }

    FUN_0018dbb0(self);
    FUN_0018d978(self);

    count = FUN_00185780(FUN_00177e98());

    SlotItem *item0 = self->sub.slots[0].item;
    SlotItem *item_cb0 = (SlotItem *)self->sub.fcb0;
    y_first = item0->y;
    int y_last = item_cb0->y;
    int gaps = count - 1;
    if (gaps <= 0) {
        step = 0.0f;
    } else {
        step = (float)(y_last - y_first) / (float)gaps;
    }

    /* Space the visible rows evenly; hide rows beyond the entry count. */
    i = 0;
    offset = 0;
    do {
        SubObj *sub = (SubObj *)((char *)self + (offset + 2940));
        Slot &slot = sub->slots[0];
        if (count <= i) {
            FUN_00105470(slot.item, 1);
        } else {
            FUN_00105470(slot.item, 0);
            SlotItem *item = slot.item;
            short new_y = (short)(int)((float)y_first + step * (float)i);
            short old_y = item->y;
            item->y = new_y;
            item->h += (short)(new_y - old_y);
        }
        i++;
        offset += LIST_ROW_STRIDE;
    } while (i < LIST_ROW_COUNT);

    if (request->type != REQUEST_TYPE_NO_INDENT) {
        ((Widget20 *)self->w20)->f64 = 16.0f;
        FUN_00108558(self->w20);
        list_item = self->f1180;
    } else {
        ((Widget20 *)self->w20)->f64 = 0.0f;
        FUN_00108558(self->w20);
        list_item = self->f1180;
    }

    FUN_001118ac(list_item, 0, 15);
    FUN_001900a0(self, ctx_b, 1, 1, request, ctx_a);
    FUN_0019078c(self, ctx_a, 1, 0, 1, 0);
}
