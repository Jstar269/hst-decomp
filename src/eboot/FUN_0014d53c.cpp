/* HSTMATCH module=EBOOT.BIN start=0x0014d53c end=0x0014d630 symbol=FUN_0014d53c lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_0014c610 placed by helpers=; the factory returns the object it creates, and both loop counters are block-scoped); exact match verified; names and types await human review. */
#include "hst/script_node.h"

/* Command carrying a block of ints: id, count, then the data. */
typedef struct DataCmd {
    ScriptNode base;
    int id;        /* 0x08 */
    unsigned count; /* 0x0c */
    int data[1];   /* 0x10, count entries */
} DataCmd;

extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc270[];
extern int DAT_003402f4[];

extern "C" {
static void FUN_0014c610(...) {}
void *FUN_00000bcc(int);
void *FUN_0014d630(void *, ScriptVars *, int, int);

/* Copies a command's data block into the global int table (from entry 8 on),
   then creates and initialises one 0x28-byte object from the command's id and
   the context's variables and field 0xc. */
void *FUN_0014d53c(DataCmd *cmd, ScriptRunCtx *ctx)
{
    int id;
    ScriptVars *vars;
    unsigned count;
    void *obj;

    if (DAT_003402f0 != 0) {
        switch (DAT_003402f0) {
        case 0:
            id = cmd->id;
            break;
        default:
            FUN_0014c610(DAT_002dc240);
            for (int n = 0; n < ctx->depth + 1; n++)
                FUN_0014c610(DAT_002dc24c);
            id = cmd->id;
            break;
        }
        FUN_0014c610(DAT_002dc270, id);
    }
    count = cmd->count;
    vars = ctx->vars;
    for (int k = 0; k < count; k++)
        DAT_003402f4[k + 8] = cmd->data[k];
    obj = FUN_00000bcc(0x28);
    if (obj != 0)
        obj = FUN_0014d630(obj, vars, cmd->id, ctx->unk0c);
    return obj;
}
}
