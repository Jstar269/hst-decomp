/* HSTMATCH module=EBOOT.BIN start=0x0006cf1c end=0x0006d140 symbol=FUN_0006cf1c lang=c++ */
/* Clone of src/eboot/tree_destroy_00196720.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0006cf1c { int v; };
struct Node_0006cf1c { Node_0006cf1c *left; Node_0006cf1c *right; Node_0006cf1c *parent; Value_0006cf1c value; };
struct Tree_0006cf1c;
extern "C" {
void FUN_0006d150(void *alloc, Value_0006cf1c *p);
void FUN_0006d140(void *alloc, Node_0006cf1c *p, unsigned n);
void *FUN_0006d148(Tree_0006cf1c *t);
void *FUN_0006d158(Tree_0006cf1c *t);
void FUN_0006cf1c(Tree_0006cf1c *t, Node_0006cf1c *n);
}
inline void Destroy2_0006cf1c(Tree_0006cf1c *t, Node_0006cf1c *n)
{
    if (n->left)
        FUN_0006cf1c(t, n->left);
    if (n->right)
        FUN_0006cf1c(t, n->right);
    FUN_0006d150(FUN_0006d158(t), &n->value);
    FUN_0006d140(FUN_0006d148(t), n, 1);
}
inline void Destroy1_0006cf1c(Tree_0006cf1c *t, Node_0006cf1c *n)
{
    if (n->left)
        Destroy2_0006cf1c(t, n->left);
    if (n->right)
        Destroy2_0006cf1c(t, n->right);
    FUN_0006d158(t);
    FUN_0006d148(t);
    delete n;
}
extern "C" void FUN_0006cf1c(Tree_0006cf1c *t, Node_0006cf1c *n)
{
    if (n->left)
        Destroy1_0006cf1c(t, n->left);
    if (n->right)
        Destroy1_0006cf1c(t, n->right);
    delete n;
}
