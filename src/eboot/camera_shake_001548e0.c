/* HSTMATCH module=EBOOT.BIN start=0x001548e0 end=0x00154964 symbol=FUN_001548e0 lang=c99 data=0x002dc95c */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed FUN_00020f5c float->long long, aligned 64-bit arg to even register pair, typed FUN_00288414 float parameter in f12; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc95c-0x002dc977) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct CameraShakeCmd {
  char pad00[8];
  float amount; /* 0x08 */
  int arg1;     /* 0x0c */
  int arg2;     /* 0x10 */
} CameraShakeCmd;

extern unsigned char DAT_003402f0; /* script trace flag */
extern long long FUN_00020f5c(float);
extern void FUN_0014d044(ScriptCtx *);
extern void FUN_0014fd94(const void *, ...);
extern void FUN_00288414(ScriptActor *, float, int, int);

/* Script command "CameraShake": trace it and shake the camera of the context's actor. */
int FUN_001548e0(CameraShakeCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    long long amount = FUN_00020f5c(cmd->amount);
    FUN_0014fd94("CameraShake [%.3f(%d,%d)]\n", amount, cmd->arg1, cmd->arg2);
  }
  ScriptActor *actor = ctx->actor;
  if (actor != 0) {
    FUN_00288414(actor, cmd->amount, cmd->arg1, cmd->arg2);
  }
  return 0;
}
