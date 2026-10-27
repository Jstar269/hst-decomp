/* HSTMATCH module=EBOOT.BIN start=0x001e77f0 end=0x001e7af4 symbol=FUN_001e77f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Type note: Elem f24/f28 are unsigned (with int fields the implicit int->unsigned conversion is missing and the sum colours v1/a0 the other way round; a no-op (int) cast on the table value also matches). */
struct Elem_001e77f0;
struct Text_001e77f0;
struct Game_001e77f0;
extern "C" {
Game_001e77f0 *FUN_001ee200(void);
void FUN_0010b980(void *p, int cur, int flag);
void FUN_000ffb3c(Elem_001e77f0 *e, int hide);
void FUN_000ffc70(Elem_001e77f0 *e, unsigned int color);
void FUN_00102c54(Text_001e77f0 *t);
int FUN_001fea10(int a, int b, int c);
void FUN_0010d4a8(Text_001e77f0 *t);
int FUN_0024e2dc(void);
}
struct Elem_001e77f0 {
    char pad[0x24];
    unsigned int f24;
    unsigned int f28;
};

struct Item_001e77f0 {
    Elem_001e77f0 *elem;
    int pad[3];
    unsigned int color;
};

struct Text_001e77f0 {
    char pad0[0x64];
    float f64;
    char pad1[0xf8 - 0x68];
    int f0f8;
    char pad2[0x138 - 0xfc];
    int f138;
    void SetFont(int font) {
        f0f8 = font;
        f138 = 1;
        FUN_0010d4a8(this);
    }
};

struct Label_001e77f0 {
    int pad;
    Text_001e77f0 *text;
    void Set(int x, int style) {
        text->f64 = (float)x;
        FUN_00102c54(text);
        text->SetFont(FUN_001fea10(0x11, 0x12, style));
    }
};

struct Self_001e77f0 {
    char pad0[0x2358];
    int f2358;
    char pad1[0x2364 - 0x235c];
    Item_001e77f0 items[9];
    char pad2[0x2454 - 0x2418];
    Label_001e77f0 label;
    int pad3;
    void *f2460;
};

struct List_001e77f0 {
    int *data;
    unsigned int size;
    int &operator[](unsigned int n) { return data[n]; }
};

struct Game_001e77f0 {
    char pad0[0x8178];
    int cur;
    char pad1[0x8184 - 0x817c];
    List_001e77f0 list;
};


extern "C" void FUN_001e77f0(Self_001e77f0 *self)
{
    int cur = FUN_001ee200()->cur;
    List_001e77f0 *list = &FUN_001ee200()->list;
    int i;

    FUN_0010b980(self->f2460, cur, 0);
    /* items[i], items[i + 3], items[i + 6]: the three elements of row i */
    for (i = 0; i < 3; i++) {
        Item_001e77f0 *a = &self->items[i + 3];
        Item_001e77f0 *b = &self->items[i + 6];
        Item_001e77f0 *c = &self->items[i];
        if (i < list->size) {
            if (cur == i) {
                FUN_000ffb3c(a->elem, 0);
                FUN_000ffb3c(b->elem, 1);
                FUN_000ffb3c(c->elem, 0);
                c->elem->f24 = c->elem->f28 + (*list)[i];
                FUN_000ffc70(c->elem, 0x80808080);
            } else {
                FUN_000ffb3c(a->elem, 1);
                FUN_000ffb3c(b->elem, 0);
                FUN_000ffb3c(c->elem, 0);
                c->elem->f24 = c->elem->f28 + (*list)[i];
                FUN_000ffc70(c->elem, c->color);
            }
        } else {
            FUN_000ffb3c(a->elem, 1);
            FUN_000ffb3c(b->elem, 1);
            FUN_000ffb3c(c->elem, 1);
        }
    }
    Label_001e77f0 *label = &self->label;
    switch ((*list)[cur]) {
    case 0:
        label->Set(self->f2358, 3);
        break;
    case 1:
        if (FUN_0024e2dc() == 3) {
            label->Set(self->f2358 + 9, 6);
        } else {
            label->Set(self->f2358, 4);
        }
        break;
    case 2:
        label->Set(self->f2358 + 9, 5);
        break;
    }
}
