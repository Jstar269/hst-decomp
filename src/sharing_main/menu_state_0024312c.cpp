/* HSTMATCH module=hstp_trans_main.prx start=0x0024312c end=0x00243478 symbol=FUN_0024312c lang=c++ rodata=0x002da240 */
/* Clone of src/eboot/menu_state_0023302c.cpp (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: flag-table address as an int offset accumulated onto the global (`off = idx; off += (int)G;`) for retail's index-first addu; names and types await human review. */
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
extern int DAT_0039bf2c;
extern int DAT_0039bf28;
extern int DAT_0039c798;
extern Glob *DAT_003ea8e8;
extern void *DAT_003ea8ec;
extern int DAT_003f3458;
extern char DAT_003f39a8[];
extern char DAT_003eaad8[];
char *FUN_0020d1e0(int a, int b, int c);
void FUN_000143b0(char *buf, char *a, char *b, char *c);
void FUN_0011e940(void *a, int b, char *s, int c, int d);
int FUN_0023c5e0(int n);
int FUN_0023c648(void);
void FUN_00243484(State *s, int a, int b);
void FUN_00230590(int a, int b);
void FUN_001bfc3c(void *p, int n);
void FUN_00242658(Menu *m, int n);
void FUN_002424e0(Menu *m);
void FUN_002422f0(Menu *m, int n);
void FUN_0022f7ac(int a, unsigned char b);
void FUN_002306d0(int a);
void FUN_0023bf2c(int a, int b);
int FUN_00243478(void);
void FUN_00244258(void *p, int n);
void FUN_001e7d30(int n);
void FUN_00242184(Menu *m, int n);
void FUN_0024312c(State *s, int n);
}

extern "C" void FUN_0024312c(State *s, int n)
{
    s->state = n;
    switch (n) {
    case 4:
        FUN_002422f0(s->menu, 0);
        if (FUN_0023c648())
            s->f11 = 1;
        else
            s->f11 = 0;
        {
            Menu *m = s->menu;
            m->f1da = s->f11;
            FUN_002422f0(m, m->f1dc);
        }
        s->f12 = 0;
        break;
    case 5:
        FUN_002422f0(s->menu, 1);
        goto tail;
    case 6:
    case 7: {
        int off = s->menu->f1e0;
        off += (int)DAT_003ea8e8;
        ((Glob *)off)->flags[0] |= 0x80;
        FUN_0023bf2c(s->menu->f1e0, s->menu->f1e4);
        break;
    }
    case 0: {
        int idx = s->menu->f1e0;
        char *a = FUN_0020d1e0(0x11, 0x11, 0);
        char *b = FUN_0020d1e0(6, 0, idx + 1);
        char *c = FUN_0020d1e0(6, idx + 1, DAT_003ea8e8->cnt + 1);
        char buf[512];
        FUN_000143b0(buf, a, b, c);
        FUN_0011e940(DAT_003ea8ec, 2, buf, 0, 0);
        bool ok = FUN_0023c5e0(7) != 0 && !FUN_0023c5e0(8);
        if (ok)
            FUN_00243484(s, 0xf0, 0x88);
        else
            FUN_00243484(s, DAT_0039c798, 0x88);
        break;
    }
    case 2: {
        int cur = DAT_0039bf2c;
        if (cur >= 0) {
            FUN_00230590(s->f8, cur);
            Menu *m = s->menu;
            if (m->f1e0 != cur - 1)
                FUN_001bfc3c(DAT_003eaad8, 1);
            m->f1e0 = cur - 1;
            switch (m->f1dc) {
            case 0:
                break;
            case 1:
                FUN_00242658(m, m->f1e0);
                break;
            }
            DAT_0039bf28 = cur - 1;
            DAT_0039bf2c = -1;
            FUN_002424e0(s->menu);
            FUN_002422f0(s->menu, 0);
            s->menu->m1();
            s->menu->m2();
            DAT_0039bf28 = cur - 1;
        } else {
            FUN_0024312c(s, 4);
            s->menu->m1();
            FUN_0022f7ac(s->f4, s->f10);
        }
        break;
    }
    case 3:
        FUN_002306d0(s->f8);
        break;
    case 8:
        DAT_0039bf28 = FUN_00243478();
        if (DAT_003f3458 != 0)
            FUN_001e7d30(DAT_003f3458);
        else
            FUN_00244258(DAT_003f39a8, 0x47);
        break;
    }
tail:
    if (s->state != 4 && s->state != 5)
        FUN_00242184(s->menu, 1);
}
