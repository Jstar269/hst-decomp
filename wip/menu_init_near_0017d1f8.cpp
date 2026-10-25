/* HSTMATCH module=EBOOT.BIN start=0x0017d1f8 end=0x0017d470 symbol=FUN_0017d1f8 lang=c++ */
inline void *operator new[](unsigned int, void *p) { return p; }

struct Rec {
    int a;
    unsigned b, c, d, e;
    unsigned f;
};

struct Item {
    int pad;
    int f4;
};

struct Mgr {
    char pad0[0x3ec];
    unsigned short *(*f3ec)(int, unsigned);
    char pad1[0x548 - 0x3f0];
    unsigned (*f548)(int);
};

struct Menu {
    char pad0[4];
    int f4;
    Item **f8;
    char pad1[0x50 - 0xc];
    int f50;
    int f54;
    char pad2[0x59 - 0x58];
    unsigned char f59;
    char pad3[0x5c - 0x5a];
    char sub5c[0x19c - 0x5c];
    int f19c;
    char sub1a0[0x2e0 - 0x1a0];
    int f2e0;
};

extern unsigned DAT_002c2014[][4];

extern "C" {
void FUN_001fe0f4(int p);
void FUN_001fe1f4(void *s);
Mgr *FUN_0016bc70();
int FUN_001fe584(void *s, unsigned id, int last, Rec *r, int p);
int FUN_001fe244(void *s, int a, unsigned id, int first, Rec *r, int b, int c);
void FUN_001fe7b8(void *s);
void FUN_0017c6d4(Menu *m, int v);
void FUN_0017c39c(Menu *m, int v);
}

static inline void SetMode(Menu *m, int v)
{
    if (m->f50 != v) {
        m->f54 = v;
        if (v) {
            m->f50 = v;
            m->f54 = 0;
        }
    } else {
        if (m->f54 != 0) {
            m->f54 = 0;
        }
    }
}

extern "C" void FUN_0017d1f8(Menu *self, int p2, int p3, int p4)
{
    FUN_001fe0f4(p4);
    self->f4 = p2;
    FUN_001fe1f4(self->sub5c);
    Rec rec;
    new (&rec) char[24]();
    unsigned v;
    Mgr *m = FUN_0016bc70();
    if (p3 != 0x7fff && p3 != 0x7ffe) {
        v = m->f548(p3);
    } else {
        v = 0;
    }
    unsigned *p = DAT_002c2014[p2];
    for (int i = 0; i < 4; i++) {
        int isLast = i == 3;
        int isFirst = i == 0;
        unsigned id = *p;
        unsigned short *q = FUN_0016bc70()->f3ec(p3, id);
        rec.b = q[0];
        rec.c = q[1];
        rec.d = q[2];
        rec.e = q[3];
        rec.a = p3;
        rec.f = v;
        FUN_001fe584(&self->sub1a0, id, isLast, &rec, p4);
        FUN_001fe244(self->sub5c, 0, id, isFirst, &rec, 1, 0);
        p++;
    }
    FUN_001fe7b8(&self->sub1a0);
    if (p4 != 0) {
        self->f19c = 3;
    } else {
        self->f19c = 0;
    }
    self->f8[0]->f4 = 0;
    self->f8[1]->f4 = 0;
    self->f8[2]->f4 = 0;
    self->f8[3]->f4 = 0;
    SetMode(self, 1);
    if (p4 != 0) {
        self->f2e0 = 3;
    } else {
        self->f2e0 = 0;
    }
    if (p4 == 0) {
        FUN_0017c6d4(self, 1);
        FUN_0017c39c(self, 1);
        FUN_0017c6d4(self, 1);
        FUN_0017c39c(self, 1);
        FUN_0017c6d4(self, 1);
        FUN_0017c39c(self, 1);
        FUN_0017c6d4(self, 1);
        FUN_0017c39c(self, 1);
    }
    self->f59 = 1;
}
// NEAR 0x0017d1f8 (about 45 words): 151/158 words. Prologue through the zeroing loop (new (&rec) char[24]()), the 0x7fff/0x7ffe test (!= && != / else), the table walk and both loop calls match structurally.
// Differs: retail keeps two compare results (i==3 -> s7, i==0 -> s6) in saved registers across the singleton call (xori/xor BEFORE `jal 16bc70`, sltiu split around it) and v in s8, so its frame is 80 and it saves s0-s8; ours folds the compares into the call arguments (frame 64, s0-s6).
// Tried: bool/int/uchar/const locals, inline Part() with the flags as by-value params, IsLast()/IsFirst() inline helpers: mwcc sinks all of them to the call. Tail: f19c/f2e0 use `if (p4 != 0) 3 else 0`; SetMode(self,1) inline with `if (f50 != v)` first (the `if (v)` stays unfolded because v is an inline param).
// near miss from lane sn8 (unreviewed)
