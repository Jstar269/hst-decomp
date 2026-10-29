/* HSTMATCH module=EBOOT.BIN start=0x00196720 end=0x00196944 symbol=FUN_00196720 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_00196720 { int v; };
struct Node_00196720 { Node_00196720 *left; Node_00196720 *right; Node_00196720 *parent; Value_00196720 value; };
struct Tree_00196720;
extern "C" {
void FUN_00066efc(void *alloc, Value_00196720 *p);
void FUN_00196944(void *alloc, Node_00196720 *p, unsigned n);
void *FUN_0019694c(Tree_00196720 *t);
void *FUN_00196954(Tree_00196720 *t);
void FUN_00196720(Tree_00196720 *t, Node_00196720 *n);
}
inline void Destroy2_00196720(Tree_00196720 *tree, Node_00196720 *node)
{
    if (node->left)
        FUN_00196720(tree, node->left);
    if (node->right)
        FUN_00196720(tree, node->right);
    FUN_00066efc(FUN_00196954(tree), &node->value);
    FUN_00196944(FUN_0019694c(tree), node, 1);
}
inline void Destroy1_00196720(Tree_00196720 *tree, Node_00196720 *node)
{
    if (node->left)
        Destroy2_00196720(tree, node->left);
    if (node->right)
        Destroy2_00196720(tree, node->right);
    FUN_00196954(tree);
    FUN_0019694c(tree);
    delete node;
}
extern "C" void FUN_00196720(Tree_00196720 *tree, Node_00196720 *node)
{
    if (node->left)
        Destroy1_00196720(tree, node->left);
    if (node->right)
        Destroy1_00196720(tree, node->right);
    delete node;
}
