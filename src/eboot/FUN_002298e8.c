/* HSTMATCH module=EBOOT.BIN start=0x002298e8 end=0x0022995c symbol=FUN_002298e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern u32 * FUN_00229d60();

/* Finds the node for *key in the tree; stores the end iterator when there is none. */
void FUN_002298e8(TreeNode **result,TreeMap *map,u32 *key)
{
  TreeNode *node;
  
  node = (TreeNode *)FUN_00229d60(map,key,map->root,(TreeNode *)&map->root);
  if ((node == (TreeNode *)&map->root) || (*key < node->key)) {
    *result = (TreeNode *)&map->root;
  }
  else {
    *result = node;
  }
}
