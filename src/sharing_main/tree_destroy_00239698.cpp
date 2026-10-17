/* HSTMATCH module=hstp_trans_main.prx start=0x00239698 end=0x002398bc symbol=FUN_00239698 lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_00239698 { int v; };
struct Node_00239698 { Node_00239698 *left; Node_00239698 *right; Node_00239698 *parent; Value_00239698 value; };
struct Tree_00239698;
extern "C" {
void FUN_002398cc(void *alloc, Value_00239698 *p);
void FUN_002398bc(void *alloc, Node_00239698 *p, unsigned n);
void *FUN_002398c4(Tree_00239698 *t);
void *FUN_002398d4(Tree_00239698 *t);
void FUN_00239698(Tree_00239698 *t, Node_00239698 *n);
}
inline void Destroy2_00239698(Tree_00239698 *t, Node_00239698 *n)
{
    if (n->left)
        FUN_00239698(t, n->left);
    if (n->right)
        FUN_00239698(t, n->right);
    FUN_002398cc(FUN_002398d4(t), &n->value);
    FUN_002398bc(FUN_002398c4(t), n, 1);
}
inline void Destroy1_00239698(Tree_00239698 *t, Node_00239698 *n)
{
    if (n->left)
        Destroy2_00239698(t, n->left);
    if (n->right)
        Destroy2_00239698(t, n->right);
    FUN_002398d4(t);
    FUN_002398c4(t);
    delete n;
}
extern "C" void FUN_00239698(Tree_00239698 *t, Node_00239698 *n)
{
    if (n->left)
        Destroy1_00239698(t, n->left);
    if (n->right)
        Destroy1_00239698(t, n->right);
    delete n;
}
