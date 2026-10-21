/* HSTMATCH module=EBOOT.BIN start=0x0012aa6c end=0x0012ac28 symbol=FUN_0012aa6c lang=c++ */
struct Mat4 {
    float m[16];
} __attribute__((aligned(16)));

extern Mat4 DAT_002bc410;
extern float DAT_002da3b4;

extern "C" {
float fabsf(float);
void FUN_0004d2cc(float, Mat4 *, const Mat4 *);
void FUN_0004d270(Mat4 *, const Mat4 *, const void *);
void FUN_00093434(void *, Mat4 *);
}

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(int);
    char pad[0x1b0 - 4];
    float pos[4];
    float prev[4];
    char pad2[0x1e4 - 0x1d0];
    float yaw;
    float target;
};

extern "C" void FUN_0012aa6c(Obj *self, const float *newPos, int arg)
{
    Mat4 m;
    self->prev[0] = self->pos[0];
    self->prev[1] = self->pos[1];
    self->prev[2] = self->pos[2];
    self->prev[3] = self->pos[3];
    self->pos[0] = newPos[0];
    self->pos[1] = newPos[1];
    self->pos[2] = newPos[2];
    self->pos[3] = newPos[3];
    self->v30(arg);
    float c = self->yaw;
    float t = self->target;
    if (t >= 0.0f && c < 0.0f && t - c > 3.1415927f) {
        c += 6.2831855f;
    } else if (t < 0.0f) {
        if (c >= 0.0f && c - t > 3.1415927f) {
            t += 6.2831855f;
        }
    }
    float diff = c - t;
    float step = DAT_002da3b4;
    if (fabsf(diff) > step) {
        if (diff < 0.0f) {
            step = -step;
        }
        c = t + step;
    }
    if (c > 3.1415927f) {
        c -= 6.2831855f;
        self->yaw = c;
    } else {
        self->yaw = c;
    }
    FUN_0004d2cc(self->yaw, &m, &DAT_002bc410);
    FUN_0004d270(&m, &m, self->pos);
    FUN_00093434(self, &m);
}
// Near miss (12 words, sn5; control flow, compares, constants and stores all match): two float-register choices differ.
// (1) retail keeps diff = c - t in $f2 and the loaded step bound (DAT_002da3b4, negated in place) in $f1; ours has diff in $f1 and the bound in $f2.
// (2) the wrap `c - 2*PI` is computed in place (`sub.s $f4,$f4,$f0`) in retail, ours writes it to $f0 (the constant's register) before the store.
// Matching idioms found: declare c (yaw) before t (target) to get t=$f3/c=$f4; the compare chain `t >= 0 && c < 0 && t - c > PI { c += 2PI } else if (t < 0) { if (c >= 0 && c - t > PI) t += 2PI; }`
// followed by one shared `diff = c - t` reproduces retail's jump layout (the nested `if (A||B||C) {...} else {...}` form with the duplicated subtraction does not);
// the wrap must store in both arms (`if (c > PI) { c -= 2PI; self->yaw = c; } else { self->yaw = c; }`) or the later `self->yaw` argument is forwarded from c instead of reloaded.
// Ruled out for (1)/(2): declaring the bound or diff first, a local `k`, `ad = fabsf(diff)` before/after the bound, store-through-variable forms of the wrap.
// near miss from lane sn5 (unreviewed)
