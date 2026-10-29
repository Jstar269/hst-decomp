/* HSTMATCH module=hstp_trans_main.prx start=0x001125a0 end=0x0011262c symbol=FUN_001125a0 lang=c99 */
/* Clone of src/eboot/FUN_0010c228.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/stream_obj.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b122c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern int * FUN_0010d2d4();

/* Destroys the stream's virtual base; frees it when delete_flag is positive. */
StreamBase * FUN_001125a0(StreamBase *base,short delete_flag)
{
  char *member;
  
  if (base != (StreamBase *)0x0) {
    member = base->member120;
    base->vtable = &DAT_003b122c;
    if ((member != (char *)0x0) && (member != (char *)0x0)) {
      FUN_0010d2d4(member,0);
    }
    if (base != (StreamBase *)0x0) {
      base->vtable = &DAT_003b0a68;
      FUN_0010642c(base,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(base);
    }
  }
  return base;
}
