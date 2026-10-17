/* HSTMATCH module=hstp_trans_main.prx start=0x000d99f4 end=0x000d9ab8 symbol=FUN_000d99f4 lang=c++ */
/* Clone of src/eboot/tree_insert_pos_000d5d04.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct String { int rep[3]; };

struct Node {
    Node *left;
    Node *right;
    unsigned parent;
    String key;
};

struct Tree {
    int pad;
    Node *root;
    char comp;
};

extern "C" int FUN_000d9ab8(void *comp, const void *k1, const void *k2);

extern "C" Node *FUN_000d99f4(Tree *tree, const String &key, Node *&j, bool &left, bool &leftmost)
{
    Node *y;
    j = 0;
    Node *x = tree->root;
    left = true;
    y = (Node *)&tree->root;
    leftmost = true;
    if (x != 0) {
        void *comp = &tree->comp;
        while (x != 0) {
            y = x;
            if (FUN_000d9ab8(comp, &key, &x->key)) {
                x = x->left;
                left = true;
            } else {
                j = x;
                x = x->right;
                left = false;
                leftmost = false;
            }
        }
    }
    return y;
}
