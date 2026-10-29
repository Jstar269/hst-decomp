/* HSTMATCH module=EBOOT.BIN start=0x0014d7fc end=0x0014d9fc symbol=FUN_0014d7fc lang=c++ rodata=0x002c1998 helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/flag_set_print_0014d7fc.c, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=; the float/int print dispatch is a switch with cases 1,3,5 in ascending order); exact match verified; names and types await human review. */
#include "hst/script_node.h"
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

/* Logs the command when debug output is on, then stores its value into the variable it names. */
extern "C" int FUN_0014d7fc(VarCmd *cmd, ScriptRunCtx *ctx)
{
    int type;
    int i;
    int *p;
    ScriptVars *vars;

    if (DAT_003402f0 != 0) {
        if (DAT_003402f0 != 0) {
            FUN_0014c610((char *)&DAT_002dc240);
            for (i = 0; i < ctx->depth + 1; i++)
                FUN_0014c610((char *)&DAT_002dc24c);
        }
        type = cmd->type;
        switch (type) {
        case VAR_KIND_FLOAT_A:
        case VAR_KIND_FLOAT_B:
        case VAR_KIND_LOCAL_FLOAT:
            FUN_0014c610((char *)&DAT_002dc2c4, DAT_002c1978[type], cmd->value.f);
            break;
        default:
            FUN_0014c610((char *)&DAT_002dc2d8, DAT_002c1978[type], cmd->value.i);
            break;
        }
    }
    type = cmd->type;
    vars = ctx->vars;
    switch (type) {
    case VAR_KIND_INT_A:
        p = FUN_0022a940(cmd->index);
        *p = cmd->value.i;
        break;
    case VAR_KIND_FLOAT_A:
        p = (int *)FUN_0022a958(cmd->index);
        *(float *)p = cmd->value.f;
        break;
    case VAR_KIND_INT_B:
        p = FUN_0022a970(cmd->index);
        *p = cmd->value.i;
        break;
    case VAR_KIND_FLOAT_B:
        p = (int *)FUN_0022a98c(cmd->index);
        *(float *)p = cmd->value.f;
        break;
    case VAR_KIND_LOCAL_INT:
        *(int *)((char *)vars + cmd->index * 4 + 0xc) = cmd->value.i;
        break;
    case VAR_KIND_LOCAL_FLOAT:
        *(float *)((char *)vars + cmd->index * 4 + 0x10c) = cmd->value.f;
        break;
    case VAR_KIND_GLOBAL_INT:
        DAT_003402f4[cmd->index] = cmd->value.i;
        break;
    case VAR_KIND_GLOBAL_FLOAT:
        DAT_00340374[cmd->index] = cmd->value.f;
        break;
    }
    return 0;
}
