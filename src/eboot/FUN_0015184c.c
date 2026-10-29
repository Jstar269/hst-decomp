/* HSTMATCH module=EBOOT.BIN start=0x0015184c end=0x001518cc symbol=FUN_0015184c lang=c99 data=0x002dc540 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc540-0x002dc554) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Actor view with the id read by the command. */
typedef struct IdActor { char pad00[0x30]; u32 id; } IdActor;
/* Context view whose actor field is an IdActor. */
typedef struct IdCtx { u32 regs; u32 unk04; u32 unk08; IdActor *actor; } IdCtx;

extern u8 DAT_003402f0; /* script trace flag */
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7160();

/* Script command "SetMyLavel": pass the actor's id and the command's string argument to the host, and
   trace them. */
u32 FUN_0015184c(ScriptCmd *cmd,IdCtx *ctx)
{
  u32 id;
  
  id = ctx->actor->id;
  FUN_001c7160(DAT_0034a114,id,cmd->arg0);
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("SetMyLavel [%d:%s]\n",id,cmd->arg0);
  }
  return 0;
}
