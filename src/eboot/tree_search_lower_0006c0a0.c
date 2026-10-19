/* HSTMATCH module=EBOOT.BIN start=0x0006c0a0 end=0x0006c0fc symbol=FUN_0006c0a0 lang=c99 */
/* Clone of src/sharing_main/tree_search_lower_0006d62c.c (hstclone.py tag s10181937g11r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node { struct Node *left; struct Node *right; int aux; unsigned int key; } Node;
typedef struct Tree { unsigned int count; Node *root; } Tree;

Node *FUN_0006c0a0(Tree *t, unsigned int *k, Node **out, unsigned char *f1, unsigned char *f2)
{
    *out = 0;
    Node *n = t->root;
    Node *best = (Node *)&t->root;
    *f1 = 1;
    *f2 = 1;
    while (n != 0) {
        best = n;
        unsigned int key = *k;
        if (key < n->key) {
            n = n->left;
            *f1 = 1;
        } else {
            *out = n;
            n = n->right;
            *f1 = 0;
            *f2 = 0;
        }
    }
    return best;
}
