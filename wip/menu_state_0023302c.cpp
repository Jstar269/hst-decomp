/* HSTMATCH module=EBOOT.BIN start=0x0023302c end=0x00233378 symbol=FUN_0023302c lang=c++ rodata=0x002c9c80 */
struct Menu {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    char pad[0x1da - 4];
    unsigned char f1da;
    char pad1db;
    int f1dc;
    int f1e0;
    int f1e4;
};

struct State {
    Menu *menu;
    int f4;
    int f8;
    int state;
    unsigned char f10;
    unsigned char f11;
    unsigned char f12;
};

struct Glob { char pad[0xc200]; unsigned char flags[0x1e24]; int cnt; };

extern "C" {
extern int DAT_002f3668;
extern int DAT_002f3664;
extern int DAT_002f3ed4;
extern Glob *DAT_003415a8;
extern void *DAT_003415ac;
extern int DAT_0034a120;
extern char DAT_0034a678[];
extern char DAT_0034179c[];
char *FUN_001fea10(int a, int b, int c);
void FUN_000143b0(char *buf, char *a, char *b, char *c);
void FUN_00114168(void *a, int b, char *s, int c, int d);
int FUN_0022c988(int n);
int FUN_0022c9ac(void);
void FUN_00233384(State *s, int a, int b);
void FUN_0022101c(int a, int b);
void FUN_001b1c44(void *p, int n);
void FUN_00232558(Menu *m, int n);
void FUN_002323e0(Menu *m);
void FUN_002321f0(Menu *m, int n);
void FUN_00220238(int a, unsigned char b);
void FUN_0022115c(int a);
void FUN_0022c4ac(int a, int b);
int FUN_00233378(void);
void FUN_00234158(void *p, int n);
void FUN_001d9c78(int n);
void FUN_00232084(Menu *m, int n);
void FUN_0023302c(State *s, int n);
}

extern "C" void FUN_0023302c(State *s, int n)
{
    s->state = n;
    switch (n) {
    case 4:
        FUN_002321f0(s->menu, 0);
        if (FUN_0022c9ac())
            s->f11 = 1;
        else
            s->f11 = 0;
        {
            Menu *m = s->menu;
            m->f1da = s->f11;
            FUN_002321f0(m, m->f1dc);
        }
        s->f12 = 0;
        break;
    case 5:
        FUN_002321f0(s->menu, 1);
        goto tail;
    case 6:
    case 7: {
        Glob *g = DAT_003415a8;
        Menu *m = s->menu;
        ((Glob *)((int)g + m->f1e0))->flags[0] |= 0x80;
        FUN_0022c4ac(s->menu->f1e0, s->menu->f1e4);
        break;
    }
    case 0: {
        int idx = s->menu->f1e0;
        char *a = FUN_001fea10(0x11, 0x11, 0);
        char *b = FUN_001fea10(6, 0, idx + 1);
        char *c = FUN_001fea10(6, idx + 1, DAT_003415a8->cnt + 1);
        char buf[512];
        FUN_000143b0(buf, a, b, c);
        FUN_00114168(DAT_003415ac, 2, buf, 0, 0);
        bool ok = FUN_0022c988(7) != 0 && !FUN_0022c988(8);
        if (ok)
            FUN_00233384(s, 0xf0, 0x88);
        else
            FUN_00233384(s, DAT_002f3ed4, 0x88);
        break;
    }
    case 2: {
        int cur = DAT_002f3668;
        if (cur >= 0) {
            FUN_0022101c(s->f8, cur);
            Menu *m = s->menu;
            if (m->f1e0 != cur - 1)
                FUN_001b1c44(DAT_0034179c, 1);
            m->f1e0 = cur - 1;
            switch (m->f1dc) {
            case 0:
                break;
            case 1:
                FUN_00232558(m, m->f1e0);
                break;
            }
            DAT_002f3664 = cur - 1;
            DAT_002f3668 = -1;
            FUN_002323e0(s->menu);
            FUN_002321f0(s->menu, 0);
            s->menu->m1();
            s->menu->m2();
            DAT_002f3664 = cur - 1;
        } else {
            FUN_0023302c(s, 4);
            s->menu->m1();
            FUN_00220238(s->f4, s->f10);
        }
        break;
    }
    case 3:
        FUN_0022115c(s->f8);
        break;
    case 8:
        DAT_002f3664 = FUN_00233378();
        if (DAT_0034a120 != 0)
            FUN_001d9c78(DAT_0034a120);
        else
            FUN_00234158(DAT_0034a678, 0x47);
        break;
    }
tail:
    if (s->state != 4 && s->state != 5)
        FUN_00232084(s->menu, 1);
}
// NEAR MISS (lane sn2, ~25 compiles): 211/211 words, 2 differ: case 6/7 `flags[menu->f1e0] |= 0x80` loads the global base and the index into swapped
// argument registers (retail `lw a0,G; lw a1,idx; addu a0,a1,a0`, ours `lw a1,G; lw a0,idx; addu a0,a1,a0`). Everything else is exact (jump table rodata=0x2c9c80 -
// NOTE the lui/addiu pair is 0x2d0000-0x6380, not 0x2d9c80 - the dense 0..8 switch, 0x1d9c78 taking the global as its argument, `switch (f1dc) { case 0: break; case 1: .. }`,
// `if (ok) ok = !F(8)` as `bool ok = F(7) != 0 && !F(8)`, virtual slots 1/2, recursion with 4, bool/int flag forms).
// Ruled out for the last two words: idx/base locals in either order, Menu* local, `G + idx`, `idx + G`, pointer-to-flag temporaries, `(int *)` view, index inside the array.
// near miss from lane sn2 (unreviewed)
