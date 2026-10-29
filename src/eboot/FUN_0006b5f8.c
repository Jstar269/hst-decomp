/* HSTMATCH module=EBOOT.BIN start=0x0006b5f8 end=0x0006b69c symbol=FUN_0006b5f8 lang=c99 */
/* Clone of src/eboot/FUN_00229af0.c (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern u8 DAT_002d12be;
extern u8 DAT_002d12bf;
extern u32 * FUN_0006c044();
extern u32 * FUN_0006c3b0();

/* Result of an insert: the node holding the key and whether a new node was created. */
typedef struct InsertResult {
  TreeNode *node;           /* 0x00 */
  u8 inserted;              /* 0x04 */
} InsertResult;

/* Inserts key into the tree unless an equal key is already there. */
void FUN_0006b5f8(InsertResult *result,TreeMap *tree,u32 *key)
{
  u32 insert_pos;
  TreeNode *node;
  u8 side_a;
  u8 side_b;
  TreeNode *parent;
  
  insert_pos = (unsigned int)(FUN_0006c044(tree,key,&parent,&side_a,&side_b));
  if ((parent == 0) || (parent->key < *key)) {
    node = (TreeNode *)(FUN_0006c3b0(tree,insert_pos,side_a,side_b,key));
    result->node = node;
    result->inserted = DAT_002d12be;
  }
  else {
    result->node = parent;
    result->inserted = DAT_002d12bf;
  }
}
