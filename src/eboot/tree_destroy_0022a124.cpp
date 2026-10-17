/* HSTMATCH module=EBOOT.BIN start=0x0022a124 end=0x0022a348 symbol=FUN_0022a124 lang=c++ */
/* Clone of src/eboot/tree_destroy_00196720.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0022a124 { int v; };
struct Node_0022a124 { Node_0022a124 *left; Node_0022a124 *right; Node_0022a124 *parent; Value_0022a124 value; };
struct Tree_0022a124;
extern "C" {
void FUN_0022a358(void *alloc, Value_0022a124 *p);
void FUN_0022a348(void *alloc, Node_0022a124 *p, unsigned n);
void *FUN_0022a350(Tree_0022a124 *t);
void *FUN_0022a360(Tree_0022a124 *t);
void FUN_0022a124(Tree_0022a124 *t, Node_0022a124 *n);
}
inline void Destroy2_0022a124(Tree_0022a124 *t, Node_0022a124 *n)
{
    if (n->left)
        FUN_0022a124(t, n->left);
    if (n->right)
        FUN_0022a124(t, n->right);
    FUN_0022a358(FUN_0022a360(t), &n->value);
    FUN_0022a348(FUN_0022a350(t), n, 1);
}
inline void Destroy1_0022a124(Tree_0022a124 *t, Node_0022a124 *n)
{
    if (n->left)
        Destroy2_0022a124(t, n->left);
    if (n->right)
        Destroy2_0022a124(t, n->right);
    FUN_0022a360(t);
    FUN_0022a350(t);
    delete n;
}
extern "C" void FUN_0022a124(Tree_0022a124 *t, Node_0022a124 *n)
{
    if (n->left)
        Destroy1_0022a124(t, n->left);
    if (n->right)
        Destroy1_0022a124(t, n->right);
    delete n;
}
