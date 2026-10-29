/* HSTMATCH module=EBOOT.BIN start=0x001bab98 end=0x001bace8 symbol=FUN_001bab98 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (wip/spawn_effect_001bab98.cpp was the starting point: the 2nd argument of FUN_00205df4 is the unsigned char result of FUN_001baf80, passed as an unsigned char parameter); names and types await human review. */

extern "C" int FUN_0019d474();
extern "C" int FUN_0016b1dc(void *p);
extern "C" void *FUN_0016b3d8(void *p, int n);
extern "C" int FUN_0016b19c(void *p);
extern "C" unsigned char FUN_001baf80(int x);
extern "C" int FUN_00204570(void *p);
extern "C" void FUN_00205df4(int a, unsigned char b, void *c, int d, int e, int f, int g);
extern "C" void FUN_001ba78c(void *a, void *b, int c);
extern "C" void FUN_001baac0(void *a, void *b, int c);

typedef void *(*Fn_1bab98)(void);

struct Rec_1bab98 {
    unsigned short w0, w1, w2, w3;
    unsigned char b8, b9, b10;
};

struct Msg_1bab98 {
    void *p;
    int a, b, c, d;
    int e;
};

struct Obj_1bab98 {
    char pad0[4];
    void *f4;
    char pad1[8];
    unsigned char f10;
    char pad2[3];
    unsigned char f14;
};

extern "C" void FUN_001bab98(Obj_1bab98 *self, void **msg, int a3)
{
    if (*(unsigned char *)*msg != 0) {
        int h = FUN_0019d474();
        void *v = (*(Fn_1bab98 *)(h + 0xf0))();
        Rec_1bab98 *r = (Rec_1bab98 *)FUN_0016b3d8(v, FUN_0016b1dc(v));
        Msg_1bab98 m = {};
        m.p = v;
        m.a = r->w0;
        m.b = r->w1;
        m.c = r->w2;
        m.d = r->w3;
        m.e = FUN_0016b19c(v);
        unsigned char f = FUN_001baf80(*(int *)(*(int *)(*(int *)((char *)self + 4)) + 4));
        void *q = self->f4;
        int res = FUN_00204570(m.p);
        FUN_00205df4(*(int *)q, f, &m, r->b8 != 0, r->b9 != 0, r->b10 != 0, res);
        self->f10 = 1;
        self->f14 = 1;
    }
    FUN_001ba78c(self, msg, a3);
    FUN_001baac0(self, msg, a3);
}
