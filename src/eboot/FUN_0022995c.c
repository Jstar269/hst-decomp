/* HSTMATCH module=EBOOT.BIN start=0x0022995c end=0x0022999c symbol=FUN_0022995c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00229d98();

/* Erases all nodes and resets the tree to empty. */
void FUN_0022995c(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_00229d98(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
