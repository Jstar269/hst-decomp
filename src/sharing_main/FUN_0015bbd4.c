/* HSTMATCH module=hstp_trans_main.prx start=0x0015bbd4 end=0x0015bc00 symbol=FUN_0015bbd4 lang=c99 */
/* Clone of src/eboot/FUN_0014fba8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Command record with three word arguments after the common header. */
typedef struct CmdArgs3 {
  char pad00[8];
  u32 arg0;  /* 0x08 */
  u32 arg1;  /* 0x0c */
  u32 arg2;  /* 0x10 */
} CmdArgs3;

extern void FUN_00299db0();

/* Script command: forward its three arguments to the handler. */
u32 FUN_0015bbd4(CmdArgs3 *cmd)
{
  FUN_00299db0(cmd->arg0,cmd->arg1,cmd->arg2);
  return 0;
}
