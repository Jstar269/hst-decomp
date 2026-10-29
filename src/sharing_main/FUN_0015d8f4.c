/* HSTMATCH module=hstp_trans_main.prx start=0x0015d8f4 end=0x0015d974 symbol=FUN_0015d8f4 lang=c99 data=0x00383a28 */
/* Clone of src/eboot/FUN_0015184c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383a28-0x00383a3c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Actor view with the id read by the command. */
typedef struct IdActor { char pad00[0x30]; u32 id; } IdActor;
/* Context view whose actor field is an IdActor. */
typedef struct IdCtx { u32 regs; u32 unk04; u32 unk08; IdActor *actor; } IdCtx;

extern u8 DAT_003e9630; /* script trace flag */
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d5588();

/* Script command "SetMyLavel": pass the actor's id and the command's string argument to the host, and
   trace them. */
u32 FUN_0015d8f4(ScriptCmd *cmd,IdCtx *ctx)
{
  u32 id;
  
  id = ctx->actor->id;
  FUN_001d5588(DAT_003f344c,id,cmd->arg0);
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("SetMyLavel [%d:%s]\n",id,cmd->arg0);
  }
  return 0;
}
