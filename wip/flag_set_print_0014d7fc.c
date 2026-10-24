/* HSTMATCH module=EBOOT.BIN start=0x0014d7fc end=0x0014d9fc symbol=FUN_0014d7fc lang=c99 rodata=0x002c1998 */
extern int FUN_0014c610(const char *, ...);
extern int *FUN_0022a940(int);
extern float *FUN_0022a958(int);
extern int *FUN_0022a970(int);
extern float *FUN_0022a98c(int);
extern unsigned char DAT_003402f0;
extern int DAT_003402f4[];
extern float DAT_00340374[];
extern char *DAT_002c1978[];
extern char DAT_002dc240;
extern char DAT_002dc24c;
extern char DAT_002dc2c4;
extern char DAT_002dc2d8;

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

int FUN_0014d7fc(struct FlagCmd *c, struct FlagCtx *x)
{
    int type;
    int i;
    int *p;
    char *base;

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
            FUN_0014c610((char *)&DAT_002dc2c4, DAT_002c1978[type], c->value.f);
            break;
        default:
            FUN_0014c610((char *)&DAT_002dc2d8, DAT_002c1978[type], c->value.i);
            break;
        }
    }
    type = c->type;
    base = x->base;
    switch (type) {
    case 0:
        p = FUN_0022a940(c->index);
        *p = c->value.i;
        break;
    case 1:
        p = (int *)FUN_0022a958(c->index);
        *(float *)p = c->value.f;
        break;
    case 2:
        p = FUN_0022a970(c->index);
        *p = c->value.i;
        break;
    case 3:
        p = (int *)FUN_0022a98c(c->index);
        *(float *)p = c->value.f;
        break;
    case 4:
        *(int *)(base + c->index * 4 + 0xc) = c->value.i;
        break;
    case 5:
        *(float *)(base + c->index * 4 + 0x10c) = c->value.f;
        break;
    case 8:
        DAT_003402f4[c->index] = c->value.i;
        break;
    case 9:
        DAT_00340374[c->index] = c->value.f;
        break;
    }
    return 0;
}

// 127/128 words. Only the debug-print if/else block layout differs: retail emits
// [tests: beql 5 / beq 3 / beq 1 -> FLOAT][b INT][FLOAT][b JOIN][INT], this emits
// [same tests][INT falls through][b JOIN][FLOAT] - one word short (the extra b + lui).
// Ruled out: switch with case 5/3/1 (MWCC sorts the compares ascending, draft 1 and
// case-order test both gave li v0,1 first); switch with default first (same ascending
// sort); positive if (5||3||1) (tests right, but the 3rd test comes out bnel -> INT);
// extra type reload inside the else (drops to 126).
// Second delta: the indent loop counter is s0 here and v1 in retail (retail's s0 is
// already live with the hoisted type load); loop shape and trip test are identical.
// near miss: 128/128 words, only 3 differ - the indent-loop counter. Retail's loop counter lives
// in v1 and ours in s0 (`move v1,zero` vs `move s0,zero`, plus the increment and the slt); the
// loop shape, the per-pass reload of x->depth, the trip test and every other word match.
// Fixed since the first attempt (was 127/128 with the two arms transposed): the float/int
// dispatch must be a SWITCH with the cases written in ASCENDING order -
// `switch (type) { case 1: case 3: case 5: float; break; default: int; break; }` - which is what
// produces retail's `beql 5 / beq 3 / beq 1` chain to the float body followed by `b` to the int
// body. Writing the cases 5/3/1 gives ascending compares (li v0,1 first), and the `if (a||b||c)`
// form puts the int arm in the fall-through position.
// A counter in a caller-saved register across the `jal` suggests the retail print helper is a
// STATIC function in the same TU (MWCC's interprocedural clobber analysis keeps v1 live);
// reproducing that would need helpers= and the print helper's own body, so parked.
// A second attempt at `for (i = 0; i <= x->depth; i++)` is wrong: it reverses the compare to
// `slt at,v0,s0` and turns the guard into `bltz` (126/128).
// improved by lane fm8 (unreviewed): 97 -> 3 differing words
