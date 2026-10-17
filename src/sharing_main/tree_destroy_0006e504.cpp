/* HSTMATCH module=hstp_trans_main.prx start=0x0006e504 end=0x0006e728 symbol=FUN_0006e504 lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_0006e504 { int v; };
struct Node_0006e504 { Node_0006e504 *left; Node_0006e504 *right; Node_0006e504 *parent; Value_0006e504 value; };
struct Tree_0006e504;
extern "C" {
void FUN_0006e738(void *alloc, Value_0006e504 *p);
void FUN_0006e728(void *alloc, Node_0006e504 *p, unsigned n);
void *FUN_0006e730(Tree_0006e504 *t);
void *FUN_0006e740(Tree_0006e504 *t);
void FUN_0006e504(Tree_0006e504 *t, Node_0006e504 *n);
}
inline void Destroy2_0006e504(Tree_0006e504 *t, Node_0006e504 *n)
{
    if (n->left)
        FUN_0006e504(t, n->left);
    if (n->right)
        FUN_0006e504(t, n->right);
    FUN_0006e738(FUN_0006e740(t), &n->value);
    FUN_0006e728(FUN_0006e730(t), n, 1);
}
inline void Destroy1_0006e504(Tree_0006e504 *t, Node_0006e504 *n)
{
    if (n->left)
        Destroy2_0006e504(t, n->left);
    if (n->right)
        Destroy2_0006e504(t, n->right);
    FUN_0006e740(t);
    FUN_0006e730(t);
    delete n;
}
extern "C" void FUN_0006e504(Tree_0006e504 *t, Node_0006e504 *n)
{
    if (n->left)
        Destroy1_0006e504(t, n->left);
    if (n->right)
        Destroy1_0006e504(t, n->right);
    delete n;
}
