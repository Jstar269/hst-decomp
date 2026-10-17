/* HSTMATCH module=hstp_trans_main.prx start=0x000de300 end=0x000de35c symbol=FUN_000de300 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { Node *left; Node *right; int pad; short key; };
struct Tree { int pad; Node *root; };
extern "C" Node *FUN_000de300(Tree *t, short *key, Node **found, unsigned char *lt, unsigned char *ge)
{
    *found = 0;
    Node *x = t->root;
    Node *y = (Node *)&t->root;
    *lt = 1;
    *ge = 1;
    while (x) {
        y = x;
        if (*key < x->key) {
            x = x->left;
            *lt = 1;
        } else {
            *found = x;
            x = x->right;
            *lt = 0;
            *ge = 0;
        }
    }
    return y;
}
