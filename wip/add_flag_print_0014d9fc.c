/* HSTMATCH module=EBOOT.BIN start=0x0014d9fc end=0x0014dc3c symbol=FUN_0014d9fc lang=c99 rodata=0x002c19d8 helpers=FUN_0014c610@0x0014c610-0x0014c63c */
static void FUN_0014c610(...)
{
}

extern int *FUN_0022a940(int);
extern float *FUN_0022a958(int);
extern int *FUN_0022a970(int);
extern float *FUN_0022a98c(int);
extern unsigned char DAT_003402f0;
extern int DAT_003402f4[];
extern float DAT_00340374[];
extern char *DAT_002c19c0[];
extern char DAT_002dc240;
extern char DAT_002dc24c;
extern char DAT_002dc2ec;
extern char DAT_002dc300;

struct FlagCmd {
    char pad0[8];
    int type;
    int index;
    union { int i; float f; } value;
};

struct FlagCtx {
    char *base;
    char pad0[0x14];
    int depth;
};

int FUN_0014d9fc(struct FlagCmd *c, struct FlagCtx *x)
{
    int type;
    int i;
    int *p;
    float *pf;

    if (DAT_003402f0 != 0) {
        if (DAT_003402f0 != 0) {
            FUN_0014c610((char *)&DAT_002dc240);
            for (i = 0; i < x->depth + 1; i++)
                FUN_0014c610((char *)&DAT_002dc24c);
        }
        type = c->type;
        switch (type) {
        case 1:
        case 3:
        case 5:
            FUN_0014c610((char *)&DAT_002dc2ec, DAT_002c19c0[type], c->value.f);
            break;
        default:
            FUN_0014c610((char *)&DAT_002dc300, DAT_002c19c0[type], c->value.i);
            break;
        }
    }
    type = c->type;
    switch (type) {
    case 0:
        p = FUN_0022a940(c->index);
        *p = *p + c->value.i;
        break;
    case 1:
        pf = FUN_0022a958(c->index);
        *pf = *pf + c->value.f;
        break;
    case 2:
        p = FUN_0022a970(c->index);
        *p = *p + c->value.i;
        break;
    case 3:
        pf = FUN_0022a98c(c->index);
        *pf = *pf + c->value.f;
        break;
    case 4:
        *(int *)(x->base + c->index * 4 + 0xc) = *(int *)(x->base + c->index * 4 + 0xc) + c->value.i;
        break;
    case 5:
        *(float *)(x->base + c->index * 4 + 0x10c) = *(float *)(x->base + c->index * 4 + 0x10c) + c->value.f;
        break;
    case 8:
        DAT_003402f4[c->index] = DAT_003402f4[c->index] + c->value.i;
        break;
    case 9:
        DAT_00340374[c->index] = DAT_00340374[c->index] + c->value.f;
        break;
    }
    return 0;
}

// 145/144 words (1 over). Same shape as its twin 0x0014d7fc, including the same
// debug-print block-order delta: retail lays [tests][b INT][FLOAT][b JOIN][INT],
// this lays [tests][INT][b JOIN][FLOAT]. The twin's four spellings are ruled out in
// wip/flag_set_print_0014d7fc.c; the += cases already match word for word.
// near miss: 146/144 words, 50 differing (was 145/144 with 107 differing and the dispatch arms
// transposed). Fixed: same ascending-case switch as its twin 0x0014d7fc -
// `switch (type) { case 1: case 3: case 5: float; break; default: int; break; }` -> retail's
// `beql 5 / beq 3 / beq 1` chain to the float body plus `b` to the int body.
// Remaining 2 extra words: retail has ONE join after the lower switch (`beqz at,0x14dc20` then
// every case `b 0x14dc20`), ours goes `beqzl at,epilogue` with `lw ra,12(sp)` in the delay slot and
// a second join (`b 0x14dc28`), i.e. MWCC merged the dispatch's skip path with the function's
// `return 0`. Tried: case order (fixed), no-default vs default. Next step would be making the
// whole dispatch the tail of the function with a single `return 0` outside the surrounding
// `if (DAT_003402f0 != 0)` block.
// improved by lane fm8 (unreviewed): 107 -> 50 differing words
