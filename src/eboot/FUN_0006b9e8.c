/* HSTMATCH module=EBOOT.BIN start=0x0006b9e8 end=0x0006ba28 symbol=FUN_0006b9e8 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_0006c934();

/* Erases all nodes and resets the tree to empty. */
void FUN_0006b9e8(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_0006c934(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
