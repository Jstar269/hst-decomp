/* HSTMATCH module=EBOOT.BIN start=0x001d9c78 end=0x001d9cc4 symbol=FUN_001d9c78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/handler_obj.h"

/* Holder whose pointer at 0x3c leads to the handler object. */
typedef struct HandlerOwner {
  char pad00[0x3c];
  HandlerObj *obj;  /* 0x3c */
} HandlerOwner;

extern void FUN_001d0624();
extern void FUN_001d57f0();

/* Sets the handler object's state to 4 and runs the follow-up helpers. */
void FUN_001d9c78(HandlerOwner *owner)
{
  HandlerObj *obj;
  
  obj = owner->obj;
  obj->unkd4 = 3;
  obj->state = 4;
  FUN_001d0624(obj->unk1110,8);
  FUN_001d57f0(obj,5,0);
}
