/* HSTMATCH module=EBOOT.BIN start=0x001b9b0c end=0x001b9d10 symbol=FUN_001b9b0c lang=c99 */
extern void FUN_00000020(char *);
extern void FUN_00000028(void);
extern int FUN_0001342c(void);
extern int FUN_000143b0(char *, const char *, ...);
extern void FUN_0001ca58(int, char *);
extern void *FUN_00000bcc(int);
extern void *FUN_000492e4(void *, int);
extern void FUN_000493fc(void *, int, char *);
extern void FUN_0001cb88(int);
extern int FUN_000494d0(float, void *, int, int);
extern void FUN_00059084(void *, int);
extern int DAT_003402a0;
extern unsigned char DAT_003386b8;
extern char DAT_0030ebf4;
extern char DAT_002e9bc0;
extern char DAT_002e9bd0;
extern char DAT_002e9bd4;
extern char DAT_002e9bf8;
extern char DAT_002e9c20;

extern char *DAT_002e9b70[];

struct PrevCam {
    char pad0[0x3c];
    void *cam;
    unsigned char f40;
    unsigned char f41;
    char pad1[2];
    int f44;
};

void FUN_001b9b0c(struct PrevCam *p, int eval)
{
    char camName[256];
    char path[256];
    char desc[256];
    char *names[20];
    char **src;
    char **dst;
    int idx;
    int n;
    int cnt;
    void *obj;
    void *cam;
    void (*fn)(void *, int);

    FUN_00000020(&DAT_002e9bc0);
    idx = *(int *)(DAT_003402a0 + 0x1364);
    if (eval != 0)
        n = 1;
    else
        n = FUN_0001342c() % 5 + 1;
    p->f41 = (unsigned char)eval;
    p->f44 = 0;
    src = DAT_002e9b70;
    dst = names;
    cnt = 10;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    } while (--cnt > 0);
    FUN_000143b0(camName, &DAT_002e9bd0, names[idx - 1]);
    FUN_000143b0(path, &DAT_002e9bd4, idx);
    if (DAT_003386b8 == 0)
        FUN_000143b0(desc, &DAT_002e9bf8, camName, camName, n);
    else
        FUN_000143b0(desc, &DAT_002e9c20, camName, camName, n);
    FUN_0001ca58((int)&DAT_0030ebf4, path);
    if (p->cam != 0) {
        if (p->cam == 0)
            p->cam = 0;
        else {
            fn = *(void (**)(void *, int))(*(int *)((char *)p->cam + 4) + 8);
            fn(p->cam, 1);
            p->cam = 0;
        }
    }
    p->cam = (cam = FUN_00000bcc(0x1f0)) != 0 ? FUN_000492e4(cam, 1) : 0;
    FUN_000493fc(p->cam, 0, desc);
    FUN_0001cb88((int)&DAT_0030ebf4);
    if (p->cam == 0 || FUN_000494d0(65533.0f, p->cam, 0, 1) == 0) {
        p->f40 = 1;
    } else {
        p->f40 = 0;
        obj = *(void **)p->cam;
        FUN_00059084(obj, -1);
        *(float *)((char *)obj + 0xd0) = *(float *)((char *)obj + 0xc4);
    }
    FUN_00000028();
}

// 129/129 words, 51 differ. Three causes, everything else is shift:
// (1) `(int)&DAT_0030ebf4` used twice is CSE'd into a callee-saved register here
//     (lui+addiu once, then move a0,sN); retail re-materialises lui+addiu at both
//     call sites. Tried: pointer cast, array decay, separate locals - all CSE.
// (2) the child release: retail lays out [beqzl a0,END][beqzl a0,STORE][sw zero in
//     the delay][vcall][STORE] and calls through t9; this gives bnezl + an extra b
//     and calls through v0. Per MWCC-NOTES the t9 form needs a real C++ virtual
//     call (vptr at +4 here, i.e. a non-virtual base with one int), not a cast.
// (3) the new/ctor pair: retail stores p->cam twice (raw pointer in the beqzl
//     delay, ctor result after) and reloads p->cam for every later use.
// near miss from lane fm8 (unreviewed)
