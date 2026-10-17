/* HSTMATCH module=EBOOT.BIN start=0x00181600 end=0x0018197c symbol=FUN_00181600 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern "C" {
extern void FUN_00103540(void *, float);
extern void FUN_001037c8(void *, int);
extern void FUN_00103628(void *, int);
extern void FUN_000ffb3c(void *, int);
extern void FUN_001814bc(void *);
extern void FUN_00181284(void *);
extern void *FUN_0016bc70();
extern int FUN_0017916c(void *);
extern void FUN_00102c54(void *);
extern void FUN_0010b6d4(void *, int, int);
extern void FUN_00183954(void *, void *, int, int, void *, void *);
extern void FUN_00184040(void *, void *, int, int, int, int);
}

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
    Slot slots[12];
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

extern "C" void FUN_00181600(Obj *param_1, Param2 *param_2, void *param_3, void *param_4, int param_5)
{
    int i;
    int offset;
    int count;
    int y0;
    Slot *slot;
    void *item_1180;
    float step;

    if (param_1->f4 != 0) {
        FUN_00103540(param_1->f4, 2000.0f);
        FUN_001037c8(param_1->f4, 16);
    }

    FUN_00103628(param_1->f10, 0);

    if (param_1->f1f48 != 0) {
        FUN_00103628(param_1->f1f48, 1);
        FUN_00103628(param_1->f2864, 1);
    }

    param_1->f0c = 1;
    param_1->f0d = 0;
    param_1->f1f45 = 0;

    param_1->w14->SetVisible(0);
    param_1->w18->SetVisible(0);
    param_1->w20->SetVisible(0);
    param_1->w2c->SetVisible(0);
    FUN_000ffb3c(param_1->sub.fcb0, 1);
    param_1->w30->SetVisible(0);
    param_1->w38->SetVisible(0);
    param_1->w40->SetVisible(0);
    param_1->w34->SetVisible(0);
    param_1->w3c->SetVisible(1);
    param_1->w24->SetVisible(1);
    param_1->w1c->SetVisible(1);

    void **p_fd0 = &param_1->fd0;
    if (param_5 != 0) {
        param_1->w14->SetVisible(1);
        FUN_000ffb3c(*p_fd0, 0);
    } else {
        param_1->w14->SetVisible(0);
        FUN_000ffb3c(*p_fd0, 1);
    }

    FUN_001814bc(param_1);
    FUN_00181284(param_1);

    count = FUN_0017916c(FUN_0016bc70());

    SlotItem *item0 = param_1->sub.slots[0].item;
    SlotItem *item_cb0 = (SlotItem *)param_1->sub.fcb0;
    y0 = item0->y;
    int y_cb0 = item_cb0->y;
    int count_minus_1 = count - 1;
    if (count_minus_1 <= 0) {
        step = 0.0f;
    } else {
        step = (float)(y_cb0 - y0) / (float)count_minus_1;
    }

    i = 0;
    offset = 0;
    do {
        SubObj *sub = (SubObj *)((char *)param_1 + (offset + 2940));
        Slot &slot = sub->slots[0];
        if (count <= i) {
            FUN_000ffb3c(slot.item, 1);
        } else {
            FUN_000ffb3c(slot.item, 0);
            SlotItem *item = slot.item;
            short new_y = (short)(int)((float)y0 + step * (float)i);
            short old_y = item->y;
            item->y = new_y;
            item->h += (short)(new_y - old_y);
        }
        i++;
        offset += 20;
    } while (i < 12);

    if (param_2->type != 4) {
        ((Widget20 *)param_1->w20)->f64 = 16.0f;
        FUN_00102c54(param_1->w20);
        item_1180 = param_1->f1180;
    } else {
        ((Widget20 *)param_1->w20)->f64 = 0.0f;
        FUN_00102c54(param_1->w20);
        item_1180 = param_1->f1180;
    }

    FUN_0010b6d4(item_1180, 0, 15);
    FUN_00183954(param_1, param_4, 1, 1, param_2, param_3);
    FUN_00184040(param_1, param_3, 1, 0, 1, 0);
}
