/* HSTMATCH module=EBOOT.BIN start=0x00154c5c end=0x00154cc0 symbol=FUN_00154c5c lang=c99 data=0x002dc9d0 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_00020f5c float->long long, FUN_0012d868 float parameter; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc9d0-0x002dc9e8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct GroundTexAnimCmd {
  char pad00[8];
  float value; /* 0x08 */
} GroundTexAnimCmd;

extern unsigned char DAT_003402f0; /* script trace flag */
extern int DAT_0033b574;
extern void FUN_0014d044(ScriptCtx *);
extern long long FUN_00020f5c(float);
extern void FUN_0014fd94(const void *, ...);
extern void FUN_0012d868(int, float);

/* Script command "Ground Tex Anim": trace it and pass the value on to the ground texture animation. */
int FUN_00154c5c(GroundTexAnimCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    long long value = FUN_00020f5c(cmd->value);
    FUN_0014fd94("Ground Tex Anim [%.0f]\n", value);
  }
  FUN_0012d868(DAT_0033b574, cmd->value);
  return 0;
}
