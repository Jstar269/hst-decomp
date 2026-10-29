/* HSTMATCH module=EBOOT.BIN start=0x001550c0 end=0x00155144 symbol=FUN_001550c0 lang=c++ data=0x002dca58 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dca58-0x002dca6f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* The first callee is declared (void *, int, float, int): that parameter order schedules the argument loads like retail (float load first, lw a1 in the jal delay slot); the print stub is variadic and the float is widened with (double) (__extendsfdf2). */
#include "hst/script_cmd.h"

/* Record of the "SeVolume" command (only the fields it uses are named). */
struct VolumeCmd { int pad0; int pad4; float volume; int option; int name; };
extern "C" void FUN_00288594(void *, int, float, int);
extern "C" void FUN_0014d044(ScriptCtx *);
extern "C" void FUN_0014fd94(const char *, ...);
extern unsigned char DAT_003402f0; /* script trace flag */

/* Script command "SeVolume": applies the volume to the context's object, if any. */
extern "C" int FUN_001550c0(VolumeCmd *cmd, ScriptCtx *ctx)
{
    if (ctx->actor != 0)
        FUN_00288594(ctx->actor, cmd->name, cmd->volume, cmd->option);
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("SeVolume [%s:%.3f:%d]\n", cmd->name, (double)cmd->volume, cmd->option);
    }
    return 0;
}
