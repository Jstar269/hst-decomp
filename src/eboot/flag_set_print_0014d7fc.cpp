/* HSTMATCH module=EBOOT.BIN start=0x0014d7fc end=0x0014d9fc symbol=FUN_0014d7fc lang=c++ rodata=0x002c1998 helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/flag_set_print_0014d7fc.c, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=; the float/int print dispatch is a switch with cases 1,3,5 in ascending order); exact match verified; names and types await human review. */
extern "C" {
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
}
extern "C" {
static void FUN_0014c610(...) {}
}

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

extern "C" int FUN_0014d7fc(struct FlagCmd *c, struct FlagCtx *x)
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
