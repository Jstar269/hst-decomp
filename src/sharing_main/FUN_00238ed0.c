/* HSTMATCH module=hstp_trans_main.prx start=0x00238ed0 end=0x00238f10 symbol=FUN_00238ed0 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_0023930c();

/* Erases all nodes and resets the tree to empty. */
void FUN_00238ed0(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_0023930c(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
