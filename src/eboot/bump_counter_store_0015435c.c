/* HSTMATCH module=EBOOT.BIN start=0x0015435c end=0x001543d0 symbol=FUN_0015435c lang=c99 data=0x002dc8b4 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global is unsigned char (lbu), global base typed as a struct pointer, counter+1 computed into a local before the lookup call; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc8b4-0x002dc8c4) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct GetRoomNoCmd {
  char pad00[8];
  int reg; /* 0x08 script register that receives the result */
} GetRoomNoCmd;

typedef struct RoomOwner {
  char padd0[0xd0];
  int unkd0; /* 0xd0 the command stores this value plus one */
} RoomOwner;

extern unsigned char DAT_003402f0; /* script trace flag */
extern RoomOwner *DAT_0034a114;
extern int *FUN_0014c384(int, int);
extern void FUN_0014d044(ScriptCtx *);
extern void FUN_0014fd94(char *, int);

/* Script command "GetRoomNo": store a counter of the owner object plus one in a register. */
int FUN_0015435c(GetRoomNoCmd *cmd, ScriptCtx *ctx)
{
  int value;
  int *slot;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("GetRoomNo [%d]\n", cmd->reg);
  }
  value = DAT_0034a114->unkd0 + 1;
  slot = FUN_0014c384(ctx->regs, cmd->reg);
  *slot = value;
  return 0;
}
