/* HSTMATCH module=EBOOT.BIN start=0x00229af0 end=0x00229b94 symbol=FUN_00229af0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern u8 DAT_002f2b57;
extern u8 DAT_002f2b58;
extern u32 * FUN_00229bf0();
extern u32 * FUN_0022a368();

/* Result of an insert: the node holding the key and whether a new node was created. */
typedef struct InsertResult {
  TreeNode *node;           /* 0x00 */
  u8 inserted;              /* 0x04 */
} InsertResult;

/* Inserts key into the tree unless an equal key is already there. */
void FUN_00229af0(InsertResult *result,TreeMap *tree,u32 *key)
{
  u32 insert_pos;
  TreeNode *node;
  u8 side_a;
  u8 side_b;
  TreeNode *parent;
  
  insert_pos = (unsigned int)(FUN_00229bf0(tree,key,&parent,&side_a,&side_b));
  if ((parent == 0) || (parent->key < *key)) {
    node = (TreeNode *)(FUN_0022a368(tree,insert_pos,side_a,side_b,key));
    result->node = node;
    result->inserted = DAT_002f2b57;
  }
  else {
    result->node = parent;
    result->inserted = DAT_002f2b58;
  }
}
