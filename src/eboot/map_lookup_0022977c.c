/* HSTMATCH module=EBOOT.BIN start=0x0022977c end=0x002297d8 symbol=FUN_0022977c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared key before iterator buffer, used explicit 0xffff0000 mask and inverted equality to return -1; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_002298e8(void *ret, void *map, void *key);

/* Value stored for (id, sub_key) in the pair tree, or -1 when absent. */
int FUN_0022977c(TreePair *maps, int id, u32 sub_key)
{
    u32 key = PAIR_KEY(id, sub_key);
    TreeNode *found[2];
    FUN_002298e8(found, &maps->pairs, &key);
    if (found[0] != (TreeNode *)&maps->pairs.root) {
        return found[0]->value;
    }
    return -1;
}
