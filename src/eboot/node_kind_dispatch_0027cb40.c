/* HSTMATCH module=EBOOT.BIN start=0x0027cb40 end=0x0027cc28 symbol=FUN_0027cb40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the doubled null test on the node pointer is retail's (Ghidra renders it the same way);
   both kind fields are read before the inner test, and their || chain alternates first/second field. */
#include "hst/blend_obj.h"

typedef struct BlendNode {
  char pad_00[0x10];
  int kindA; /* 0x10 */
  char pad_14[0x0c];
  int kindB; /* 0x20 */
} BlendNode;

extern int DAT_0034a7e0;
extern void FUN_0027c328(int, int, BlendNode *);

void FUN_0027cb40(BlendObj *self)
{
  BlendNode *node;
  int kindA;
  int kindB;

  node = *self->nodeRef;
  if (node != 0) {
    kindA = node->kindA;
    kindB = node->kindB;
    if (node != 0) {
      if (kindA == 1 || kindB == 1 || kindA == 2 || kindB == 2) {
        FUN_0027c328(*(int *)(DAT_0034a7e0 + 0x3c), self->unk94, node);
      }
      else if (kindA == 5 || kindB == 5 || kindA == 6 || kindB == 6 || kindA == 7 ||
               kindB == 7 || kindA == 8 || kindB == 8 || kindA == 9 || kindB == 9) {
        FUN_0027c328(*(int *)(DAT_0034a7e0 + 0x3c), self->unk94, node);
      }
    }
  }
  return;
}
