/* HSTMATCH module=EBOOT.BIN start=0x002294f4 end=0x002295f4 symbol=FUN_002294f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured if/else ladder sharing common return variable, ternary map end check; readability pass; exact match verified; names and types await human review. */
#include "hst/tree_map.h"
#include "hst/text_bank_lookup.h"

extern void FUN_00229868(void *out, void *map, void *key);

/* Finds the group id for key_val in the name tree, then returns string index of that group in the bank. */
void *FUN_002294f4(TreeMap *map, TextBank *bank, int key_val, int index)
{
  int key = key_val;
  TreeNode *it[2];
  
  FUN_00229868(it, map, &key);
  int id = (it[0] != (TreeNode *)&map->root) ? it[0]->value : -1;

  if (bank != 0) {
    if (id >= 0) {
      void *res;
      if (bank->loaded == 0) {
        res = &DAT_002c0e20;
      } else if (id < 0 || id >= bank->header->groupCount) {
        res = &DAT_002c0e1c;
      } else if (index < 0 || index >= bank->groups[id].count) {
        res = &DAT_002c0e18;
      } else {
        res = (void *)bank->groups[id].strings[index];
      }
      return res;
    }
  }
  return 0;
}
