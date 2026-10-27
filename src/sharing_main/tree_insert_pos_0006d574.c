/* HSTMATCH module=hstp_trans_main.prx start=0x0006d574 end=0x0006d5d0 symbol=FUN_0006d574 lang=c99 */
/* Clone of src/eboot/tree_insert_pos_0006bed4.c (hstclone.py tag a0db26hsEB): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node {
    struct Node *left;
    struct Node *right;
    int parent;
    int key;
} Node;

typedef struct Tree {
    int count;
    Node *root;
} Tree;

Node *FUN_0006d574(Tree *tree, int *key, Node **found, unsigned char *wentLeft, unsigned char *allLeft)
{
    Node *y;
    Node *x;
    *found = 0;
    y = (Node *)&tree->root;
    x = tree->root;
    *wentLeft = 1;
    *allLeft = 1;
    while (x != 0) {
        y = x;
        if (*key < x->key) {
            x = x->left;
            *wentLeft = 1;
        } else {
            *found = x;
            x = x->right;
            *wentLeft = 0;
            *allLeft = 0;
        }
    }
    return y;
}
