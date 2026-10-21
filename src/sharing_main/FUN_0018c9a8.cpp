/* HSTMATCH module=hstp_trans_main.prx start=0x0018c9a8 end=0x0018cc90 symbol=FUN_0018c9a8 lang=c++ */
/* Clone of src/eboot/FUN_001802b4.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode; matching idioms: each member is allocated as p = alloc(n); if (p != 0) p = ctor(p); field = p (merged likely-branch store), the screen is a struct so every access is a displacement off one register, and the panel is read into a local for the two stores but through the member again for the virtual call; exact match verified; names and types await human review. */
extern char DAT_00387edc[];
extern char DAT_00387ef8[];
extern char DAT_00387f20[];
extern char DAT_00387f40[];
extern char DAT_003b7ebc[];
extern char DAT_00387e30[];
extern char DAT_00387e58[];
extern char DAT_002d2710[];
extern char DAT_002d27dc[];
extern char DAT_002d27b8[];
extern char DAT_002d2864[];
extern char DAT_002d2888[];
extern "C" int DAT_003ea860;

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
extern void *FUN_0010873c(void *);
extern void *FUN_00196af0(void *);
extern void FUN_0001c684(char *, int, char *);
extern void FUN_002262f8(int *, char *, int);
extern void FUN_00109a44(void *, char *, int);
extern void FUN_00108e6c(float, void *);
extern void FUN_001090f4(void *, int);
extern void FUN_0001c73c(char *);
extern void FUN_00225e94(void *, void *, char *, int);
extern void FUN_00225f18(void *, void *, int, int);
extern void FUN_00225fb4(void *, void *, char *, int);
extern void FUN_002261ec(void *, void *, char *, int);
extern void FUN_0022618c(void *, void *, char *);
extern void FUN_00226298(void *, void *, char *);
extern void FUN_00193b8c(Screen *);
extern void FUN_001091c4(void *);
extern void FUN_001098a0(void *);
}

extern "C" void FUN_0018c9a8(Screen *self)
{
    void *p;

    if (self->inited == 0) {
        self->inited = 1;
        if (self->layout == 0) {
            p = FUN_00000bcc(0x54);
            if (p != 0) p = FUN_0010873c(p);
            self->layout = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p2878 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p2880 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p2888 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p2894 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p28a0 = p;
            p = FUN_00000bcc(0x110);
            if (p != 0) p = FUN_00196af0(p);
            self->p28a8 = p;
            p = FUN_00000bcc(0x54);
            if (p != 0) p = FUN_0010873c(p);
            self->names = p;
        }
        FUN_0001c684(DAT_003b7ebc, 1, DAT_00387edc);
        FUN_002262f8(&DAT_003ea860, DAT_00387ef8, 0x6b);
        FUN_00109a44(self->layout, DAT_00387f20, 0);
        FUN_00108e6c(0.0f, self->layout);
        FUN_001090f4(self->layout, 0x10);
        FUN_00109a44(self->names, DAT_00387f40, 0);
        FUN_00108e6c(2900.0f, self->names);
        FUN_001090f4(self->names, -256);
        FUN_0001c73c(DAT_003b7ebc);
        FUN_00225e94(self->sub1, self->layout, DAT_00387e30, 10);
        FUN_00225f18(self->sub2, self->sub1, DAT_003ea860, 0x6b);
        FUN_00225fb4(self->sub3, self->sub1, DAT_002d2710, 5);
        FUN_002261ec(self->sub4, self->sub1, DAT_002d27dc, 4);
        FUN_0022618c(&self->panel, self->sub1, DAT_002d27b8);
        FUN_00226298(self->sub5, self->sub1, DAT_002d2864);
        FUN_00193b8c(self);
        Panel *pn = self->panel;
        pn->f_d8 = 0;
        pn->f114 = 1;
        self->panel->v5(-256);
        self->v2a18 = self->rect1->y0;
        self->v2a1c = self->rect2->y1 - self->rect1->y0;
        self->v2a20 = (short)(self->rect1->y1 - self->rect1->y0);
        FUN_001091c4(self->layout);
        FUN_001098a0(self->layout);
        FUN_00225e94(self->sub6, self->names, DAT_00387e58, 1);
        FUN_00225fb4(self->sub7, self->sub6, DAT_002d2888, 1);
    }
}
