/* HSTMATCH module=EBOOT.BIN start=0x0014dd38 end=0x0014de24 symbol=FUN_0014dd38 lang=c99 rodata=0x002c1a28 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern int DAT_003402f4[];
extern float DAT_00340374[];
extern int * FUN_0022a940();
extern float * FUN_0022a958();
extern int * FUN_0022a970();
extern float * FUN_0022a98c();

/* Reads the variable named by the command as a float (ints are converted).
   Local variables are addressed by byte offset (ints[index] / floats[index]), which keeps the operand order. */
float FUN_0014dd38(VarCmd *cmd,ScriptVars *vars)
{
  float result;

  result = 0.0f;
  switch(cmd->type) {
  case VAR_KIND_INT_A:
    result = (float)*FUN_0022a940(cmd->index);
    break;
  case VAR_KIND_FLOAT_A:
    result = *FUN_0022a958(cmd->index);
    break;
  case VAR_KIND_INT_B:
    result = (float)*FUN_0022a970(cmd->index);
    break;
  case VAR_KIND_FLOAT_B:
    result = *FUN_0022a98c(cmd->index);
    break;
  case VAR_KIND_LOCAL_INT:
    result = (float)*(int *)((char *)vars + cmd->index * 4 + 0xc);
    break;
  case VAR_KIND_LOCAL_FLOAT:
    result = *(float *)((char *)vars + cmd->index * 4 + 0x10c);
    break;
  case VAR_KIND_GLOBAL_INT:
    result = (float)DAT_003402f4[cmd->index];
    break;
  case VAR_KIND_GLOBAL_FLOAT:
    result = DAT_00340374[cmd->index];
  }
  return result;
}
