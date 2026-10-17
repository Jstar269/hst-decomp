/* HSTMATCH module=hstp_trans_main.prx start=0x0006d754 end=0x0006d978 symbol=FUN_0006d754 lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0006d754 { int v; };
struct Node_0006d754 { Node_0006d754 *left; Node_0006d754 *right; Node_0006d754 *parent; Value_0006d754 value; };
struct Tree_0006d754;
extern "C" {
void FUN_0006d988(void *alloc, Value_0006d754 *p);
void FUN_0006d978(void *alloc, Node_0006d754 *p, unsigned n);
void *FUN_0006d980(Tree_0006d754 *t);
void *FUN_0006d990(Tree_0006d754 *t);
void FUN_0006d754(Tree_0006d754 *t, Node_0006d754 *n);
}
inline void Destroy2_0006d754(Tree_0006d754 *t, Node_0006d754 *n)
{
    if (n->left)
        FUN_0006d754(t, n->left);
    if (n->right)
        FUN_0006d754(t, n->right);
    FUN_0006d988(FUN_0006d990(t), &n->value);
    FUN_0006d978(FUN_0006d980(t), n, 1);
}
inline void Destroy1_0006d754(Tree_0006d754 *t, Node_0006d754 *n)
{
    if (n->left)
        Destroy2_0006d754(t, n->left);
    if (n->right)
        Destroy2_0006d754(t, n->right);
    FUN_0006d990(t);
    FUN_0006d980(t);
    delete n;
}
extern "C" void FUN_0006d754(Tree_0006d754 *t, Node_0006d754 *n)
{
    if (n->left)
        Destroy1_0006d754(t, n->left);
    if (n->right)
        Destroy1_0006d754(t, n->right);
    delete n;
}
