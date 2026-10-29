/* HSTMATCH module=hstp_trans_main.prx start=0x001e7d30 end=0x001e7d7c symbol=FUN_001e7d30 lang=c99 */
/* Clone of src/eboot/FUN_001d9c78.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/handler_obj.h"

/* Holder whose pointer at 0x3c leads to the handler object. */
typedef struct HandlerOwner {
  char pad00[0x3c];
  HandlerObj *obj;  /* 0x3c */
} HandlerOwner;

extern void FUN_001e77e4();
extern void FUN_001e35f4();

/* Sets the handler object's state to 4 and runs the follow-up helpers. */
void FUN_001e7d30(HandlerOwner *owner)
{
  HandlerObj *obj;
  
  obj = owner->obj;
  obj->unkd4 = 3;
  obj->state = 4;
  FUN_001e77e4(obj->unk1110,8);
  FUN_001e35f4(obj,5,0);
}
