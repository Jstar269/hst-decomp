/* HSTMATCH module=EBOOT.BIN start=0x000c5014 end=0x000c50c4 symbol=FUN_000c5014 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: byte entries as a typed 7-byte struct array (unsigned char flag, lbu), for-loop with signed bound (blez) and index declared before use; readability pass; exact match verified; names and types await human review. */
#include "hst/member_session.h"

#define PLAYERS_SINGLES 2
#define PLAYERS_DOUBLES 4

extern MemberSession * DAT_00338ac4;
extern unsigned char DAT_003417b8;
extern void FUN_000bb190(MemberSession *);
extern void FUN_000bd568(MemberSession *);

/* Runs the first helper when the current member index (below 2, or below 4 when the global flag is set) has its slot used; then runs the second. */
void FUN_000c5014(void)
{
  if (DAT_00338ac4 != 0) {
    int cur = DAT_00338ac4->found;
    int n;
    int i;
    if (DAT_003417b8 == 0) {
      n = PLAYERS_SINGLES;
    }
    else {
      n = PLAYERS_DOUBLES;
    }
    for (i = 0; i < n; i++) {
      if (DAT_00338ac4->members[i].used != 0 && i == cur) {
        FUN_000bd568(DAT_00338ac4);
      }
    }
    FUN_000bb190(DAT_00338ac4);
  }
}
