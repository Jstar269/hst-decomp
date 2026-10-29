/* HSTMATCH module=hstp_trans_main.prx start=0x0019caa0 end=0x0019cae0 symbol=FUN_0019caa0 lang=c99 */
/* Clone of src/eboot/FUN_00190290.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with an embedded sub-object at 0xc that is copied on copy construction. */
typedef struct BodyObj {
  char head[0xc];
  char body[1]; /* 0xc */
} BodyObj;

extern u32 FUN_00003e04();
extern u32 * FUN_0019d090();

/* Copy constructor: base setup, then copies the embedded sub-object from src. */
BodyObj * FUN_0019caa0(BodyObj *self,BodyObj *src)
{
  FUN_00003e04();
  FUN_0019d090(self->body,src->body);
  return self;
}
