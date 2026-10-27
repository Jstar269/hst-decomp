/* HSTMATCH module=EBOOT.BIN start=0x0022cdd0 end=0x0022d250 symbol=FUN_0022cdd0 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane ol3 near miss reworked); exact match verified; names and types await human review. Matching idiom: byte-offset table loops written as (unsigned int)self + off + DISP with an (unsigned long) re-spelling after the call, so they keep self+off per pass with strength reduction on. */
class VObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
    virtual void m6(float);
};
struct Node {
    void *vt;
    short x, y;
    char pad8[0x18];
    VObj *f20;
    int f24;
};
struct Extra {
    char pad0[0xd8];
    int fD8;
    char padDC[0x114 - 0xdc];
    unsigned char b114;
    char pad115[0x12c - 0x115];
    unsigned char b12c;
};
struct Entry {
    int idx;
    int id;
    int out;
};
struct Self {
    void *vt;
    char pad4[0x54];
    int z58[18];
    unsigned char ba0;
    int m1[5];
    unsigned char bb8;
    int panes[3];
    Node *items[70];
    VObj *subs[12];
    Extra *f210;
    int f214;
    int pad218;
    int f21c;
    int f220;
    int z224[8];
    char pad244[0x290 - 0x244];
    char a290[0x344 - 0x290];
    char a344[0x404 - 0x344];
    int f404;
    int f408;
    int f40c;
    int f410;
    int f414;
};
extern "C" {
extern char DAT_0030983c[];
extern unsigned char DAT_002f332c;
extern int DAT_0034a318[15];
extern int DAT_002c9b38[15];
extern char DAT_002f3480[];
extern float DAT_002f2bd4;
extern int DAT_002f2bf0[3];
extern Entry DAT_002f2fb4[70];
extern int DAT_002f32fc[12];
extern int DAT_003386c8;
extern int DAT_0034a114;
extern int DAT_003415d4;
extern int DAT_0034b350;
void FUN_00102e38(void *);
void FUN_000007f4(void *, void *, void *, int, int);
void FUN_000c777c();
void FUN_00053618();
void FUN_00104118(void *, void *, int);
void FUN_00103540(void *, float);
int FUN_001039d8(void *, int, int);
Node *FUN_001026b8(int, int);
void FUN_000ffc3c(void *, int);
void FUN_0010b8cc(Extra *, int, int);
void *FUN_0008d994(int);
void *FUN_001cd804(int);
void FUN_001037c8(int, int);
void FUN_0022d3f0(Self *, int);
void *FUN_00000bcc(unsigned);
int FUN_0015dbc8(void *);
int FUN_0018ff74(void *);
void FUN_002a49d8(void *);
void FUN_0001f21c(int, int);
}

extern "C" Self *FUN_0022cdd0(Self *self, int reload)
{
    FUN_00102e38(self);
    self->vt = DAT_0030983c;
    self->z58[0] = 0;
    self->z58[1] = 0;
    self->z58[2] = 0;
    self->z58[3] = 0;
    self->z58[4] = 0;
    self->z58[5] = 0;
    self->z58[6] = 0;
    self->z58[7] = 0;
    self->z58[8] = 0;
    self->z58[9] = 0;
    self->z58[10] = 0;
    self->z58[11] = 0;
    self->z58[12] = 0;
    self->z58[13] = 0;
    self->z58[14] = 0;
    self->z58[15] = 0;
    self->z58[16] = 0;
    self->z58[17] = 0;
    self->bb8 = 0;
    self->f21c = 0;
    self->f220 = 0;
    FUN_000007f4(self->a290, (void *)FUN_000c777c, (void *)FUN_00053618, 12, 15);
    FUN_000007f4(self->a344, (void *)FUN_000c777c, (void *)FUN_00053618, 12, 15);
    if (DAT_002f332c) {
        for (int i = 0; i < 15; i++)
            DAT_0034a318[i] = DAT_002c9b38[i];
        DAT_002f332c = 0;
    }
    FUN_00104118(self, DAT_002f3480, 0);
    FUN_00103540(self, DAT_002f2bd4);
    self->z224[0] = 0;
    self->z224[1] = 0;
    self->z224[2] = 0;
    self->z224[3] = 0;
    self->z224[4] = 0;
    self->z224[5] = 0;
    self->z224[6] = 0;
    self->z224[7] = 0;
    self->f414 = 0;
    self->m1[0] = -1;
    self->m1[1] = -1;
    self->m1[2] = -1;
    self->m1[3] = -1;
    self->m1[4] = -1;
    self->ba0 = 1;
    int n1 = 0;
    int *tab = DAT_002f2bf0;
    int off = 0;
    do {
        VObj *o;
        *(VObj **)((unsigned int)self + off + 188) = o = (VObj *)FUN_001039d8(self, *tab, 0);
        o->m5(-2);
        n1++;
        tab++;
        off += 4;
    } while (n1 < 3);
    int k = 0;
    Entry *e = DAT_002f2fb4;
    int off2 = 0;
    do {
        Node *n = FUN_001026b8(self->panes[e->idx], e->id);
        *(Node **)((unsigned int)self + off2 + 200) = n;
        if (n != 0) {
            FUN_000ffc3c(n, -256);
            e->out = (*(Node **)((unsigned long)self + off2 + 200))->f24;
        }
        k++;
        e++;
        off2 += 4;
    } while (k < 70);
    int j = 0;
    int *tab3 = DAT_002f32fc;
    int off3 = 0;
    do {
        VObj **slot = (VObj **)((unsigned int)self + off3 + 480);
        Node *n = self->items[*tab3];
        *slot = n->f20;
        (*slot)->m5(-16);
        j++;
        tab3++;
        off3 += 4;
    } while (j < 12);
    self->f404 = self->items[67]->y;
    self->f408 = self->items[68]->y;
    self->f40c = self->items[13]->x;
    self->f410 = self->items[19]->x;
    Extra *x = (Extra *)self->items[69]->f20;
    self->f210 = x;
    x->fD8 = 0;
    x->b114 = 1;
    FUN_0010b8cc(self->f210, self->z224[0], 2);
    self->f210->b12c = 0;
    ((VObj *)self->f210)->m6(100.0f + DAT_002f2bd4);
    FUN_000ffc3c(self->items[69], -8);
    self->f214 = 0;
    if (DAT_003386c8 != 0) {
        void *p = FUN_0008d994(DAT_003386c8);
        self->f214 = (int)p;
        FUN_00103540(p, 100000.0f);
    } else if (DAT_0034a114 != 0) {
        void *p = FUN_001cd804(DAT_0034a114);
        self->f214 = (int)p;
        FUN_00103540(p, 100000.0f);
        FUN_001037c8(self->f214, -1);
    }
    FUN_0022d3f0(self, reload);
    void *m = FUN_00000bcc(68);
    if (m != 0)
        self->f21c = FUN_0015dbc8(m);
    else
        self->f21c = (int)m;
    if (reload == 0) {
        if (DAT_003415d4 == 0) {
            void *q = FUN_00000bcc(64);
            if (q != 0)
                self->f220 = FUN_0018ff74(q);
            else
                self->f220 = (int)q;
            FUN_0001f21c(DAT_003386c8, DAT_003415d4);
        }
        if (DAT_0034b350 == 0) {
            void *q = FUN_00000bcc(0xd58);
            if (q != 0)
                FUN_002a49d8(q);
            FUN_0001f21c(DAT_003386c8, DAT_0034b350);
        }
    }
    ((VObj *)self)->m1();
    return self;
}
