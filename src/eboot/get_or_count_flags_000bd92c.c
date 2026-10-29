/* HSTMATCH module=EBOOT.BIN start=0x000bd92c end=0x000bd97c symbol=FUN_000bd92c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: made the indexed flag loop and count explicit; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_session.h"

/* member >= 0: returns that member's flag; member < 0: returns whether the flagged members number exactly the received count. */
u8 FUN_000bd92c(MemberSession *session,int member)
{
  int flagged;
  int i;
  u8 result;
  if (member < 0) {
    flagged = 0;
    i = 0;
    for (; i < MEMBER_MAX; i++) {
      if (session->flags[i] != 0) flagged++;
    }
    result = session->count == flagged;
  } else {
    result = session->flags[member];
  }
  return result;
}
