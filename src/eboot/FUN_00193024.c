/* HSTMATCH module=EBOOT.BIN start=0x00193024 end=0x001930a8 symbol=FUN_00193024 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
#include "hst/challenge_tables.h"

extern ChallengeTableBig *DAT_00341730;
extern ChallengeIndex *DAT_00341748;
extern void FUN_00196478(TreeNode **, TreeMap *, const char **);

/* Finds the record with the given name through the name index; 0 when the table is not loaded or the name is unknown. */
ChallengeRecBig *FUN_00193024(const char *name)
{
  TreeNode *node;
  const char *key;

  key = name;
  if (DAT_00341730 == 0) {
    goto ret0;
  }
  FUN_00196478(&node,&DAT_00341748->unk30,&key);
  if (node == (TreeNode *)&DAT_00341748->unk30.root) {
    goto ret0;
  }
  return DAT_00341730->records + node->value;
ret0:
  return 0;
}
