/* HSTMATCH module=hstp_trans_main.prx start=0x00239064 end=0x00239108 symbol=FUN_00239064 lang=c99 */
/* Clone of src/eboot/FUN_00229af0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern u8 DAT_0039af23;
extern u8 DAT_0039af24;
extern u32 * FUN_00239164();
extern u32 * FUN_002398dc();

/* Result of an insert: the node holding the key and whether a new node was created. */
typedef struct InsertResult {
  TreeNode *node;           /* 0x00 */
  u8 inserted;              /* 0x04 */
} InsertResult;

/* Inserts key into the tree unless an equal key is already there. */
void FUN_00239064(InsertResult *result,TreeMap *tree,u32 *key)
{
  u32 insert_pos;
  TreeNode *node;
  u8 side_a;
  u8 side_b;
  TreeNode *parent;
  
  insert_pos = (unsigned int)(FUN_00239164(tree,key,&parent,&side_a,&side_b));
  if ((parent == 0) || (parent->key < *key)) {
    node = (TreeNode *)(FUN_002398dc(tree,insert_pos,side_a,side_b,key));
    result->node = node;
    result->inserted = DAT_0039af23;
  }
  else {
    result->node = parent;
    result->inserted = DAT_0039af24;
  }
}
