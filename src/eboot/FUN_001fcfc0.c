/* HSTMATCH module=EBOOT.BIN start=0x001fcfc0 end=0x001fd060 symbol=FUN_001fcfc0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define SINGLETON_SIZE 0x1350  /* allocation size of the global object */

extern u32 DAT_0034a13c;  /* the global object, created on first use */
extern int FUN_00000bcc();
extern u32 * FUN_001fd180();
extern void FUN_001fd46c();
extern void FUN_001fd7e8();

/* Create the global object on first use, then forward the remaining arguments to it. */
void FUN_001fcfc0(u32 ctorArg,u32 arg1,u32 arg2,u32 arg3)
{
  int mem;
  
  if (DAT_0034a13c == 0) {
    mem = FUN_00000bcc(SINGLETON_SIZE);
    if (mem != 0) {
      FUN_001fd180(mem,ctorArg);
    }
    FUN_001fd46c(DAT_0034a13c,1,0);
  }
  if (DAT_0034a13c != 0) {
    FUN_001fd7e8(DAT_0034a13c,arg1,arg2,arg3);
  }
}
