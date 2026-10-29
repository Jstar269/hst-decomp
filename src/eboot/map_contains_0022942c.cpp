/* HSTMATCH module=EBOOT.BIN start=0x0022942c end=0x00229470 symbol=FUN_0022942c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, char* pointer types, extern "C" linkage; readability pass; exact match verified; names and types await human review. */
#include "hst/tree_map.h"

extern "C" void FUN_00229868(void*, const void*, const void*);

/* True when key is present in the tree. */
extern "C" bool FUN_0022942c(TreeMap *map, int key)
{
  TreeNode *found;
  int search_key = key;
  
  FUN_00229868(&found, map, &search_key);
  return found != (TreeNode *)&map->root;
}
