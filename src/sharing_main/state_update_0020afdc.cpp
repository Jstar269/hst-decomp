/* HSTMATCH module=hstp_trans_main.prx start=0x0020afdc end=0x0020b508 symbol=FUN_0020afdc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* State update of an object whose state word is at +0x4c (FUN_0020ae30 sets it): states 2-5 are handled
   first and return; the remaining states move the +0x3c node's index at +0x8c between the bounds
   DAT_0039707c..DAT_00397088. The trailing `return;` of those cases (not `break;`) is what puts MWCC's branch
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
extern Pad *DAT_003751d4;
extern Timer *DAT_003daec4;
extern unsigned char DAT_003e19f8;
extern void *DAT_003e9738;
extern char DAT_003eaad8;
extern int DAT_0039707c;
extern int DAT_00397080;
extern int DAT_00397084;
extern int DAT_00397088;
extern void FUN_001bfc3c(void *p, int n);
extern void FUN_0020ae30(Obj *self, int state);
extern void FUN_0020a4d0(Node *p, int n);
extern void FUN_001666f0(int h);
extern int FUN_00169770(void *p, int n);
extern void FUN_0016972c(void *p, int n);
extern void FUN_00105470(void *p, int on);
}

template <class T> static inline T Clamp(const T &v, const T &lo, const T &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0020afdc(Obj *self)
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
        FUN_001666f0(self->f48);
        if (DAT_003751d4->b != 0 && --self->f50 >= 0) {
            return;
        }
        FUN_001bfc3c(&DAT_003eaad8, 3);
        if (DAT_003e19f8 != 0) {
            FUN_0020ae30(self, DAT_003e19f8 ? 3 : 4);
        } else if (FUN_00169770(DAT_003e9738, 0) < 3) {
            FUN_0020ae30(self, 0);
            if (DAT_003e19f8 != 0 && FUN_00169770(DAT_003e9738, 0) > 0) {
                return;
            }
            FUN_0016972c(DAT_003e9738, 0);
            FUN_0016972c(DAT_003e9738, 1);
            FUN_0016972c(DAT_003e9738, 2);
        } else {
            FUN_0020ae30(self, DAT_003e19f8 ? 3 : 4);
        }
        return;
    case 3:
        FUN_0020a4d0(self->f40, 0);
        return;
    case 4:
        if (DAT_003daec4->fc == 0.0f) {
            if (--self->f50 <= 0) {
                FUN_0020ae30(self, 5);
            }
        }
        return;
    case 5:
        return;
    }

    cur = self->f3c->f8c;
    next = cur;
    if (DAT_003751d4->c == 0) {
        if (state == 1) {
            if (self->f54 == 0) {
                FUN_001bfc3c(&DAT_003eaad8, 4);
                FUN_0020ae30(self, 5);
            }
        } else if (cur > 0) {
            next = Clamp(cur - 1, DAT_0039707c, DAT_00397080);
        } else if (state == 0 && self->f54 == 0) {
            FUN_001bfc3c(&DAT_003eaad8, 4);
            FUN_0020ae30(self, 5);
        }
    } else if (DAT_003751d4->b == 0) {
        if (state == 1) {
            if (self->f54 != 0) {
                FUN_001bfc3c(&DAT_003eaad8, 3);
                self->f4c = 0;
            } else {
                FUN_001bfc3c(&DAT_003eaad8, 3);
                FUN_0020ae30(self, 5);
            }
        } else if (cur < 2) {
            next = Clamp(cur + 1, DAT_00397084, DAT_00397088);
        } else {
            FUN_001bfc3c(&DAT_003eaad8, 3);
            if (self->f54 != 0) {
                FUN_0020ae30(self, 4);
            } else {
                FUN_0020ae30(self, 5);
            }
        }
    }

    if (self->f4c == 0 && cur != next) {
        if (cur < next) {
            FUN_001bfc3c(&DAT_003eaad8, 3);
        } else {
            FUN_001bfc3c(&DAT_003eaad8, 4);
        }
        on = self->f54;
        p = self->f3c;
        p->f8c = next;
        if (on != 0) {
            FUN_00105470(p->f64, p->f8c == 0);
            FUN_00105470(p->f70, p->f8c == 0);
            FUN_00105470(p->f68, 1);
            FUN_00105470(p->f74, 1);
        } else {
            FUN_00105470(p->f64, 0);
            FUN_00105470(p->f70, 0);
            FUN_00105470(p->f68, 0);
            FUN_00105470(p->f74, 0);
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
