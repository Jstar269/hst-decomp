/* HSTMATCH module=EBOOT.BIN start=0x002a1d7c end=0x002a1f60 symbol=FUN_002a1d7c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names (from the model-part name strings l_key10..30, l_assign10..30, letter0, envelope0) and types await human review. */
struct Widget {
    char pad0[0x60];
    float x;
    float y;
};

struct Model {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int n);
};

struct Ui {
    char pad0[0xc];
    Model *model;
    Widget *key10;
    Widget *key20;
    Widget *key30;
    void *assign10;
    void *assign20;
    void *assign30;
    void *letter;
    void *envelope;
    short s30;
    short s32;
    short s34;
    short s36;
    float f38;
};

struct Owner {
    char pad0[0x1d0];
    Ui *ui;
};

extern "C" {
extern char DAT_002cc17c[];
extern char DAT_002cc174[];
extern char DAT_002cc16c[];
extern char DAT_002cc160[];
extern char DAT_002cc154[];
extern char DAT_002cc148[];
extern char DAT_002cc140[];
extern char DAT_002cc134[];
void *FUN_001d6280(void *model, char *name);
void FUN_002a0e34(void *src, Widget **dst);
void FUN_002a22d8(void *obj, float a, float b);
void FUN_001d764c(void *obj, int a, int b);
void FUN_002a22b4(void *obj, int a);
short FUN_001d6240(void *obj);
short FUN_001d621c(void *obj);
void FUN_001d1bf0(void *obj);
void FUN_001d61e4(void *obj);
void FUN_00102c54(void *obj);
void FUN_002a1f60(Ui *ui, int n);
}

extern "C" void FUN_002a1d7c(Owner *self, Model *model)
{
    Ui *u = self->ui;
    u->model = model;
    model->m5(-1);
    FUN_002a0e34(FUN_001d6280(u->model, DAT_002cc17c), &u->key10);
    FUN_002a0e34(FUN_001d6280(u->model, DAT_002cc174), &u->key20);
    FUN_002a0e34(FUN_001d6280(u->model, DAT_002cc16c), &u->key30);
    u->assign10 = FUN_001d6280(u->model, DAT_002cc160);
    u->assign20 = FUN_001d6280(u->model, DAT_002cc154);
    u->assign30 = FUN_001d6280(u->model, DAT_002cc148);
    u->letter = FUN_001d6280(u->model, DAT_002cc140);
    u->envelope = FUN_001d6280(u->model, DAT_002cc134);
    FUN_002a22d8(u->envelope, 0.75f, 0.75f);
    FUN_001d764c(u->envelope, 374, 85);
    u->key10->x = 370.0f;
    u->key10->y = 142.0f;
    u->key20->x = 370.0f;
    u->key20->y = 142.0f;
    u->key30->y = 236.0f;
    FUN_001d764c(u->assign10, 395, 144);
    FUN_001d764c(u->assign20, 395, 144);
    FUN_002a22b4(u->assign30, 237);
    FUN_002a22b4(u->letter, 16);
    u->s30 = FUN_001d6240(u->letter);
    u->s32 = FUN_001d621c(u->letter);
    u->s34 = u->s30;
    u->s36 = u->s32;
    u->f38 = 1.0f;
    FUN_001d1bf0(u->key20);
    FUN_001d61e4(u->assign20);
    FUN_00102c54(u->model);
    FUN_002a1f60(self->ui, 0);
}
