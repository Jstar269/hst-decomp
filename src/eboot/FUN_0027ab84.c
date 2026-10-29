/* HSTMATCH module=EBOOT.BIN start=0x0027ab84 end=0x0027ab98 symbol=FUN_0027ab84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
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
bool FUN_0027ab84(NodeHolder *holder,KeyNode *other)
{
  return other->key < holder->node->key;
}
