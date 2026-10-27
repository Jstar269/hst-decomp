/* HSTMATCH module=EBOOT.BIN start=0x001fc8bc end=0x001fcde8 symbol=FUN_001fc8bc lang=c++ */
/* Clone of src/sharing_main/state_update_0020afdc.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* State update of an object whose state word is at +0x4c (FUN_001fc718 sets it): states 2-5 are handled
   first and return; the remaining states move the +0x3c node's index at +0x8c between the bounds
   DAT_002ef040..DAT_002ef04c. The trailing `return;` of those cases (not `break;`) is what puts MWCC's branch
   cleanup into the mode retail shows (dead delay-slot originals, unthreaded `b` chains). */
struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad04[0x60];
    void *f64;              /* 0x64 */
    void *f68;              /* 0x68 */
    char pad6c[4];
    void *f70;              /* 0x70 */
    void *f74;              /* 0x74 */
    char pad78[0x14];
    int f8c;                /* 0x8c cursor */
};

struct Obj {
    char pad0[0x3c];
    Node *f3c;              /* 0x3c */
    Node *f40;              /* 0x40 */
    Node *f44;              /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c state */
    int f50;                /* 0x50 counter */
    unsigned char f54;      /* 0x54 */
};

struct Pad {
    char pad0[0x8b];
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
};

struct Timer {
    char pad0[0xc];
    float fc;
};

extern "C" {
extern Pad *DAT_002cfc8c;
extern Timer *DAT_00331b84;
extern unsigned char DAT_003386b8;
extern void *DAT_003403f8;
extern char DAT_0034179c;
extern int DAT_002ef040;
extern int DAT_002ef044;
extern int DAT_002ef048;
extern int DAT_002ef04c;
extern void FUN_001b1c44(void *p, int n);
extern void FUN_001fc718(Obj *self, int state);
extern void FUN_001fbdb8(Node *p, int n);
extern void FUN_0015a118(int h);
extern int FUN_0015d1c8(void *p, int n);
extern void FUN_0015d184(void *p, int n);
extern void FUN_000ffb3c(void *p, int on);
}

template <class T> static inline T Clamp(const T &v, const T &lo, const T &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001fc8bc(Obj *self)
{
    int state;
    int cur;
    int next;
    int on;
    Node *p;

    state = self->f4c;
    switch (state) {
    case 2:
        self->f40->v2();
        FUN_0015a118(self->f48);
        if (DAT_002cfc8c->b != 0 && --self->f50 >= 0) {
            return;
        }
        FUN_001b1c44(&DAT_0034179c, 3);
        if (DAT_003386b8 != 0) {
            FUN_001fc718(self, DAT_003386b8 ? 3 : 4);
        } else if (FUN_0015d1c8(DAT_003403f8, 0) < 3) {
            FUN_001fc718(self, 0);
            if (DAT_003386b8 != 0 && FUN_0015d1c8(DAT_003403f8, 0) > 0) {
                return;
            }
            FUN_0015d184(DAT_003403f8, 0);
            FUN_0015d184(DAT_003403f8, 1);
            FUN_0015d184(DAT_003403f8, 2);
        } else {
            FUN_001fc718(self, DAT_003386b8 ? 3 : 4);
        }
        return;
    case 3:
        FUN_001fbdb8(self->f40, 0);
        return;
    case 4:
        if (DAT_00331b84->fc == 0.0f) {
            if (--self->f50 <= 0) {
                FUN_001fc718(self, 5);
            }
        }
        return;
    case 5:
        return;
    }

    cur = self->f3c->f8c;
    next = cur;
    if (DAT_002cfc8c->c == 0) {
        if (state == 1) {
            if (self->f54 == 0) {
                FUN_001b1c44(&DAT_0034179c, 4);
                FUN_001fc718(self, 5);
            }
        } else if (cur > 0) {
            next = Clamp(cur - 1, DAT_002ef040, DAT_002ef044);
        } else if (state == 0 && self->f54 == 0) {
            FUN_001b1c44(&DAT_0034179c, 4);
            FUN_001fc718(self, 5);
        }
    } else if (DAT_002cfc8c->b == 0) {
        if (state == 1) {
            if (self->f54 != 0) {
                FUN_001b1c44(&DAT_0034179c, 3);
                self->f4c = 0;
            } else {
                FUN_001b1c44(&DAT_0034179c, 3);
                FUN_001fc718(self, 5);
            }
        } else if (cur < 2) {
            next = Clamp(cur + 1, DAT_002ef048, DAT_002ef04c);
        } else {
            FUN_001b1c44(&DAT_0034179c, 3);
            if (self->f54 != 0) {
                FUN_001fc718(self, 4);
            } else {
                FUN_001fc718(self, 5);
            }
        }
    }

    if (self->f4c == 0 && cur != next) {
        if (cur < next) {
            FUN_001b1c44(&DAT_0034179c, 3);
        } else {
            FUN_001b1c44(&DAT_0034179c, 4);
        }
        on = self->f54;
        p = self->f3c;
        p->f8c = next;
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
    }

    switch (self->f4c) {
    case 0:
    case 4:
        self->f3c->v2();
        break;
    case 1:
        self->f40->v2();
        break;
    }
    self->f44->v2();
}
