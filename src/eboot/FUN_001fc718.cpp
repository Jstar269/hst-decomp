/* HSTMATCH module=EBOOT.BIN start=0x001fc718 end=0x001fc8bc symbol=FUN_001fc718 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char byte;

struct Node {
    virtual void v0();
    virtual void v1();
    char pad04[0x60];
    void *f64;              /* 0x64 */
    void *f68;              /* 0x68 */
    char pad6c[4];
    void *f70;              /* 0x70 */
    void *f74;              /* 0x74 */
    char pad78[0x14];
    int f8c;                /* 0x8c */
};

struct Obj {
    char pad0[0x3c];
    Node *f3c;              /* 0x3c */
    Node *f40;              /* 0x40 */
    char pad44[4];
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
    unsigned char f54;      /* 0x54 */
};

extern "C" {
extern void *DAT_00338c24;
extern void *DAT_00331b84;
extern void FUN_0006391c(void *p, float f, int n);
extern void FUN_000fbed0(void *p, int n);
extern void FUN_000ffb3c(void *p, int n);
extern int FUN_0015b698();
extern void FUN_0015b6a4(int h, int a, int b, int c);
}

extern "C" void FUN_001fc718(Obj *self, int mode)
{
    Node *p;
    int v;
    int on;

    self->f4c = mode;
    switch (mode) {
    case 0:
        on = self->f54;
        p = self->f3c;
        p->f8c = 0;
        if (on != 0) {
            FUN_000ffb3c(p->f64, p->f8c == 0);
            FUN_000ffb3c(p->f70, p->f8c == 0);
            FUN_000ffb3c(p->f68, 1);
            FUN_000ffb3c(p->f74, 1);
        } else {
            FUN_000ffb3c(p->f64, 0);
            FUN_000ffb3c(p->f70, 0);
            FUN_000ffb3c(p->f68, 0);
            FUN_000ffb3c(p->f74, 0);
        }
        self->f3c->v1();
        break;
    case 1:
        self->f40->v1();
        break;
    case 2:
        v = FUN_0015b698();
        FUN_0015b6a4(self->f48, v, 0, 1);
        self->f40->v1();
        self->f50 = 300;
        break;
    case 3:
        FUN_000fbed0(DAT_00338c24, 1);
        break;
    case 4:
        FUN_000fbed0(DAT_00338c24, 0);
        FUN_0006391c(DAT_00331b84, 65535.0f, 15);
        self->f50 = 3;
        break;
    }
}
