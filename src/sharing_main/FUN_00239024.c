/* HSTMATCH module=hstp_trans_main.prx start=0x00239024 end=0x00239064 symbol=FUN_00239024 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00239698();

/* Erases all nodes and resets the tree to empty. */
void FUN_00239024(TreeMap *map)
{
  if (map->root != (TreeNode *)0x0) {
    FUN_00239698(map,map->root);
    map->unk00 = 0;
    map->root = 0;
    map->first = (TreeNode *)&map->root;
  }
}
