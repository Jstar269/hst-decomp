/* HSTMATCH module=EBOOT.BIN start=0x00229470 end=0x002294f4 symbol=FUN_00229470 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the sentinel conditional and indexed through a typed int pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"
#include "hst/text_bank_lookup.h"

extern void FUN_00229868();

/* Looks up key in the name tree and returns the string count of the matching text group, or 0. */
u32 FUN_00229470(TreeMap *map,TextBank *bank,u32 key)
{
  int id;
  u32 search_key;
  TreeNode *found [2];
  
  search_key = key;
  FUN_00229868(found,map,&search_key);
  id = (found[0] != (TreeNode *)&map->root) ? found[0]->value : -1;
  if ((bank != 0) && (id >= 0)) {
    TextGroup *groups = bank->groups;
    return groups[id].count;
  }
  return 0;
}
