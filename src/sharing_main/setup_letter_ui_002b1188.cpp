/* HSTMATCH module=hstp_trans_main.prx start=0x002b1188 end=0x002b136c symbol=FUN_002b1188 lang=c++ */
/* Clone of src/eboot/setup_letter_ui_002a1d7c.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_002dc21c[];
extern char DAT_002dc214[];
extern char DAT_002dc20c[];
extern char DAT_002dc200[];
extern char DAT_002dc1f4[];
extern char DAT_002dc1e8[];
extern char DAT_002dc1e0[];
extern char DAT_002dc1d4[];
void *FUN_001e4070(void *model, char *name);
void FUN_002b0240(void *src, Widget **dst);
void FUN_001a8688(void *obj, float a, float b);
void FUN_0011be94(void *obj, int a, int b);
void FUN_002b16c0(void *obj, int a);
short FUN_001e4030(void *obj);
short FUN_001e400c(void *obj);
void FUN_001df9f4(void *obj);
void FUN_001e3fe8(void *obj);
void FUN_00108558(void *obj);
void FUN_002b136c(Ui *ui, int n);
}

extern "C" void FUN_002b1188(Owner *self, Model *model)
{
    Ui *u = self->ui;
    u->model = model;
    model->m5(-1);
    FUN_002b0240(FUN_001e4070(u->model, DAT_002dc21c), &u->key10);
    FUN_002b0240(FUN_001e4070(u->model, DAT_002dc214), &u->key20);
    FUN_002b0240(FUN_001e4070(u->model, DAT_002dc20c), &u->key30);
    u->assign10 = FUN_001e4070(u->model, DAT_002dc200);
    u->assign20 = FUN_001e4070(u->model, DAT_002dc1f4);
    u->assign30 = FUN_001e4070(u->model, DAT_002dc1e8);
    u->letter = FUN_001e4070(u->model, DAT_002dc1e0);
    u->envelope = FUN_001e4070(u->model, DAT_002dc1d4);
    FUN_001a8688(u->envelope, 0.75f, 0.75f);
    FUN_0011be94(u->envelope, 374, 85);
    u->key10->x = 370.0f;
    u->key10->y = 142.0f;
    u->key20->x = 370.0f;
    u->key20->y = 142.0f;
    u->key30->y = 236.0f;
    FUN_0011be94(u->assign10, 395, 144);
    FUN_0011be94(u->assign20, 395, 144);
    FUN_002b16c0(u->assign30, 237);
    FUN_002b16c0(u->letter, 16);
    u->s30 = FUN_001e4030(u->letter);
    u->s32 = FUN_001e400c(u->letter);
    u->s34 = u->s30;
    u->s36 = u->s32;
    u->f38 = 1.0f;
    FUN_001df9f4(u->key20);
    FUN_001e3fe8(u->assign20);
    FUN_00108558(u->model);
    FUN_002b136c(self->ui, 0);
}
