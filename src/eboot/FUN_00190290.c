/* HSTMATCH module=EBOOT.BIN start=0x00190290 end=0x001902d0 symbol=FUN_00190290 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with an embedded sub-object at 0xc that is copied on copy construction. */
typedef struct BodyObj {
  char head[0xc];
  char body[1]; /* 0xc */
} BodyObj;

extern u32 FUN_00003e04();
extern u32 * FUN_00190880();

/* Copy constructor: base setup, then copies the embedded sub-object from src. */
BodyObj * FUN_00190290(BodyObj *self,BodyObj *src)
{
  FUN_00003e04();
  FUN_00190880(self->body,src->body);
  return self;
}
