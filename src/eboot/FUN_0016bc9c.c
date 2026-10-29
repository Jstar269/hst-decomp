/* HSTMATCH module=EBOOT.BIN start=0x0016bc9c end=0x0016bcec symbol=FUN_0016bc9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_0016bc9c.c) corrected by hand: expressed the final status result with explicit 1/0 branches and the positive branch first; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define INSTANCE_SIZE 0xdbc   /* bytes of the object the constructor builds */

extern float DAT_00331c30;
extern void * DAT_00341518;
extern void * FUN_00000bcc();
extern void FUN_0016d194();

/* Builds the object with its constructor; returns 1 when DAT_00341518 is set afterwards. */
int FUN_0016bc9c(void)
{
  void *obj;
  
  DAT_00331c30 = -0.015f;
  obj = FUN_00000bcc(INSTANCE_SIZE);
  if (obj != 0) {
    FUN_0016d194(obj);
  }
  if (DAT_00341518 != 0) return 1;
  return 0;
}
