/* HSTMATCH module=EBOOT.BIN start=0x002b42a0 end=0x002b42b4 symbol=FUN_002b42a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Node carrying an integer sort key at +0x50. */
typedef struct KeyNode {
  char pad00[0x50];
  int key;          /* 0x50 */
} KeyNode;

/* Holder whose second word points at the current node. */
typedef struct NodeHolder {
  int unk0;
  KeyNode *node;    /* 0x04 */
} NodeHolder;

/* True when the key of other is lower than the key of the holder's current node. */
bool FUN_002b42a0(NodeHolder *holder,KeyNode *other)
{
  return other->key < holder->node->key;
}
