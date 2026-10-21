/* HSTMATCH module=EBOOT.BIN start=0x001802b4 end=0x0018059c symbol=FUN_001802b4 lang=c++ */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; matching idioms: each member is allocated as p = alloc(n); if (p != 0) p = ctor(p); field = p (merged likely-branch store), the screen is a struct so every access is a displacement off one register, and the panel is read into a local for the two stores but through the member again for the virtual call; exact match verified; names and types await human review. */
extern char DAT_002e08a4[];
extern char DAT_002e08c0[];
extern char DAT_002e08e8[];
extern char DAT_002e0908[];
extern char DAT_0030ebf4[];
extern char DAT_002e07f8[];
extern char DAT_002e0820[];
extern char DAT_002c2210[];
extern char DAT_002c22dc[];
extern char DAT_002c22b8[];
extern char DAT_002c2364[];
extern char DAT_002c2388[];
extern "C" int DAT_00341520;

struct Rect {
    char pad0[6];
    short y0;
    char pad1[2];
    short y1;
};

struct Panel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    char pad1[0xd8 - 4];
    int f_d8;
    char pad2[0x114 - 0xd8 - 4];
    unsigned char f114;
};

struct Screen {
    char pad0[0x1f44];
    unsigned char inited;
    char pad1[3];
    void *layout;
    char sub1[0x28];
    char sub2[0x64];
    Rect *rect1;
    char pad2[0x2014 - 0x1fdc];
    Rect *rect2;
    char pad3[0x27d0 - 0x2018];
    char sub3[0x3c];
    char sub4[0x50];
    Panel *panel;
    char sub5[4];
    void *names;
    char sub6[4];
    char sub7[8];
    char pad4a[4];
    void *p2878;
    char pad4[4];
    void *p2880;
    char pad5[4];
    void *p2888;
    char pad6[8];
    void *p2894;
    char pad7[8];
    void *p28a0;
    char pad8[4];
    void *p28a8;
    char pad9[0x2a18 - 0x28ac];
    int v2a18;
    int v2a1c;
    int v2a20;
};

extern "C" {
extern void *FUN_00000bcc(unsigned);
extern void *FUN_00102e38(void *);
extern void *FUN_0018a3a4(void *);
extern void FUN_0001cad0(char *, int, char *);
extern void FUN_002172f4(int *, char *, int);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(float, void *);
extern void FUN_001037c8(void *, int);
extern void FUN_0001cb88(char *);
extern void FUN_00216e90(void *, void *, char *, int);
extern void FUN_00216f14(void *, void *, int, int);
extern void FUN_00216fb0(void *, void *, char *, int);
extern void FUN_002171e8(void *, void *, char *, int);
extern void FUN_00217188(void *, void *, char *);
extern void FUN_00217294(void *, void *, char *);
extern void FUN_00187440(Screen *);
extern void FUN_00103898(void *);
extern void FUN_00103f74(void *);
}

extern "C" void FUN_001802b4(Screen *self)
{
    void *p;

    if (self->inited == 0) {
        self->inited = 1;
        if (self->layout == 0) {
            p = FUN_00000bcc(0x54);
            if (p != 0) p = FUN_00102e38(p);
            self->layout = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p2878 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p2880 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p2888 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p2894 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p28a0 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_0018a3a4(p);
            self->p28a8 = p;
            p = FUN_00000bcc(0x54);
            if (p != 0) p = FUN_00102e38(p);
            self->names = p;
        }
        FUN_0001cad0(DAT_0030ebf4, 1, DAT_002e08a4);
        FUN_002172f4(&DAT_00341520, DAT_002e08c0, 0x6b);
        FUN_00104118(self->layout, DAT_002e08e8, 0);
        FUN_00103540(0.0f, self->layout);
        FUN_001037c8(self->layout, 0x10);
        FUN_00104118(self->names, DAT_002e0908, 0);
        FUN_00103540(2900.0f, self->names);
        FUN_001037c8(self->names, -256);
        FUN_0001cb88(DAT_0030ebf4);
        FUN_00216e90(self->sub1, self->layout, DAT_002e07f8, 10);
        FUN_00216f14(self->sub2, self->sub1, DAT_00341520, 0x6b);
        FUN_00216fb0(self->sub3, self->sub1, DAT_002c2210, 5);
        FUN_002171e8(self->sub4, self->sub1, DAT_002c22dc, 4);
        FUN_00217188(&self->panel, self->sub1, DAT_002c22b8);
        FUN_00217294(self->sub5, self->sub1, DAT_002c2364);
        FUN_00187440(self);
        Panel *pn = self->panel;
        pn->f_d8 = 0;
        pn->f114 = 1;
        self->panel->v5(-256);
        self->v2a18 = self->rect1->y0;
        self->v2a1c = self->rect2->y1 - self->rect1->y0;
        self->v2a20 = (short)(self->rect1->y1 - self->rect1->y0);
        FUN_00103898(self->layout);
        FUN_00103f74(self->layout);
        FUN_00216e90(self->sub6, self->names, DAT_002e0820, 1);
        FUN_00216fb0(self->sub7, self->sub6, DAT_002c2388, 1);
    }
}
