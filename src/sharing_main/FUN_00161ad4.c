/* HSTMATCH module=hstp_trans_main.prx start=0x00161ad4 end=0x00161afc symbol=FUN_00161ad4 lang=c99 */
/* Clone of src/eboot/FUN_00155604.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

#define CALL_DELAY 1000 /* third argument of the helper call */

extern void FUN_00299f90();

u32 FUN_00161ad4(ScriptCmd *cmd)
{
  FUN_00299f90(cmd->arg0,cmd->arg1,CALL_DELAY);
  return 0;
}
