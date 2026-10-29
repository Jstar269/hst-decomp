/* HSTMATCH module=hstp_trans_main.prx start=0x00238e5c end=0x00238ed0 symbol=FUN_00238e5c lang=c99 */
/* Clone of src/eboot/FUN_002298e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern u32 * FUN_002392d4();

/* Finds the node for *key in the tree; stores the end iterator when there is none. */
void FUN_00238e5c(TreeNode **result,TreeMap *map,u32 *key)
{
  TreeNode *node;
  
  node = (TreeNode *)FUN_002392d4(map,key,map->root,(TreeNode *)&map->root);
  if ((node == (TreeNode *)&map->root) || (*key < node->key)) {
    *result = (TreeNode *)&map->root;
  }
  else {
    *result = node;
  }
}
