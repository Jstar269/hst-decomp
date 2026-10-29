/* HSTMATCH module=hstp_trans_main.prx start=0x0028be68 end=0x0028be7c symbol=FUN_0028be68 lang=c99 */
/* Clone of src/eboot/FUN_0027ab84.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Node carrying an integer sort key at +0x10. */
typedef struct KeyNode {
  char pad00[0x10];
  int key;          /* 0x10 */
} KeyNode;

/* Holder whose second word points at the current node. */
typedef struct NodeHolder {
  int unk0;
  KeyNode *node;    /* 0x04 */
} NodeHolder;

/* True when the key of other is lower than the key of the holder's current node. */
bool FUN_0028be68(NodeHolder *holder,KeyNode *other)
{
  return other->key < holder->node->key;
}
