/* HSTMATCH module=EBOOT.BIN start=0x0025604c end=0x002561b4 symbol=FUN_0025604c lang=c++ */

extern char DAT_002fd698[];
extern char DAT_002fd69c[];

struct VC {
    virtual void d0();
    virtual void m1(int);
};

struct Widget : VC {
    char pad[0xf8 - 4];
    char *text;
    char pad2[0x138 - 0xfc];
    int flag;
};

struct SubEntry {
    char pad[4];
    short y;
    short pad2;
    short y2;
};

struct Player {
    char pad[0x90];
    SubEntry *sub;
    char pad2[0xa4 - 0x94];
};

struct Obj {
    Player players[4];
    char pad_290[0x29c - 0x290];
    int state[4];
    char pad_2ac[0x390 - (0x29c + 16)];
    Widget *widgets[4];
    char pad_3a0[0x3c0 - (0x390 + 16)];
    int scores[4];
};

extern "C" {
void FUN_000143b0(char *, const char *, ...);
void FUN_0010d4a8(Widget *);
}

#define BUF_BASE ((char *)0x0034a7a0)

extern "C" void FUN_0025604c(Obj *self, int idx, int val)
{
    self->state[idx] = val;

    Player *pl = &self->players[idx];
    SubEntry **ps = &pl->sub;
    SubEntry *t0 = *ps;
    if (t0 != 0) {
        short cur = (short)self->scores[idx];
        short old = t0->y;
        t0->y = cur;
        short delta = cur - old;
        t0->y2 += delta;
    }

    Widget **pw = &self->widgets[idx];
    Widget *w = *pw;
    if (w == 0)
        return;

    if (self->state[idx] == 9) {
        w->m1(1);
        return;
    }

    int off = idx * 8;
    if (val < 10) {
        FUN_000143b0(BUF_BASE + off, DAT_002fd698);
    } else {
        FUN_000143b0(BUF_BASE + off, DAT_002fd69c);
    }

    Widget *cur_w = *pw;
    cur_w->text = BUF_BASE + off;
    cur_w->flag = 1;
    FUN_0010d4a8(cur_w);

    SubEntry *sub2 = *ps;
    if (sub2 != 0) {
        int v = self->scores[idx] + 8;
        short old2 = sub2->y;
        sub2->y = v;
        short delta2 = (short)v - old2;
        sub2->y2 += delta2;
    }
}
// near miss from lane s10171846g1r1-0 (unreviewed)
