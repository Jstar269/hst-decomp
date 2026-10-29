/* HSTMATCH module=EBOOT.BIN start=0x00151688 end=0x0015171c symbol=FUN_00151688 lang=c99 data=0x002dc508 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), local declaration order value, first, second for the saved-register assignment; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc508-0x002dc522) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

/* The actor's check values, read by the check commands. */
typedef struct CheckActor { char pad00[0x34]; u32 unk34; u32 unk38; } CheckActor;
/* Context view whose actor field is a CheckActor. */
typedef struct CheckCtx { u32 regs; u32 unk04; u32 unk08; CheckActor *actor; } CheckCtx;

extern unsigned char DAT_003402f0; /* script trace flag */
extern int FUN_0014c384(); /* register slot of a script register bank */
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern bool FUN_0022baec();

#define TALK_REG 8 /* register holding the talk value */

/* Script command "CmdCheckTalkProc": log the actor's two check values and the register value when tracing, then
   run the check. */
u32 FUN_00151688(u32 cmd,CheckCtx *ctx)
{
  u32 value;
  u32 first;
  u32 second;
  u32 *slot;
  
  first = ctx->actor->unk34;
  second = ctx->actor->unk38;
  slot = (u32 *)FUN_0014c384(ctx->regs,TALK_REG);
  value = *slot;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("CmdCheckTalkProc(%d, %d)\n",first,value);
  }
  FUN_0022baec(first,second,value);
  return 0;
}
