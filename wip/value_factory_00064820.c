/* HSTMATCH module=EBOOT.BIN start=0x00064820 end=0x000649c0 symbol=FUN_00064820 lang=c99 */
extern char DAT_00307148[];
extern char DAT_00307124[];
extern char DAT_00307100[];
extern char DAT_003070dc[];

extern void *FUN_00000bcc(unsigned int);
extern void *FUN_00000a90(unsigned int);
extern unsigned int FUN_00014a40(const char *);
extern void FUN_000149a8(void *, const char *);
extern long long FUN_0000d610(const char *);
extern int FUN_0000d62c(const char *);
extern float FUN_000223a0(long long);

typedef struct Value {
    void *vptr;
    union {
        int i;
        float f;
        char *s;
    } u;
} Value;

Value *FUN_00064820(char *s)
{
    char c;
    int dot;
    int invalid;
    unsigned int n;
    Value *o;
    char *p;

    invalid = 0;
    dot = 0;
    for (p = s; *p != 0; p++) {
        c = *p;
        if (!((c >= '0' && c <= '9') || c == '.' || c == '-')) {
            invalid = 1;
            break;
        }
        if (c == '.') {
            dot = 1;
            break;
        }
    }
    if (invalid || FUN_00014a40(s) == 0) {
        o = (Value *)FUN_00000bcc(8);
        if (o != 0) {
            o->vptr = &DAT_00307148;
            o->vptr = &DAT_00307124;
            o->u.s = 0;
            if (s != 0) {
                n = FUN_00014a40(s);
                o->u.s = (char *)FUN_00000a90(n + 1);
                FUN_000149a8(o->u.s, s);
            }
        }
        return o;
    }
    if (dot) {
        o = (Value *)FUN_00000bcc(8);
        if (o != 0) {
            long long d = FUN_0000d610(s);
            float f = FUN_000223a0(d);
            o->vptr = &DAT_00307148;
            o->vptr = &DAT_00307100;
            o->u.f = f;
        }
        return o;
    }
    o = (Value *)FUN_00000bcc(8);
    if (o != 0) {
        int v = FUN_0000d62c(s);
        o->vptr = &DAT_00307148;
        o->vptr = &DAT_003070dc;
        o->u.i = v;
    }
    return o;
}
// sy4 NEAR MISS (105/104 words, 66 differ, but the first 40 words match exactly, incl. frame 16 and register colouring a2=p a3=invalid s0=dot):
// done: the scan is `for (p = s; *p != 0; p++) { c = *p; if (!((c >= '0' && c <= '9') || c == '.' || c == '-')) { invalid = 1; break; } if (c == '.') { dot = 1; break; } }`
// (a do/while behind `if (*s)` gives different slti order and drops the guard), FUN_0000d610 returns `long long` and FUN_000223a0 takes it (no stack slot, frame 16),
// the objects are a `Value {void *vptr; union {int i; float f; char *s;} u;}` with the vptr stored twice. Declaration order p,c before invalid,dot.
// Still different: (1) retail keeps a dead `addiu a2,a2,1` copy of the loop increment after `b done` (bnel target is +4 past it), ours drops it (1 word);
// (2) retail's three arms test the new object with `beqz v0` and put `move s0,v0` in the delay slot (arm 1: `beqzl v0,EPILOGUE; lw ra` and the null case returns v0 directly),
// ours does `move s0,v0` first and tests s0 (`beqzl s0`), which shifts every later word. Ruled out: `if ((o = new) != 0)`, `t = new; o = t; if (t)`, per-arm `return o;` vs shared return,
// all 720 declaration orders of the six locals. Probably the arms are inline C++ ctors of real classes (`new Str(s)` / `new Float(f)` / `new Int(i)`) with vtable symbols.
// improved by lane sy4 (unreviewed): 99 -> 66 differing words
