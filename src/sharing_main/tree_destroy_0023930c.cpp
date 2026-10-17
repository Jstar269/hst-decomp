/* HSTMATCH module=hstp_trans_main.prx start=0x0023930c end=0x00239530 symbol=FUN_0023930c lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0023930c { int v; };
struct Node_0023930c { Node_0023930c *left; Node_0023930c *right; Node_0023930c *parent; Value_0023930c value; };
struct Tree_0023930c;
extern "C" {
void FUN_00068350(void *alloc, Value_0023930c *p);
void FUN_00239530(void *alloc, Node_0023930c *p, unsigned n);
void *FUN_00239538(Tree_0023930c *t);
void *FUN_00239540(Tree_0023930c *t);
void FUN_0023930c(Tree_0023930c *t, Node_0023930c *n);
}
inline void Destroy2_0023930c(Tree_0023930c *t, Node_0023930c *n)
{
    if (n->left)
        FUN_0023930c(t, n->left);
    if (n->right)
        FUN_0023930c(t, n->right);
    FUN_00068350(FUN_00239540(t), &n->value);
    FUN_00239530(FUN_00239538(t), n, 1);
}
inline void Destroy1_0023930c(Tree_0023930c *t, Node_0023930c *n)
{
    if (n->left)
        Destroy2_0023930c(t, n->left);
    if (n->right)
        Destroy2_0023930c(t, n->right);
    FUN_00239540(t);
    FUN_00239538(t);
    delete n;
}
extern "C" void FUN_0023930c(Tree_0023930c *t, Node_0023930c *n)
{
    if (n->left)
        Destroy1_0023930c(t, n->left);
    if (n->right)
        Destroy1_0023930c(t, n->right);
    delete n;
}
