/* HSTMATCH module=EBOOT.BIN start=0x0017fff4 end=0x001802b4 symbol=FUN_0017fff4 lang=c++ */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode (character-select screen init, sibling of 0x1802b4); the two globals tested first are the arguments of FUN_0008d994 / FUN_001cd804 (Ghidra dropped them), the layout is a struct so accesses are displacements off s0; exact match verified; names and types await human review. */
struct Rect {
    char pad0[4];
    short a, b, c, d;
};

struct Panel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    virtual void v6(float);
    char pad1[0xd8 - 4];
    int f_d8;
    char pad2[0x114 - 0xd8 - 4];
    unsigned char f114;
};

struct Obj28 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int, int, int, int);
    char pad[0x60 - 4];
    float f60;
};

struct Screen {
    char pad00[0x4];
    void * f4;
    void * f8;
    char pad01[0x4];
    void * layout;
    void * h14;
    char pad02[0x8];
    void * f20;
    void * f24;
    Obj28 * f28;
    void * f2c;
    void * f30;
    void * f34;
    void * f38;
    char pad03[0x8];
    char sub2[0x8c];
    int fd0;
    char pad04[0x90c];
    Rect * r9e0;
    char pad05[0x10];
    Rect * r9f4;
    char pad06[0x178];
    Rect * rb70;
    char pad07[0x40c];
    Rect * rf80;
    char pad08[0x178];
    char sub3[0x84];
    Panel * panel;
    int v1184;
    char pad09[0xb0];
    int v1238;
    int v123c;
    char pad10[0x14];
    char s1254[0x8c];
    char s12e0[0x8c];
    char s136c[0x8c];
    char s13f8[0x8c];
    char s1484[0x8c];
    char s1510[0x8c];
    char s159c[0x8c];
    char s1628[0x8c];
    char s16b4[0x8c];
};

extern char DAT_002e083c[];
extern char DAT_002e0858[];
extern char DAT_002e0880[];
extern char DAT_0030ebf4[];
extern char DAT_002e0798[];
extern char DAT_002c2080[];
extern char DAT_002c21ec[];
extern "C" int DAT_003386c8;
extern "C" int DAT_0034a114;
extern "C" int DAT_0034151c;

extern "C" {
void FUN_0001cad0(char *, int, char *);
void FUN_002172f4(int *, char *, int);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_0001cb88(char *);
void *FUN_0008d994(int);
void *FUN_001cd804(int);
void FUN_00103628(void *, int);
void FUN_001815bc(Screen *);
void FUN_00216e90(void *, void *, char *, int);
void FUN_00216f14(void *, void *, int, int);
void FUN_00216fb0(void *, void *, char *, int);
void FUN_00217188(void *, void *, char *);
void FUN_00057b58(float, void *, int, int);
void FUN_00058ddc(void *, int, int);
void FUN_00059084(void *, int);
char *FUN_0016bc7c(void);
void FUN_000550ec(float, void *);
void FUN_000550c8(void *, float *);
void FUN_00217704(void *, void *);
void FUN_00217614(void *, int);
}

extern "C" void FUN_0017fff4(Screen *self)
{
    FUN_0001cad0(DAT_0030ebf4, 1, DAT_002e083c);
    FUN_002172f4(&DAT_0034151c, DAT_002e0858, 0xd6);
    FUN_00104118(self->layout, DAT_002e0880, 0);
    FUN_00103540(0.0f, self->layout);
    FUN_001037c8(self->layout, 0x10);
    FUN_0001cb88(DAT_0030ebf4);
    if (DAT_003386c8 != 0) {
        self->f4 = FUN_0008d994(DAT_003386c8);
    } else if (DAT_0034a114 != 0) {
        self->f4 = FUN_001cd804(DAT_0034a114);
    }
    if (self->f4 != 0) {
        FUN_00103628(self->f4, 0);
    }
    FUN_001815bc(self);
    FUN_00216e90(&self->h14, self->layout, DAT_002e0798, 12);
    FUN_00216f14(self->sub2, &self->h14, DAT_0034151c, 0xd6);
    FUN_00216fb0(self->sub3, &self->h14, DAT_002c2080, 11);
    FUN_00217188(&self->panel, &self->h14, DAT_002c21ec);
    Panel *pn = self->panel;
    pn->f_d8 = 0;
    pn->f114 = 1;
    self->panel->v5(-256);
    self->panel->v6(2300.0f);
    self->v1184 = (short)(self->rf80->c - self->rf80->a);
    if (self->f8 != 0) {
        float v[4];
        FUN_00057b58(0.0f, self->f8, 0, 0);
        FUN_00058ddc(self->f8, 1, -1);
        FUN_00059084(self->f8, -1);
        FUN_000550ec(*(float *)(FUN_0016bc7c() + 0x6c), self->f8);
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        FUN_000550c8(self->f8, v);
    }
    FUN_00217704(self->s1254, self->h14);
    FUN_00217614(self->s12e0, self->fd0);
    FUN_00217704(self->s136c, self->f20);
    FUN_00217704(self->s13f8, self->f2c);
    FUN_00217704(self->s1484, self->f28);
    FUN_00217704(self->s1510, self->f24);
    FUN_00217704(self->s159c, self->f30);
    FUN_00217704(self->s1628, self->f34);
    FUN_00217704(self->s16b4, self->f38);
    self->v1238 = (int)self->f28->f60;
    self->v123c = self->r9f4->a - self->r9e0->a;
    Rect *rr = self->rb70;
    self->f28->v8(1, rr->a, rr->b, rr->c, rr->d);
}
