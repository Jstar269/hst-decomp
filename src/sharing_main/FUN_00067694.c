/* HSTMATCH module=hstp_trans_main.prx start=0x00067694 end=0x000676d4 symbol=FUN_00067694 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_0006811c();

/* Erases all nodes and resets the tree to empty. */
void FUN_00067694(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_0006811c(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
