/* HSTMATCH module=EBOOT.BIN start=0x000da340 end=0x000da39c symbol=FUN_000da340 lang=c++ */
/* Clone of src/sharing_main/tree_find_insert_pos_000de300.cpp (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { Node *left; Node *right; int pad; short key; };
struct Tree { int pad; Node *root; };
extern "C" Node *FUN_000da340(Tree *t, short *key, Node **found, unsigned char *lt, unsigned char *ge)
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
