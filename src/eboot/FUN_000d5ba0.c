/* HSTMATCH module=EBOOT.BIN start=0x000d5ba0 end=0x000d5bf0 symbol=FUN_000d5ba0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Vtable pointer plus one word. */
typedef struct WordObj {
  const void *vtable;  /* 0x00 */
  int value;           /* 0x04 */
} WordObj;

#define WORD_OBJ_SIZE 8

extern u8 DAT_0030753c;
extern u8 DAT_00307550;
extern void * FUN_00000bcc();

/* Allocates a copy of src: the base vtable is stored first, then replaced by the derived one. The pointer is not kept. */
void FUN_000d5ba0(WordObj *src)
{
  WordObj *copy;
  
  copy = (WordObj *)FUN_00000bcc(WORD_OBJ_SIZE);
  if (copy != (WordObj *)0x0) {
    copy->vtable = &DAT_0030753c;
    copy->value = src->value;
    copy->vtable = &DAT_00307550;
  }
}
