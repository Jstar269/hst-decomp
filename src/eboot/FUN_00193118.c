/* HSTMATCH module=EBOOT.BIN start=0x00193118 end=0x0019319c symbol=FUN_00193118 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
#include "hst/challenge_tables.h"

extern ChallengeTableSmall *DAT_00341734;
extern ChallengeIndex *DAT_00341748;
extern void FUN_00196478(TreeNode **, TreeMap *, const char **);

/* Finds the record with the given name through the name index; 0 when the table is not loaded or the name is unknown. */
ChallengeRecSmall *FUN_00193118(const char *name)
{
  TreeNode *node;
  const char *key;

  key = name;
  if (DAT_00341734 == 0) {
    goto ret0;
  }
  FUN_00196478(&node,&DAT_00341748->match,&key);
  if (node == (TreeNode *)&DAT_00341748->match.root) {
    goto ret0;
  }
  return DAT_00341734->records + node->value;
ret0:
  return 0;
}
