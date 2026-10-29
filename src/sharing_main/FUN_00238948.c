/* HSTMATCH module=hstp_trans_main.prx start=0x00238948 end=0x002389a0 symbol=FUN_00238948 lang=c99 */
/* Clone of src/eboot/FUN_002293d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_000009e4();
extern void FUN_000652ac();
extern void FUN_00238ed0();

/* Frees the string key of every node, then clears the tree. */
void FUN_00238948(TreeMap *map)
{
  TreeNode *node;
  
  node = map->first;
  if (node != (TreeNode *)&map->root) {
    do {
      FUN_000009e4(node->key);
      FUN_000652ac(&node);
    } while (node != (TreeNode *)&map->root);
  }
  FUN_00238ed0(map);
}
