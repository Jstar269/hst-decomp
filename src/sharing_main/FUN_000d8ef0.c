/* HSTMATCH module=hstp_trans_main.prx start=0x000d8ef0 end=0x000d8f34 symbol=FUN_000d8ef0 lang=c99 */
/* Clone of src/eboot/FUN_000d5200.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Vtable pointer plus one word. */
typedef struct WordObj {
  const void *vtable;  /* 0x00 */
  int value;           /* 0x04 */
} WordObj;

#define WORD_OBJ_SIZE 8

extern u8 DAT_003b0808;
extern void * FUN_00000bcc();

/* Allocates a copy of src with the base vtable. The pointer is not kept. */
void FUN_000d8ef0(WordObj *src)
{
  WordObj *copy;
  
  copy = (WordObj *)FUN_00000bcc(WORD_OBJ_SIZE);
  if (copy != (WordObj *)0x0) {
    copy->vtable = &DAT_003b0808;
    copy->value = src->value;
  }
}
