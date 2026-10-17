/* HSTMATCH module=EBOOT.BIN start=0x000d5d04 end=0x000d5dc8 symbol=FUN_000d5d04 lang=c++ */
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

extern "C" int FUN_000d5dc8(void *comp, const void *k1, const void *k2);

extern "C" Node *FUN_000d5d04(Tree *tree, const String &key, Node *&j, bool &left, bool &leftmost)
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
            if (FUN_000d5dc8(comp, &key, &x->key)) {
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
