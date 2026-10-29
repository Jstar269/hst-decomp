/* HSTMATCH module=EBOOT.BIN start=0x00066240 end=0x00066280 symbol=FUN_00066240 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00066cc8();

/* Erases all nodes and resets the tree to empty. */
void FUN_00066240(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_00066cc8(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
