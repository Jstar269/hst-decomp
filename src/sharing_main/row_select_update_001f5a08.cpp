/* HSTMATCH module=hstp_trans_main.prx start=0x001f5a08 end=0x001f5d0c symbol=FUN_001f5a08 lang=c++ */
/* Clone of src/eboot/row_select_update_001e77f0.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Type note: Elem f24/f28 are unsigned (with int fields the implicit int->unsigned conversion is missing and the sum colours v1/a0 the other way round; a no-op (int) cast on the table value also matches). */
struct Elem_001f5a08;
struct Text_001f5a08;
struct Game_001f5a08;
extern "C" {
Game_001f5a08 *FUN_001fc5c8(void);
void FUN_00111b58(void *p, int cur, int flag);
void FUN_00105470(Elem_001f5a08 *e, int hide);
void FUN_001055a4(Elem_001f5a08 *e, unsigned int color);
void FUN_00108558(Text_001f5a08 *t);
int FUN_0020d1e0(int a, int b, int c);
void FUN_00113a50(Text_001f5a08 *t);
int FUN_0025e514(void);
}
struct Elem_001f5a08 {
    char pad[0x24];
    unsigned int f24;
    unsigned int f28;
};

struct Item_001f5a08 {
    Elem_001f5a08 *elem;
    int pad[3];
    unsigned int color;
};

struct Text_001f5a08 {
    char pad0[0x64];
    float f64;
    char pad1[0xf8 - 0x68];
    int f0f8;
    char pad2[0x138 - 0xfc];
    int f138;
    void SetFont(int font) {
        f0f8 = font;
        f138 = 1;
        FUN_00113a50(this);
    }
};

struct Label_001f5a08 {
    int pad;
    Text_001f5a08 *text;
    void Set(int x, int style) {
        text->f64 = (float)x;
        FUN_00108558(text);
        text->SetFont(FUN_0020d1e0(0x11, 0x12, style));
    }
};

struct Self_001f5a08 {
    char pad0[0x2358];
    int f2358;
    char pad1[0x2364 - 0x235c];
    Item_001f5a08 items[9];
    char pad2[0x2454 - 0x2418];
    Label_001f5a08 label;
    int pad3;
    void *f2460;
};

struct List_001f5a08 {
    int *data;
    unsigned int size;
    int &operator[](unsigned int n) { return data[n]; }
};

struct Game_001f5a08 {
    char pad0[0x8178];
    int cur;
    char pad1[0x8184 - 0x817c];
    List_001f5a08 list;
};


extern "C" void FUN_001f5a08(Self_001f5a08 *self)
{
    int cur = FUN_001fc5c8()->cur;
    List_001f5a08 *list = &FUN_001fc5c8()->list;
    int i;

    FUN_00111b58(self->f2460, cur, 0);
    /* items[i], items[i + 3], items[i + 6]: the three elements of row i */
    for (i = 0; i < 3; i++) {
        Item_001f5a08 *a = &self->items[i + 3];
        Item_001f5a08 *b = &self->items[i + 6];
        Item_001f5a08 *c = &self->items[i];
        if (i < list->size) {
            if (cur == i) {
                FUN_00105470(a->elem, 0);
                FUN_00105470(b->elem, 1);
                FUN_00105470(c->elem, 0);
                c->elem->f24 = c->elem->f28 + (*list)[i];
                FUN_001055a4(c->elem, 0x80808080);
            } else {
                FUN_00105470(a->elem, 1);
                FUN_00105470(b->elem, 0);
                FUN_00105470(c->elem, 0);
                c->elem->f24 = c->elem->f28 + (*list)[i];
                FUN_001055a4(c->elem, c->color);
            }
        } else {
            FUN_00105470(a->elem, 1);
            FUN_00105470(b->elem, 1);
            FUN_00105470(c->elem, 1);
        }
    }
    Label_001f5a08 *label = &self->label;
    switch ((*list)[cur]) {
    case 0:
        label->Set(self->f2358, 3);
        break;
    case 1:
        if (FUN_0025e514() == 3) {
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
