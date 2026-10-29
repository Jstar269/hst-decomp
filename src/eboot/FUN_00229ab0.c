/* HSTMATCH module=EBOOT.BIN start=0x00229ab0 end=0x00229af0 symbol=FUN_00229ab0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_0022a124();

/* Erases all nodes and resets the tree to empty (second tree type). */
void FUN_00229ab0(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_0022a124(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
