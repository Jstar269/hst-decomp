/* HSTMATCH module=EBOOT.BIN start=0x002293d4 end=0x0022942c symbol=FUN_002293d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_000009e4();
extern void FUN_000643e8();
extern void FUN_0022995c();

/* Frees the string key of every node, then clears the tree. */
void FUN_002293d4(TreeMap *map)
{
  TreeNode *node;
  
  node = map->first;
  if (node != (TreeNode *)&map->root) {
    do {
      FUN_000009e4(node->key);
      FUN_000643e8(&node);
    } while (node != (TreeNode *)&map->root);
  }
  FUN_0022995c(map);
}
