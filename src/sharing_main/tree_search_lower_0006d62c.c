/* HSTMATCH module=hstp_trans_main.prx start=0x0006d62c end=0x0006d688 symbol=FUN_0006d62c lang=c99 */
/* Clone of src/eboot/tree_search_lower_00229bf0.c (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node { struct Node *left; struct Node *right; int aux; unsigned int key; } Node;
typedef struct Tree { unsigned int count; Node *root; } Tree;

Node *FUN_0006d62c(Tree *t, unsigned int *k, Node **out, unsigned char *f1, unsigned char *f2)
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
