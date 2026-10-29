/* HSTMATCH module=EBOOT.BIN start=0x001c6cac end=0x001c6cf4 symbol=FUN_001c6cac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: return condition variable directly and negate equality !(x == 1); readability pass; exact match verified; names and types await human review. */
#include "hst/gimmick_mgr.h"

int FUN_001c6cac(GimmickMgr *mgr)
{
  GimmickState *state = mgr->state;
  int cond = state->unk6c >= 0;
  if (!cond) {
    cond = state->kind == 2;
  }
  if (cond) {
    cond = !(state->sub->unk54 == 1);
  }
  return cond;
}
