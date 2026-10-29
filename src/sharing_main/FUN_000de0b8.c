/* HSTMATCH module=hstp_trans_main.prx start=0x000de0b8 end=0x000de15c symbol=FUN_000de0b8 lang=c99 */
/* Clone of src/eboot/FUN_000da0f8.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037d702;
extern u8 DAT_0037d703;

/* Tree node with a halfword key at 0x0c. */
typedef struct ShortKeyNode {
  char pad00[0xc];
  short key;  /* 0x0c */
} ShortKeyNode;

/* Result of an insert: the node and whether it was newly inserted. */
typedef struct InsertResult {
  ShortKeyNode *node;  /* 0x00 */
  u8 inserted;         /* 0x04 */
} InsertResult;

extern ShortKeyNode * FUN_000de300();
extern ShortKeyNode * FUN_000deaf0();

/* Insert-unique for a halfword key: find the position, then insert unless an equal key exists. */
void FUN_000de0b8(InsertResult *result,void *tree,short *key)
{
  ShortKeyNode *parent;
  ShortKeyNode *node;
  ShortKeyNode *found;
  u8 left;
  u8 leftmost;
  
  parent = FUN_000de300(tree,key,&found,&left,&leftmost);
  if ((found == 0) || (found->key < *key)) {
    node = FUN_000deaf0(tree,parent,left,leftmost,key);
    result->node = node;
    result->inserted = DAT_0037d702;
  }
  else {
    result->node = found;
    result->inserted = DAT_0037d703;
  }
}
