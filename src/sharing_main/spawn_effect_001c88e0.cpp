/* HSTMATCH module=hstp_trans_main.prx start=0x001c88e0 end=0x001c8a30 symbol=FUN_001c88e0 lang=c++ */
/* Clone of src/eboot/spawn_effect_001bab98.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (wip/spawn_effect_001c88e0.cpp was the starting point: the 2nd argument of FUN_0021465c is the unsigned char result of FUN_001c8cc8, passed as an unsigned char parameter); names and types await human review. */

extern "C" int FUN_001aa91c();
extern "C" int FUN_001773a0(void *p);
extern "C" void *FUN_0017759c(void *p, int n);
extern "C" int FUN_00177360(void *p);
extern "C" unsigned char FUN_001c8cc8(int x);
extern "C" int FUN_00212dd8(void *p);
extern "C" void FUN_0021465c(int a, unsigned char b, void *c, int d, int e, int f, int g);
extern "C" void FUN_001c84d4(void *a, void *b, int c);
extern "C" void FUN_001c8808(void *a, void *b, int c);

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

extern "C" void FUN_001c88e0(Obj_1bab98 *self, void **msg, int a3)
{
    if (*(unsigned char *)*msg != 0) {
        int h = FUN_001aa91c();
        void *v = (*(Fn_1bab98 *)(h + 0xf0))();
        Rec_1bab98 *r = (Rec_1bab98 *)FUN_0017759c(v, FUN_001773a0(v));
        Msg_1bab98 m = {};
        m.p = v;
        m.a = r->w0;
        m.b = r->w1;
        m.c = r->w2;
        m.d = r->w3;
        m.e = FUN_00177360(v);
        unsigned char f = FUN_001c8cc8(*(int *)(*(int *)(*(int *)((char *)self + 4)) + 4));
        void *q = self->f4;
        int res = FUN_00212dd8(m.p);
        FUN_0021465c(*(int *)q, f, &m, r->b8 != 0, r->b9 != 0, r->b10 != 0, res);
        self->f10 = 1;
        self->f14 = 1;
    }
    FUN_001c84d4(self, msg, a3);
    FUN_001c8808(self, msg, a3);
}
