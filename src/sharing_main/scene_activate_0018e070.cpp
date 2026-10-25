/* HSTMATCH module=hstp_trans_main.prx start=0x0018e070 end=0x0018e2ec symbol=FUN_0018e070 lang=c++ */
/* Clone of src/eboot/scene_activate_0018197c.cpp (hstclone.py tag nxc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

class Widget {
public:
    virtual void func0();
    virtual void SetVisible(int v);
};

struct Sub20 {
    char pad[100];
    int f64;
};

struct Obj {
    char pad0[4];
    void *f4;         // 0x04
    char pad1[4];
    char fc;          // 0x0c
    char fd;          // 0x0d
    char pad2[2];
    void *f10;        // 0x10
    Widget *w14;      // 0x14
    Widget *w18;      // 0x18
    Widget *w1c;      // 0x1c
    Sub20 *f20;       // 0x20
    Widget *w24;      // 0x24
    char pad3[4];
    Widget *w2c;      // 0x2c
    Widget *w30;      // 0x30
    Widget *w34;      // 0x34
    Widget *w38;      // 0x38
    Widget *w3c;      // 0x3c
    Widget *w40;      // 0x40
    char pad4[0xd0 - 0x44];
    void *fd0;        // 0xd0
    char pad5[0xcb0 - 0xd4];
    void *fcb0;       // 0xcb0
    char pad6[0x1180 - 0xcb4];
    Widget *w1180;    // 0x1180
    char pad7[0x1f45 - 0x1184];
    char f1f45;       // 0x1f45
    char pad8[2];
    void *f1f48;      // 0x1f48
    char pad9[0x2864 - 0x1f4c];
    void *f2864;      // 0x2864
};

extern "C" {
    void FUN_00108e6c(void *, float);
    void FUN_001090f4(void *, int);
    void FUN_00108f54(void *, int);
    void FUN_00108558(void *);
    void FUN_00105470(void *, int);
    void FUN_0018dbb0(Obj *);
    void FUN_0018d978(Obj *);
    void FUN_001118ac(void *, int, int);
    void FUN_001900a0(Obj *, int, int, int, int, int);
    void FUN_0019078c(Obj *, int, int, int, int, int);
    void FUN_00190fd0(Obj *, int, int);
}

extern "C" void FUN_0018e070(Obj *self, int p2, int p3, int p4, int p5) {
    if (self->f4 != 0) {
        FUN_00108e6c(self->f4, 2000.0f);
        FUN_001090f4(self->f4, 16);
    }

    FUN_00108f54(self->f10, 0);

    if (self->f1f48 != 0) {
        FUN_00108f54(self->f1f48, 1);
        FUN_00108f54(self->f2864, 1);
    }

    self->fc = 1;
    self->fd = 1;
    self->f1f45 = 0;
    self->f20->f64 = 0;
    FUN_00108558(self->f20);

    self->w14->SetVisible(0);
    self->w18->SetVisible(0);
    self->w30->SetVisible(0);
    ((Widget *)self->f20)->SetVisible(1);
    self->w24->SetVisible(0);
    self->w2c->SetVisible(0);

    FUN_00105470(self->fcb0, 1);

    self->w40->SetVisible(0);
    self->w34->SetVisible(0);
    self->w38->SetVisible(0);
    self->w3c->SetVisible(1);
    self->w1c->SetVisible(1);

    void **p_fd0 = &self->fd0;
    if (p4 != 0) {
        self->w14->SetVisible(1);
        FUN_00105470(*p_fd0, 0);
    } else {
        self->w14->SetVisible(0);
        FUN_00105470(*p_fd0, 1);
    }

    FUN_0018dbb0(self);
    FUN_0018d978(self);

    self->w1180->SetVisible(0);
    FUN_001118ac(self->w1180, 16, 20);

    FUN_001900a0(self, 0, 1, 0, p2, p3);
    FUN_0019078c(self, p3, 1, 0, 0, p5);
    FUN_00190fd0(self, p3, p5);
}
