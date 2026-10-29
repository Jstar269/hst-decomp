/* HSTMATCH module=EBOOT.BIN start=0x0014fba8 end=0x0014fbd4 symbol=FUN_0014fba8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Command record with three word arguments after the common header. */
typedef struct CmdArgs3 {
  char pad00[8];
  u32 arg0;  /* 0x08 */
  u32 arg1;  /* 0x0c */
  u32 arg2;  /* 0x10 */
} CmdArgs3;

extern void FUN_0028867c();

/* Script command: forward its three arguments to the handler. */
u32 FUN_0014fba8(CmdArgs3 *cmd)
{
  FUN_0028867c(cmd->arg0,cmd->arg1,cmd->arg2);
  return 0;
}
