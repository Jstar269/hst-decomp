/* HSTMATCH module=EBOOT.BIN start=0x00193364 end=0x001933e8 symbol=FUN_00193364 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
#include "hst/challenge_tables.h"

extern ChallengeTableBig *DAT_0034173c;
extern ChallengeIndex *DAT_00341748;
extern void FUN_00196478(TreeNode **, TreeMap *, const char **);

/* Finds the record with the given name through the name index; 0 when the table is not loaded or the name is unknown. */
ChallengeRecBig *FUN_00193364(const char *name)
{
  TreeNode *node;
  const char *key;

  key = name;
  if (DAT_0034173c == 0) {
    goto ret0;
  }
  FUN_00196478(&node,&DAT_00341748->vspc,&key);
  if (node == (TreeNode *)&DAT_00341748->vspc.root) {
    goto ret0;
  }
  return DAT_0034173c->records + node->value;
ret0:
  return 0;
}
