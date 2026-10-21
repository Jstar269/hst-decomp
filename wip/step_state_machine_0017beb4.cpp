/* HSTMATCH module=EBOOT.BIN start=0x0017beb4 end=0x0017c204 symbol=FUN_0017beb4 lang=c++ */
struct Sub {
    virtual void m0();
    virtual void m1();
};
struct Owner {
    char pad[0x1b4];
    int idx;
};
struct Rec {
    char pad[0x24];
    unsigned char f24;
};
struct Part {
    char pad[0x108];
    float f108;
};
struct Self {
    volatile int cur;
    volatile int next;
    char pad8[8];
    Sub sub;
    char pad14[0x60 - 0x14];
    Owner *owner;
    char pad64[0x68 - 0x64];
    Part *objA;
    char pad6c[0x74 - 0x6c];
    Part *objB;
};
extern "C" {
int FUN_001fe974(int, int);
int FUN_0017c304(int, int);
void FUN_00093524(float, Sub *);
void FUN_00092078(float, Sub *, int, int, int);
void FUN_000937f0(Sub *, float, int);
void FUN_002054b0(float, Part *, int, int);
unsigned char *FUN_0016bb88();
void FUN_000575fc(Part *, int, int);
void FUN_0016c030(int);
Rec *FUN_00193474(int);
}

static inline void Tail(Self *s, int idx, int mode)
{
    Part *a = s->objA;
    Part *b = s->objB;
    int flag = 0;
    unsigned char *tab = FUN_0016bb88();
    int c;
    if (idx >= 0 && idx < 15) {
        c = tab[idx + 0x1025];
    } else {
        c = 1;
    }
    if (c == 2) {
        flag = 1;
    }
    if (a != 0) {
        FUN_000575fc(a, mode, flag);
    }
    if (b != 0) {
        FUN_000575fc(b, mode, flag);
    }
    Sub *p = &s->sub;
    p->m1();
}

extern "C" int FUN_0017beb4(Self *self, int idx, int idx2, Self *other, int p5, int p6)
{
    int state = self->next;
    int ret = 0;
    if (state != 0) {
        switch (state) {
        case 1:
        case 2:
        case 3:
        case 5:
            self->cur = self->next;
            self->next = 0;
            ret = self->cur;
            if (FUN_001fe974(p5, idx) == 0) {
                int oi = self->owner->idx;
                Rec *r = FUN_00193474(oi);
                int mode;
                if (r->f24 == 0) {
                    mode = 4;
                } else {
                    mode = 2;
                }
                if (FUN_0017c304(p6, mode) != 0) {
                    float fv = -1.0f;
                    FUN_00093524(1.0f, &self->sub);
                    FUN_00092078(-1.0f, &self->sub, mode, 1, 0);
                    if (idx != idx2) {
                        if (self->cur == other->cur) {
                            if (other->objA != 0) {
                                fv = other->objA->f108;
                            } else {
                                fv = 0.0f;
                            }
                            FUN_000937f0(&self->sub, fv, -1);
                        }
                    }
                    FUN_002054b0(fv, self->objB, mode, 1);
                    Tail(self, oi, mode);
                }
            }
            break;
        case 4:
            if (FUN_001fe974(p5, idx) == 0) {
                if (FUN_0017c304(p6, 1) != 0) {
                    int flag;
                    Part *b;
                    Part *a;
                    int oi;
                    oi = self->owner->idx;
                    FUN_00093524(1.0f, &self->sub);
                    FUN_00092078(-1.0f, &self->sub, 1, 0, 0);
                    FUN_002054b0(-1.0f, self->objB, 1, 0);
                    a = self->objA;
                    b = self->objB;
                    flag = 0;
                    unsigned char *tab = FUN_0016bb88();
                    int c;
                    if (oi >= 0 && oi < 15) {
                        c = tab[oi + 0x1025];
                    } else {
                        c = 1;
                    }
                    if (c == 2) {
                        flag = 1;
                    }
                    if (a != 0) {
                        FUN_000575fc(a, 1, flag);
                    }
                    if (b != 0) {
                        FUN_000575fc(b, 1, flag);
                    }
                    Sub *p = &self->sub;
                    p->m1();
                }
                self->cur = self->next;
                self->next = 0;
                if (self->owner != 0) {
                    FUN_0016c030(self->owner->idx);
                }
                ret = self->cur;
            }
            break;
        default:
            self->cur = state;
            self->next = 0;
            ret = self->cur;
            break;
        }
    }
    return ret;
}
// NEAR 7 words (of 212). Everything matches except the register colours of the second inlined tail (the state-4 arm, manually duplicated here):
//  retail: oi (owner->idx) = s2, objB = s0, objA = s1, flag = s3; ours: oi = s0, objB = s2, objA = s1, flag = s3 (the rest of the 7 words follow from the swap).
// Tried: all 24 declaration orders of {oi, a, b, flag} x both load orders of a/b (perm2), oi declared at function top in three positions x declaration orders of {a, b, flag} (perm3), the shared inline Tail() helper
//  (gives oi = s0 as well), and using `ret` itself as the index variable (moves ret to s1 and the first arm's mode to s2).
// Learned (212/212 words): the state switch is `if (state != 0) switch (state) { case 1: case 2: case 3: case 5: B; break; case 4: A; break; default: cur = state; next = 0; ret = cur; break; }`;
//  `cur` and `next` are volatile members (retail reloads self->next and self->cur around the stores); the c-clamp is `int c; if (idx >= 0 && idx < 15) c = tab[idx + 0x1025]; else c = 1;` with `unsigned char *tab` (the `if (idx < 0) ... else if (idx < 15)` chain compiles to the bgezl form);
//  FUN_000937f0 declared (Sub *, float, int) so addiu a0 precedes mov.s f12; `if (other->objA != 0) fv = objA->f108; else fv = 0.0f;`; the volatile reloads give retail's delay-slot loads on the state==5 branch.
// near miss from lane sn6 (unreviewed)
