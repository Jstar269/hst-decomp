/* HSTMATCH module=hstp_trans_main.prx start=0x000d9adc end=0x000d9b54 symbol=FUN_000d9adc lang=c++ */
/* Clone of src/eboot/tree_lower_bound_000d5dec.cpp (hstclone.py tag u1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: outer null check, hoisted comparator address, natural while loop; exact match verified; names and types await human review. */

extern "C" int FUN_000d9ab8(void *comp, const void *k1, const void *k2);

struct Node {
    Node *left;
    Node *right;
    int pad;
    char key[4];
};

struct Tree {
    char pad[8];
    char comp;
};

extern "C" Node *FUN_000d9adc(Tree *tree, const void *key, Node *x, Node *y)
{
    if (x != 0) {
        void *comp = &tree->comp;
        while (x != 0) {
            if (FUN_000d9ab8(comp, x->key, key) == 0) {
                y = x;
                x = x->left;
            } else {
                x = x->right;
            }
        }
    }
    return y;
}
