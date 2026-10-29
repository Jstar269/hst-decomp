/* HSTMATCH module=EBOOT.BIN start=0x001c6328 end=0x001c6354 symbol=FUN_001c6328 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/gimmick_mgr.h"

extern void FUN_0015a304();

/* Calls the helper on the state's member at 0x58 when it is set. */
void FUN_001c6328(GimmickMgr *mgr)
{
  void *member;
  
  member = mgr->state->unk58;
  if (member != 0) {
    FUN_0015a304(member);
  }
}
