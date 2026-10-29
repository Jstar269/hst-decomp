/* HSTMATCH module=EBOOT.BIN start=0x000da0f8 end=0x000da19c symbol=FUN_000da0f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d6acd;
extern u8 DAT_002d6ace;

/* Tree node with a halfword key at 0x0c. */
typedef struct ShortKeyNode {
  char pad00[0xc];
  short key;  /* 0x0c */
} ShortKeyNode;

/* Result of an insert: the node and whether it was newly inserted. */
typedef struct InsertResult {
  ShortKeyNode *node;  /* 0x00 */
  u8 inserted;         /* 0x04 */
} InsertResult;

extern ShortKeyNode * FUN_000da340();
extern ShortKeyNode * FUN_000dab30();

/* Insert-unique for a halfword key: find the position, then insert unless an equal key exists. */
void FUN_000da0f8(InsertResult *result,void *tree,short *key)
{
  ShortKeyNode *parent;
  ShortKeyNode *node;
  ShortKeyNode *found;
  u8 left;
  u8 leftmost;
  
  parent = FUN_000da340(tree,key,&found,&left,&leftmost);
  if ((found == 0) || (found->key < *key)) {
    node = FUN_000dab30(tree,parent,left,leftmost,key);
    result->node = node;
    result->inserted = DAT_002d6acd;
  }
  else {
    result->node = found;
    result->inserted = DAT_002d6ace;
  }
}
