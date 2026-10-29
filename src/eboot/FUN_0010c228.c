/* HSTMATCH module=EBOOT.BIN start=0x0010c228 end=0x0010c2b4 symbol=FUN_0010c228 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_obj.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307f60;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern int * FUN_00107514();

/* Destroys the stream's virtual base; frees it when delete_flag is positive. */
StreamBase * FUN_0010c228(StreamBase *base,short delete_flag)
{
  char *member;
  
  if (base != (StreamBase *)0x0) {
    member = base->member120;
    base->vtable = &DAT_00307f60;
    if ((member != (char *)0x0) && (member != (char *)0x0)) {
      FUN_00107514(member,0);
    }
    if (base != (StreamBase *)0x0) {
      base->vtable = &DAT_0030779c;
      FUN_00100b24(base,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(base);
    }
  }
  return base;
}
