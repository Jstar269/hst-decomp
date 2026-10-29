/* HSTMATCH module=hstp_trans_main.prx start=0x001d4720 end=0x001d474c symbol=FUN_001d4720 lang=c99 */
/* Clone of src/eboot/FUN_001c6328.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/gimmick_mgr.h"

extern void FUN_001668dc();

/* Calls the helper on the state's member at 0x58 when it is set. */
void FUN_001d4720(GimmickMgr *mgr)
{
  void *member;
  
  member = mgr->state->unk58;
  if (member != 0) {
    FUN_001668dc(member);
  }
}
