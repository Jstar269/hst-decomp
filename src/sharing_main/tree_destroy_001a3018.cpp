/* HSTMATCH module=hstp_trans_main.prx start=0x001a3018 end=0x001a323c symbol=FUN_001a3018 lang=c++ */
/* Clone of src/eboot/tree_destroy_00066cc8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_001a3018 { int v; };
struct Node_001a3018 { Node_001a3018 *left; Node_001a3018 *right; Node_001a3018 *parent; Value_001a3018 value; };
struct Tree_001a3018;
extern "C" {
void FUN_00068350(void *alloc, Value_001a3018 *p);
void FUN_001a323c(void *alloc, Node_001a3018 *p, unsigned n);
void *FUN_001a3244(Tree_001a3018 *t);
void *FUN_001a324c(Tree_001a3018 *t);
void FUN_001a3018(Tree_001a3018 *t, Node_001a3018 *n);
}
inline void Destroy2_001a3018(Tree_001a3018 *t, Node_001a3018 *n)
{
    if (n->left)
        FUN_001a3018(t, n->left);
    if (n->right)
        FUN_001a3018(t, n->right);
    FUN_00068350(FUN_001a324c(t), &n->value);
    FUN_001a323c(FUN_001a3244(t), n, 1);
}
inline void Destroy1_001a3018(Tree_001a3018 *t, Node_001a3018 *n)
{
    if (n->left)
        Destroy2_001a3018(t, n->left);
    if (n->right)
        Destroy2_001a3018(t, n->right);
    FUN_001a324c(t);
    FUN_001a3244(t);
    delete n;
}
extern "C" void FUN_001a3018(Tree_001a3018 *t, Node_001a3018 *n)
{
    if (n->left)
        Destroy1_001a3018(t, n->left);
    if (n->right)
        Destroy1_001a3018(t, n->right);
    delete n;
}
