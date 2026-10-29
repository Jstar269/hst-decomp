/* HSTMATCH module=EBOOT.BIN start=0x001fcf64 end=0x001fcfc0 symbol=FUN_001fcf64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define SINGLETON_SIZE 0x1350  /* allocation size of the global object */

extern u32 DAT_0034a13c;  /* the global object */
extern int FUN_00000bcc();
extern u32 * FUN_001fd180();
extern void FUN_001fd46c();

/* Create the global object, then pass it the given value. */
void FUN_001fcf64(u32 ctorArg,u32 value)
{
  int mem;
  
  mem = FUN_00000bcc(SINGLETON_SIZE);
  if (mem != 0) {
    FUN_001fd180(mem,ctorArg);
  }
  FUN_001fd46c(DAT_0034a13c,value,0);
}
