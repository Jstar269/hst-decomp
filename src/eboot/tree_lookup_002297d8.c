/* HSTMATCH module=EBOOT.BIN start=0x002297d8 end=0x00229868 symbol=FUN_002297d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed sentinel ternaries and local array dimensions for 48-byte frame; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00229868(void *, const void *, const int *);
extern void FUN_002298e8(void *, const void *, const int *);

/* Looks up a name key to get an id, then the (id, sub_key) pair; -1 at either miss. */
int FUN_002297d8(TreePair *maps, int name_key, u32 sub_key)
{
    int key1 = name_key;
    int key2[2];
    TreeNode *it1[2];
    TreeNode *it2;

    FUN_00229868(it1, maps, &key1);
    int id = (it1[0] != (TreeNode *)&maps->names.root) ? it1[0]->value : -1;

    key2[0] = PAIR_KEY(id, sub_key);
    FUN_002298e8(&it2, &maps->pairs, key2);
    return (it2 != (TreeNode *)&maps->pairs.root) ? it2->value : -1;
}
