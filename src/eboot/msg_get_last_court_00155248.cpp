/* HSTMATCH module=EBOOT.BIN start=0x00155248 end=0x001552c8 symbol=FUN_00155248 lang=c++ data=0x002dca88 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dca88-0x002dcaa1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

extern unsigned char DAT_003402f0;     /* script trace flag */
extern "C" int FUN_0022cbd4();
extern "C" int *FUN_0014c384(int key, int id);
extern "C" void FUN_0014d044(ScriptCtx *ctx);
extern "C" void FUN_0014fd94(const char *fmt, ...);

/* Script command "GetLastCourt": stores the host's value in the register named by the command. */
extern "C" int FUN_00155248(ScriptCmd *cmd, ScriptCtx *ctx)
{
    int bank = ctx->regs;
    int value = FUN_0022cbd4();
    *FUN_0014c384(bank, cmd->arg0) = value;
    if (DAT_003402f0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("GetLastCourt %d(reg:%d)\n", value, cmd->arg0);
    }
    return 0;
}
