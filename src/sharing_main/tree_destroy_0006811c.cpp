/* HSTMATCH module=hstp_trans_main.prx start=0x0006811c end=0x00068340 symbol=FUN_0006811c lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0006811c { int v; };
struct Node_0006811c { Node_0006811c *left; Node_0006811c *right; Node_0006811c *parent; Value_0006811c value; };
struct Tree_0006811c;
extern "C" {
void FUN_00068350(void *alloc, Value_0006811c *p);
void FUN_00068340(void *alloc, Node_0006811c *p, unsigned n);
void *FUN_00068348(Tree_0006811c *t);
void *FUN_00068358(Tree_0006811c *t);
void FUN_0006811c(Tree_0006811c *t, Node_0006811c *n);
}
inline void Destroy2_0006811c(Tree_0006811c *t, Node_0006811c *n)
{
    if (n->left)
        FUN_0006811c(t, n->left);
    if (n->right)
        FUN_0006811c(t, n->right);
    FUN_00068350(FUN_00068358(t), &n->value);
    FUN_00068340(FUN_00068348(t), n, 1);
}
inline void Destroy1_0006811c(Tree_0006811c *t, Node_0006811c *n)
{
    if (n->left)
        Destroy2_0006811c(t, n->left);
    if (n->right)
        Destroy2_0006811c(t, n->right);
    FUN_00068358(t);
    FUN_00068348(t);
    delete n;
}
extern "C" void FUN_0006811c(Tree_0006811c *t, Node_0006811c *n)
{
    if (n->left)
        Destroy1_0006811c(t, n->left);
    if (n->right)
        Destroy1_0006811c(t, n->right);
    delete n;
}
